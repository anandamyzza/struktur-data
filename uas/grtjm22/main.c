/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan UAS dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

int main()
{
    /* Deklarasi Variabel */

    int i, n, distance;      // Untuk Iterasi, masukan user, dan jarak.
    char start, destination; // Char untuk nama node yang memiliki hubungan.
    char awal, akhir;        // char untuk node awal dan tujuan.

    graph G;         // Deklarasi graph.
    createEmpty(&G); // Membuat graph kosong.

    scanf("%d", &n); // Meminta masukan user.

    /* Proses Pengulangan untuk Meminta Masukan User */
    for (i = 0; i < n; i++)
    {
        scanf(" %c", &start);             // Meminta node awal.
        if (findSimpul(start, G) == NULL) // Jika node tidak ditemukan di graph.
        {
            addSimpul(start, &G); // Maka add simpul.
        }

        scanf(" %c", &destination);             // Meminta node yang terhubung ke node awal.
        if (findSimpul(destination, G) == NULL) // Jika node tidak ditemukan di graph.
        {
            addSimpul(destination, &G); // Maka add simpul.
        }

        scanf("%d", &distance); // Meminta bobot jarak pada kedua node.

        /* Deklarasi dan Inisialisasi Simpul Awal dan Akhir */
        simpul *begin = findSimpul(start, G);
        simpul *end = findSimpul(destination, G);

        if (begin != NULL && end != NULL) // Jika simpul tidak bernilai NULL.
        {
            addJalur(begin, end, distance); // Maka tambahkan jalur.
        }
    }
    scanf(" %c %c", &awal, &akhir); // Masukan user untuk awal dan tujuan.

    char path[100];        // Deklarasi variabel untuk menampung node yang sudah ter-explore
    jarakTerpanjang = -88; // Inisialisasi jarak

    searching(awal, akhir, path, 0, 0, G); // Memanggil prosedur untuk mencari jarak terpanjang.

    printf("%d\n", jarakTerpanjang); // Print jarak terpanjang.

    return 0;
}