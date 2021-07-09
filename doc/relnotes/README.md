# Official Hush Release Notes

Hush release notes were done on Github until 3.5.2,
and now are officially part of our Git repo.

## Downloading Releases

Hush releases are on our own Gitea at <a href="https://git.hush.is/">git.hush.is</a>
and no longer on Github, since they banned Duke Leto and
also because they censor many people around the world and work with
evil organizations.

# Hush 3.8.0 "XXX YYY"

This is an OPTIONAL release, but since it contains many privacy improvements, it's HIGHLY RECOMMENDED for all users to upgrade.

    * New Sietch feature: Randomized change output location
      * Zcash and Pirate always put the change as the last shielded output, which leaks metadata. Hush no longer has this metadata leakage.
      * This feature improves the `z_sendmany`, `z_mergetoaddress` and `z_shieldtocoinbase` since it's done in the Hush TransactionBuilder.
    * New Sietch feature: Sitech-ified `z_shieldcoinbase`
      * This RPC now leaks less metadata by making it hard for blockchain analysts to know which of the three outputs has value.
      * This also increases Hush's "anonset velocity", which is how fast we increase our anonymity set, or "anonset".
    * Previously you could only run `stop` while Hush was in RPC warmup, but now additional RPCs are allowed:
      * `stop` - Oops, you started hushd on accident a few seconds ago? Now you can stop it without waiting.
      * `help` - Get help during long rescans, finally!
      * `z_listaddresses` - See a list of all zaddrs in this wallet, even during a long rescan!
      * `z_exportkey` - Export a key from this node, even during rescan!
      * `listaddresses` - See a list of taddrs as soon as we load the wallet.
      * `dumpprivkey` - Dump the private key of a taddr, even when node isn't fully synced!
      * `getpeerinfo` - See current peers even before we get enough peers to start syncing or a long rescan!
    * `-keepnotewitnesscache` prevents the Sapling Note Witness cache from being deleted from wallet.dat on shutdown.
    * `-rescanheight` can be used with `-keepnotewitnesscache` and `-rescan` to do a partial rescan of history and avoid completely rebuilding the Witness Cache.
    * `-zindex` data is now stored on disk in the new `zindex.dat` file
      * All nodes that use `-zindex` will now have reliable anonset statistics even after a restart
    * Improvements to the RPC help documentation

# Hush 3.7.1 "Neologistic Nautilus"

```
638 files changed, 1484 insertions(+), 962 deletions(-)
```

This is an OPTIONAL release for average Hush users, but is HIGHLY RECOMMENDED for service providers, such as lite wallet server ops, mining pools, exchanges, bots, etc.

## Notable Changes

  * :tada: More internals code related to unused Sprout transactions was removed, making Hush run and compile faster and use less memory.
  * :smile: We now give a more useful error message when a user attempts to make a tx before the node is synced.
  * :nerd_face: `z_sendmany` RPC docs now show an example of a z2z transaction
  * :closed_lock_with_key: Various security + privacy improvements to the network Peer To Peer (p2p) layer, including:
    * The deprecated `alert` p2p message is no longer processed and nodes using it will be banned.
    * `try-before-evict` ported from BTC core, which helps protect again Eclipse and Sybil Attacks
    * "Feeler connections" ported from BTC, another technique which makes Eclipse and Sybil Attacks harder and more expensive
    * From the paper "Eclipse Attacks on Bitcoin’s Peer-to-Peer Network" Ethan Heilman, Alison Kendler, Aviv Zohar, Sharon Goldberg. https://eprint.iacr.org/2015/263.pdf
    * Related to https://github.com/bitcoin/bitcoin/pull/8282
  * :unicorn: New RPC: `z_getbalances` returns a list of all zaddrs with non-zero balance.
      * An optional paramater can filter addresses to those with a specified minimum balance, such as
          `z_getbalances 0.1` will only show HUSH zaddrs with at least 0.1 HUSH.
  * :rainbow: "Automagic `z_sendmany`" makes the RPC easier to use and also improves privacy
      * The `z_sendmany` RPC now understands a symbolic from address of `z` which means:
          * Randomly choose any zaddr with enough balance as from address
      * This means CLI users no longer need to run multiple RPC's to find a zaddr with enough balance and specify it themselves
      * It also means that CLI shell history and cronjobs or source code does not contain the source zaddr, improving privacy.


