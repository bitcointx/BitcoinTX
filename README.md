
BitcoinTX development tree for version 2.1.5.

BitcoinTX is a PoS-based cryptocurrency.

BitcoinTX is dependent upon libsecp256k1.

Block Spacing: 60 Seconds
Diff Retarget: 2 Blocks
Maturity: 40 Blocks
Stake Minimum Age: 1 Hour
Stake Maximun Age: 14 Days
Masternode Deposit: 250,000
Port: 28280
RPC Port: 28282


BitcoinTX includes an Address Index feature, based on the address index API (searchrawtransactions RPC command) implemented in Bitcoin Core but modified implementation to work with the BitcoinTX codebase (PoS coins maintain a txindex by default for instance).

Initialize the Address Index By Running with -reindexaddr Command Line Argument.  It may take 10-15 minutes to build the initial index.

Discussion:
https://bitcointalk.org/index.php?topic=1051266.0

Release Notes:



