#include "cset99/safearray.h"
#include "assert.h"
#include "stdio.h"

int main(void)
{
    int v1[3] = {1,2,3}, v2[3] = {1,2,3};
    int v3[3] = {1,2,4}; int v4[3] = {1,2,2};

    safeArray a, b, c, d;
    a.array = v1;
    b.array = v2; 
    c.array = v3;
    d.array = v4;
    a.n = b.n = c.n = d.n = 3;

    assert(safecmp(a,b) == 0);
    assert(safecmp(a,c) == -1);
    assert(safecmp(a,d) == 1);

    printf("safecmp: OK"); 
}