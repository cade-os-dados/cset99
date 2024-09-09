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

    printf("safecmp: OK\n"); 

    int v5[2] = {1,2};
    safeArray e = safenew(v5, 2);

    safeArrayPtr x;
    x[0] = a; x[1] = b; x[2] = c;
    x[3] = d; x[4] = e;

    safeqsort(x, 0, 4);

    assert(safecmp(x[0], c) == 0);
    assert(safecmp(x[1], a) == 0);
    assert(safecmp(x[2], b) == 0);
    assert(safecmp(x[3], d) == 0);
    assert(safecmp(x[4], e) == 0);
    printf("safeqsort: OK\n");

    int k1[3] = {4,2,1}, k23[3] = {3,2,1}, k4[3] = {2,2,1}, k5[2] = {2,1};

    safeArray j1 = safenew(k1, 3), j23 = safenew(k23, 3), 
    j4 = safenew(v4, 3), j5 = safenew(k5, 2);

    safeqsortElements(x, 5);

    assert(safecmp(x[0], j1) == 0);
    assert(safecmp(x[1], j23) == 0);
    assert(safecmp(x[2], j23) == 0);
    assert(safecmp(x[3], j4) == 0);
    assert(safecmp(x[4], j5) == 0);
    printf("safeqsortElements: OK");
}