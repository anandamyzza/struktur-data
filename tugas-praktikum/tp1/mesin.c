/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TP1 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

void createList(list *L)
{
    (*L).first = NULL;
}

/* Prosedur untuk Proses Menghitung Berapa Banyak Elemen pada List */
int countElement(list L)
{
    int hasil = 0;

    /* Jika List Tidak Kosong */
    if (L.first != NULL)
    {
        elemen *tunjuk;

        /* Inisialisasi */
        tunjuk = L.first;
        while (tunjuk != NULL)
        {
            /* Iterasi */
            hasil = hasil + 1;
            tunjuk = tunjuk->next;
        }
    }

    /* Mengembalikan Hasil */
    return hasil;
}

/* Prosedur untuk Proses Menambahkan Elemen di Awal List */
void addFirst(char title[], char tv[], double rating, list *L)
{
    /* Deklarasi List Baru */
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.title, title);
    strcpy(baru->kontainer.tv, tv);
    baru->kontainer.rating = rating;

    /* Mencari Data First yang Memiliki NULL */
    if ((*L).first == NULL)
    {
        /* Jika List Kosong, Pasangkan List Baru dengan NULL*/
        baru->next = NULL;
    }
    else
    {
        /* Jika List Tidak Kosong */
        baru->next = (*L).first;
    }

    /* Rubah First dengan Baru */
    (*L).first = baru;
    baru = NULL;
}

/* Prosedur untuk Proses Menambahkan Elemen di Elemen yang Dipilih */
void addAfter(elemen *prev, char title[], char tv[], double rating, list *L)
{
    /* Deklarasi List Baru */
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.title, title);
    strcpy(baru->kontainer.tv, tv);
    baru->kontainer.rating = rating;

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

/* Prosedur untuk Proses Menambahkan Elemen di Elemen Terakhir */
void addLast(char title[], char tv[], double rating, list *L)
{
    /* Jika List Kosong*/
    if ((*L).first == NULL)
    {
        // Memanggil Add First.
        addFirst(title, tv, rating, L);
    }
    /* Jika List Tidak Kosong */
    else
    {
        /* Mencari Elemen Terakhir List*/
        elemen *prev = (*L).first;

        while (prev->next != NULL)
        {
            /* Iterasi */
            prev = prev->next;
        }
        // Lalu memanggil Add First.
        addAfter(prev, title, tv, rating, L);
    }
}

