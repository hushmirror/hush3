#!/bin/bash
# Copyright (c) 2019-2020 Hush developers

#set -ex
echo "...Checking HUSH3.conf"

if [ ! -e "$HOME/.komodo/HUSH3/HUSH3.conf" ]; then
    mkdir -p $HOME/.komodo/HUSH3

    echo "...Creating HUSH3.conf"
    cat <<EOF > $HOME/.komodo/HUSH3.conf
rpcuser=hush
rpcpassword=${rpcpassword:-`dd if=/dev/urandom bs=33 count=1 2>/dev/null | base64`}
txindex=1
bind=${listenip:-127.0.0.1}
rpcbind=${listenip:-127.0.0.1}
# Some knobs you might want to turn
debug=0
zdebug=0
zindex=0
EOF

    cat $HOME/.komodo/HUSH3/HUSH3.conf
fi

if [ $# -gt 0 ]; then
    args=("$@")
elif [  -z ${assetchain+x} ]; then
    args=("-gen -genproclimit=${genproclimit:-2} -pubkey=${pubkey}")
else
    args=("-pubkey=${pubkey} -ac_name=${assetchain} -addnode=${seednode}")
fi

echo "Running: hushd ${args[@]}"

exec hushd ${args[@]}
