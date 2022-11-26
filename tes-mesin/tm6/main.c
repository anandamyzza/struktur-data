/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM6 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"
// Program membaca kata satu per satu dari pita menggunakan mesin kata.

int main()
{
    char name[6][50];
    int price[6];
    int i;

    stack S1;
    stack S2;
    createEmpty(&S1);
    createEmpty(&S2);

    for (i = 0; i < 6; i++)
    {
        scanf("%s %d", name[i], &price[i]);
    }

    printf("S1:\n");
    printStack(S1);
    printf("S2:\n");
    printStack(S2);
    printf("==================\n");

    push(name[0], price[0], &S1);
    push(name[1], price[1], &S2);
    push(name[2], price[2], &S2);
    printf("S1:\n");
    printStack(S1);
    printf("S2:\n");
    printStack(S2);
    printf("==================\n");

    pop(&S1);
    move(&S2, &S1);
    push(name[3], price[3], &S1);
    push(name[4], price[4], &S2);
    push(name[5], price[5], &S1);
    pop(&S2);
    move(&S1, &S2);
    printf("S1:\n");
    printStack(S1);
    printf("S2:\n");
    printStack(S2);
    printf("==================\n");

    return 0;
}