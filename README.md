##BitcoinTX development tree for version 2.1.5.
===============================

**BitcoinTX is a PoS-based cryptocurrency.**

####Specifications:

* Block Spacing: 60 Seconds
* Diff Retarget: 2 Blocks
* Maturity: 40 Blocks
* Stake Minimum Age: 1 Hour
* Stake Maximun Age: 14 Days
* Masternode Deposit: 250,000
* Port: 28280
* RPC Port: 28282

BitcoinTX is dependent upon libsecp256k1.  BitcoinTX includes an Address Index feature, based on the address index API (searchrawtransactions RPC command) implemented in Bitcoin Core but modified implementation to work with the BitcoinTX codebase (PoS coins maintain a txindex by default for instance).

Initialize the Address Index By Running with -reindexaddr Command Line Argument.  It may take 10-15 minutes to build the initial index.

===============================
#### Release Notes for *v2.1.5 (11/02/2015)*:
1. Updated src/chainparams.cpp. Added five DNS seeders. Turned ON by default.  Use -dnsseed to turn off.
  * btxseed1.bitcointx.info (New York)
  * btxseed2.bitcointx.io (San Francisco)
  * btxseed3.btxcoin.org (Amsterdam)
  * btxseed4.btxcoin.net (London)
  * btxseed5.bitcointx.co (Sigapore)
2. Updated src/net.cpp. IRC seeding. Turned OFF by default.  Use -ircseed to turn on.
3. Updated src/checkpoints.cpp.  Added new checkpoints.
4. Updated src/clientversion.h. Bump version to 2.1.5.0.
5. Updated src/version.h. Bump protocol version to 61339 for v2.1.5. 
6. Updated src/main.cpp. 
  * Ignore "gettaddr" requests on Outbound connections.
  * Don't check duplicate stake while importing. 
  * Ignore blocks received while importing.
7. Updated src/compat.h. Max number of fds in fd_set and prevent redefinition compiler warning.
8. Updated src/spork.h. Masternode enforce payments.
9. Updated src/timedata.cpp. Do not store more than 200 timedata samples.
10. Updated src/wallet.cpp. Fix priority calculation in CreateTransaction.
11. Updated src/rpcprotocol.cpp. prevent easy memory exhaustion attack in rpc. 

**Special thanks to SCDeveloper (https://github.com/SCDeveloper/) for item #6-11.**  

* This version has NOT been fully tested.  Please use at your own risk.
* DNS seeder nodes maintained and deployed by MCDev.
* All coding changes performed and reviewed by CrytoVote. Email: CrytoVote@yandex.com.

####Contact:
* Wallet Code: CrytoVote@yandex.com.
* Network/MN Support: 
* DNS Seeds: 

####Discussions:
* BitcoinTalk.org: https://bitcointalk.org/index.php?topic=1051266.0
* Slack: https://btxcoin.slack.com

####Exchanges:
* C-CEX: https://c-cex.com/index.html?p=btx-btc

####Build Instructions:
* *Linux*:  
* *Windows*:  
* *MacOS*:  

## License

### Code
MIT License: http://bitcointx.mit-license.org/

### Logo
# ![BitcoinTX logo](https://github.com/CryptoDJ/BitcoinTX/blob/master/src/qt/res/images/about.png) 
Copyright 2015, MIT License: http://bitcointx.mit-license.org/
