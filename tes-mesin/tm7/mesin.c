/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM7 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

void createEmpty(queue *Q)
{
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int isEmpty(queue Q)
{
    int hasil = 0;
    if (Q.first == NULL)
    {
        hasil = 1;
    }
    return hasil;
}

int countElement(queue Q)
{
    int hasil = 0;
    if (Q.first != NULL)
    {
        /* queue tidak kosong */
        elemen *bantu;
        /* inisialisasi */
        bantu = Q.first;
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

void add(char name[], int rate, queue *Q)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.name, name);
    baru->kontainer.rate = rate;

    baru->next = NULL;
    if ((*Q).first == NULL)
    {
        (*Q).first = baru;
    }
    else
    {
        (*Q).last->next = baru;
    }
    (*Q).last = baru;
    baru = NULL;
}

void addPriority(char name[], int rate, int priority, queue *Q)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.name, name);
    baru->kontainer.rate = rate;

    baru->next = NULL;
    if ((*Q).first == NULL)
    {
        (*Q).first = baru;
        (*Q).last = baru;
    }
    else
    {
        if (priority == 1)
        {
            baru->next = (*Q).first;
            (*Q).first = baru;
        }
        else if (priority > countElement(*Q))
        {
            add(name, rate, Q);
        }
        else
        {
            elemen *bantu = (*Q).first;
            int i = 1;
            while (bantu != NULL)
            {
                if (i == priority - 1)
                {
                    baru->next = bantu->next;
                    bantu->next = baru;
                }
                bantu = bantu->next;
                i++;
            }
        }
    }
    baru = NULL;
}

void del(queue *Q1, queue *Q2)
{
    if ((*Q1).first != NULL)
    {
        /* jika queue bukan queue kosong */
        elemen *tunjuk = (*Q1).first;

        if (countElement(*Q1) == 1)
        {
            (*Q1).first = NULL;
            (*Q1).last = NULL;
        }
        else
        {
            (*Q1).first = (*Q1).first->next;
            tunjuk->next = NULL;
        }

        if ((*Q2).first == NULL)
        {
            (*Q2).first = tunjuk;
        }
        else
        {
            (*Q2).last->next = tunjuk;
        }
        (*Q2).last = tunjuk;
        tunjuk = NULL;
    }
}

void printQueue(queue Q, int num)
{
    if (Q.first != NULL)
    {
        printf("******************\n");
        printf("Queue %d\n", num);
        elemen *bantu = Q.first;
        int i = 1;
        while (bantu != NULL)
        {
            printf("%s ", bantu->kontainer.name);
            printf("%d\n", bantu->kontainer.rate);
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else
    {
        /* proses jika queue kosong */
        printf("queue kosong\n");
    }
}