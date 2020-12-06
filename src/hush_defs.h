// Copyright (c) 2019-2020      The Hush developers
/******************************************************************************
 * Copyright © 2014-2019 The SuperNET Developers.                             *
 *                                                                            *
 * See the AUTHORS, DEVELOPER-AGREEMENT and LICENSE files at                  *
 * the top-level directory of this distribution for the individual copyright  *
 * holder information and the developer policies on copyright and licensing.  *
 *                                                                            *
 * Unless otherwise agreed in a custom licensing agreement, no part of the    *
 * SuperNET software, including this file may be copied, modified, propagated *
 * or distributed except according to the terms contained in the LICENSE file *
 *                                                                            *
 * Removal or modification of this copyright notice is prohibited.            *
 *                                                                            *
 ******************************************************************************/
#ifndef KOMODO_DEFS_H
#define KOMODO_DEFS_H
#include "arith_uint256.h"
#include "chain.h"
#include "hush_nk.h"
#define KOMODO_EARLYTXID_HEIGHT 100
//#define ADAPTIVEPOW_CHANGETO_DEFAULTON 1572480000
#define ASSETCHAINS_MINHEIGHT 128
#define ASSETCHAINS_MAX_ERAS 7
#define KOMODO_ELECTION_GAP 2000
#define ROUNDROBIN_DELAY 61
#define HUSH_SMART_CHAIN_MAXLEN 65
#define KOMODO_LIMITED_NETWORKSIZE 4
#define IGUANA_MAXSCRIPTSIZE 10001
#define KOMODO_MAXMEMPOOLTIME 3600 // affects consensus
#define CRYPTO555_PUBSECPSTR "020e46e79a2a8d12b9b5d12c69d1adb4e454edfae43c0a0cb805427d2acbadcaca"
#define CRYPTO555_HUSHADDR   "RHushEyeDm7XwtaTWtyCbjGQumYyV8vMjn"
#define CRYPTO555_RMD160STR  "deadbeef2fce875748c4986b240ff7d7bc3fffb0"
#define HUSH_FIRSTFUNGIBLEID 100
#define KOMODO_SAPLING_ACTIVATION 1544832000 // Dec 15th, 2018
#define KOMODO_SAPLING_DEADLINE 1550188800 // Feb 15th, 2019
#define _COINBASE_MATURITY 100

// Notary Seasons: To add seasons, change NUM_HUSH_SEASONS, and add timestamp and height of activation to these arrays. 
// Always define one more season than is actually needed, which has a block activation in the far future
//TODO: some parts of the codebase assume 64 and do not use this constant
#define NUM_HUSH_SEASONS 7
#define NUM_HUSH_NOTARIES 64

// $ ./contrib/block_time.pl 166250
// Hush Block 166250 will happen at roughly:
// Wed Jan 29 08:14:12 2020 Eastern # 1580303652
// Wed Jan 29 13:14:12 2020 GMT     # 1580303652
const uint32_t nHushHardforkHeight  = 166250;
// $ ./contrib/block_time.pl 245555
// Hush Block 245555 will happen at roughly... now
const uint32_t nHushHardforkHeight2 = 245055;

// This height begins Hush DPoW from Hush notaries
const uint32_t nHushHardforkHeight3 = 340420;

// No coins/code are currently using timestamp activated fork
const uint32_t nHushHardforkTimestamp  = 1580303652; // Jan 29nd 1pm GMT
const uint32_t nHushHardforkTimestamp2 = 1594425600; // Jul 11th 12a GMT

static const uint32_t HUSH_SEASON_TIMESTAMPS[NUM_HUSH_SEASONS] = {1525132800, 1563148800, nHushHardforkTimestamp, nHushHardforkTimestamp2, nHushHardforkTimestamp2*5, nHushHardforkTimestamp2*6, nHushHardforkTimestamp2*7};
static const int32_t  HUSH_SEASON_HEIGHTS[NUM_HUSH_SEASONS]    = {1,2,nHushHardforkHeight, nHushHardforkHeight2, (int)340000, nHushHardforkHeight3, nHushHardforkHeight3*5};

