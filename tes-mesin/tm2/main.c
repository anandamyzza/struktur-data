/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM2 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"
// Program membaca kata satu per satu dari pita menggunakan mesin kata.
int main()
{
    list L;

    int i;
    char o[6][50], p[6][10], q[6][50];
    for (i = 0; i < 6; i++)
    {
        scanf("%s %s %s", o[i], p[i], q[i]);
    }

    printf("--------------------\n");
    createList(&L);
    addFirst(o[0], p[0], q[0], &L);
    addLast(o[1], p[1], q[1], &L);
    addAfter(L.first->next, o[2], p[2], q[2], &L);
    printElement(L);
    printf("--------------------\n");

    delAfter(L.first->next);
    delFirst(&L);
    delLast(&L);
    printElement(L);
    printf("--------------------\n");

    addFirst(o[3], p[3], q[3], &L);
    addFirst(o[4], p[4], q[4], &L);
    delLast(&L);
    printElement(L);
    printf("--------------------\n");

    delAll(&L);
    printElement(L);
    printf("--------------------\n");

    addLast(o[5], p[5], q[5], &L);
    printElement(L);
    printf("--------------------\n");

    return 0;
}