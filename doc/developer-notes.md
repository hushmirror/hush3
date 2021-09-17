# Fresh sync

Many times, you will want to do a "fresh sync" test, to verify code works when syncing from the genesis block, which is a different code path than a "partial sync" which means you already have part of blockchain history and are "catching up" to get in sync.

A "fresh sync" goes thru the Initial Blockchain Download (IBD) optimized codepath and is often faster than than rescanning all of history. Fresh sync and partial sync testing any important change should be done for all important changes.

A fresh sync preserves peers.dat, so it will always be faster than a "fresh clone", which has to learn enough p2p peers to being syncing, which can often add many minutes to completing a sync. When code related to peers.dat changes (such in the `p2p` branch) then doing a fresh clone is needed to fully test it.

One way to do a fresh sync is:

```
cd ~/.hush/HUSH3
rm blocks chainstate database notarizations hushstate
```

NOTE: The legacy directory is ~/.komodo/HUSH3 and hushd will use data from either, or ~/.hush/HUSH3 if both exist.

If you are using `zindex=1` then you need to also delete zindex.dat

```
cd ~/.hush/HUSH3
rm zindex.dat blocks chainstate database notarizations hushstate
```

It's possible to confused hush if you ran old code, stop, restart, and then write out zindex.dat that is incorrect, with later hushds will load from disk and believe.

# Making a new release of Hush

  * Update version in configure.ac and src/clientversion.h
  * Run ./contrib/devtools/gen-manpages.sh, commit + push results
  * Update checkpoints
  * Update protocol version if necessary
  * Make Gitea release
  * Make Git Tag (Gitea can do this)


# Testing a Branch

To test a branch called `zindexdb` with a fresh clone:

```
# TODO: this should probably become a script in ./contrib
git clone https://git.hush.is/hush/hush3 hush3-testing
cd hush3-testing
git checkout zindexdb
# you need 2GB RAM free per -jN
./build.sh -j2; make; make; make # this deals with build-system race condition bugs

# we want to test a fresh sync, so backup current data
TIME=`perl -e "print time"`
mv ~/.hush/{HUSH3,HUSH3-backup-$TIME}
mkdir ~/.hush/HUSH3

# Use your previous config as a base
cp ~/.hush/{HUSH3-backup-$TIME,HUSH3}/HUSH3.conf
# Add zindex to your node
echo "zindex=1" >> ~/.hush/HUSH3/HUSH3.conf


# This is optional but will likely speed up sync time greatly
cp ~/.hush/{HUSH3-backup,HUSH3}/peers.dat

# This log file is helpful for debugging more and will contain a history of the
# size of the anonset at every block height
./src/hushd &> hushd.log &
# to look at the log
tail -f hushd.log
```

To get a CSV file of the value of the anonset size for every block height:
```
grep anonset hushd.log | cut -d= -f2 > anonset.csv
```

This only needs to be calculated once, if we can verify it's correct. These are historical values that do not change. The goal is a web page with a historical view of the HUSH anonset size.


These values should match on all nodes:

```
46913,2547,2253,294
46914,2549,2254,295
46915,2549,2254,295
46916,2553,2257,296
46917,2553,2257,296
```

We should also check a recent block height to verify it's working correctly. The big "test" for this `zindexdb` branch is: 

  * If you stop a node, and restart, are the stats from `getchaintxtstats` correct, i.e. the anonset stats? For instance, `shielded_pool_size` should be close to 500000, if it's close to or exactly 0, something is wrong.
  * Is there a new file called `zindex.dat` in `~/.hush/HUSH3/` ? 
  * Is `zindex.dat` 149 bytes ?
  
# Coding

Various coding styles have been used during the history of the codebase,
and the result is not very consistent. However, we're now trying to converge to
a single style, so please use it in new code. Old code will be converted
gradually.
- Basic rules specified in src/.clang-format. Use a recent clang-format-3.5 to format automatically.
  - Braces on new lines for namespaces, classes, functions, methods.
  - Braces on the same line for everything else.
  - 4 space indentation (no tabs) for every block except namespaces.
  - No indentation for public/protected/private or for namespaces.
  - No extra spaces inside parenthesis; don't do ( this )
  - No space after function names; one space after if, for and while.

