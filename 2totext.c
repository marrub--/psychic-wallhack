#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp = fopen("nice_.txt", "r");

	for(;;)
	{
		if(feof(fp))
		{
			break;
		}

		char c[9] = { 0 };
		fread(c, 1, 8, fp);
		fgetc(fp);

		printf("%c", strtol(c, NULL, 2));
	}

	return 0;
}


