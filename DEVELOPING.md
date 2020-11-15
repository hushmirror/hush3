# Being a Hush Developer

## Compiling Hush

Normal compiling is as simple as:

	./build.sh

To make it use as many CPU threads as you have:

	./build.sh -j$(nproc)  # assumes linux
	./build.sh -j8 		  # use a fixed 8 threads, more portable

## Good Hygiene

To avoid weird build system issues, it's often good to run:

	make clean

*before* you switch Git branches. Otherwise, the new branches Makefiles
often are incompatible and `make clean` will be impossible, which can
sometimes introduce weird bugs or make compiling really annoying.
If `make clean` produces a compilation error, you just experienced it.

## Switching branches

Switching branches and doing partial compiles in Hush source code
can introduce weird bugs, which are fixed by running `build.sh` again.
Additionally, it's a good idea to run `make clean` before you switch
between branches.

## Partial compiles

At any point, you can modify hush source code and then use `make` or `build.sh`
to do a partial compile. The first is faster but the latter is more likely to
work correctly in all circustances. Sometimes partial compiles break weird
build system dependencies, and you must do a `make clean` first, or even
`git clean -fdx` (look up what it means first!) to clean things. The nuclear
option is to re-clone the repo, which sometimes is the least work to fix
the problem.

Running `make` doesn't understand about dependency changes, such as Rust crates.
A simple C/C++ change can be tested with just `make` but if you change the version
of a dependency or something inside of Rust, you will need `build.sh` .

## Generating new unix man pages

Make sure that you have updated all version numbers in hushd and compiled, then
to generate new unix man pages for that version :

	./contrib/devtools/gen-manpages.sh

## Generating new debian packages

After successfully compiling Hush, you can generate a debian package of these binaries with:

	./zcutil/build-debian-package.sh

This command will not work on Mac OS X. Currently you cannot generate a Debian package
from operating systems other than Linux. Oh well.

## Updates to this document

If you think something else should be in this guide, please send your suggestions!

Gitea: https://git.hush.is/hush/hush3
