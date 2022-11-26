/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM1 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

void createList(list *L)
{
    (*L).first = NULL;
}

int countElementB(list L)
{
    int hasil = 0;
    if (L.first != NULL)
    {
        /*list tidak kosong*/
        eBaris *bantu;
        /*inisialisasi*/
        bantu = L.first;
        while (bantu != NULL)
        {
            /*proses*/
            hasil = hasil + 1;

            /*iterasi*/
            bantu = bantu->next;
        }
    }
    return hasil;
}

int countElementK(eBaris L)
{
    int hasil = 0;
    if (L.col != NULL)
    {
        /*list tidak kosong*/
        eKolom *bantu;
        /*inisialisasi*/
        bantu = L.col;
        while (bantu != NULL)
        {
            /*proses*/
            hasil = hasil + 1;

            /*iterasi*/
            bantu = bantu->next_kol;
        }
    }
    return hasil;
}

void addFirstB(char code[], char name[], list *L)
{
    eBaris *baru;
    baru = (eBaris *)malloc(sizeof(eBaris));

    strcpy(baru->kontainer.code, code);
    strcpy(baru->kontainer.name, name);
    baru->col = NULL;

    if ((*L).first == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void addFirstK(char codeCorp[], char zat[], int month, int year, eBaris *L)
{
    eKolom *baru;
    baru = (eKolom *)malloc(sizeof(eKolom));

    strcpy(baru->kontainer_kol.codeCorp, codeCorp);
    strcpy(baru->kontainer_kol.zat, zat);
    baru->kontainer_kol.month = month;
    baru->kontainer_kol.year = year;

    if ((*L).col == NULL)
    {
        baru->next_kol = NULL;
    }
    else
    {
        baru->next_kol = (*L).col;
    }
    (*L).col = baru;
    baru = NULL;
}

void addAfterB(eBaris *prev, char code[], char name[])
{
    eBaris *baru;
    baru = (eBaris *)malloc(sizeof(eBaris));

    strcpy(baru->kontainer.code, code);
    strcpy(baru->kontainer.name, name);
    baru->col = NULL;

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

void addAfterK(eKolom *prev, char codeCorp[], char zat[], int month, int year)
{
    eKolom *baru;
    baru = (eKolom *)malloc(sizeof(eKolom));

    strcpy(baru->kontainer_kol.codeCorp, codeCorp);
    strcpy(baru->kontainer_kol.zat, zat);
    baru->kontainer_kol.month = month;
    baru->kontainer_kol.year = year;

    if (prev->next_kol == NULL)
    {
        baru->next_kol = NULL;
    }
    else
    {
        baru->next_kol = prev->next_kol;
    }

    prev->next_kol = baru;
    baru = NULL;
}

void addLastB(char code[], char name[], list *L)
{
    if ((*L).first == NULL)
    {
        /*jika list adalah list kosong*/
        addFirstB(code, name, L);
    }
    else
    {
        /*jika list tidak kosong*/
        /*mencari elemen terakhir list*/
        eBaris *last = (*L).first;
        while (last->next != NULL)
        {
            /*iterasi*/
            last = last->next;
        }
        addAfterB(last, code, name);
    }
}

void addLastK(char codeCorp[], char zat[], int month, int year, eBaris *L)
{
    if ((*L).col == NULL)
    {
        /*jika list adalah list kosong*/
        addFirstK(codeCorp, zat, month, year, L);
    }
    else
    {
        /*jika list tidak kosong*/
        /*mencari elemen terakhir list*/
        eKolom *last = (*L).col;
        while (last->next_kol != NULL)
        {
            /*iterasi*/
            last = last->next_kol;
        }
        addAfterK(last, codeCorp, zat, month, year);
    }
}

void delFirstK(eBaris *L)
{
    if ((*L).col != NULL)
    {
        /*jika list bukan list kosong*/
        eKolom *hapus = (*L).col;
        if (countElementK(*L) == 1)
        {
            (*L).col = NULL;
        }
        else
        {
            (*L).col = (*L).col->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

void delAfterK(eKolom *prev)
{
    eKolom *hapus = prev->next_kol;
    if (hapus != NULL)
    {
        if (hapus->next_kol == NULL)
        {
            prev->next_kol = NULL;
        }
        else
        {
            prev->next_kol = hapus->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

void delLastK(eBaris *L)
{
    if ((*L).col != NULL)
    {
        /*jika list tidak kosong*/
        if (countElementK(*L) == 1)
        {
            /*list terdiri dari satu
            elemen*/
            delFirstK(L);
        }
        else
        {
            /*mencari elemen terakhir list*/
            eKolom *last = (*L).col;
            eKolom *before_last;

            while (last->next_kol != NULL)
            {
                /*iterasi*/
                before_last = last;
                last = last->next_kol;
            }
            delAfterK(before_last);
        }
    }
}

void delAllK(eBaris *L)
{
    if (countElementK(*L) != 0)
    {
        int i;
        for (i = countElementK(*L); i >= 1; i--)
        {
            /*proses menghapus elemen list*/
            delLastK(L);
        }
    }
}

void delFirstB(list *L)
{
    if ((*L).first != NULL)
    {
        /*jika list bukan list kosong*/
        eBaris *hapus = (*L).first;
        if (hapus->col != NULL)
        {
            // menghapus semua elemen kolom jika ada
            delAllK(hapus);
        }
        if (countElementB(*L) == 1)
        {
            (*L).first = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
        }
        hapus->next = NULL;
        free(hapus);
    }
    else
    {
        printf("list kosong");
    }
}

void delAfterB(eBaris *prev)
{
    if (prev != NULL)
    {
        eBaris *hapus = prev->next;
        if (hapus != NULL)
        {
            if (hapus->col != NULL)
            {
                // menghapus semua elemen kolom jika ada
                delAllK(hapus);
            }
            if (hapus->next == NULL)
            {
                prev->next = NULL;
            }
            else
            {
                prev->next = hapus->next;
            }
            hapus->next = NULL;
            free(hapus);
        }
    }
}

void delLastB(list *L)
{
    if ((*L).first != NULL)
    {
        /*jika list tidak kosong*/
        if (countElementB(*L) == 1)
        {
            /*list terdiri dari satu
            elemen*/
            delFirstB(L);
        }
        else
        {
            /*mencari elemen terakhir list*/
            eBaris *last = (*L).first;
            eBaris *before_last;
            while (last->next != NULL)
            {
                /*iterasi*/
                before_last = last;
                last = last->next;
            }
            delAfterB(before_last);
        }
    }
}

void delAllB(list *L)
{
    if (countElementB(*L) != 0)
    {
        int i;
        for (i = countElementB(*L); i >= 1; i--)
        {
            /*proses menghapus elemen list*/
            delLastB(L);
        }
    }
}

void printElement(list L)
{
    if (L.first != NULL)
    {
        /*jika list tidak kosong*/
        /*inisialisasi*/
        eBaris *bantu = L.first;
        int i = 1;
        while (bantu != NULL)
        {
            /*proses*/
            printf("%s %s\n", bantu->kontainer.code, bantu->kontainer.name);
            eKolom *eCol = bantu->col;
            while (eCol != NULL)
            {
                printf("- %s %s ", eCol->kontainer_kol.codeCorp, eCol->kontainer_kol.zat);
                printf("%d %d\n", eCol->kontainer_kol.month, eCol->kontainer_kol.year);
                eCol = eCol->next_kol;
            }
            /*iterasi*/
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else
    {
        /*proses jika list kosong*/
        printf("list kosong\n");
    }
}

eBaris *getBaris(list L, char code[])
{
    eBaris *bantu = L.first; // menunjuk ke baris pertama
    while (bantu != NULL)
    {
        // selama belum mencapai elemen akhir
        // dan baris yg dicari belum ditemukan
        if (strcmp(bantu->kontainer.code, code) == 0)
        {
            // jika ketemu, kembalikan alamat elemen
            return bantu;
        }
        bantu = bantu->next;
    }
    return NULL;
}

eKolom *getKolom(eBaris *L, char zat[], int month, int year)
{
    eKolom *bantu = (*L).col;
    while (bantu != NULL)
    {
        if (strcmp(bantu->kontainer_kol.zat, zat) == 0 && bantu->kontainer_kol.month == month && bantu->kontainer_kol.year == year)
        {
            return bantu;
        }
        bantu = bantu->next_kol;
    }
    return NULL;
}

// /* Mengambil Alamat Elemen Terakhir */
eKolom *getLastKolom(eBaris *L)
{
    eKolom *last = (*L).col; // menunjuk ke kolom pertama
    while (last->next_kol != NULL)
    {
        // selama next elemen nya bukan null
        last = last->next_kol;
    }
    // kembalikan alamat elemen
    return last;
}

void switchKol(eBaris *temp, eKolom *tunjuk, list *L)
{
    eBaris *main = temp;
    eBaris *last = getBaris(*L, "org");
    // mencari alamat kolom terakhi
    eKolom *lastKol = getLastKolom(last);
    // menunjuk ke elemen pertama
    // eKolom *swap = main->col;

    if (last->col == NULL)
    {
        main->col = tunjuk->next_kol;
        tunjuk->next_kol = last->col;
        last->col = tunjuk;
    }
    else
    {
        main->col = tunjuk->next_kol;
        tunjuk->next_kol = lastKol->next_kol;
        lastKol->next_kol = tunjuk;
    }
}

void swap(list *L, char zat[], int month, int year)
{
    if ((*L).first != NULL)
    {
        /*jika list tidak kosong*/
        /*inisialisasi*/
        eBaris *temp = (*L).first;
        int i = 1;
        while (temp->next != NULL)
        {
            /*proses*/
            eKolom *bantu = getKolom(temp, zat, month, year);
            if (bantu != NULL)
            {
                switchKol(temp, bantu, L);
            }
            /*iterasi*/
            temp = temp->next;
            i = i + 1;
        }
    }
}