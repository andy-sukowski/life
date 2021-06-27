# Customize below to fit your system

# paths
PREFIX = /usr/local

# libs
LIBS = -lncurses

# flags
CFLAGS   = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os
LDFLAGS  = ${LIBS}

# compiler and linker
CC = cc
