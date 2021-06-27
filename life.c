/* See LICENSE file for copyright and license details. */

#define _POSIX_C_SOURCE 199309L

#include <curses.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 48
#define HEIGHT 32

bool grid[HEIGHT][WIDTH];

/* initial setup */
void setup(void)
{
	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();
	nonl();
	intrflush(stdscr, FALSE);
	keypad(stdscr, TRUE);
	timeout(0);
	curs_set(0);

	srand(time(NULL));

	memset(grid, false, sizeof(grid));
	for (int i = 0; i < 250; ++i) {
		int x, y;
		do {
			x = rand() % WIDTH;
			y = rand() % HEIGHT;
		} while (grid[y][x]);
		grid[y][x] = true;
	}
}

/* draw grid */
void draw(void)
{
	clear();
	for (int y = 0; y < HEIGHT; ++y)
		for (int x = 0; x < WIDTH; ++x)
			if (grid[y][x])
				mvprintw(y, x * 2, "o");
	refresh();
}

/* return whether cell is alive */
bool alive(int x, int y)
{
	int n = 0; /* neighbours */
	for (int j = y - 1; j <= y + 1; ++j)
		for (int i = x - 1; i <= x + 1; ++i)
			if (grid[(j + HEIGHT) % HEIGHT][(i + WIDTH) % WIDTH] &&
			    (x != i || y != j))
				++n;

	return (n == 3 || (n == 2 && grid[y][x]));
}

/* run one generation */
bool evolve(void)
{
	char c = getch();
	if (c == 'q')
		return false;

	bool new_grid[HEIGHT][WIDTH];
	for (int y = 0; y < HEIGHT; ++y)
		for (int x = 0; x < WIDTH; ++x)
			new_grid[y][x] = alive(x, y);

	memcpy(grid, new_grid, sizeof(grid));

	return true;
}

/* call functions */
int main(void)
{
	setup();

	bool gameover = false;
	while (!gameover) {
		draw();
		struct timespec ts;
		ts.tv_sec = 0;
		ts.tv_nsec = 100000000;
		nanosleep(&ts, &ts);
		gameover = !evolve();
	}

	endwin();
	return EXIT_SUCCESS;
}
