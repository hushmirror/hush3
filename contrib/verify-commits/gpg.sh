#!/bin/sh
# Copyright (c) 2019-2020 Hush developers
# Distributed under the GPLv3 software license, see the accompanying
# file COPYING or https://www.gnu.org/licenses/gpl-3.0.en.html
INPUT=$(</dev/stdin)
VALID=false
IFS=$'\n'
for LINE in $(echo "$INPUT" | gpg --trust-model always "$@" 2>/dev/null); do
	case "$LINE" in "[GNUPG:] VALIDSIG"*)
		while read KEY; do
			case "$LINE" in "[GNUPG:] VALIDSIG $KEY "*) VALID=true;; esac
		done < ./contrib/verify-commits/trusted-keys
	esac
done
if ! $VALID; then
	exit 1
fi
echo "$INPUT" | gpg --trust-model always "$@" 2>/dev/null
