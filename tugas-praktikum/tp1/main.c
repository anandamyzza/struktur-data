/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TP1 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

int main()
{
    /* Deklarasi Variabel */
    list L; // Untuk List.
    int i;  // Untuk pengulangan for.
    // Untuk menampung data inputan sementara.
    char o[150], p[150];
    double q;
    // Penanda inputan sudah selesai/belum.
    int mark = 0;

    /* Proses Pengulangan untuk Inputan Data dari User */
    do
    {
        if (mark == 0)
        {
            scanf("%s", &o);
            if (strcmp(o, "-") != 0)
            {
                scanf("%s %lf", &p, &q);
                addFirst(o, p, q, &L);
            }
            else
            {
                mark = 1;
            }
        }
    } while (mark != 1);

    /* Deklarasi Variabel untuk Menampung Opsi Sorting */
    char option[10];
    char sorting[10];

    /* Meminta Masukan dari User untuk Opsi Sorting dari Judul/Rating */
    scanf("%s %s", &option, &sorting);

    /* Syarat "Jika" untuk Sorting apabila User memilih Judul/Rating dan Asc/Desc */
    if (strcmp(option, "judul") == 0)
    {
        if (strcmp(sorting, "asc") == 0)
        {
            bubbleAscTitle(&L);
        }
        else if (strcmp(sorting, "desc") == 0)
        {
            bubbleDescTitle(&L);
        }
    }
    else if (strcmp(option, "rating") == 0)
    {
        if (strcmp(sorting, "asc") == 0)
        {
            bubbleAscRate(&L);
        }
        else if (strcmp(sorting, "desc") == 0)
        {
            bubbleDescRate(&L);
        }
    }

    /* Print Hasil */
    printElement(L);

    return 0;
}