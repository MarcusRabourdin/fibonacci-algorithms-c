#pragma once

char *Encrypt(char *message, char *key);
char *Decrypt(char *CipheredMessage,char *key);
int Scramble(int x, int i, int k);
char *SubkeyGen(void *s1, void *s2);

/*
* f(x,k) = [(2i * k) ^ x ] % (2^32-1)
* Li = Ri - 1
* Ri = L[i-1] XOR f(R[i-1], ki)
*/


