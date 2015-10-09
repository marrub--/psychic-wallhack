#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int len = strlen(argv[1]);
	size_t hash = 0;
	for(int i = 0; i < len; i++)
	{
		hash = hash * 101 + argv[1][i];
	}
	printf("%zu\n", hash);
	return 0;
}