# Hush 3.7.0 "Diffy The DAA Kungfoo Cuckoo"

```
13 files changed, 102 insertions(+), 91 deletions(-)
```

This is an OPTIONAL release for most Hush users. It is MANDATORY for miners, specifically solo miners and mining pools. It is not required for POOL miners.

# Hush 3.6.3 "Autonomous Aconite's Aunt"

:rainbow: OPTIONAL but RECOMMENDED release. :rainbow:

This release is mostly the same as 3.6.2 but it fixes some issues in Debian+Arch packages and binaries not being able to find asmap.dat, which did not occur when building from Git source. This release protects all users, by default, from network attacks like the Erebus Attack: https://erebus-attack.comp.nus.edu.sg/

# Hush 3.6.2 "Autonomous Aconite"

:eyes: This is an OPTIONAL but RECOMMENDED Hush Full Node release :eyes:


##  Notable changes

  * :robot: Autonomous System Map (asmap) bucketing by default
    * :tada: HUSH is the first cryptocoin to take this work from BTC Core and turn it on by default for all nodes
    *  :100: SD 1.1.1 did this itself, and now we push that change into the full node itself.
    * :metal: The new CLI flag `-asmap` is on by default, and can be turned off with `-asmap=0`
    * :peach: This setting helps users by having 7.4 million "buckets" for peers instead of only 65000 which the traditional /16 scheme uses. This means all Hush full nodes are more protected against network-layer attacks such as the Erebus Attack: https://erebus-attack.comp.nus.edu.sg/
  * :wink: debug.log is now shrunk to 15MB instead of 100MB
  * :nerd_face: The max size of debug.log can now be controlled via `-maxdebugfilesize`
  * :rainbow: A new document that gives an Overview of Hush:  https://git.hush.is/hush/hush3/src/branch/master/doc/overview.md

```
30db6e6f0cab9f4ac0a4c4b5968a9db8e04ee6a2eb23fe4ae51e8e6bf76b8044  hush-3.6.2-ubuntu-16.04-amd64.tar.gz
2393910c224b98213725bd4671dd245c36c19dbe6abb4015b8df181064eb9b64  hush-3.6.2-ubuntu-16.04.deb
```

# Hush 3.6.1 "Syncopated Sphinx"

:fire: This is an OPTIONAL release, but upgrading is ENCOURAGED. :fire:

```
 101 files changed, 1158 insertions(+), 5793 deletions(-)
```

  * :tada: WolfSSL upgraded to 4.6.0 and side-channel resistance enabled via `ECC_TIMING_RESISTANT`
  * :rainbow: Hush full nodes will now exclusively communivate via P2P messages with TLS1.3,
    the option -tls=only has become default and cannot be turned off
  * :100: Improved error-handling and logging of TLS connections
  * :peach: getpeerinfo now shows 3 new keys for each peer:
    * `tls_established` - if a TLS connection has been established to this peer
    * `tls_cipher`      - which TLS cipher is being used with this peer
    * `tls_verified`    - if the TLS certificate was validated
  * :kiss: Important Windows bugfix: SIGTERM is now handled correctly on Windows, which means
    hushd will be less likely to corrupt data on disk
  * :nerd_face: New developer documentation in DEVELOPING.md
  * :alien: `-whitelist` and `-whitelistaddress` are now called `-allowlist` and `-allowlistaddress`
    * Duke Leto felt the old terminology of a "whitelist" was racist and unintuitive for
      non-native speakers, so it was changed.
  * :closed_lock_with_key: Minimum protocol version is now `1987420`

