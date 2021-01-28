#!/bin/bash
# Copyright (c) 2016-2020 The Hush developers
# Distributed under the GPLv3 software license, see the accompanying
# file COPYING or https://www.gnu.org/licenses/gpl-3.0.en.html

set -eu -o pipefail
./zcutil/build.sh --disable-tests $@
