#include "bios.h"
#include <graphics.h>
#include <stdlib.h>
#include <time.h>

void randomize(void)
{
	srand((unsigned)time(NULL));
	// 첫부분의 숫자는 거의 랜덤하지 않기에, 앞부분에서 랜덤한 개수로 뽑아서 버림
	for (int i = 0; i < (rand() % RAND_MAX); i++) (rand() % RAND_MAX);
}


void sound(int pitch)
{
	//not implemented!!
}

void nosound()
{
	//not implemented!!
}

int bioskey(int temp)
{
	if (temp == 1)
		return 1;

	if (key_value == SDLK_ESCAPE)
		return 283;

	if (key_value == SDLK_UP)
		return 18432;

	if (key_value == SDLK_RIGHT)
		return 19712;

	if (SDLK_LEFT == key_value)
		return 19200;

	if (key_value == SDLK_SPACE)
		return 14624;


	return 0;
}