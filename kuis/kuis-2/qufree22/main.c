/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi KUIS 2 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

int main()
{
    /* Deklarasi Queue */
    queue Q1; // Menampung pekerjaan yang menanti.
    queue Q2; // Menampung pekerjaan yang selesai.

    /* Membuat Queue Kosong untuk kedua Queue */
    createEmpty(&Q1);
    createEmpty(&Q2);

    /* Deklarasi Variabel */
    int n, m;               // Menampung total pekerjaan & jumlah pekerjaan yang selesai.
    char name[50], job[50]; // Menampung sementara nama pekerja, dan pekerjaannya.
    int i, num, order;      // Untuk proses pengulangan, tanda untuk printQueue, dan urutan pekerjaan para pekerja.

    scanf("%d", &n); // Meminta masukan user untuk total pekerjaan yang ada.

    /* Pengulangan untuk Meminta Masukan User dan Memasukan Datanya ke dalam Queue Sesuai Prioritas */
    for (i = 0; i < n; i++)
    {
        scanf("%s %s %d", name, job, &order);
        addPriority(name, job, order, order, &Q1);
    }

    scanf("%d", &m); // Meminta masukan user untuk jumlah pekerjaan yang selesai.

    /* Pengulangan untuk Memindahkan Pekerjaan yang Selesai ke Queue Pekerjaan yang Selesai */
    for (i = 0; i < m; i++)
    {
        move(&Q1, &Q2);
    }

    /* Print Hasil */
    printQueue(Q2, 2);
    printf("\n");
    printQueue(Q1, 1);

    return 0;
}