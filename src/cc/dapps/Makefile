# Copyright 2020 The Hush Developers
# Just type make to compile all dat dapp code, fellow cypherpunk

# we no longer build zmigrate by default, nobody uses that fucking code
all: hushdex

hushdex:
	$(CC) hushdex.c -o hushdex -lm

# Just for historical knowledge, to study how fucking stupid
# ZEC+KMD were to still support sprout, to this day!!!!!!!!
zmigrate:
	$(CC) zmigrate.c -o zmigrate -lm

clean:
	rm zmigrate

