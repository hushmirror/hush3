# Contrib Devtools

This directory contains tools for developers working on this repository.

## security-check.py

Perform basic ELF security checks on a series of executables.

## symbol-check.py

A script to check that the (Linux) executables produced by gitian only contain
allowed gcc, glibc and libstdc++ version symbols.  This makes sure they are
still compatible with the minimum supported Linux distribution versions.

Example usage after a gitian build:

    find ../gitian-builder/build -type f -executable | xargs python contrib/devtools/symbol-check.py 

If only supported symbols are used the return value will be 0 and the output will be empty.

If there are 'unsupported' symbols, the return value will be 1 a list like this will be printed:

    .../64/test_bitcoin: symbol memcpy from unsupported version GLIBC_2.14
    .../64/test_bitcoin: symbol __fdelt_chk from unsupported version GLIBC_2.15
    .../64/test_bitcoin: symbol std::out_of_range::~out_of_range() from unsupported version GLIBCXX_3.4.15
    .../64/test_bitcoin: symbol _ZNSt8__detail15_List_nod from unsupported version GLIBCXX_3.4.15

## update-translations.py

Run this script from the root of the repository to update all translations from transifex.
It will do the following automatically:

- fetch all translations
- post-process them into valid and committable format
- add missing translations to the build system (TODO)

See doc/translation-process.md for more information.

## gen-manpages.sh

A small script to automatically create manpages in ../../doc/man by running the release binaries with the -help option.
This requires help2man which can be found at: https://www.gnu.org/software/help2man/
