/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM1 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"
// Program membaca kata satu per satu dari pita menggunakan mesin kata.
int main()
{
    list L;

    int i;
    char o[5][50], p[5][10], q[5][50];
    for (i = 0; i < 5; i++)
    {
        scanf("%s %s %s", o[i], p[i], q[i]);
    }

    createList(&L);
    addFirst(o[0], p[0], q[0], &L);
    addFirst(o[1], p[1], q[1], &L);
    addAfter(L.first, o[2], p[2], q[2], &L);
    printElement(L);
    printf("--------------------\n");

    delLast(&L);
    addAfter(L.data[L.first].next, o[3], p[3], q[3], &L);
    addLast(o[4], p[4], q[4], &L);
    printElement(L);
    printf("--------------------\n");

    delAfter(L.data[L.first].next, &L);
    delFirst(&L);
    delLast(&L);
    printElement(L);
    printf("--------------------\n");

    delLast(&L);
    printElement(L);
    printf("--------------------\n");

    return 0;
}