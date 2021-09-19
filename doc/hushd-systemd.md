# Systemd script for the Hush daemon

## Set it up

First set it up as follows:
* Copy hushd.service to the /usr/lib/systemd/user directory (on Arch Linux, but I believe it's the same for the others too)

## Basic Usage

How to start the script:
`systemctl start --user hushd.service`

How to stop the script:
`systemctl stop --user hushd.service`

How to restart the script:
`systemctl stop --user hushd.service`

## How to watch it as it starts

Use the following:
`watch systemctl status --user hushd.service`

## Troubleshooting

Don't run it with sudo or root, or it won't work with the wallet.