Block style example:
```c++
namespace foo
{
class Class
{
    bool Function(char* psz, int n)
    {
        // Comment summarising what this section of code does
        for (int i = 0; i < n; i++) {
            // When something fails, return early
            if (!Something())
                return false;
            ...
        }

        // Success return is usually at the end
        return true;
    }
}
}
```

Development tips and tricks
---------------------------

**compiling for debugging**

Run configure with the --enable-debug option, then make. Or run configure with
CXXFLAGS="-g -ggdb -O0" or whatever debug flags you need.

**debug.log**

If the code is behaving strangely, take a look in the debug.log file in the data directory;
error and debugging messages are written there.

The -debug=... command-line option controls debugging; running with just -debug or -debug=1 will turn
on all categories (and give you a very large debug.log file).

**testnet and regtest modes**

Run with the -testnet option to run with "play zcash" on the test network, if you
are testing multi-machine code that needs to operate across the internet.

If you are testing something that can run on one machine, run with the -regtest option.
In regression test mode, blocks can be created on-demand; see qa/rpc-tests/ for tests
that run in -regtest mode.

**DEBUG_LOCKORDER**

Hush is a multithreaded application, and deadlocks or other multithreading bugs
can be very difficult to track down. Compiling with -DDEBUG_LOCKORDER (configure
CXXFLAGS="-DDEBUG_LOCKORDER -g") inserts run-time checks to keep track of which locks
are held, and adds warnings to the debug.log file if inconsistencies are detected.

Locking/mutex usage notes
-------------------------

The code is multi-threaded, and uses mutexes and the
LOCK/TRY_LOCK macros to protect data structures.

Deadlocks due to inconsistent lock ordering (thread 1 locks cs_main
and then cs_wallet, while thread 2 locks them in the opposite order:
result, deadlock as each waits for the other to release its lock) are
a problem. Compile with -DDEBUG_LOCKORDER to get lock order
inconsistencies reported in the debug.log file.

Re-architecting the core code so there are better-defined interfaces
between the various components is a goal, with any necessary locking
done by the components (e.g. see the self-contained CKeyStore class
and its cs_KeyStore lock for example).

Threads
-------

- ThreadScriptCheck : Verifies block scripts.

- ThreadImport : Loads blocks from blk*.dat files or bootstrap.dat.

- StartNode : Starts other threads.

- ThreadDNSAddressSeed : Loads addresses of peers from the DNS.

- ThreadMapPort : Universal plug-and-play startup/shutdown

- ThreadSocketHandler : Sends/Receives data from peers on port 8233.

- ThreadOpenAddedConnections : Opens network connections to added nodes.

- ThreadOpenConnections : Initiates new connections to peers.

- ThreadMessageHandler : Higher-level message handling (sending and receiving).

- DumpAddresses : Dumps IP addresses of nodes to peers.dat.

- ThreadFlushWalletDB : Close the wallet.dat file if it hasn't been used in 500ms.

- ThreadRPCServer : Remote procedure call handler, listens on port 8232 for connections and services them.

- HushMiner : Generates zcash (if wallet is enabled).

- Shutdown : Does an orderly shutdown of everything.

Pull Request Terminology
------------------------

Concept ACK - Agree with the idea and overall direction, but have neither reviewed nor tested the code changes.

utACK (untested ACK) - Reviewed and agree with the code changes but haven't actually tested them.

Tested ACK - Reviewed the code changes and have verified the functionality or bug fix.

ACK -  A loose ACK can be confusing. It's best to avoid them unless it's a documentation/comment only change in which case there is nothing to test/verify; therefore the tested/untested distinction is not there.

NACK - Disagree with the code changes/concept. Should be accompanied by an explanation.