// Era array of pubkeys. Add extra seasons to bottom as requried, after adding appropriate info above. 
static const char *notaries_elected[NUM_HUSH_SEASONS][NUM_HUSH_NOTARIES][2] =
{
    {
        // season 1
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
    },

    {
        // season 2
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
    },

    {
        // season 3
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
    },

    {
        // Season 4 third party NN pubkeys from https://github.com/KomodoPlatform/dPoW/blob/master/dragon/3rd_party
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
    },

    {
        // Season 5 (fuck season 3.5) https://github.com/KomodoPlatform/dPoW/blob/s4/dragon/3rd_party
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
        { "fuck_jl777", "034ea5e2d1b858e9b026dc5a4ea5bb2e4a5b625a086d9954c94b002d0858987214"},
   },

   {
        // Hush Delayed Proof of Work, Season 6 In The Great History Of DPoW
        // NOTE: Hush notaries are proudly anon, where KMD notaries doxx themselves, derpz and lulz
        {"RHush8GC36rip8uY4fyDU79NxbhKNtqghk","0311e75bdbb9215eb040eb01f932097b2dde8632570b314087883dcd4344b27a8f"},
        {"RHushPhhtqMDgdHe16NXuZfzQVAyKYzPZB","0387c4fbc3df18437820f1ecb3ce072c41b9ee3db45bb5df5bd4c9504ff769a0e3"},
        {"RHush7Ua35bjt7RobikaG2rXp8oSu27uuE","033af93c56093489b836f309b1f1709ede0d34dcc01e676ba04c41492d45c2a82d"},
        {"RHushXfsrvBTd1UKE5b86GpW7kPy6x8kMc","02735b7707a601677a201115d222ea96cca019e2537989202c930b5eabc1b7d0d1"},
        {"RHushGKVM7V66vxaVMVKZa5zfU31jHnvvJ","02b64255d2ed8e72efb8606a5f3edd991706d6fa405e2edb2366ccc0d04411a971"},
        {"RHushhj9ZqSxbsoKmbdQCs31udPj7R84L1","0219fd04e4d10a9a3a3bdd8463d817e27af21f9ee8fd9c96ab168f4075c7f8ab04"},
        {"RHushHSVgpiFKTzKeYX1WeEVSFvaRJntfG","031f342fb96cfbe54881ad4feb5d6d4ffa431671a88f55ccd5c97710a40492858c"},
        {"RHushhgnoYHyo1FAPd95pnSZ41ku9pbsTa","03c6c9f035edaa08b1361d4a36650506c33f9224dcca3e5e670e79cd6cacf4272a"},
        {"RHushzyxZZWRTbeoL2kBTwpKRPQnCSydY2","02ed6ae515061943197e4666966107c60419d0f76051c6eff56f4aa325b4a4d909"},
        {"RHushTgVyVCR2nfHSnFpnQdYpAJkuhh32A","03651c4e20684ba32afd45a51b78120b1d88a165a56a465b480e08a27877b25511"},
        {"RHushfUUfe2mEvzooNJPVd46ajGR5mVk8u","02196af172bb155312575b55f7e9beec21fa861aa7ab424eafa8555e5c90cbf959"},
        {"RHushycRhdDqFMmU2CsHsPNdsFy2gYxmLw","03686768588bd270934f38c9c747703bd13923a271781d53d73e35d516a8d95e06"},
        {"RHusheqVQ3qFtSVbQz751H4EiNaP47bKPf","033d099e4bf7d6250adab6d1519aecd0c234b465de6c3c3569864b87acc160926d"},
        {"RHushiEq7kXBBCAWz1E44i2aw1SAt6cMku","025260889f16fdb809f415a457a92c5afcd1b0f30101a2eca495c6fcc333684fd5"},
        {"RHushVTxFKFfySmNqpHtFBg7s3whm3Zk4q","035ed8e13cd4861a76336f2f78aab5af350d363b4f7ce784b1ab24697b951ef352"},
        {"RHushzssPeRpshz2Qgezx33QafbeeW67Wa","02a257c40452cc405e4b53f54224d2a76c7a74477f32b0e50e7349b9d4a7d8eb73"},
        {"RHush9Mz58wqRMYwQmQ2uehTphpwyjNPF8","022dd50c6325d5739c49c1158b3d0c4300db5e05bbb180674bbe37563695bb7c4c"},
        {"RHushLVwBCVsj5wQfL3Vqn5dtCUNzYACqR","03d7f02d5bf50eeb66b24932e2aa1ee68536184d8e904a9f08a19f1e63247bd370"},
        {"RHushnwstemVMdgejh5tmb51GFCgfrW5Wn","03d7071297ce99b58ee5c16c91a682a67b98423df19c83016e30c3b566ee7d5013"},
        {"RHushah3awaNJnms5fDzHQJde1QeoWhjnV","02279ff0ca33d8a6570e643cc8dc8feb48d5bd51a6bb8fe36b98fb30b01ce31ff8"},
        {"RHushjrJUjLzE4am73D1aNkjH5S6hHWmWc","027ab4c14966b13955616c4a17de8a497088b3ceff076077aeb02504d73314b928"},
        {"RHushptDtbjDvdeeyDZUvps6wFoPECxwEd","0209f18cc2f708ccc6c6d0ef380440dec0f6052dc3904f14dfa9303e7feb583128"},
        {"RHushQH3qtbFHZ5qCjWYbPfWCa8tV8WVDR","035108e4d8415aa4dcffb076e3e7f681645be7ae9860b552147f46a26fa4995fe7"},
        {"RHushw4ztWqhZycAJHzz2kaUwDQNr1CFUn","02d852b7ac1a0f8407cf6e17bd5729ad471ec8ff9b1010ea43b2dd11ab1f1fcc0f"},
        {"RHushz1vQti15q7Cc1CwUvA2ctPnNVZQQj","03651736c7f6f19991ab047687fe1a832d97fdec946d185b0e475625692ad3eb2a"},
        {"RHush3FwGHgmcSDUB6pLNfhser8qbwyCrS","0344bfb5e40f33f033869f0259e1baefdb297e4a266b87424af72fa09cf7f32e0e"},
        {"RHushNnHbhKgtMbGM3dWnJ4Wa8FZvDL2es","03cceb1d4ce28edd255805b9e2cfad215c29e8aed068ae5ec76183e2b5b413d48c"},
        {"RHush2dcugTQ8vGHMdFVwD9ULkFWzbsZ5W","02b762e56f508cb14127fe725017772b575925881911fd8fc374529b5e509ab7d3"},
        {"RHushJ1ydfCUcAvNUsikkct9ZoW7nFqrmK","03b36c60c7fc1c81cc989e45847ad2faff93398a95ec6b8138b38f8078d5652e73"},
        {"RHushdyAmvxV8Em5Gud33wDDQN74sKNUSK","02e096a7b57f6d5ac6d731b39dc9a656ea920d60c8db6f1d4f433985cb4756fb3e"},
        {"RHushPdks3JJphcYrxukGtJDdx9spMwWS1","02ff62a40b44d34f7f96c303903bf76fca5a60693cb085ea1ce72e4bb29f572b95"},
        {"RHushDUQxu68DZstxx3yj8jFV9G3iKn2dC","0227ac6e3b61069570b3f1c519492620929406120a0e77b71a8ead0f1f5a084a98"},
        {"RHushU3jFwas7B7mJz5A9dSTUzBq9ifmD9","02cef39af8bb49fd5b920f75f28ea75de8202e3ad87a07e9a86fae2e78c54fe1be"},
        {"RHushVBhtjBroSZU3NwS2JHPsaL6XpHMWc","02861aefc110ff5d8eb8783c068ee421872ad37d49830a5b14d7b19c01668a6e12"},
        {"RHushxBYs561RAtoJbPPptzrS4LDg2yzkx","03e1235ad6da52d1ba97d5e5dbb0dad35aa0453ef92fc8c368abe8fce102cdc2e9"},
        {"RHush6Cb9H11o77QkTwjj8HkUgHVySkYKN","03d22020cad60b83344414bdad05853c192c545d71539f463c974605eb0d118334"},
        {"RHush19GGZa3yzPPdcyEYFGpJZepe2UoC5","03dbc620a20d4f9c9f066ec6773fbdd49e0062ff242fc1134d59e6058b4ef6627c"},
        {"RHushcDcHdfLEuGPf9NfF8RyfuR9y7pfG9","02a55a7cb6f6784afd44bac0033c754e238683e7f9b4ce6ea3da5ed70aeeb297ab"},
        {"RHushUwawFZ3hx4YYjiKrDw3EsEV5BguDw","03485a646f2c9d52a5dfc35d3db16b609f29bdc7c6ea3a3fbb9930f7cd8026722b"},
        {"RHushRy6RUcozhxoySbxVmuWD2fnmA7Lnu","02aca0c996cdd7d180c788bca7a574af2e8824514849f087ec3784aaf82b4e09c1"},
        {"RHushp5dFxnudvYmTMVvhHCpv7wAeg9yme","039603fcb707cf7a150bb3c8dcff70efb3652e28c5cb9f275a2723d6e7769b35e6"},
        {"RHushYC8WX1DZZFSyEnKwWfYkaPbp3NYV2","033464b6800aa374ddda0499eeb17440a14c6f01b16e1ca8533721f565615b5652"},
        {"RHushLmLU8qCQ2suwJCmLUGDP8UHeKakQ1","03f729b004fa78ad47d8a9948a9cec9c183251c60d19b722132825e91979ea1718"},
        {"RHushf3WM6J2YkWW6jrzfysRJaL7ixvA4S","02d1f4327470ac0548d7e1c806793c555d28d53cbad2458f5e206bdd05238eb357"},
        {"RHushe75FywZGhRZGuK16LBtStkQGH8Ft9","0204e1cb1cbdb494a4cd7d29447acad55748fe9a4bcf35db5ed9eb793ca88545cc"},
        {"RHush8wqe1SkcweBBPqusQ5uakjEUKvxk1","0256120d1d2556284b6256d463d245fb0b6853d48b56c249c4092b9903043db4a6"},
        {"RHushKidwwcrGGe6i75x8eP652kVSSZMvm","036e24c5212aaf795485b827f67af8d2b04558a6663815f62611830d9d0dce114c"},
        {"RHushGV6GSMQePaLL7xcgWed6atye48cT1","02a298865ccbb575a770b68ece73962ddf5bcaeedc7b8bccab33e2ffda33ab0773"},
        {"RHush2P6tQr1MSXsm8VUFzRhJUbPswkdpg","02db2b276a9cabdf93579492b20ff507b118f7406e70b10550fd53836431e83e2a"},
        {"RHusheDCeKe5y3npBbHWbpCktTLbW1wVSG","0281d9e0ed1a854967e54d48aaa9276343e9b76c5efdc1d044ff5009641324fbc4"},
        {"RHushxF6budLeauye6gYvNcmhriU3xdaef","0354a23100ae28c9b0265c555a6fa7354216aeb28fed6519f335c2c4e405432554"},
        {"RHushEFSwwkmCUuJBHyi8GVeyToN3c9MBb","026ef72515d057d4dd3698ae3e5c5ccaccb71dfde4b6830949883ab8e0907f6715"},
        {"RHushaW7hadHXYY5TqYpnNJhHrAET72nLe","0228391f4e557ece7c5f0d7145cd278ff78048dde393c3685f18fd7c1602481db7"},
        {"RHushJbS2wBabhYyH8KDiyVkcg7haKvKYW","0255428e8b42cb23b85bbd4d22fd329cc30fc6c5e85fa8f3daf3109453e44cacd6"},
        {"RHushXxE9Mhp7PdJ92SqcJUQbfvrM5ERtx","02bc2a7a7682d6b0ddc745229aff8defc26f26649c9138a82e598ff97887924713"},
        {"RHush1En19qX2RygkcEg8tSZ1tog8kRFiZ","02d26b12982c4516faf3ccd2be162f21659f0022c88a89de905f9c18d833c7c371"},
        {"RHushXP2DHksHNQe6W572Yzv4awwCdW3xd","038587a8e96f487afed148ca93328b766928c4968b25c6b27e292af0d56715df98"},
        {"RHushUq1jpKdiWmHmnF7KQKEFY1HL3jxJi","03e9c491270b08613d1ec7c69b779e99f2c8c18475dd22f0cb2f35792822cd5335"},
        {"RHushDE7wimzRmQ1vGyQAb4tHfY17tSNBG","02ac63417f3ca77b5040db2c8e7029a115cd01ef3482d30bbaffcbc6bcb737fd43"},
        {"RHushSjWrj9NCs4CVoJPYL9aaUfunqLVPH","023b16bf42f558117d4277ec4814da82a58e2be744c5ce65022eb1c14d75f2c64d"},
        {"RHushqCoG4swiBnPZfASZxPezxWQQm5b4y","02a2ab4315f2845989c007443e740ccbc8dc8272f98680d97228a0bc5ab8780146"},
        {"RHushGnyatVjV3P6XV3AFEKtvpJKjZBwEy","0229d0fe5e080de8d9ff6d6c81d58db6d091de33854cb81dfb687caedd2ea08907"},
        {"RHushzUshnwkZoh2WmH7SLy1XqB9EYa7in","02409c2b52f7dda4a940f989e1582087925407da1ce63ff4a1a6914f1774effa09"},
        {"RHushaSfRLrsnxE4z8s3FVmSkyhaf2FCy8","03c8d684550004b16c061fc34331d106f9e54323e75824ddefe386a552018e4857"}
   }
};

