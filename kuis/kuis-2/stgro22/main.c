/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi KUIS 2 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

int main()
{
    /* Deklarasi dan Membuat Stack Kosong untuk menampung Ekspedisi Masing-Masing */
    stack S, S1[10];
    createEmpty(&S);
    createEmpty(&S1[10]);

    /* Deklarasi Variabel */
    int i, n, m, w8;                           // Untuk pengulangan, menampung total pengiriman, jumlah ekspedisi yang dibuat stacknya, dan menampung berat paket.
    char name[50], expedition[50], region[50]; // Menampung data pengiriman.
    scanf("%d", &n);                           // Meminta masukan dari user untuk seberapa banyak pengiriman yang ada

    /* Pengulangan untuk Meminta Data Pengiriman dari User */
    for (i = 0; i < n; i++)
    {
        scanf("%s %s %s %d", name, expedition, region, &w8);
        push(name, expedition, region, w8, &S);
    }

    /* Meminta Masukan User untuk Banyaknya Ekspedisi dan Data Ekspedisi Apa Saja yang Dipisah */
    scanf("%d", &m);
    char bench[m][50];
    for (i = 0; i < m; i++)
    {
        scanf("%s", bench[i]);
    }

    /* Proses Memisahkan Data Dari Stack Utama ke Stack Masing-Masing sesuai nama Ekspedisi */
    if (S.top != -1)
    {
        int i, j;
        for (i = S.top; i >= 0; i--)
        {
            for (j = 0; j < m; j++)
            {
                // Jika Nama Ekspedisi sama dengan nama Ekspedisi yang dipisah.
                if (strcmp(S.data[i].expedition, bench[j]) == 0)
                {
                    // Maka memanggil prosedur popPush untuk memindahkan data.
                    popPush(&S, &S1[j]);
                }
            }
        }
    }

    /* Proses Print Seluruh Data */
    for (i = 0; i < m; i++)
    {
        printf("stack %s:\n", bench[i]);
        printStack(S1[i]);
        if (i < m - 1)
        {
            printf("\n");
        }
    }

    return 0;
}