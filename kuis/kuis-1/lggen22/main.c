/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM3 dalam mata kuliah Struktur Datas
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"
// Program membaca kata satu per satu dari pita menggunakan mesin kata.
int main()
{
    list L;
    list L2;
    createList(&L);
    createList(&L2);

    int i, n, m;
    char o[50], p[50];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s %s", o, p);
        addLast(o, p, &L);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%s %s", o, p);
        addLast(o, p, &L2);
    }

    scanf("%d", &m);
    swap(&L, &L2, m);

    printElement(L);
    printElement(L2);

    return 0;
}