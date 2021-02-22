#!/bin/bash
# Copyright (c) 2016-2021 The Hush developers
# Released under the GPLv3

#TODO: autodect version number, error handling
FILE="hush-3.6.2-linux-amd64.tar"

mkdir build
cp contrib/asmap/asmap.dat build/
cp sapling*.params build/
cd src
cp komodod komodo-cli komodo-tx hushd hush-cli hush-tx hush-smart-chain ../build
cd ../build
tar -f $FILE -c  *
gzip $FILE

