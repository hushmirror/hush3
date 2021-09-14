// Copyright (c) 2019-2020      The Hush developers
// Distributed under the GPLv3 software license, see the accompanying
// file COPYING or https://www.gnu.org/licenses/gpl-3.0.en.html
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
#ifndef HUSH_DEFS_H
#define HUSH_DEFS_H
#include "arith_uint256.h"
#include "chain.h"
#include "hush_nk.h"
#define HUSH_EARLYTXID_HEIGHT 100
#define ASSETCHAINS_MINHEIGHT 128
#define ASSETCHAINS_MAX_ERAS 7
#define HUSH_DPOW_GAP 2000
#define ROUNDROBIN_DELAY 61
#define HUSH_SMART_CHAIN_MAXLEN 65
#define HUSH_LIMITED_NETWORKSIZE 4
#define DRAGON_MAXSCRIPTSIZE 10001
#define HUSH_MAXMEMPOOLTIME 3600 // affects consensus
#define CRYPTO555_PUBSECPSTR "038a1bd41a08f38edda51042988022933c5775dfce81f7bae0b32a9179650352ac"
#define CRYPTO555_HUSHADDR   "RFetqf8WUfWnwNeXdknkm8ojk7EXnYFzrv"
#define CRYPTO555_RMD160STR  "deadbeefbadcaca748c4986b240ff7d7bc3fffb0"
#define HUSH_FIRSTFUNGIBLEID 100
#define HUSH_SAPING_ACTIVATION 1544832000 // Dec 15th, 2018
#define HUSH_SAPING_DEADLINE 1550188800 // Feb 15th, 2019
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
const uint32_t nHushHardforkHeight3    = 340420;
const uint32_t nHushHardforkTimestamp  = 1580303652; // Jan 29nd 1pm GMT
const uint32_t nHushHardforkTimestamp2 = 1594425600; // Jul 11th 12a GMT

// Used by HSCs
static const uint32_t HUSH_SEASON_TIMESTAMPS[NUM_HUSH_SEASONS] = {1525132800, 1563148800, nHushHardforkTimestamp, nHushHardforkTimestamp2, nHushHardforkTimestamp2*5, nHushHardforkTimestamp2*6, nHushHardforkTimestamp2*7};

