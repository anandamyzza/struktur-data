/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM6 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

void createEmpty(stack *S)
{
    (*S).top = NULL;
}

int isEmpty(stack S)
{
    int hasil = 0;

    if (S.top == NULL)
    {
        hasil = 1;
    }
    return hasil;
}

int countElement(stack S)
{
    int hasil = 0;

    if (S.top != NULL)
    {
        /* stack tidak kosong */
        elemen *bantu;

        /* inisialisasi */
        bantu = S.top;
        while (bantu != NULL)
        {
            /* proses */
            hasil = hasil + 1;

            /* iterasi */
            bantu = bantu->next;
        }
    }
    return hasil;
}

void push(char name[], int price, stack *S)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.name, name);

    baru->kontainer.price = price;
    if ((*S).top == NULL)
    {
        // jika stack kosong
        baru->next = NULL;
    }
    else
    {
        // jika stack tidak kosong
        baru->next = (*S).top;
    }
    (*S).top = baru;
    baru = NULL;
}

void pop(stack *S)
{
    if ((*S).top != NULL)
    {
        /*jika stack bukan list kosong*/
        elemen *hapus = (*S).top;

        if (countElement(*S) == 1)
        {
            (*S).top = NULL;
        }
        else
        {
            (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        free(hapus);
    }
    else
    {
        printf("- Stack Kosong\n");
    }
}

void move(stack *Sa, stack *Sb)
{
    if ((*Sa).top != NULL)
    {
        /*jika stack bukan list kosong*/
        elemen *hapus = (*Sa).top;

        if (countElement(*Sa) == 1)
        {
            (*Sa).top = NULL;
        }
        else
        {
            (*Sa).top = (*Sa).top->next;
        }
        hapus->next = (*Sb).top;
        (*Sb).top = hapus;
    }
    else
    {
        printf("- Stack Kosong\n");
    }
}

void printStack(stack S)
{

    if (S.top != NULL)
    {
        elemen *bantu = S.top;

        int i = 1;

        while (bantu != NULL)
        {
            printf("%d. %s\n", i, bantu->kontainer.name);
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else
    {
        /* proses jika stack kosong */
        printf("- Stack Kosong\n");
    }
}