#define SETBIT(bits,bitoffset) (((uint8_t *)bits)[(bitoffset) >> 3] |= (1 << ((bitoffset) & 7)))
#define GETBIT(bits,bitoffset) (((uint8_t *)bits)[(bitoffset) >> 3] & (1 << ((bitoffset) & 7)))
#define CLEARBIT(bits,bitoffset) (((uint8_t *)bits)[(bitoffset) >> 3] &= ~(1 << ((bitoffset) & 7)))

#define KOMODO_MAXNVALUE (((uint64_t)1 << 63) - 1)
#define KOMODO_BIT63SET(x) ((x) & ((uint64_t)1 << 63))
#define KOMODO_VALUETOOBIG(x) ((x) > (uint64_t)10000000001*COIN)

//#ifndef TESTMODE
#define PRICES_DAYWINDOW ((3600*24/ASSETCHAINS_BLOCKTIME) + 1)
//#else
//#define PRICES_DAYWINDOW (7)
//#endif

extern uint8_t ASSETCHAINS_TXPOW,ASSETCHAINS_PUBLIC;
extern int8_t ASSETCHAINS_ADAPTIVEPOW;
int32_t MAX_BLOCK_SIZE(int32_t height);
extern char SMART_CHAIN_SYMBOL[HUSH_SMART_CHAIN_MAXLEN];
extern uint16_t ASSETCHAINS_P2PPORT,ASSETCHAINS_RPCPORT;
extern uint32_t ASSETCHAIN_INIT, ASSETCHAINS_MAGIC;
extern int32_t ASSETCHAINS_LWMAPOS, ASSETCHAINS_SAPLING, ASSETCHAINS_OVERWINTER,ASSETCHAINS_BLOCKTIME;
extern uint64_t ASSETCHAINS_SUPPLY, ASSETCHAINS_FOUNDERS_REWARD;