/* Prosedur untuk Proses Menghapus Elemen Pertama */
void delFirst(list *L)
{
    /* Jika List Tidak Kosong */
    if ((*L).first != NULL)
    {
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

/* Prosedur untuk Proses Menghapus Elemen Setelah Elemen yang Dipilih */
void delAfter(elemen *prev)
{
    elemen *hapus = prev->next;

    /* Jika List Tidak Kosong */
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

/* Prosedur untuk Proses Menghapus Elemen Terakhir */
void delLast(list *L)
{
    /* Jika List Tidak Kosong */
    if ((*L).first != NULL)
    {
        if (countElement(*L) == 1)
        {
            delFirst(L);
        }
        else
        {
            /* Mencari Elemen Terakhir dalam List*/
            elemen *last = (*L).first;
            elemen *prev;

            while (last->next != NULL)
            {
                /* Iterasi */
                prev = last;
                last = last->next;
            }
            delAfter(prev);
        }
    }
}

/* Prosedur untuk Proses Print Elemen pada Data List */
void printElement(list L)
{
    /* Jika List Tidak Kosong */
    if (L.first != NULL)
    {
        elemen *tunjuk = L.first;

        while (tunjuk != NULL)
        {
            printf("%s - ", tunjuk->kontainer.title);
            printf("%s\n", tunjuk->kontainer.tv);

            tunjuk = tunjuk->next;
        }
    }
}

/* Prosedur untuk Proses Menghapus Elemen List */
void delAll(list *L)
{
    int i;
    for (i = countElement(*L); i >= 1; i--)
    {

        delLast(L);
    }
}

/* Prosedur untuk Proses Sorting Rating Ascending */
void bubbleAscRate(list *L)
{
    /* Deklarasi Variabel untuk Membantu Proses Sorting */
    int swap;
    elemen *temp;
    elemen *tunjuk;

    temp = (elemen *)malloc(sizeof(elemen));
    tunjuk = (elemen *)malloc(sizeof(elemen));

    /* Proses Pengulangan untuk Sorting Bubble */
    do
    {
        swap = 0;
        tunjuk = (*L).first;

        while (tunjuk->next != NULL)
        {
            if (tunjuk->kontainer.rating > tunjuk->next->kontainer.rating)
            {
                temp->kontainer = tunjuk->kontainer;
                tunjuk->kontainer = tunjuk->next->kontainer;
                tunjuk->next->kontainer = temp->kontainer;
                swap = 1;
            }
            tunjuk = tunjuk->next;
        }
    } while (swap == 1);
}

/* Prosedur untuk Proses Sorting Rating Descending */
void bubbleDescRate(list *L)
{
    /* Deklarasi Variabel untuk Membantu Proses Sorting */
    int swap;
    elemen *temp;
    elemen *tunjuk;

    temp = (elemen *)malloc(sizeof(elemen));
    tunjuk = (elemen *)malloc(sizeof(elemen));

    /* Proses Pengulangan untuk Sorting Bubble */
    do
    {
        swap = 0;
        tunjuk = (*L).first;

        while (tunjuk->next != NULL)
        {
            if (tunjuk->kontainer.rating < tunjuk->next->kontainer.rating)
            {
                temp->kontainer = tunjuk->kontainer;
                tunjuk->kontainer = tunjuk->next->kontainer;
                tunjuk->next->kontainer = temp->kontainer;
                swap = 1;
            }
            tunjuk = tunjuk->next;
        }
    } while (swap == 1);
}

/* Prosedur untuk Proses Sorting Judul Ascending */
void bubbleAscTitle(list *L)
{
    /* Deklarasi Variabel untuk Membantu Proses Sorting */
    int swap;
    elemen *temp;
    elemen *tunjuk;

    temp = (elemen *)malloc(sizeof(elemen));
    tunjuk = (elemen *)malloc(sizeof(elemen));

    /* Proses Pengulangan untuk Sorting Bubble */
    do
    {
        swap = 0;
        tunjuk = (*L).first;

        while (tunjuk->next != NULL)
        {
            if (strcmp(tunjuk->kontainer.title, tunjuk->next->kontainer.title) > 0)
            {
                temp->kontainer = tunjuk->kontainer;
                tunjuk->kontainer = tunjuk->next->kontainer;
                tunjuk->next->kontainer = temp->kontainer;
                swap = 1;
            }
            tunjuk = tunjuk->next;
        }
    } while (swap == 1);
}

/* Prosedur untuk Proses Sorting Judul Descending */
void bubbleDescTitle(list *L)
{
    /* Deklarasi Variabel untuk Membantu Proses Sorting */
    int swap;
    elemen *temp;
    elemen *tunjuk;

    temp = (elemen *)malloc(sizeof(elemen));
    tunjuk = (elemen *)malloc(sizeof(elemen));

    /* Proses Pengulangan untuk Sorting Bubble */
    do
    {
        swap = 0;
        tunjuk = (*L).first;

        while (tunjuk->next != NULL)
        {
            if (strcmp(tunjuk->kontainer.title, tunjuk->next->kontainer.title) < 0)
            {
                temp->kontainer = tunjuk->kontainer;
                tunjuk->kontainer = tunjuk->next->kontainer;
                tunjuk->next->kontainer = temp->kontainer;
                swap = 1;
            }
            tunjuk = tunjuk->next;
        }
    } while (swap == 1);
}