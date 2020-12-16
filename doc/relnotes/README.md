# Official Hush Release Notes

Hush release notes were done on Github until 3.5.2,
and now are officially part of our Git repo.

## Downloading Releases

Hush releases are on our own Gitea at <a href="https://git.hush.is/">git.hush.is</a>
and no longer on Github, since they banned Duke Leto and
also because they censor many people around the world and work with
evil organizations.

# 3.6.0

  * Fixes "block 340k" sync issues!
  * New Hush DPoW Notaries replace KMD Notaries (who attacked us, lulz)
  * More secure+private TLS 1.3 implementation from miodrag, thanks!
    * We now use WolfSSL instead of OpenSSL, a huge improvement and
      decrease in attack surface as well as allowing use to do TLS
      on low resource devices (like internet-of-shit light bulbs/etc)
  * Hush Docker scripts are now officially maintained!
  * Faster release binaries with -03
  * Optimized and hardened memory pool code to remove KMD-isms
  * Updated all our error messages and things for https://hush.is,
    our new official domain
  * getblocktemplate RPC now provides better error reporting about
    whether there are no peers or if it's not in sync
  * Increasd in-memory UTXO cache db by 100MB (25%) to increase
    performance of initial syncing
  * Removed more Sprout code which is tightly mixed into deep internals


## Bounty

Would you like to transcribe old Github releases to this file for a HUSH
bounty? Join https://hush.is/tg to learn more.