extern int32_t ASSETCHAINS_LWMAPOS, ASSETCHAINS_SAPLING, ASSETCHAINS_OVERWINTER,ASSETCHAINS_BLOCKTIME;
extern int32_t KOMODO_BLOCK_POSUNITS, KOMODO_CONSECUTIVE_POS_THRESHOLD, KOMODO_NOPOS_THRESHHOLD;

extern uint64_t ASSETCHAINS_TIMELOCKGTE;
extern uint32_t ASSETCHAINS_ALGO,ASSETCHAINS_EQUIHASH,HUSH_INITDONE;

extern int32_t HUSH_MININGTHREADS,HUSH_LONGESTCHAIN,ASSETCHAINS_SEED,IS_HUSH_NOTARY,USE_EXTERNAL_PUBKEY,KOMODO_CHOSEN_ONE,KOMODO_ON_DEMAND,HUSH_PASSPORT_INITDONE,ASSETCHAINS_STAKED,KOMODO_NSPV;
extern uint64_t ASSETCHAINS_COMMISSION, ASSETCHAINS_LASTERA,ASSETCHAINS_CBOPRET;
extern uint64_t ASSETCHAINS_REWARD[ASSETCHAINS_MAX_ERAS+1], ASSETCHAINS_NOTARY_PAY[ASSETCHAINS_MAX_ERAS+1], ASSETCHAINS_TIMELOCKGTE, ASSETCHAINS_NONCEMASK[],ASSETCHAINS_NK[2];
extern const char *ASSETCHAINS_ALGORITHMS[];
extern uint32_t ASSETCHAINS_NONCESHIFT[], ASSETCHAINS_HASHESPERROUND[];
extern std::string NOTARY_PUBKEY,ASSETCHAINS_OVERRIDE_PUBKEY,ASSETCHAINS_SCRIPTPUB;
extern uint8_t NOTARY_PUBKEY33[33],ASSETCHAINS_OVERRIDE_PUBKEY33[33],ASSETCHAINS_MARMARA;
extern std::vector<std::string> ASSETCHAINS_PRICES,ASSETCHAINS_STOCKS;

