#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp = fopen("nice.txt", "r");

	for(;;)
	{
		if(feof(fp))
		{
			break;
		}

		char c[3] = { 0 };
		fread(c, 1, 2, fp);
		fgetc(fp);

		printf("%c", strtol(c, NULL, 16));
	}

	return 0;
}


