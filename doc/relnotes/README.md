# Official Hush Release Notes

Hush release notes were done on Github until 3.5.2,
and now are officially part of our Git repo.

## Downloading Releases

Hush releases are on our own Gitea at <a href="https://git.hush.is/">git.hush.is</a>
and no longer on Github, since they banned Duke Leto and
also because they censor many people around the world and work with
evil organizations.

# Hush 3.6.0 "Decentralized Dominatrix"

```
983 files changed, 7736 insertions(+), 17688 deletions(-)
```

<img src="https://git.hush.is/hush/hush3/raw/branch/master/doc/relnotes/img/hush-3.6.0.png">

:metal: :metal: :metal:
This release consists of 25454 lines of change, almost 18000 lines of deletions
and just short of 1000 files changed! This is why Hush code is so fast, we delete
all that KYC/PoS/Sprout stuff from KMD internals we inherited and improve daily.
:metal: :metal: :metal:

  * :100: Fixes sync issues near block 340k caused by blocktime halving bug
  * :sweat_drops: New official domain https://hush.is reflected everywhere
  * :eggplant: New Hush DPoW Notaries replace KMD Notaries (who attacked us, lulz)
  * :rocket: Increasd in-memory UTXO cache db by 100MB (25%) to increase performance of initial syncing
  * :dragon: Prevent Delayed-Proof-of-Work attack from Komodo Notaries
    * :shit: KMD notaries provably attacked the HUSH blockchain their pubkeys
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
  * :tada: Hush Docker scripts are now officially maintained!
  * :rabbit2: Faster release binaries with -03
  * :fork_and_knife: Optimized and hardened memory pool code
  * :hammer: getblocktemplate RPC now provides better error reporting about
    whether there are no peers or if it's not in sync
  * :recycle: Removed more Sprout code which is tightly mixed into deep internals,
    which increases compile speed and reduces memory overhead
  * :surfer: New P2P protocol version. Peers only talk to 3.5.x nodes and newer


## Bounty

Would you like to transcribe old Github releases to this file for a HUSH
bounty? Join https://hush.is/tg to learn more.
