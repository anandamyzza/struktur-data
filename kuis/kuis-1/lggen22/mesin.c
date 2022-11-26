/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM3 dalam mata kuliah Struktur Datas
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

void createList(list *L)
{
    (*L).first = -1;
    (*L).tail = -1;
    int i;

    for (i = 0; i < 100; i++)
    {
        // Inisialisasi isi array elemen.
        (*L).data[i].next = -2;
        (*L).data[i].prev = -2;
    }
}

int countElement(list L)
{
    int hasil = 0;
    if (L.first != -1)
    {
        /* list tidak kosong */
        int hitung;
        /* inisialisasi */
        hitung = L.first;
        while (hitung != -1)
        {
            /* proses */
            hasil = hasil + 1;

            /* iterasi */
            hitung = L.data[hitung].next;
        }
    }

    return hasil;
}

int emptyElement(list L)
{
    int hasil = -1;

    if (countElement(L) < 100)
    {
        int ketemu = 0;
        int i = 0;
        while ((ketemu == 0) && (i < 100))
        {
            if (L.data[i].next == -2)
            {
                hasil = i;
                ketemu = 1;
            }
            else
            {
                i = i + 1;
            }
        }
    }
    return hasil;
}

void addFirst(char code[], char parentCode[], list *L)
{

    if (countElement(*L) < 100)
    {
        // Bikin list baru
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.code, code);
        strcpy((*L).data[baru].kontainer.parentCode, parentCode);

        // Cari data first yang memiliki NULL
        if ((*L).first == -1)
        {
            /*jika list kosong, pasangkan list baru dengan NULL*/
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }
        else
        {
            /*jika list tidak kosong*/
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = (*L).first;
            (*L).data[(*L).first].prev = baru;
        }

        // Rubah first dengan baru
        (*L).first = baru;
    }
    else
    {
        /*proses jika array penuh*/
        printf("sudah tidak dapat ditambah\n");
    }
}

void addAfter(int before, char code[], char parentCode[], list *L)
{
    if (before != -1)
    {
        if (countElement(*L) < 100)
        {
            int baru = emptyElement(*L);
            strcpy((*L).data[baru].kontainer.code, code);
            strcpy((*L).data[baru].kontainer.parentCode, parentCode);

            if ((*L).data[before].next != -1)
            {
                (*L).data[baru].prev = before;
                (*L).data[baru].next = (*L).data[before].next;
                (*L).data[before].next = baru;
                (*L).data[(*L).data[baru].next].prev = baru;
            }
            else
            {
                (*L).data[baru].prev = before;
                (*L).data[before].next = baru;
                (*L).data[baru].next = -1;
                (*L).tail = baru;
            }
        }
        else
        {
            /*proses jika array penuh*/
            printf("sudah tidak dapat ditambah\n");
        }
    }
}

void addLast(char code[], char parentCode[], list *L)
{
    if ((*L).first == -1)
    {
        /*proses jika list masih kosong*/
        addFirst(code, parentCode, L);
    }
    else
    {
        /*proses jika list telah berisi elemen*/
        addAfter((*L).tail, code, parentCode, L);
    }
}

void delFirst(list *L)
{
    if ((*L).first != -1)
    {
        int hapus = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = -1;
            (*L).tail = -1;
        }
        else
        {
            (*L).first = (*L).data[(*L).first].next;
            (*L).data[(*L).first].prev = -1;
        }
        /*elemen awal sebelumnya dikosongkan*/
        (*L).data[hapus].prev = -2;
        (*L).data[hapus].next = -2;
    }
    else
    {
        /*proses jika list kosong*/
        printf("list kosong\n");
    }
}

void delAfter(int before, list *L)
{
    int hapus = (*L).data[before].next;

    if (before != -1)
    {
        if (hapus != -1)
        {
            if ((*L).data[hapus].next == -1)
            {
                (*L).tail = before;
                (*L).data[before].next = -1;
            }
            else
            {
                (*L).data[before].next = (*L).data[hapus].next;
                (*L).data[(*L).data[hapus].next].prev = before;
            }
            /*pengosongan elemen*/
            (*L).data[hapus].prev = -2;
            (*L).data[hapus].next = -2;
        }
    }
}

void delLast(list *L)
{

    if ((*L).first != -1)
    {
        if (countElement(*L) == 1)
        {
            /*proses jika list hanya berisi satu elemen*/
            delFirst(L);
        }
        else
        {
            /*elemen sebelum elemen terakhir menjadi elemen terakhir*/
            delAfter((*L).data[(*L).tail].prev, L);
        }
    }
    else
    {
        /*proses jika list kosong*/
        printf("list kosong\n");
    }
}

void printElement(list L)
{
    if (L.first != -1)
    {
        /*inisialisasi*/
        int bantu = L.first;
        int i = 1;
        while (bantu != -1)
        {
            /*proses*/

            printf("%s ", L.data[bantu].kontainer.code);
            printf("%s\n", L.data[bantu].kontainer.parentCode);

            /*iterasi*/
            bantu = L.data[bantu].next;
            i = i + 1;
        }
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

void swap(list *L, list *L2, int num)
{
    gen temp;
    gen tempA;

    int head = (*L).first;
    int tail = (*L).tail;

    int headA = (*L2).first;
    int tailA = (*L2).tail;

    int i;

    for (i = 0; i < num; i++)
    {
        temp = (*L).data[head].kontainer;
        tempA = (*L2).data[head].kontainer;
        (*L).data[head].kontainer = tempA;
        (*L2).data[head].kontainer = temp;

        temp = (*L).data[tail].kontainer;
        tempA = (*L2).data[tail].kontainer;
        (*L).data[tail].kontainer = tempA;
        (*L2).data[tail].kontainer = temp;

        head = (*L).data[head].next;
        tail = (*L).data[tail].prev;
        headA = (*L2).data[head].next;
        tailA = (*L2).data[tail].prev;
    }
}