// Used by HUSH3+TUSH
// Block 1702100  = nHushHardforkHeight3*5
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
        {"RFetqf8WUfWnwNeXdknkm8ojk7EXnYFzrv", "038a1bd41a08f38edda51042988022933c5775dfce81f7bae0b32a9179650352ac"},
        {"RV7YSVW89WC9jBDtFG4ubtopDRove4Tfvc", "03c9d35488be73fe4f2dbb1dc011468482d71bac32249f8cce6480bcc574415d19"},
        {"RBPFE9oXceZBWTn3Vhne4FUKE9vxGEXUKX", "028a8bb6ded2692b39a69ec2d3c9836ff221815909d5cd65257374aeb66394a002"},
        {"RM3cvUcafPhjyypZLEginQjdhjLnSgJHte", "03a36180014115b47b97c1c8776a269bba66047b1ce2c7eb1a3d4e995a6dfff0df"},
        {"RFFX1VaTmZYPBLCzFj7w3iJQArV9ZdaWcW", "02190865f3ca3678d322c96e49a3ddf8ad394a4c8cd97d4bb3376cf547d0d83c66"},
        {"RDwZsLpH1QiAbJwUEY8ajXwTzu3PaWhx7n", "023ea0babb34e1ff9f4db8131ee84ad8991b954038a1e6ef9afc2a1b3fa13bbcb9"},
        {"RCUvfnmt16ZMvLTmLGGAztcAE8fBjfbP6u", "0379a5ba9fb6b463ffcdc0b1f3ecf45a5b737275354f9c2598492f20660f6f7dfd"},
        {"RBLu9adNVMVf6jzLLbAenWovcwq8nU6gYd", "022cd69381231d69d6d3b9638762df849bc7bbab71cbb8383eec29ca677f1afa30"},
        {"RWfv6wd2fwgecnJxC1Ykpf1SJefGh2Wc6i", "03da8a8f57d88afb61f712a8cd35462b65ce2b2575db8f9ee33a725dcd12c44755"},
        {"RWiK4xooG3dPdvaovu6JvR3DWoYD4tfRjx", "02ffe66af4d71345fe6984b5002ad69206e1817566a70d9ac406a679be6a3335a0"},
        {"RYLNiJiRnEGeMxx1Q2xLoFujshRNkBa2x4", "028ef6501004569c1170ce2d7ec7ecfe5739001130ad1b39129f8b88cd3d610257"},
        {"RTw36Ksy5Wk1Xv3B53T79zoRd6XDsE9MS6", "02d7cf4ece00895ca857fcdd0a4c2fc9c949a518d2750396f77d9f031c08a94364"},
        {"RTPkUBriQzZy67WmFhEs6aQzJn5HBB3ntb", "03319ca1eae5888c45115d160ac07c4f2abd1720926aa579d535c4b46c807bb7f7"},
        {"RBmZzttvDnMaEv47cWXs8SgdC993djB68r", "034302c4e1ff72a5f5391f259f7a46e646c7845aa2c9de9fb0c0a4c4802aad79d6"},
        {"RGocb2jLCa2E9kVHDUsijrVGTDP82ngGYZ", "024440a18a16e38b836b3ad9bb54ab0b5ba83b04edebb58c62c09b2de29e9fc703"},
        {"RVqwCjPQ6AJ6r9WeGzQvAT4eGXDScprLkW", "028a94e53ad8ed9e78f0f8a87cf3bc4754784222ad7ddf2d3dc5fafec2f6891cde"},
        {"RB2Xc8eLrATRWVsxrZKHHx3hyJz1vugMt9", "02eca07a9b5810fe929a87f90e5f02e29a06479d39cd3a888abfa1793e1565155a"},
        {"RKm7WUuFfqCTiUBkbxBsdh54nT6ivXpDPX", "03e3f634671005c8ffb7fe883fcf9e08f6f5486df057f215d761741d91c88de898"},
        {"RLbHTvFQoz946W3o3gXTrjxxADeUsWWW16", "02e6bb6dcecf5e3abfe239dec55842a92f096eeac7f0ff7621c3e8948e5e789b27"},
        {"RD75njr2RLGC5PqjHbWwuL7ndTqZiUfYxs", "0250d9996c25a34cb1b4e86303a297fc5c49c65615eb31a57fb17d1e1b376e71be"},
        {"RT1VTzZYZLWUsPWFJ2oypEqB1MXMfq8b5Y", "02d1797941b7df42a98f59ede0f22294e7c02754232a8b1de9512ededaf3f82880"},
        {"RKeXriTVXioHeKpFTjC8Cjohd6DHGUcKqt", "0341e62f0cdffc4ba3e0efb793c0fcaaad1b611db7021b844f643d5c25847733d2"},
        {"RQYrDEgZPKMFAgTHNkWFeMHEmpkXe8j28T", "02b8719cd8484755990158cbdf7b9d990d4a5c3741cabe204e51ed04be5bd50133"},
        {"RE85TACcn8CEn26itAxQV9afxV9mVg17vm", "0367f569d3dc304e699196fe9b798671fe3f12df7851a0a474879b0dbf8bc508d1"},
        {"RPYWQJXto1aeCGe8T6g9Wo4tAL4xE82LJ8", "02cf1e245dfb44e418fd550abb825a600e1753d46a51995970e70c98be539da33e"},
        {"RSVHRS5wqEw7bxfuE9k6xJGbARcy5guisp", "03ab8ac83d689ce76b5d29a54c3b34d0a6cb37d64313ff4467c744787475969a23"},
        {"REAQwBaJFo6DyBkwfW7rTTDbUtkdmATcQ8", "025e80f0075514cc5940de85c0c559efa99a3688faf6cccb8c1d1f38b96ca91e71"},
        {"RF1gz8QBw5uFScGasqVxoUjQwJCD9zHJwC", "031cdae4b545e5049ccee8e0cb792e25795b56e08b5e64b1d972c9b94e9bfd4ed0"},
        {"RTnLGoWzpsyoGSViGH8GyYcYhSveSEmnPV", "03cf3403a9d1cefa83e07b73e618a7f991d140a8283a02df3ce7c00223f27f43d0"},
        {"RArURqxp6qfF7fqv38tCYr6p4zBtLtqf4x", "026bc4c91c2c35fabe88fea6470d6cda98977a97c251656adf25b81653c00c3800"},
        {"RN8GCryShNFvBWtcNEWrQJ5A9AWb3JJoXt", "02afa94f6574cd0fe4f5dc83b09a2112457862421ce96bdc75c1cf25ef5b1f8c4b"},
        {"RQSC2eBckcFPWzq9UtofePC31wgDySfJtw", "035d570768d844c8150a3bd966a2e13aa99316f4ab3e80370c4d16fb02f95d0974"},
        {"RC4uQsfH6jXpgnTFuFiDwAFo58gHLNkWo7", "02402b0ab7001fd4bcb4fa0d8d7006a6c521b1c76e85aad7b374ecd6c5d564c237"},
        {"RREcuaUWSkNzTNPBbFLbXKTKiC4fd5t47J", "03d5bf8b43c44ba064e897da47dd36dba537bebf013d28247ce7a088496dd9b66d"},
        {"REFyC5e7kmse3PUapDuXHL2xmtYEGttYYL", "035f56fd01dd21725928bbd878b795dccafecc03b978dc83748e9194dcbfebfb79"},
        {"RH1BLwZosLp2hv9msdZGdSu93K8GrMWw7D", "0224ab22ece88f624f80a8535b8d5194646ad6be749070ec188a22c5e29fdd7098"},
        {"RNkhugMQVbqDysSayHu2eAhTQpXzKWqZ3m", "02caab4c83c8cc245a7aeb6d25504363555d1b0874aef0f9f8116b4ddb61f24799"},
        {"RKiyhLELDJATA7ZCUcutkP1WCEHnAgZRZ8", "028c01859a700ed3941a5786cf2043992e17a45c6689ac4bf608ad3f19e6d0e832"},
        {"RLKARvLNo6Abkh5qh5NVn2HJmYfj8ELa6A", "0300a33629da90b9d3c0519d796f4b1278355bb8c46e4caee04b1305e2ab2ff3f2"},
        {"RACX21FKLenyyEf8SYK3LmjsDzkDthwUbR", "0205d73c6a3e969eff29e5f424c861d22544245e09eaafc3fefe021cad052b7c0b"},
        {"RETb7pEDauKBEuTBuXDhKS3ksd2p8x9KYa", "025c1f7596fd0b7286e6ebd1b3c275a14a13aa4d134db4677769324969b7b7e3a5"},
        {"RJrAo78TL6zUmiHXbBv8oRhfGKxGnPnxUu", "02d40a76fbab96a78898b7579626be6dfe360c63b91030e513f849f212d57c1af6"},
        {"RL8g6ANxhZBPHHHWgApaiSQ2BSP9qKwuwf", "020236a5748ea49da891276bcb85dc03487cb9f3d0c2b2cdb35227b6a624f86797"},
        {"RY3vwBjuuTCiYL5am9HmwbdCjffWd9f4CE", "032f61fd08957d9b88dabc077d8732bef6c30d0234c14e02f3a741116834f591dc"},
        {"RQW4LsSzjCPtNw1HGamSaCoiirvsrZmDY5", "02e29451f9baf0186a655396726a22a20617a3e54ea895590f6066abc993f83d32"},
        {"RJtjorxqhazz39UpFdhDW8MiW4E3jhXDNk", "03795b7a650db872c22f13a9c88ad5c1ad3cb07a349f1f29e9789efd27e151164b"},
        {"RSi8AiCCtS3doFupdpdfuorAhkrCS6mLMu", "037a62ff6b7eb2ba1e170b5c42e7788817ded6a3a7ed841321c01cc107aa647d42"},
        {"RMjMXC8m9PgAaMMvwqgLCyCrv47pp6F6XY", "033bdf151c01bc733e614f9d4f204ca44396bf56984df6643205d349a35f7b265d"},
        {"RYB3ZMgHt4h7YL8TUzpqaSDw22ABksAPGC", "021266e045f95322fceddae02877dca9721792bef8f2be28cacd7c36290cd813a7"},
        {"RGwy64PXswUKpiepfzgaRW98v3gsuqPtow", "03008783c34c2622e7167f0a5201846133e530e89dfe1a8fbcf4c29b33051c4565"},
        {"RKJRPLaQV4AkWF6EfUUzFwawTGU4RQZgcS", "03c20a9fd21de76a20ffc87e384be735dfabb7f34a2d881ca9714830fb1bbe6bdb"},
        {"RQ4SPvBKTEKyV6y31iSihtfMxi3KeyAJgV", "033c5a23c75d946c15c15fac1e6d78e08c2b656549a158627cfb6bc44bb7b3a560"},
        {"RTvRBC1pCQpPKrS27Q4hUCVKVpa5tSTsFS", "02c25672fae388a0613d0127fcfe38ef37f5f354ecfdea0fb734528e354319bd9d"},
        {"RKxWu9HpCg7m3UeUGw2Xs1SpFiR96fSCQj", "02ec760d09b369b82b34d864af5a468d8a7dc5609b06bce455d045d1059c4b0f71"},
        {"RBAaUWAD8jwVLL7ueb7ciAQewqgheKxwdk", "0274ec3abcca214cdf7f1a565f5f3d3fa910e62e751a1ab0de148ea14ba72d6ba7"},
        {"RT853SBEGt4EWrKbpSujya69DG1jSNYjob", "02e80260ca44b8539159e6af678cf5ed0bc596753e4985f66418d6417085b4104e"},
        {"RKjEuhVByPwJcZ9wuBgfELiCVnBrc4F8i4", "0357c38f5d5eb1662a54b980c9243ddd8b2100d4b2b9f8175246938ef76e100678"},
        {"RT6wVuFFPU5tY6C7Buup1GLV3SE5mpYEha", "02571085ead1aca86b9e90fa9a23d99a194c862524b0c714102888be5bf122dc7d"},
        {"RSTgcpV82AivrvWJpd4LR2KwWirwbwXE3Y", "021a0ee4611ca4d8a2e209cc43b95036deb0a9d1cc31fc9f87d50233a44f05ec1a"},
        {"RCiaXRzo4AAG3zmPL3Hx63NsRWv5UGiNuM", "02f4876be65c54613e47f7fac67f1453e8d8fde5e19fa53f278a1083a08b258ab3"},
        {"RCGgLWrTTaqBhUsS1BqrmFpJZAdNJMzscv", "02893d2db5329b15a33aa7edfbf323c85cabbdc25caa6cf6186fac6052ae6d96a0"},
        {"RAJWHL6MzGFKg7KB2sZ87KPQUSvxy3VrEW", "0389971362b002ab5dfa1b5f9c4f88e68249511a3935242ba1e0d31c1c88a36d70"},
        {"RU592tQnbH8gt6xd5Uu23nEw3SucDNkXmK", "02b8b6a2266fe57b25f2d4b1da93a07d27930154e78f9d137bc7509cf1ae8e3d49"},
        {"RLGCLRzaEmruPC9UmVt5qRHEhXwHip1e6d", "02a2fd96b4459411ad2b09597ba59cf52b282c56330da7c0cc6d2a5c0323a18f1e"}
   },
   {
        // season 7
        {"RFetqf8WUfWnwNeXdknkm8ojk7EXnYFzrv", "038a1bd41a08f38edda51042988022933c5775dfce81f7bae0b32a9179650352ac"},
        {"RV7YSVW89WC9jBDtFG4ubtopDRove4Tfvc", "03c9d35488be73fe4f2dbb1dc011468482d71bac32249f8cce6480bcc574415d19"},
        {"RBPFE9oXceZBWTn3Vhne4FUKE9vxGEXUKX", "028a8bb6ded2692b39a69ec2d3c9836ff221815909d5cd65257374aeb66394a002"},
        {"RM3cvUcafPhjyypZLEginQjdhjLnSgJHte", "03a36180014115b47b97c1c8776a269bba66047b1ce2c7eb1a3d4e995a6dfff0df"},
        {"RFFX1VaTmZYPBLCzFj7w3iJQArV9ZdaWcW", "02190865f3ca3678d322c96e49a3ddf8ad394a4c8cd97d4bb3376cf547d0d83c66"},
        {"RDwZsLpH1QiAbJwUEY8ajXwTzu3PaWhx7n", "023ea0babb34e1ff9f4db8131ee84ad8991b954038a1e6ef9afc2a1b3fa13bbcb9"},
        {"RCUvfnmt16ZMvLTmLGGAztcAE8fBjfbP6u", "0379a5ba9fb6b463ffcdc0b1f3ecf45a5b737275354f9c2598492f20660f6f7dfd"},
        {"RBLu9adNVMVf6jzLLbAenWovcwq8nU6gYd", "022cd69381231d69d6d3b9638762df849bc7bbab71cbb8383eec29ca677f1afa30"},
        {"RWfv6wd2fwgecnJxC1Ykpf1SJefGh2Wc6i", "03da8a8f57d88afb61f712a8cd35462b65ce2b2575db8f9ee33a725dcd12c44755"},
        {"RWiK4xooG3dPdvaovu6JvR3DWoYD4tfRjx", "02ffe66af4d71345fe6984b5002ad69206e1817566a70d9ac406a679be6a3335a0"},
        {"RYLNiJiRnEGeMxx1Q2xLoFujshRNkBa2x4", "028ef6501004569c1170ce2d7ec7ecfe5739001130ad1b39129f8b88cd3d610257"},
        {"RTw36Ksy5Wk1Xv3B53T79zoRd6XDsE9MS6", "02d7cf4ece00895ca857fcdd0a4c2fc9c949a518d2750396f77d9f031c08a94364"},
        {"RTPkUBriQzZy67WmFhEs6aQzJn5HBB3ntb", "03319ca1eae5888c45115d160ac07c4f2abd1720926aa579d535c4b46c807bb7f7"},
        {"RBmZzttvDnMaEv47cWXs8SgdC993djB68r", "034302c4e1ff72a5f5391f259f7a46e646c7845aa2c9de9fb0c0a4c4802aad79d6"},
        {"RGocb2jLCa2E9kVHDUsijrVGTDP82ngGYZ", "024440a18a16e38b836b3ad9bb54ab0b5ba83b04edebb58c62c09b2de29e9fc703"},
        {"RVqwCjPQ6AJ6r9WeGzQvAT4eGXDScprLkW", "028a94e53ad8ed9e78f0f8a87cf3bc4754784222ad7ddf2d3dc5fafec2f6891cde"},
        {"RB2Xc8eLrATRWVsxrZKHHx3hyJz1vugMt9", "02eca07a9b5810fe929a87f90e5f02e29a06479d39cd3a888abfa1793e1565155a"},
        {"RKm7WUuFfqCTiUBkbxBsdh54nT6ivXpDPX", "03e3f634671005c8ffb7fe883fcf9e08f6f5486df057f215d761741d91c88de898"},
        {"RLbHTvFQoz946W3o3gXTrjxxADeUsWWW16", "02e6bb6dcecf5e3abfe239dec55842a92f096eeac7f0ff7621c3e8948e5e789b27"},
        {"RD75njr2RLGC5PqjHbWwuL7ndTqZiUfYxs", "0250d9996c25a34cb1b4e86303a297fc5c49c65615eb31a57fb17d1e1b376e71be"},
        {"RT1VTzZYZLWUsPWFJ2oypEqB1MXMfq8b5Y", "02d1797941b7df42a98f59ede0f22294e7c02754232a8b1de9512ededaf3f82880"},
        {"RKeXriTVXioHeKpFTjC8Cjohd6DHGUcKqt", "0341e62f0cdffc4ba3e0efb793c0fcaaad1b611db7021b844f643d5c25847733d2"},
        {"RQYrDEgZPKMFAgTHNkWFeMHEmpkXe8j28T", "02b8719cd8484755990158cbdf7b9d990d4a5c3741cabe204e51ed04be5bd50133"},
        {"RE85TACcn8CEn26itAxQV9afxV9mVg17vm", "0367f569d3dc304e699196fe9b798671fe3f12df7851a0a474879b0dbf8bc508d1"},
        {"RPYWQJXto1aeCGe8T6g9Wo4tAL4xE82LJ8", "02cf1e245dfb44e418fd550abb825a600e1753d46a51995970e70c98be539da33e"},
        {"RSVHRS5wqEw7bxfuE9k6xJGbARcy5guisp", "03ab8ac83d689ce76b5d29a54c3b34d0a6cb37d64313ff4467c744787475969a23"},
        {"REAQwBaJFo6DyBkwfW7rTTDbUtkdmATcQ8", "025e80f0075514cc5940de85c0c559efa99a3688faf6cccb8c1d1f38b96ca91e71"},
        {"RF1gz8QBw5uFScGasqVxoUjQwJCD9zHJwC", "031cdae4b545e5049ccee8e0cb792e25795b56e08b5e64b1d972c9b94e9bfd4ed0"},
        {"RTnLGoWzpsyoGSViGH8GyYcYhSveSEmnPV", "03cf3403a9d1cefa83e07b73e618a7f991d140a8283a02df3ce7c00223f27f43d0"},
        {"RArURqxp6qfF7fqv38tCYr6p4zBtLtqf4x", "026bc4c91c2c35fabe88fea6470d6cda98977a97c251656adf25b81653c00c3800"},
        {"RN8GCryShNFvBWtcNEWrQJ5A9AWb3JJoXt", "02afa94f6574cd0fe4f5dc83b09a2112457862421ce96bdc75c1cf25ef5b1f8c4b"},
        {"RQSC2eBckcFPWzq9UtofePC31wgDySfJtw", "035d570768d844c8150a3bd966a2e13aa99316f4ab3e80370c4d16fb02f95d0974"},
        {"RC4uQsfH6jXpgnTFuFiDwAFo58gHLNkWo7", "02402b0ab7001fd4bcb4fa0d8d7006a6c521b1c76e85aad7b374ecd6c5d564c237"},
        {"RREcuaUWSkNzTNPBbFLbXKTKiC4fd5t47J", "03d5bf8b43c44ba064e897da47dd36dba537bebf013d28247ce7a088496dd9b66d"},
        {"REFyC5e7kmse3PUapDuXHL2xmtYEGttYYL", "035f56fd01dd21725928bbd878b795dccafecc03b978dc83748e9194dcbfebfb79"},
        {"RH1BLwZosLp2hv9msdZGdSu93K8GrMWw7D", "0224ab22ece88f624f80a8535b8d5194646ad6be749070ec188a22c5e29fdd7098"},
        {"RNkhugMQVbqDysSayHu2eAhTQpXzKWqZ3m", "02caab4c83c8cc245a7aeb6d25504363555d1b0874aef0f9f8116b4ddb61f24799"},
        {"RKiyhLELDJATA7ZCUcutkP1WCEHnAgZRZ8", "028c01859a700ed3941a5786cf2043992e17a45c6689ac4bf608ad3f19e6d0e832"},
        {"RLKARvLNo6Abkh5qh5NVn2HJmYfj8ELa6A", "0300a33629da90b9d3c0519d796f4b1278355bb8c46e4caee04b1305e2ab2ff3f2"},
        {"RACX21FKLenyyEf8SYK3LmjsDzkDthwUbR", "0205d73c6a3e969eff29e5f424c861d22544245e09eaafc3fefe021cad052b7c0b"},
        {"RETb7pEDauKBEuTBuXDhKS3ksd2p8x9KYa", "025c1f7596fd0b7286e6ebd1b3c275a14a13aa4d134db4677769324969b7b7e3a5"},
        {"RJrAo78TL6zUmiHXbBv8oRhfGKxGnPnxUu", "02d40a76fbab96a78898b7579626be6dfe360c63b91030e513f849f212d57c1af6"},
        {"RL8g6ANxhZBPHHHWgApaiSQ2BSP9qKwuwf", "020236a5748ea49da891276bcb85dc03487cb9f3d0c2b2cdb35227b6a624f86797"},
        {"RY3vwBjuuTCiYL5am9HmwbdCjffWd9f4CE", "032f61fd08957d9b88dabc077d8732bef6c30d0234c14e02f3a741116834f591dc"},
        {"RQW4LsSzjCPtNw1HGamSaCoiirvsrZmDY5", "02e29451f9baf0186a655396726a22a20617a3e54ea895590f6066abc993f83d32"},
        {"RJtjorxqhazz39UpFdhDW8MiW4E3jhXDNk", "03795b7a650db872c22f13a9c88ad5c1ad3cb07a349f1f29e9789efd27e151164b"},
        {"RSi8AiCCtS3doFupdpdfuorAhkrCS6mLMu", "037a62ff6b7eb2ba1e170b5c42e7788817ded6a3a7ed841321c01cc107aa647d42"},
        {"RMjMXC8m9PgAaMMvwqgLCyCrv47pp6F6XY", "033bdf151c01bc733e614f9d4f204ca44396bf56984df6643205d349a35f7b265d"},
        {"RYB3ZMgHt4h7YL8TUzpqaSDw22ABksAPGC", "021266e045f95322fceddae02877dca9721792bef8f2be28cacd7c36290cd813a7"},
        {"RGwy64PXswUKpiepfzgaRW98v3gsuqPtow", "03008783c34c2622e7167f0a5201846133e530e89dfe1a8fbcf4c29b33051c4565"},
        {"RKJRPLaQV4AkWF6EfUUzFwawTGU4RQZgcS", "03c20a9fd21de76a20ffc87e384be735dfabb7f34a2d881ca9714830fb1bbe6bdb"},
        {"RQ4SPvBKTEKyV6y31iSihtfMxi3KeyAJgV", "033c5a23c75d946c15c15fac1e6d78e08c2b656549a158627cfb6bc44bb7b3a560"},
        {"RTvRBC1pCQpPKrS27Q4hUCVKVpa5tSTsFS", "02c25672fae388a0613d0127fcfe38ef37f5f354ecfdea0fb734528e354319bd9d"},
        {"RKxWu9HpCg7m3UeUGw2Xs1SpFiR96fSCQj", "02ec760d09b369b82b34d864af5a468d8a7dc5609b06bce455d045d1059c4b0f71"},
        {"RBAaUWAD8jwVLL7ueb7ciAQewqgheKxwdk", "0274ec3abcca214cdf7f1a565f5f3d3fa910e62e751a1ab0de148ea14ba72d6ba7"},
        {"RT853SBEGt4EWrKbpSujya69DG1jSNYjob", "02e80260ca44b8539159e6af678cf5ed0bc596753e4985f66418d6417085b4104e"},
        {"RKjEuhVByPwJcZ9wuBgfELiCVnBrc4F8i4", "0357c38f5d5eb1662a54b980c9243ddd8b2100d4b2b9f8175246938ef76e100678"},
        {"RT6wVuFFPU5tY6C7Buup1GLV3SE5mpYEha", "02571085ead1aca86b9e90fa9a23d99a194c862524b0c714102888be5bf122dc7d"},
        {"RSTgcpV82AivrvWJpd4LR2KwWirwbwXE3Y", "021a0ee4611ca4d8a2e209cc43b95036deb0a9d1cc31fc9f87d50233a44f05ec1a"},
        {"RCiaXRzo4AAG3zmPL3Hx63NsRWv5UGiNuM", "02f4876be65c54613e47f7fac67f1453e8d8fde5e19fa53f278a1083a08b258ab3"},
        {"RCGgLWrTTaqBhUsS1BqrmFpJZAdNJMzscv", "02893d2db5329b15a33aa7edfbf323c85cabbdc25caa6cf6186fac6052ae6d96a0"},
        {"RAJWHL6MzGFKg7KB2sZ87KPQUSvxy3VrEW", "0389971362b002ab5dfa1b5f9c4f88e68249511a3935242ba1e0d31c1c88a36d70"},
        {"RU592tQnbH8gt6xd5Uu23nEw3SucDNkXmK", "02b8b6a2266fe57b25f2d4b1da93a07d27930154e78f9d137bc7509cf1ae8e3d49"},
        {"RLGCLRzaEmruPC9UmVt5qRHEhXwHip1e6d", "02a2fd96b4459411ad2b09597ba59cf52b282c56330da7c0cc6d2a5c0323a18f1e"}
   }
};

