# Hush

## What is Hush?

![Logo](doc/hush/hush.png "Logo")

Hush implements Extreme Privacy via blockchain tech. We have our own
genesis block. We are not a chain fork (copy) of another coin. We are based on
Bitcoin code, with sophisticated zero-knowledge mathematics added for privacy.
This keeps your transaction metadata private!

## This repository

This software is the Hush node and command-line client. It downloads and stores
the entire history of Hush transactions; depending on the speed of your
computer and network connection, it will likely take a few hours at least, but
some people report full nodes syncing in less than 1.5 hours. A competing privacy
coin takes over 24 hours to sync their full nodes because of Sprout Transactions, lulz.

## BANNED BY GITHUB

In working on this release, Duke Leto was suspended from Github, which gave Hush developers
the impetus to completely leave that racist and censorship-loving platform.

Hush now has it's own <a href="https://git.hush.is/hush">git.hush.is</a> Gitea instance,
because we will not be silenced by Microsoft.

All Hush software will be released from git.hush.is and hush.is, downloads from any other
domains should be assumed to be backdoored.

**Hush is unfinished and highly experimental.** Use at your own risk! Just like Bitcoin.

## Socials

Please feel free to join us on Telegram for official support :
    * Main group: https://hush.is/tg
    * Support group: https://hush.is/telegram_support
    * Mining group: https://hush.is/telegram_mining

Other socials:

    * <a href="https://hush.is/twitter">@MyHushTeam</a> on Twitter</a>
    * <a href="https://hush.is/yt">Hush</a> on YouTube</a>
    * <a href="https://hush.is/reddit">Hush</a> on Reddit</a>

## Official Explorer

<a href="https://explorer.hush.is">explorer.hush.is</a>

We are looking for alternate explorers to be run on Tor, i2P and other TLDs, if you are interested
please join TG and ask questions.

## Claiming Funds From Old Hush Wallets

Hush migrated to a new mainnet after Block 500,000 on the old Hush blockchain.
Funds in addresses as of Block 500,000 were transported to our new chain. About
31,000 addresses with at least 0.00000001 HUSH were transported to the new Hush
mainnet.

To claim funds on the new chain, there are few options.

### Funds on exchanges

Firstly, no bueno! Not your keys, not your coins. It's best not to store coins
on exchanges. But in this case, you lucked out! There is nothing to do to claim
new coins if you have coins on an exchange that supports the new Hush chain.
The exchange will follow the instructions from the next section and you will
magically have funds on the new chain. Note that old Hush addresses started
with `t1` and now they begin with `R`.

To see what an old HUSH v2 address looks like on the new chain, this online tool
can be used: https://dexstats.info/addressconverter.php

or this command line tool: https://git.hush.is/hush/hush3/src/master/contrib/convert_address.py


### Using an old wallet.dat

Backup your old HUSH wallet.dat, and backup any current wallet.dat that is in your

        ~/.komodo/HUSH3/

directory. There is no way to lose funds, as long as you have backups!!! Make sure
to make backups. Do not skip this step.

Make sure any/all GUI wallets are stopped! Also make sure your old Hush node
and new Hush3 node are stopped:

        cd hush3
        ./src/hush-cli stop

Do not copy wallets or move wallets while your full node is running! This could
corrupt your wallet!

Now copy your old Hush wallet.dat to

        ~/.komodo/HUSH3/

with a command like

        # DO NOT RUN THIS WITHOUT MAKING BACKUPS!
        cp ~/.hush/wallet.dat ~/.komodo/HUSH3/

The reason this works is that both old HUSH and new HUSH are still Bitcoin Protocol
coins, which both use secp256k1 public keys. Now start your HUSH3 node again,
with this special CLI argument that will clear out transactions from your wallet:

        cd hush3
        ./src/hushd -zapwallettxes

This will cause a full history rescan, which will take some time. Once it's complete,
you can see your funds with this command:

        ./src/hush-cli getwalletinfo

NOTE: Do not use this wallet except to send funds to a new wallet!

### Private Keys

You can also transport funds one address at a time via private keys.

Agama Desktop Wallet WIF-to-WIF Tool can convert between old HUSH and new HUSH3
private keys.

# Installing

See [INSTALL.md](https://git.hush.is/hush/hush3/src/branch/master/INSTALL.md)

# License

For license information see the file [COPYING](COPYING).
