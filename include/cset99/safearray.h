typedef struct sfarr
{
    int* array;
    int n;
} safeArray;

int safecmp(safeArray a, safeArray b);
safeArray safenew(int* vetor, int n);