// Copyright (c) 2016-2021 The Hush developers
// Copyright (c) 2012-2013 The Bitcoin Core developers
// Distributed under the GPLv3 software license, see the accompanying
// file COPYING or https://www.gnu.org/licenses/gpl-3.0.en.html

#include "compat/sanity.h"
#include "key.h"
#include "test/test_bitcoin.h"

#include <boost/test/unit_test.hpp>

BOOST_FIXTURE_TEST_SUITE(sanity_tests, BasicTestingSetup)

BOOST_AUTO_TEST_CASE(basic_sanity)
{
  BOOST_CHECK_MESSAGE(glibc_sanity_test() == true, "libc sanity test");
  BOOST_CHECK_MESSAGE(glibcxx_sanity_test() == true, "stdlib sanity test");
  BOOST_CHECK_MESSAGE(ECC_InitSanityCheck() == true, "openssl ECC test");
}

BOOST_AUTO_TEST_SUITE_END()
