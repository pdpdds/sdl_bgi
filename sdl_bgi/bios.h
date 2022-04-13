#ifndef _BIOS_H
#define _BIOS_H

extern int key_value;

#ifdef _WIN32
void randomize(void);
#endif

void sound(int pitch);
void nosound();

int bioskey(int temp);

#endif