/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM3 dalam mata kuliah Struktur Datas
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"
// Program membaca kata satu per satu dari pita menggunakan mesin kata.
int main()
{
    list L;

    int i;
    char o[7][50], p[7][50];
    int q[7];
    for (i = 0; i < 7; i++)
    {
        scanf("%s %s %d", o[i], p[i], &q[i]);
    }

    createList(&L);
    addFirst(o[0], p[0], q[0], &L);
    addLast(o[1], p[1], q[1], &L);
    addAfter(L.first, o[2], p[2], q[2], &L);
    printf("Data Kebun Binatang\n");
    printf("===================\n");
    printElement(L);
    printf("===================\n");

    delAfter(L.data[L.first].next, &L);
    addAfter(L.first, o[3], p[3], q[3], &L);
    addAfter(L.data[L.tail].prev, o[4], p[4], q[4], &L);
    delFirst(&L);
    printElement(L);
    printf("===================\n");

    addFirst(o[5], p[5], q[5], &L);
    addAfter(L.data[L.first].next, o[6], p[6], q[6], &L);
    delLast(&L);
    printReverse(L);
    printf("===================\n");

    delAfter(L.first, &L);
    delAll(&L);
    printElement(L);

    return 0;
}