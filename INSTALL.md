# Installing Hush

## Installing Binaries

To install a Debian package:

	dpkg -i hush-3.6.2-amd4.deb

To uninstall:

	apt-get remove hush

## Build HUSH dependencies

The following build process generally applies to Ubuntu (and similar) Linux
distributions. For best results it is recommended to use Ubuntu Linux 16.04
or later.

## Swap Space (Optional)
You will need at least 4GB of RAM to build hush from git source, OR you can
enable a swap file. To enable a 4GB swap file on modern Linux distributions:

```sh
sudo fallocate -l 4G /swapfile
sudo chmod 600 /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile
```

## Build on Linux:


```sh
# install build dependencies
sudo apt-get install build-essential pkg-config libc6-dev m4 g++-multilib \
      autoconf libtool ncurses-dev unzip git python zlib1g-dev wget \
      bsdmainutils automake curl unzip nano libsodium-dev
# pull
git clone https://git.hush.is/hush/hush3
cd hush3
# Build
./build.sh -j$(nproc)
```

## Building On Ubuntu 16.04 and older systems

Some older compilers may not be able to compile modern code, such as gcc 5.4 which comes with Ubuntu 16.04 by default. Here is how to install gcc 7 on Ubuntu 16.04. Run these commands as root:

```
add-apt-repository ppa:ubuntu-toolchain-r/test && \
apt update && \
apt-get install -y gcc-7 g++-7 && \
  update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-7 60 && \
  update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-7 60
```

## Run a HUSH Node

```sh
./src/hushd
```

## Windows (cross-compiled on Linux)
Get dependencies:
```ssh
sudo apt-get install \
      build-essential pkg-config libc6-dev m4 g++-multilib \
      autoconf libtool ncurses-dev unzip git python \
      zlib1g-dev wget bsdmainutils automake mingw-w64 cmake libsodium-dev
```

Downloading Git source repo, building and running Hush:

```sh
# pull
git clone https://git.hush.is/hush/hush3
cd hush
# Build
./build-win.sh -j$(nproc)
# Run a HUSH node
./src/hushd
```

Currently Linux,  Windows and Mac OS X are our supported platforms. If you
are interested in porting Hush to a new operating system, we are interested
to talk with you. Experimental FreeBSD support is in progress, thanks to radix42.

We aim to support all platforms, but there is only so much time in the day.

Currently, any ARMv7 machine will not be able to build this repo, because the
underlying tech (zcash and the zksnark library) do not support that instruction
set.

This also means that RaspberryPi devices will not work, unless they have a
newer ARMv8-based Raspberry Pi.
