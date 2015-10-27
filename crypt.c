#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>

/* WHY IS THIS VALID
main(argc, argv)
	int argc;
	char **argv;*/
int main(int argc, char **argv)
{
	printf("%s\n", crypt(argv[1], "zd"));
	return 0;
}
