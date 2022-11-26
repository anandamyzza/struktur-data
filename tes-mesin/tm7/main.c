/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM7 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"
// Program membaca kata satu per satu dari pita menggunakan mesin kata.

int main()
{
    queue Q1;
    queue Q2;

    createEmpty(&Q1);
    createEmpty(&Q2);

    char name[6][50];
    int i, num, rate[6];

    for (i = 0; i < 6; i++)
    {
        scanf("%s %d", name[i], &rate[i]);
    }

    add(name[0], rate[0], &Q1);
    add(name[1], rate[1], &Q1);
    addPriority(name[2], rate[2], 2, &Q1);
    printQueue(Q1, 1);
    del(&Q1, &Q2);
    printQueue(Q1, 1);
    printQueue(Q2, 2);
    addPriority(name[3], rate[3], 1, &Q1);
    addPriority(name[4], rate[4], 99, &Q1);
    printQueue(Q1, 1);
    del(&Q1, &Q2);
    del(&Q1, &Q2);
    add(name[5], rate[5], &Q1);
    printQueue(Q1, 1);
    printQueue(Q2, 2);
    printf("******************\n");

    return 0;
}