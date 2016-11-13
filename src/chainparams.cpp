// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xb1;
        pchMessageStart[1] = 0xb5;
        pchMessageStart[2] = 0xa2;
        pchMessageStart[3] = 0xa4;
        vAlertPubKey = ParseHex("0469983e0cc246fb426e7358f2aa29e09e4033c841455dc296f8f2dc99bb41fafda903f80f617ce9414aecb895d501cb5fb73c0bef8bb30ddab8e4a78f504dfd83");
        nDefaultPort = 28280;
        nRPCPort = 28282;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.				
        const char* pszTimestamp = "BT, currency for people (and robots...and animals, maybe)";
        CTransaction txNew;
        txNew.nTime = 1430222400;
		txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].SetEmpty();
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1430222400;
        genesis.nBits    = 0x1e0fffff;
        genesis.nNonce   = 171310;

        hashGenesisBlock = genesis.GetPoWHash();	
        assert(hashGenesisBlock == uint256("0x00000449ae58462bbad8d26c7eb0270d332948872cfe97b7d5c42c154bfa5523"));
        assert(genesis.hashMerkleRoot == uint256("0x543528ec7c8617e4816916806d3536b6a22f18907deae54c13c30d725b7d908f"));

        vSeeds.push_back(CDNSSeedData("bitcointx.info", "btxseed1.bitcointx.info"));
        vSeeds.push_back(CDNSSeedData("bitcointx.io", "btxseed2.bitcointx.io"));
        vSeeds.push_back(CDNSSeedData("btxcoin.org", "btxseed3.btxcoin.org"));
        vSeeds.push_back(CDNSSeedData("btxcoin.net", "btxseed4.btxcoin.net"));
        vSeeds.push_back(CDNSSeedData("bitcointx.co", "btxseed5.bitcointx.co"));
        vSeeds.push_back(CDNSSeedData("bitcointx.io", "btxseed6.bitcointx.io"));
        vSeeds.push_back(CDNSSeedData("bitcointx.io", "btxseed7.bitcointx.io"));

        base58Prefixes[PUBKEY_ADDRESS] = boost::assign::list_of(35);
        base58Prefixes[SCRIPT_ADDRESS] = boost::assign::list_of(85);
        base58Prefixes[SECRET_KEY] =     boost::assign::list_of(153);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nLastPOWBlock = 2000;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xb2;
        pchMessageStart[1] = 0xa0;
        pchMessageStart[2] = 0xa2;
        pchMessageStart[3] = 0xa3;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 12);
        vAlertPubKey = ParseHex("04bce55edfa485b7f0efb41f56be9356cc597c570d2b9479b9ee0f1eb4bcd271ca8dc7b12289fa3b366d1868453544e369abfeb00b646aff8d61cfc8111e122c5e");
        nDefaultPort = 28281;
        nRPCPort = 28283;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 219671;
        hashGenesisBlock = genesis.GetPoWHash();  
        assert(hashGenesisBlock == uint256("0xd3aa2697d4c3d92664895cac715a3f2529e377a36bdb22cff4d28ea11ec85796"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = boost::assign::list_of(125);
        base58Prefixes[SCRIPT_ADDRESS] = boost::assign::list_of(196);
        base58Prefixes[SECRET_KEY]     = boost::assign::list_of(239);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nLastPOWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    
    bool fTestNet = GetBoolArg("-testnet", false);
    
    if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
