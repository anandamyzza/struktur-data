/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TP3 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

int main()
{
    /* Deklarasi Variabel */
    char name[50], band[50]; // Menampung sementara data inputan judul dan nama band.
    int year;                // Menampung tahun liris lagu.
    int i, n, sum = 0;       // Untuk pengulangan, menampung banyaknya inputan yang ingin diinput user, dan menapung total ASCII yang dimiliki judul lagu.

    /* Deklarasi dan Membuat Stack Kosong */
    stack main;  // Stack Utama.
    stack grock; // Stack untuk lagu genre rock.
    stack gpop;  // Stack untuk lagu genre pop.

    createEmpty(&main);
    createEmpty(&grock);
    createEmpty(&gpop);

    /* Meminta Masukan User */
    scanf("%d", &n);        // Jumlah data yang ingin diinput.
    for (i = 0; i < n; i++) // Pengulangan untuk meminta data dari inputan user.
    {
        scanf("%d %s %s", &year, name, band);
        push(year, name, band, &main);
    }

    /* Proses Memisahkan Lagu Genre Rock dan Pop */
    elemen *tunjuk = main.top; // Deklarasi dan inisialisasi elemen tunjuk.
    while (tunjuk != NULL)     // Selama tunjuk bukan NULL
    {
        // Maka lakukan pengulangan sepanjang string lenght yang dimiliki judul.
        for (i = 0; i < strlen(tunjuk->kontainer.name); i++)
        {
            sum = sum + tunjuk->kontainer.name[i]; // Jumlahkan semua nilai ASCII.
        }
        tunjuk = tunjuk->next; // Iterasi tunjuk

        /* Kondisi Untuk Memisahkan Lagu Genre Rock dan Pop */
        if (sum % 2 == 0) // Jika Totalnya Genap.
        {
            move(&main, &grock); // Maka memanggil prosedur move dan memindahkan data dari stack utama ke stack rock.
        }
        else if (sum % 2 != 0) // Jika Totalnya Ganjil.
        {
            move(&main, &gpop); // Maka memanggil prosedur move dan memindahkan data dari stack utama ke stack pop.
        }
        sum = 0; // Mereset total ASCII ke 0.
    }

    /* Print Data */
    printStack(grock, 0);
    printf("\n");
    printStack(gpop, 1);

    return 0;
}