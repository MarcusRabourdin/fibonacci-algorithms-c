#include "utils.h"

int my_pow(int x, int n)
{
    if (n == 1)
    {
        return x; 
    }

    if(n%2 == 0)
    {
        return my_pow(x*x, n/2);
    }
    else {
        return my_pow(x*x, (n-1)/2);
    }
}
