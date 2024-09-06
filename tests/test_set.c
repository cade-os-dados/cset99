#include "cset99/set.h"
#include "valset.h"
#include <assert.h>
#include <stdio.h>

int main(void)
{
    int v[3] = {1,2,3}; int v2[3] = {4,5,6}; int v3[3] = {9,8,7};
    int v4[3] = {12,9,8}; int v5[3] = {14,9,8}; int v6[3] = {0,1,2};
    safeArray s1 = safenew(v, 3); safeArray s2 = safenew(v2, 3);
    safeArray s3 = safenew(v3, 3); safeArray s4 = safenew(v4,3);
    safeArray s5 = safenew(v5, 3); safeArray s6 = safenew(v6, 3); 
    
    set a = begin(s1);
    set b = begin(s2); set c = begin(s4);
    a->d = b; b->d = c;

    assert(search(a, s1) == a);
    assert(search(a, s2) == b);
    assert(search(a, s3) == NULL);
    assert(search(a, s4) == c);
    printf("search: OK\n");

    assert(searchCloser(a, s1) == NULL);
    assert(searchCloser(a, s2) == NULL);
    assert(searchCloser(a, s3) == b);
    assert(searchCloser(a, s5) == c);
    assert(searchCloser(a, s6) == a);
    printf("searchCloser: OK\n");

    a = insert(a, s3);
    assert(search(a,s3) != NULL);
    assert(is_busca(a));
    assert(is_balanced(a));

    printf("insert: OK");
}