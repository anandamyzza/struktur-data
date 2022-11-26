/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM4 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"
// Program membaca kata satu per satu dari pita menggunakan mesin kata.
int main()
{

    list L;

    int i;
    char o[7][50], p[7][50], q[7][50];
    for (i = 0; i < 7; i++)
    {
        scanf("%s %s %s", o[i], p[i], q[i]);
    }

    createList(&L);
    addLast(o[0], p[0], q[0], &L);
    addFirst(o[1], p[1], q[1], &L);
    addBefore(L.first->next, o[2], p[2], q[2], &L);
    printf("Data Golongan Darah\n");
    printf("===================\n");
    printElement(L);
    printf("===================\n");

    addAfter(L.first->next, o[3], p[3], q[3], &L);
    delAfter(L.first, &L);
    addAfter(L.first, o[4], p[4], q[4], &L);
    addBefore(L.tail, o[5], p[5], q[5], &L);
    delFirst(&L);
    printElement(L);
    printf("===================\n");

    delLast(&L);
    delAfter(L.first, &L);
    addLast(o[6], p[6], q[6], &L);
    printReverse(L);
    printf("===================\n");

    delAll(&L);
    printElement(L);

    return 0;
}