#define SETBIT(bits,bitoffset) (((uint8_t *)bits)[(bitoffset) >> 3] |= (1 << ((bitoffset) & 7)))
#define GETBIT(bits,bitoffset) (((uint8_t *)bits)[(bitoffset) >> 3] & (1 << ((bitoffset) & 7)))
#define CLEARBIT(bits,bitoffset) (((uint8_t *)bits)[(bitoffset) >> 3] &= ~(1 << ((bitoffset) & 7)))

#define HUSH_MAXNVALUE (((uint64_t)1 << 63) - 1)
#define HUSH_BIT63SET(x) ((x) & ((uint64_t)1 << 63))
#define HUSH_VALUETOOBIG(x) ((x) > (uint64_t)10000000001*COIN)

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
extern uint64_t ASSETCHAINS_TIMELOCKGTE;
extern uint32_t ASSETCHAINS_ALGO,ASSETCHAINS_EQUIHASH,HUSH_INITDONE;
extern int32_t HUSH_MININGTHREADS,HUSH_LONGESTCHAIN,ASSETCHAINS_SEED,IS_HUSH_NOTARY,USE_EXTERNAL_PUBKEY,HUSH_CHOSEN_ONE,HUSH_ON_DEMAND,HUSH_PASSPORT_INITDONE,ASSETCHAINS_STAKED,HUSH_NSPV;
extern uint64_t ASSETCHAINS_COMMISSION, ASSETCHAINS_LASTERA,ASSETCHAINS_CBOPRET;
extern uint64_t ASSETCHAINS_REWARD[ASSETCHAINS_MAX_ERAS+1], ASSETCHAINS_NOTARY_PAY[ASSETCHAINS_MAX_ERAS+1], ASSETCHAINS_TIMELOCKGTE, ASSETCHAINS_NONCEMASK[],ASSETCHAINS_NK[2];
extern const char *ASSETCHAINS_ALGORITHMS[];
extern uint32_t ASSETCHAINS_NONCESHIFT[], ASSETCHAINS_HASHESPERROUND[];
extern std::string NOTARY_PUBKEY,ASSETCHAINS_OVERRIDE_PUBKEY,ASSETCHAINS_SCRIPTPUB;
extern uint8_t NOTARY_PUBKEY33[33],ASSETCHAINS_OVERRIDE_PUBKEY33[33],ASSETCHAINS_MARMARA;
extern std::vector<std::string> ASSETCHAINS_PRICES,ASSETCHAINS_STOCKS;
extern uint256 HUSH_EARLYTXID;
extern int32_t HUSH_CONNECTING,HUSH_CCACTIVATE,HUSH_DEALERNODE;
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
extern int32_t HUSH_TESTNODE, HUSH_SNAPSHOT_INTERVAL;
extern int32_t ASSETCHAINS_EARLYTXIDCONTRACT;
int tx_height( const uint256 &hash );
extern std::vector<std::string> vAllowListAddress;
extern std::map <std::int8_t, int32_t> mapHeightEvalActivate;
void komodo_netevent(std::vector<uint8_t> payload);
int32_t getacseason(uint32_t timestamp);
int32_t gethushseason(int32_t height);