extern uint256 KOMODO_EARLYTXID;

extern int32_t KOMODO_CONNECTING,KOMODO_CCACTIVATE,KOMODO_DEALERNODE;
extern uint32_t ASSETCHAINS_CC;
extern std::string CCerror,ASSETCHAINS_CCLIB;
extern uint8_t ASSETCHAINS_CCDISABLES[256];

extern int32_t USE_EXTERNAL_PUBKEY;
extern std::string NOTARY_PUBKEY,NOTARY_ADDRESS;
extern std::string DONATION_PUBKEY;
extern uint8_t ASSETCHAINS_PRIVATE;
extern int32_t USE_EXTERNAL_PUBKEY;
extern char NOTARYADDRS[64][64];
extern char NOTARY_ADDRESSES[NUM_HUSH_SEASONS][64][64];
extern int32_t KOMODO_TESTNODE, KOMODO_SNAPSHOT_INTERVAL;
extern int32_t ASSETCHAINS_EARLYTXIDCONTRACT;
extern int32_t ASSETCHAINS_STAKED_SPLIT_PERCENTAGE;
int tx_height( const uint256 &hash );
extern std::vector<std::string> vWhiteListAddress;
extern std::map <std::int8_t, int32_t> mapHeightEvalActivate;
void komodo_netevent(std::vector<uint8_t> payload);
int32_t getacseason(uint32_t timestamp);
int32_t gethushseason(int32_t height);

