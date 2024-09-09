#include "cset99/safearray.h"

int safecmp(safeArray a, safeArray b)
{
    if(a.n > b.n) return 1;
    else if(a.n < b.n) return 0;

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

void safeswap(safeArrayPtr sp, int i, int j)
{
    safeArray t = sp[i];
    sp[i] = sp[j];
    sp[j] = t;
}

int safepart(safeArrayPtr sp, int left, int right)
{
    safeArray pivot = sp[left];
    int i = left;

    for(int j = left+1; j <= right; j++)
    {
        if(safecmp(sp[j], pivot) > 0)
        {
            i+=1;
            safeswap(sp, i, j);
        }
    }
    safeswap(sp, left, i);
    return i;
}

void safeqsort(safeArrayPtr sp, int left, int right)
{
    if(left < right)
    {
        int idx = safepart(sp, left, right);
        safeqsort(sp, left, idx-1);
        safeqsort(sp, idx+1, right);
    }
}

int _compare(const void* a, const void* b) {
   return (*(int*)b - *(int*)a);
}

void safeqsortElements(safeArrayPtr sp, int n)
{
    for(int i = 0; i < n; i++)
    {
        safeArray a = sp[i];
        qsort(a.array, a.n, sizeof(int), _compare);
    }
}