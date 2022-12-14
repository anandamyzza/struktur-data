/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM10 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

int main()
{
    graph G;
    createEmpty(&G);
    addSimpul(1, &G);
    addSimpul(2, &G);
    addSimpul(3, &G);
    addSimpul(4, &G);
    addSimpul(5, &G);
    addSimpul(6, &G);
    addSimpul(7, &G);
    addSimpul(8, &G);

    int del;
    scanf("%d", &del);

    simpul *begin = findSimpul(3, G);
    simpul *end = findSimpul(8, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }

    end = findSimpul(1, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }

    end = findSimpul(7, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }

    begin = findSimpul(4, G);
    end = findSimpul(2, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }

    begin = findSimpul(5, G);
    end = findSimpul(6, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }

    begin = findSimpul(6, G);
    end = findSimpul(3, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }

    begin = findSimpul(7, G);
    end = findSimpul(4, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }

    begin = findSimpul(8, G);
    end = findSimpul(1, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }

    end = findSimpul(6, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }

    printGraph(G);
    printf("==============\n");

    begin = findSimpul(del, G);
    if (begin != NULL)
    {
        delSimpul(del, &G);
    }

    printGraph(G);

    return 0;
}