#define DRAGON_MAXSCRIPTSIZE 10001
#define HUSH_KVDURATION 1440
#define HUSH_KVBINARY 2
#define PRICES_SMOOTHWIDTH 1
#define PRICES_MAXDATAPOINTS 8
uint64_t komodo_paxprice(uint64_t *seedp,int32_t height,char *base,char *rel,uint64_t basevolume);
int32_t komodo_paxprices(int32_t *heights,uint64_t *prices,int32_t max,char *base,char *rel);
int32_t hush_notaries(uint8_t pubkeys[64][33],int32_t height,uint32_t timestamp);
char *bitcoin_address(char *coinaddr,uint8_t addrtype,uint8_t *pubkey_or_rmd160,int32_t len);
int32_t hush_minerids(uint8_t *minerids,int32_t height,int32_t width);
int32_t hush_kvsearch(uint256 *refpubkeyp,int32_t current_height,uint32_t *flagsp,int32_t *heightp,uint8_t value[DRAGON_MAXSCRIPTSIZE],uint8_t *key,int32_t keylen);

uint32_t hush_blocktime(uint256 hash);
int32_t hush_longestchain();
int32_t hush_dpowconfs(int32_t height,int32_t numconfs);
int8_t hush_segid(int32_t nocache,int32_t height);
int32_t hush_heightpricebits(uint64_t *seedp,uint32_t *heightbits,int32_t nHeight);
char *komodo_pricename(char *name,int32_t ind);
int32_t komodo_priceind(const char *symbol);
int32_t komodo_pricesinit();
int64_t komodo_priceave(int64_t *tmpbuf,int64_t *correlated,int32_t cskip);
int64_t komodo_pricecorrelated(uint64_t seed,int32_t ind,uint32_t *rawprices,int32_t rawskip,uint32_t *nonzprices,int32_t smoothwidth);
int32_t hush_nextheight();
uint32_t hush_heightstamp(int32_t height);
int64_t komodo_pricemult(int32_t ind);
int32_t komodo_priceget(int64_t *buf64,int32_t ind,int32_t height,int32_t numblocks);
int32_t hush_currentheight();
int32_t hush_notarized_bracket(struct notarized_checkpoint *nps[2],int32_t height);
arith_uint256 komodo_adaptivepow_target(int32_t height,arith_uint256 bnTarget,uint32_t nTime);
bool hush_hardfork_active(uint32_t time);

uint256 Parseuint256(const char *hexstr);
void komodo_sendmessage(int32_t minpeers, int32_t maxpeers, const char *message, std::vector<uint8_t> payload);
CBlockIndex *hush_getblockindex(uint256 hash);
int32_t hush_nextheight();
CBlockIndex *hush_blockindex(uint256 hash);
CBlockIndex *hush_chainactive(int32_t height);
int32_t hush_blockheight(uint256 hash);
bool hush_txnotarizedconfirmed(uint256 txid);
int32_t hush_blockload(CBlock& block, CBlockIndex *pindex);
uint32_t hush_chainactive_timestamp();
uint32_t GetLatestTimestamp(int32_t height);

#ifndef HUSH_NSPV_FULLNODE
#define HUSH_NSPV_FULLNODE (HUSH_NSPV <= 0)
#endif // !HUSH_NSPV_FULLNODE
#ifndef HUSH_NSPV_SUPERLITE
#define HUSH_NSPV_SUPERLITE (HUSH_NSPV > 0)
#endif // !HUSH_NSPV_SUPERLITE

#endif
