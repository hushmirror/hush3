// Copyright (c) 2017 The Zcash developers
// Copyright (c) 2016-2020 The Hush developers
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

#ifndef ASYNCRPCOPERATION_SHIELDCOINBASE_H
#define ASYNCRPCOPERATION_SHIELDCOINBASE_H

#include "asyncrpcoperation.h"
#include "amount.h"
#include "primitives/transaction.h"
#include "transaction_builder.h"
#include "zcash/JoinSplit.hpp"
#include "zcash/Address.hpp"
#include "wallet.h"

#include <unordered_map>
#include <tuple>

#include <univalue.h>

// Default transaction fee if caller does not specify one.
#define SHIELD_COINBASE_DEFAULT_MINERS_FEE   10000

using namespace libzcash;

struct ShieldCoinbaseUTXO {
    uint256 txid;
    int vout;
    CScript scriptPubKey;
    CAmount amount;
};

// Package of info which is passed to perform_joinsplit methods.
struct ShieldCoinbaseJSInfo
{
    std::vector<JSInput> vjsin;
    std::vector<JSOutput> vjsout;
    CAmount vpub_old = 0;
    CAmount vpub_new = 0;
};

class AsyncRPCOperation_shieldcoinbase : public AsyncRPCOperation {
public:
    AsyncRPCOperation_shieldcoinbase(
        TransactionBuilder builder,
        CMutableTransaction contextualTx,
        std::vector<ShieldCoinbaseUTXO> inputs,
        std::string toAddress,
        CAmount fee = SHIELD_COINBASE_DEFAULT_MINERS_FEE,
        UniValue contextInfo = NullUniValue);
    virtual ~AsyncRPCOperation_shieldcoinbase();

    // We don't want to be copied or moved around
    AsyncRPCOperation_shieldcoinbase(AsyncRPCOperation_shieldcoinbase const&) = delete;             // Copy construct
    AsyncRPCOperation_shieldcoinbase(AsyncRPCOperation_shieldcoinbase&&) = delete;                  // Move construct
    AsyncRPCOperation_shieldcoinbase& operator=(AsyncRPCOperation_shieldcoinbase const&) = delete;  // Copy assign
    AsyncRPCOperation_shieldcoinbase& operator=(AsyncRPCOperation_shieldcoinbase &&) = delete;      // Move assign

    virtual void main();

    virtual UniValue getStatus() const;

    bool testmode = false;  // Set to true to disable sending txs and generating proofs
    bool cheatSpend = false; // set when this is shielding a cheating coinbase

private:
    friend class ShieldToAddress;
    friend class TEST_FRIEND_AsyncRPCOperation_shieldcoinbase;    // class for unit testing

    UniValue contextinfo_;     // optional data to include in return value from getStatus()

    CAmount fee_;
    PaymentAddress tozaddr_;

    uint256 joinSplitPubKey_;
    unsigned char joinSplitPrivKey_[crypto_sign_SECRETKEYBYTES];

    std::vector<ShieldCoinbaseUTXO> inputs_;

    TransactionBuilder builder_;
    CTransaction tx_;

    bool main_impl();

    // JoinSplit without any input notes to spend
    UniValue perform_joinsplit(ShieldCoinbaseJSInfo &);

    void sign_send_raw_transaction(UniValue obj);     // throws exception if there was an error

    void lock_utxos();

    void unlock_utxos();
};

class ShieldToAddress : public boost::static_visitor<bool>
{
private:
    AsyncRPCOperation_shieldcoinbase *m_op;
    CAmount sendAmount;
public:
    ShieldToAddress(AsyncRPCOperation_shieldcoinbase *op, CAmount sendAmount) :
        m_op(op), sendAmount(sendAmount) {}

    bool operator()(const libzcash::SaplingPaymentAddress &zaddr) const;
    bool operator()(const libzcash::InvalidEncoding& no) const;
};


// To test private methods, a friend class can act as a proxy
class TEST_FRIEND_AsyncRPCOperation_shieldcoinbase {
public:
    std::shared_ptr<AsyncRPCOperation_shieldcoinbase> delegate;

    TEST_FRIEND_AsyncRPCOperation_shieldcoinbase(std::shared_ptr<AsyncRPCOperation_shieldcoinbase> ptr) : delegate(ptr) {}

    CTransaction getTx() {
        return delegate->tx_;
    }

    void setTx(CTransaction tx) {
        delegate->tx_ = tx;
    }

    // Delegated methods

    bool main_impl() {
        return delegate->main_impl();
    }

    UniValue perform_joinsplit(ShieldCoinbaseJSInfo &info) {
        return delegate->perform_joinsplit(info);
    }

    void sign_send_raw_transaction(UniValue obj) {
        delegate->sign_send_raw_transaction(obj);
    }

    void set_state(OperationStatus state) {
        delegate->state_.store(state);
    }
};


#endif /* ASYNCRPCOPERATION_SHIELDCOINBASE_H */

