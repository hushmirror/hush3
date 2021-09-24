# Systemd script for the Hush daemon

## Set it up

First set it up as follows:
* Copy hushd.service to the systemd user directory, which is /usr/lib/systemd/user directory

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

* Don't run it with sudo or root, or it won't work with the wallet.

### To-do

* determine best method to get logs when using on Ubuntu server as it is not displayed when watching it or when start/stopping the systemd service (testd on Ubuntu server 20.04 running on VPS)
