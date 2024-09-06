#include "valset.h"

set minr(set r)
{
    if(r==NULL) return r;
    set min_e = minr(r->e);
    set min_d = minr(r->d);
    set resultado = r;
    if(min_e!=NULL && safecmp(min_e->chave, resultado->chave) == -1)
        resultado = min_e;
    if(min_d!=NULL && safecmp(min_d->chave, resultado->chave) == -1)
        resultado = min_d;
    return resultado;
}

set maxr(set r)
{
    if(r==NULL) return r;
    set max_e = maxr(r->e);
    set max_d = maxr(r->d);
    set resultado = r;
    if(max_e!=NULL && safecmp(max_e->chave, resultado->chave) == 1)
        resultado = max_e;
    if(max_d!=NULL && safecmp(max_d->chave, resultado->chave) == 1)
        resultado = max_d;
    return resultado;
}

int is_busca(set r)
{
    if(r==NULL) return 1;
    if(r->e!=NULL)
    {
        if((safecmp(r->chave, minr(r->e)->chave) == -1) || !is_busca(r->e))
            return 0;
    }
    if(r->d!=NULL)
    {
        if((safecmp(r->chave, maxr(r->d)->chave) == 1) || !is_busca(r->d))
            return 0;
    }
    return 1;
}

int is_balanced(set r)
{
    if(r == NULL) return 1;
    if ((is_balanced(r -> d)) & (is_balanced(r -> e)))
    {
        int he = altura(r -> e);
        int hd = altura(r -> d);
        if (abs(he-hd) <= 1)
            return 1;
    }
    return 0;
}