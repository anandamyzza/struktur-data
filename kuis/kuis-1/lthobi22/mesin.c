/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi KUIS 1 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

void createList(list *L)
{
    (*L).first = NULL;
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

void addFirst(char jenis[], char merk[], char nama[], list *L)
{
    // Bikin list baru
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.jenis, jenis);
    strcpy(baru->kontainer.merk, merk);
    strcpy(baru->kontainer.nama, nama);

    // Cari data first yang memiliki NULL
    if ((*L).first == NULL)
    {
        /*jika list kosong, pasangkan list baru dengan NULL*/
        baru->next = NULL;
    }
    else
    {
        /*jika list tidak kosong*/
        baru->next = (*L).first;
    }

    // Rubah first dengan baru
    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen *prev, char jenis[], char merk[], char nama[], list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.jenis, jenis);
    strcpy(baru->kontainer.merk, merk);
    strcpy(baru->kontainer.nama, nama);

    if (prev->next == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;
}

void addLast(char jenis[], char merk[], char nama[], list *L)
{
    if ((*L).first == NULL)
    {
        /*jika list adalah list kosong*/
        addFirst(jenis, merk, nama, L);
    }
    else
    {
        /*jika list tidak kosong
        /*mencari elemen terakhir list*/
        elemen *prev = (*L).first;
        while (prev->next != NULL)
        {
            /*iterasi*/
            prev = prev->next;
        }
        addAfter(prev, jenis, merk, nama, L);
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
        }
        else
        {
            (*L).first = (*L).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delAfter(elemen *prev)
{
    elemen *hapus = prev->next;
    if (hapus != NULL)
    {
        if (hapus->next == NULL)
        {
            prev->next = NULL;
        }
        else
        {
            prev->next = hapus->next;
            hapus->next = NULL;
        }
        free(hapus);
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
            /*mencari elemen terakhir list*/
            elemen *last = (*L).first;
            elemen *prev;
            while (last->next != NULL)
            {
                /*iterasi*/
                prev = last;
                last = last->next;
            }
            delAfter(prev);
        }
    }
}

void printElement(list L)
{
    if (L.first != NULL)
    {
        /*inisialisasi*/
        elemen *tunjuk = L.first;
        int i = 1;
        while (tunjuk != NULL)
        {
            /*proses*/
            printf("%s ", tunjuk->kontainer.jenis);
            printf("%s ", tunjuk->kontainer.merk);
            printf("%s\n", tunjuk->kontainer.nama);
            /*iterasi*/
            tunjuk = tunjuk->next;
            i = i + 1;
        }
    }
    else
    {
        /*proses jika list kosong*/
        printf("List Kosong.\n");
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

void knockdown(list *L, list *L5)
{
    if ((*L).first != NULL)
    {
        /*inisialisasi*/
        elemen *move = (*L).first;
        elemen *temp;
        while (move != NULL)
        {
            // (*L).first = move->next
            move->next = NULL;
            if ((*L5).first == NULL)
            {
                (*L5).first = move;
                temp = move;
            }
            else
            {
                temp->next = move;
            }
            move = (*L).first;
        }
        // printf("n\n");
    }
}