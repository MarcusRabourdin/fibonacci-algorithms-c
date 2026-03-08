#include "feistel.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>


int main(void)
{
    
    return 0;
}


char *SubkeyGen(char *s1, char *s2)
{
    char *concat = strcat(s1,s2);
    return sha256(concat);

}

int Scramble(int x, int i, int k)
{
    return (my_pow(x*i*k,i) % (my_pow(2,32-1))
}

