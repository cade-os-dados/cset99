#include "safearray.h"

int safecmp(safeArray a, safeArray b)
{
    if(a.n != b.n) return 0;

    int i = 0;
    while(i < a.n && a.array[i] == b.array[i])
        i++;
    if(i == a.n) return 0;
    else if(a.array[i] > b.array[i]) return 1;
    else return -1;
}

safeArray safenew(int* vetor, int n)
{
    safeArray s;
    s.array = vetor;
    s.n=n;
    return s;
}