// https://adventofcode.com/2023/day/2

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1024
#define MAXr 12
#define MAXg 13
#define MAXb 14
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main() {

	char line[SIZE];	
	char round[SIZE];
	int nr = 0;
	char col = '.';
	int gamenr = 0;
	int r = 0, g = 0, b = 0;
	int ret = 0;
	int sum = 0;

	while (!feof(stdin)) {
		if (fgets(line, SIZE, stdin) == NULL) continue;
		if (line[strlen(line)-1] == '\n') line[strlen(line)] = '\0';
		if (sscanf(line, "Game %d: %[^\n]", &gamenr, round) != 2) continue;
		r = g = b = 0;
		ret = sscanf(round, "%d %c%[^\n]", &nr, &col, round);
		while ((ret == 3) && (ret != -1)) {
			switch (col) {
				case 'r': r = MAX(r, nr); break;
				case 'g': g = MAX(g, nr); break;
				case 'b': b = MAX(b, nr);
			}
			ret = sscanf(round, "%*[^0-9]%d %c%[^\n]", &nr, &col, round);
		}
		if (r <= MAXr && g <= MAXg && b <= MAXb) sum += gamenr;
		printf("Game %2d: r=%d, g=%d, b=%d - Sum: %d\n", gamenr, r, g, b, sum);
	}
	return 0;
}
