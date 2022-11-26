/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM4 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

void createList(list *L)
{
    (*L).first = NULL;
    (*L).tail = NULL;
}

int countElement(list L)
{
    int hasil = 0;
    if (L.first != NULL)
    {
        /* list tidak kosong */
        elemen *tunjuk;
        /* inisialisasi */
        tunjuk = L.first;
        while (tunjuk != NULL)
        {
            /* proses */
            hasil = hasil + 1;

            /* iterasi */
            tunjuk = tunjuk->next;
        }
    }

    return hasil;
}

void addFirst(char nama[], char nim[], char goldar[], list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.goldar, goldar);

    if ((*L).first == NULL)
    {

        baru->prev = NULL;
        baru->next = NULL;

        (*L).tail = baru;
    }
    else
    {
        baru->next = (*L).first;
        baru->prev = NULL;

        (*L).first->prev = baru;
    }
    (*L).first = baru;
    baru = NULL;
}

void addBefore(elemen *before, char nama[], char nim[], char goldar[], list *L)
{
    addAfter(before->prev, nama, nim, goldar, L);
}

void addAfter(elemen *before, char nama[], char nim[], char goldar[], list *L)
{
    if (before != NULL)
    {
        elemen *baru;
        baru = (elemen *)malloc(sizeof(elemen));

        strcpy(baru->kontainer.nama, nama);
        strcpy(baru->kontainer.nim, nim);
        strcpy(baru->kontainer.goldar, goldar);

        if (before->next == NULL)
        {
            baru->next = NULL;
            (*L).tail = baru;
        }
        else
        {
            baru->next = before->next;
            baru->next->prev = baru;
        }

        baru->prev = before;
        before->next = baru;
        baru = NULL;
    }
}

void addLast(char nama[], char nim[], char goldar[], list *L)
{

    if ((*L).first == NULL)
    {
        /*jika list adalah list kosong*/
        addFirst(nama, nim, goldar, L);
    }
    else
    {
        /*jika list tidak kosong*/
        addAfter((*L).tail, nama, nim, goldar, L);
    }
}

void delFirst(list *L)
{

    if ((*L).first != NULL)
    {
        /*jika list bukan list kosong*/
        elemen *hapus = (*L).first;

        if (countElement(*L) == 1)
        {
            (*L).first = NULL;
            (*L).tail = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            hapus->next = NULL;
        }

        free(hapus);
    }
}

void delAfter(elemen *before, list *L)
{

    if (before != NULL)
    {
        elemen *hapus = before->next;

        if (hapus != NULL)
        {
            if (hapus->next == NULL)
            {
                L->tail = before;
                before->next = NULL;
            }
            else
            {
                before->next = hapus->next;
                hapus->next->prev = before;
                hapus->next = NULL;
            }

            hapus->prev = NULL;
            free(hapus);
        }
    }
}

void delLast(list *L)
{
    if ((*L).first != NULL)
    {
        /*jika list tidak kosong*/
        if (countElement(*L) == 1)
        {
            /*list terdiri dari satu elemen*/
            delFirst(L);
        }
        else
        {
            /*jika banyak elemen*/
            delAfter((*L).tail->prev, L);
        }
    }
}

void printElement(list L)
{
    if (L.first != NULL)
    {
        /*jika list tidak kosong*/
        /*inisialisasi*/
        elemen *bantu = L.first;
        int i = 1;
        while (bantu != NULL)
        {
            /*proses*/
            printf("%s ", bantu->kontainer.nama);
            printf("%s ", bantu->kontainer.nim);
            printf("%s\n", bantu->kontainer.goldar);

            /*iterasi*/
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else
    {
        /*proses jika list kosong*/
        printf("List Kosong\n");
    }
}

void printReverse(list L)
{
    if (L.tail != NULL)
    {
        /*inisialisasi*/
        elemen *bantu = L.tail;
        int i = 1;
        while (bantu != NULL)
        {
            /*proses*/

            printf("%s ", bantu->kontainer.nama);
            printf("%s ", bantu->kontainer.nim);
            printf("%s\n", bantu->kontainer.goldar);
            // printf("%d\n", i);

            /*iterasi*/
            bantu = bantu->prev;
            i = i + 1;
        }
    }
    else
    {
        /*proses jika listkosong*/
        printf("List Kosong\n");
    }
}

void delAll(list *L)
{
    int i;
    for (i = countElement(*L); i >= 1; i--)
    {
        /*proses menghapus elemen list*/
        delLast(L);
    }
}