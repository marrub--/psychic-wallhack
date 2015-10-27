#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("invalid number of arguments (%d)\n", argc);
		return 1;
	}

	printf("key is '%d'\n", SDL_GetKeyFromName(argv[1]));

	return 0;
}

