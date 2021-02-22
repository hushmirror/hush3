#!/bin/bash
# Copyright (c) 2016-2021 The Hush developers
# Released under the GPLv3

set -e
set -x

#TODO: autodect version number, error handling
FILE="hush-3.6.2-linux-amd64.tar"
TIME=$(perl -e 'print time')

mv build build.$TIME
mkdir build
cp contrib/asmap/asmap.dat build/
cp sapling*.params build/
cd src
cp komodod komodo-cli komodo-tx hushd hush-cli hush-tx hush-smart-chain ../build
cd ../build
strip komodo*
tar -f $FILE -c  *
gzip -9 $FILE
sha256sum *.gz
du -sh *.gz
