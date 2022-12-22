/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TP5 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

int main()
{
    /* Deklarasi Variabel */
    int i, n, distance;      // Untuk Iterasi, masukan user, dan jarak.
    char start, destination; // Char untuk nama node yang memiliki hubungan.
    char techi, ibu;         // char untuk node awal dan tujuan.

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
    scanf(" %c %c", &techi, &ibu); // Masukan user untuk alamat techi dan dan ibu.

    char path[100];                          // Deklarasi variabel untuk menampung node yang sudah ter-explore.
    possibleLane(techi, ibu, path, 0, 0, G); // Memanggil prosedur untuk mencari jalur yang bisa dilewati Techi untuk Ke Ibunya beserta jarak setiap jalurnya.

    return 0;
}