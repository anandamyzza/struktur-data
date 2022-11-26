/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi KUIS 2 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

/* Prosedur untuk Membuat Queue */
void createEmpty(queue *Q)
{
    (*Q).first = NULL;
    (*Q).last = NULL;
}

/* Prosedur untuk Mencari Tahu Apakah Queue Ada atau Kosong */
int isEmpty(queue Q)
{
    int hasil = 0; // Deklarasi hasil = 0 sebagai penanda.

    if (Q.first == NULL) // Jika Queue First nya bernilai null.
    {
        hasil = 1; // Hasil bernilai 1 sebagai tanda bahwa Queue kosong.
    }
    return hasil; // Mengembalikan hasil, 0 = Queue Ada, 1 = Queue Kosong.
}

/* Prosedur untuk Proses Menghitung Berapa Banyak Elemen pada Queue */
int countElement(queue Q)
{
    int hasil = 0;

    /* Jika List Tidak Kosong */
    if (Q.first != NULL)
    {
        /* Inisialisasi */
        elemen *bantu;
        bantu = Q.first;

        while (bantu != NULL) // Selama bantu tidak NULL.
        {
            // Maka lakukan proses iterasi.
            hasil = hasil + 1;
            bantu = bantu->next;
        }
    }

    /* Mengembalikan Banyaknya Elemen pada Queue */
    return hasil;
}

/* Prosedur untuk Proses Menambahkan Elemen pada Queue */
void add(char name[], char job[], int order, queue *Q)
{
    /* Deklarasi Elemen Baru */
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    /* Menampung Nama, Pekerjaan, dan Urutan ke Dalam Elemen Baru */
    strcpy(baru->kontainer.name, name);
    strcpy(baru->kontainer.job, job);
    baru->kontainer.order = order;

    baru->next = NULL;      // Pasangkan Elemen Baru dengan NULL
    if ((*Q).first == NULL) // Jika Queue Kosong.
    {
        (*Q).first = baru; // Pasangkan First dengan elemen baru.
    }
    else // Jika Queue berisi.
    {
        (*Q).last->next = baru; // Pasangkan last->next dengan elemen baru.
    }
    // Lalu pasangkan last dengan elemen baru, dan buat pointer baru di NULL kan.
    (*Q).last = baru;
    baru = NULL;
}

/* Prosedur untuk Proses Menambahkan Elemen pada Queue Sesuai Prioritas */
void addPriority(char name[], char job[50], int order, int priority, queue *Q)
{
    /* Deklarasi Elemen Baru */
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    /* Menampung Nama, Pekerjaan, dan Urutan ke Dalam Elemen Baru */
    strcpy(baru->kontainer.name, name);
    strcpy(baru->kontainer.job, job);
    baru->kontainer.order = order;

    baru->next = NULL;      // Pasangkan Elemen Baru dengan NULL
    if ((*Q).first == NULL) // Jika Queue Kosong.
    {
        // Pasangkan First dan Last dengan elemen baru.
        (*Q).first = baru;
        (*Q).last = baru;
    }
    else // Jika Queue berisi.
    {
        if (priority == 1) // Jika prioritas bernilai 1.
        {
            // Maka elemen baru akan dipasangkan ke first (Urutan pertama).
            baru->next = (*Q).first;
            (*Q).first = baru;
        }
        else if (priority > countElement(*Q)) // Jika prioritas melebihi jumlah elemen pada Queue.
        {
            add(name, job, order, Q); // Maka antrian akan di masukan dengan memanggil prosedur add.
        }
        else // Jika lainnya.
        {
            /* Deklarasi & Inisialisasi Elemen Bantu */
            elemen *bantu = (*Q).first;
            int i = 1;

            while (bantu != NULL) // Selama bantu bukan NULL.
            {
                if (i == priority - 1) // Jika nilai i sama dengan prioritas dikurangi 1.
                {
                    // Maka elemen baru->next dipasangkan dengan elemen bantu->next.
                    baru->next = bantu->next;
                    // Dan pointer bantu->next di pasangkan ke elemen baru.
                    bantu->next = baru;
                }
                /* Iterasi */
                bantu = bantu->next;
                i++;
            }
        }
    }
    // Lalu baru di NULL kan.
    baru = NULL;
}

/* Prosedur untuk Memindahkan Antrian di Q1 ke Q2 */
void move(queue *Q1, queue *Q2)
{
    if ((*Q1).first != NULL) // Jika Q1 bukan queue kosong.
    {
        /* Deklarasi Variabel Tunjuk yang Dipasangkan ke First Q1 */
        elemen *tunjuk = (*Q1).first;

        /* Proses Melepaskan Elemen pada Q1 */
        if (countElement(*Q1) == 1) // Jika jumlah elemen 1.
        {
            // Maka first dan last di NULL kan.
            (*Q1).first = NULL;
            (*Q1).last = NULL;
        }
        else // Jika tidak.
        {
            // Maka Q1 First akan dasangkan ke next, dan tunjuk->next di NULL kan.
            (*Q1).first = (*Q1).first->next;
            tunjuk->next = NULL;
        }

        /* Proses Memasangkan Elemen yang Dilepas dari Q1 ke Q2 */
        if ((*Q2).first == NULL) // Jika jumlah elemen 1.
        {
            // Maka first dipasangkan ke tunjuk.
            (*Q2).first = tunjuk;
        }
        else // Jika tidak.
        {
            // Maka Q2 last->next dipasangkan ke tunjuk.
            (*Q2).last->next = tunjuk;
        }
        // Lalu Q2.last dipasangkan ke tunjuk, dan tunjuk di NULL kan.
        (*Q2).last = tunjuk;
        tunjuk = NULL;
    }
}

/* Prosedur Print untuk Queue */
void printQueue(queue Q, int num)
{
    if (Q.first != NULL) // Jika queue tidak kosong.
    {
        /* Proses Print untuk judul pekerjaan selesai atau menanti */
        if (num == 2)
        {
            printf("pekerjaan yang telah selesai:\n");
        }
        else if (num == 1)
        {
            printf("pekerjaan yang masih menanti:\n");
        }

        /* Inisialisasi */
        elemen *bantu = Q.first;
        int i = 1;

        while (bantu != NULL) // Selama bantu bukan NULL
        {
            /* Maka print data berikut */
            printf("%s ", bantu->kontainer.name);
            printf("%s ", bantu->kontainer.job);
            printf("%d\n", bantu->kontainer.order);

            /* Iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
}