# Hush 3.6.0 "Decentralized Dominatrix"

```
983 files changed, 7736 insertions(+), 17688 deletions(-)
```

<img src="https://git.hush.is/hush/hush3/raw/branch/master/doc/relnotes/img/hush-3.6.0.png">

:metal: :metal: :metal:
This release consists of 25454 lines of changes, almost 18000 lines of deletions
and just short of 1000 files changed! This is why Hush code is so fast, we delete
all that KYC/PoS/Sprout stuff from KMD internals we inherited and improve daily.
:metal: :metal: :metal:

  * :100: Fixes sync issues near block 340k caused by blocktime halving bug
  * :sweat_drops: New official domain https://hush.is reflected everywhere
  * :tada: Hush Docker scripts are now officially maintained!
  * :eggplant: New Hush DPoW Notaries replace KMD Notaries (who attacked us, lulz)
  * :rocket: Increasd in-memory UTXO cache db by 100MB (25%) to increase performance of initial syncing
  * :dragon: Prevent Delayed-Proof-of-Work attack from Komodo Notaries
    * :shit: KMD notaries provably attacked the HUSH blockchain via their pubkeys
    * :speak_no_evil: All trust in their service has now been lost, and all Komodo pubkeys
      have been removed from Hush source code
    * :alien: "Malicious Notarized Chainforks" is an attack only Komodo Notaries
      can perform against chains they are supposed to protect. More details
      to be released soon.
    * :rainbow: Defense-in-depth has been implemented and an overhaul+audit of the entire
      Hush source code was implemented, which is partially why this release
      has so many changes.
    * :angel: New -dpow-start-height CLI flag can be used to reject all DPoW transactions
      (and attacks) up to a certain height, which is a general defense against
      potential future DPoW attacks. Also: Fuck you, jl777.
    * :kiss: Hush developers will not be silenced and laugh at KMD NN ops with too much
      time on their hands
  * :closed_lock_with_key: More secure+private TLS 1.3 implementation from miodrag, thanks!
    * :loudspeaker: We now use WolfSSL 4.5.0 instead of OpenSSL, a huge improvement and
      decrease in attack surface as well as allowing use to do TLS
      on low resource devices (like internet-of-shit light bulbs/etc)
    * :lock: Nodes randomly choose between GCM-SHA384 and CHACHA20-POLY1305-SHA256 when
      making connections to other nodes.
  * :rabbit2: Faster release binaries with -03
  * :fork_and_knife: Optimized and hardened memory pool code
  * :hammer: getblocktemplate RPC now provides better error reporting about
    whether there are no peers or if it's not in sync
  * :recycle: Removed more Sprout code which is tightly mixed into deep internals,
    which increases compile speed and reduces memory overhead
  * :surfer: New P2P protocol version. Peers only talk to 3.5.x nodes and newer


### 3.6.0 Checksums

```
33cd82c51eac404796e6c296044b1d8fcc653d60b2bf26eecb5df0e374a35825  hush-3.6.0-linux-ubuntu-18.04-amd64.tar.gz
9c2f19c50fdc44af2c89494b06cda2c9e176d7ae2f038ca0fb7c0cd083dd71b9  hush-3.6.0-linux-ubuntu-18.04-noparams-amd64.tar.gz
9799aaea1503770336efc328fcd43c3a46d7bede8c485f77977423f949145d81  hush-3.6.0-amd64.deb
2f0ebbcbb9bb0bcffe95a397e7eba89c29eb4dde6191c339db88570e3f3fb0e4  sapling-output.params
8e48ffd23abb3a5fd9c5589204f32d9c31285a04b78096ba40a79b75677efc13  sapling-spend.params

```


## Bounty

Would you like to transcribe old Github releases to this file for a HUSH
bounty? Join https://hush.is/tg to learn more.
