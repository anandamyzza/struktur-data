/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TP2 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

int main()
{
    /* Deklarasi Variabel */
    list L; // Untuk List.
    // Untuk menampung data inputan sementara.
    char o[150];
    int p;
    // Penanda inputan sudah selesai/belum.
    int mark = 0;
    createList(&L); // Memanggil prosedur pembuatan list dinamis

    /* Proses Pengulangan untuk Inputan Data dari User */
    do
    {
        if (mark == 0)
        {
            scanf("%s", &o);
            if (strcmp(o, "--stop--") != 0)
            {
                scanf("%d", &p);
                addFirst(o, p, &L);
            }
            else
            {
                mark = 1;
            }
        }
    } while (mark != 1);

    /* Proses Sorting dan Print Reverse/Descending Data Bahan Dapur */
    printf("==== Inventory Dapur ====\n");
    printf("List semua bahan:\n");
    ascSort(&L);     // Memanggil proses sorting ascending.
    printReverse(L); // Memanggil proses print descending menggunakan tail.

    /* Proses Print dan Penghapusan Data Bahan Kadaluarsa */
    printf("\nList bahan kadaluarsa:\n");
    printExpired(L);   // Memanggil proses print untuk data bahan kadaluarsa.
    deleteExpired(&L); // Memanggil proses penghapusan data kadaluarsa dari list.

    /* Proses Print Data Bahan Sisa */
    printf("\nList bahan sisa:\n");
    if (countElement(L) == 0) // Jika list kosong.
    {
        printf("-\n"); // Maka, print tanda berikut.
    }
    else // Jika tidak.
    {
        ascSortName(&L); // Maka memanggil proses sorting ascending berdasarkan urutan nama.
        printAll(L);     // Lalu, print data bahan sisa.
    }
    printf("=========================\n");

    return 0;
}