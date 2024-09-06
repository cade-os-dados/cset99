# include "set.h"

set begin(safeArray s)
{
    set new = malloc(sizeof(no));
    new->e = new->d = NULL;
    new->chave=s;

    return new;
}

set search(set r, safeArray s)
{
    if(r==NULL) return NULL;
    int cmps = safecmp(r->chave, s);
    if(cmps == 0)
        return r;
    set b;
    if(cmps > 0 && (b = search(r->e, s)) != NULL)
        return b;
    if(cmps < 0 && (b = search(r->d, s)) != NULL)
        return b;
    return NULL;
}

/* 
    s > resultado, 
    exceto se s < r e r->e == NULL
*/
set searchCloser(set r, safeArray s)
{
    int scmp = safecmp(r->chave, s);
    if (scmp == 0) return NULL;

    if (scmp > 0) {
        while (r->e != NULL && (scmp = safecmp(r->chave, s)) > 0)
            r = r->e;
    } else {
        while (r->d != NULL && (scmp = safecmp(r->d->chave, s)) < 0)
            r = r->d;
    }

    return scmp == 0 ? NULL : r;
}

int altura(set r)
{
    if(r==NULL) return 0;
    int he = altura(r->e);
    int hd = altura(r->d);
    return 1 + (he > hd) ? he : hd;
}

set leftRotation(set r)
{
    set y = r->d;
    set t2 = y->e;
    y->e=r;
    r->d=t2;
    return y;
}

set rightRotation(set r)
{
    set x = r->e;
    set t2 = r->d;
    x->d = r;
    r->e = t2;
    return x;
}

set balance(set r, safeArray s)
{
    int h = altura(r->e) - altura(r->d);
    if(h > 1)
    {
        if(r->e != NULL && safecmp(s, r->e->chave) > 0)
            r->e = leftRotation(r->e);
        return rightRotation(r);
    }
    if(h < -1)
    {
        if(r->d != NULL && safecmp(s, r->d->chave) > 0)
            r->d = rightRotation(r->d);
        return leftRotation(r);
    }

    return r;
}

set insert(set r, safeArray s)
{
    set anterior = searchCloser(r, s);
    if(anterior==NULL) return r;
    set nova = begin(s);
    if(safecmp(anterior->chave, s) < 0)
    {
        set t = anterior->d;
        anterior->d=nova;
        nova->d=t;
    }   
    else
    {
        set t = anterior->e;
        anterior->e=nova;
        nova->e=t;
    }

    return balance(r,s);
}