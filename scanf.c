#include <stdio.h>

struct
{
	int x;
	int y;
} a;

int main(int argc, char **argv)
{
	FILE *f = stdin;
	char mapname[12];
	fscanf(f, "MAP %12s\n", mapname);
	fscanf(f, "TILESIZE %d %d\n", &a.x, &a.y);
	printf("map: %s\ntilesize: %d %d\n", mapname, a.x, a.y);
	return 0;
}