#define IGUANA_MAXSCRIPTSIZE 10001
#define KOMODO_KVDURATION 1440
#define KOMODO_KVBINARY 2
#define PRICES_SMOOTHWIDTH 1
#define PRICES_MAXDATAPOINTS 8
uint64_t komodo_paxprice(uint64_t *seedp,int32_t height,char *base,char *rel,uint64_t basevolume);
int32_t komodo_paxprices(int32_t *heights,uint64_t *prices,int32_t max,char *base,char *rel);
int32_t komodo_notaries(uint8_t pubkeys[64][33],int32_t height,uint32_t timestamp);
char *bitcoin_address(char *coinaddr,uint8_t addrtype,uint8_t *pubkey_or_rmd160,int32_t len);
int32_t komodo_minerids(uint8_t *minerids,int32_t height,int32_t width);
int32_t komodo_kvsearch(uint256 *refpubkeyp,int32_t current_height,uint32_t *flagsp,int32_t *heightp,uint8_t value[IGUANA_MAXSCRIPTSIZE],uint8_t *key,int32_t keylen);

uint32_t komodo_blocktime(uint256 hash);
int32_t hush_longestchain();
int32_t hush_dpowconfs(int32_t height,int32_t numconfs);
int8_t komodo_segid(int32_t nocache,int32_t height);
int32_t komodo_heightpricebits(uint64_t *seedp,uint32_t *heightbits,int32_t nHeight);
char *komodo_pricename(char *name,int32_t ind);
int32_t komodo_priceind(const char *symbol);
int32_t komodo_pricesinit();
int64_t komodo_priceave(int64_t *tmpbuf,int64_t *correlated,int32_t cskip);
int64_t komodo_pricecorrelated(uint64_t seed,int32_t ind,uint32_t *rawprices,int32_t rawskip,uint32_t *nonzprices,int32_t smoothwidth);
int32_t komodo_nextheight();
uint32_t komodo_heightstamp(int32_t height);
int64_t komodo_pricemult(int32_t ind);
int32_t komodo_priceget(int64_t *buf64,int32_t ind,int32_t height,int32_t numblocks);
uint64_t komodo_accrued_interest(int32_t *txheightp,uint32_t *locktimep,uint256 hash,int32_t n,int32_t checkheight,uint64_t checkvalue,int32_t tipheight);
int32_t komodo_currentheight();
int32_t komodo_notarized_bracket(struct notarized_checkpoint *nps[2],int32_t height);
arith_uint256 komodo_adaptivepow_target(int32_t height,arith_uint256 bnTarget,uint32_t nTime);
bool hush_hardfork_active(uint32_t time);

uint256 Parseuint256(const char *hexstr);
void komodo_sendmessage(int32_t minpeers, int32_t maxpeers, const char *message, std::vector<uint8_t> payload);
CBlockIndex *komodo_getblockindex(uint256 hash);
int32_t komodo_nextheight();
CBlockIndex *komodo_blockindex(uint256 hash);
CBlockIndex *komodo_chainactive(int32_t height);
int32_t komodo_blockheight(uint256 hash);
bool komodo_txnotarizedconfirmed(uint256 txid);
int32_t komodo_blockload(CBlock& block, CBlockIndex *pindex);
uint32_t komodo_chainactive_timestamp();
uint32_t GetLatestTimestamp(int32_t height);

#ifndef KOMODO_NSPV_FULLNODE
#define KOMODO_NSPV_FULLNODE (KOMODO_NSPV <= 0)
#endif // !KOMODO_NSPV_FULLNODE
#ifndef KOMODO_NSPV_SUPERLITE
#define KOMODO_NSPV_SUPERLITE (KOMODO_NSPV > 0)
#endif // !KOMODO_NSPV_SUPERLITE

#endif
