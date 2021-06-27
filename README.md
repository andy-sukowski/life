# life - Conway's Game of Life

This is a lightweight, text-based implementation of [Conway's Game of
Life][1], written in C.

## Requirements

In order to build life you need [ncurses][2].

## Installation

Edit `config.mk` to match your local setup (life is installed into the
`/usr/local` namespace by default).

Afterward, enter the following command to build and install life (if
necessary as root):

    make clean install

## Running life

After successfully installing life, you can run it:

    life

The width and height of the grid are defined in `life.c`.

[1]: https://en.wikipedia.org/wiki/Conway's_Game_of_Life
[2]: https://www.gnu.org/software/ncurses/ncurses.html
