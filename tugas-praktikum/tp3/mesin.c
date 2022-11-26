/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TP3 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

/* Prosedur untuk Membuat Stack */
void createEmpty(stack *S)
{
    (*S).top = NULL;
}

/* Fungsi untuk Mencari Tahu Apakah Stack Ada atau Kosong */
int isEmpty(stack S)
{
    int hasil = 0; // Deklarasi hasil = 0 sebagai penanda.

    if (S.top == NULL) // Jika Stack topnya bernilai NULL.
    {
        hasil = 1; // Hasil di set bernilai 1 sebagai tanda bahwa Stack kosong.
    }
    return hasil; // Mengembalikan hasil, 0 = Stack Ada, 1 = Stack Kosong.
}

/* Fungsi untuk Proses Menghitung Banyak Elemen pada Stack */
int countElement(stack S)
{
    int hasil = 0;

    /* Jika Stack Tidak Kosong */
    if (S.top != NULL)
    {
        /* Inisialisasi */
        elemen *bantu;
        bantu = S.top;

        while (bantu != NULL) // Selama bantu tidak NULL.
        {
            /*  Maka Lakukan Proses Iterasi */
            hasil = hasil + 1;
            bantu = bantu->next;
        }
    }

    /* Mengembalikan Banyaknya Elemen pada Queue */
    return hasil;
}

/* Prosedur Untuk Memasukan Data ke dalam Stack */
void push(int year, char name[], char band[], stack *S)
{
    /* Deklarasi Elemen Baru */
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    /* Menampung Tahun, Judul, dan Nama Band ke Dalam Elemen Baru */
    baru->kontainer.year = year;
    strcpy(baru->kontainer.name, name);
    strcpy(baru->kontainer.band, band);

    if ((*S).top == NULL) // Jika Stack Kosong.
    {
        baru->next = NULL; // NULL kan baru->next.
    }
    else // Jika Stack berisi.
    {
        baru->next = (*S).top; // Pasngkan baru->next ke top.
    }
    // Lalu pasangkan top dengan elemen baru, dan buat pointer baru di NULL kan.
    (*S).top = baru;
    baru = NULL;
}

/* Prosedur untuk Pop Data dari Stack */
void pop(stack *S)
{
    if ((*S).top != NULL) // Jika Stack tidak kosong.
    {
        /* Deklarasi Elemen Hapus dan Pasangkan dengan Top */
        elemen *hapus = (*S).top;

        if (countElement(*S) == 1) // Jika jumlah elemen 1.
        {
            (*S).top = NULL; // Maka Top di NULL kan.
        }
        else // Jika tidak.
        {
            (*S).top = (*S).top->next; // Maka pasangkan Top dengan Top->next.
        }

        // Lalu copot hapus->next dengan di NULL kan dan free memori.
        hapus->next = NULL;
        free(hapus);
    }
}

/* Prosedur untuk Memindahkan Data dari Stack 1 ke Stack 2 */
void move(stack *Sa, stack *Sb)
{
    if ((*Sa).top != NULL) // Jika Stack tidak kosong.
    {
        /* Deklarasi Elemen Tunjuk dan Pasangkan dengan Top */
        elemen *tunjuk = (*Sa).top;

        if (countElement(*Sa) == 1) // Jika jumlah elemen 1.
        {
            (*Sa).top = NULL; // Maka Top di NULL kan.
        }
        else // Jika tidak.
        {
            (*Sa).top = (*Sa).top->next; // Maka pasangkan Top dengan Top->next.
        }

        // Lalu copot tunjuk->next dan pasangkan pointer ke Stack 2.
        tunjuk->next = (*Sb).top;
        // Lalu pasangkan Top di Stack 2 dengan elemen tunjuk.
        (*Sb).top = tunjuk;
    }
}

/* Prosedur Print untuk Stack */
void printStack(stack S, int status)
{
    /* Kondisi untuk Menentukan apakah Print Rock atau Pop */
    if (status == 0) // Jika status 0, maka print Rock.
    {
        printf("Playlist Musik Rock:\n");
    }
    else if (status == 1) // Jika status 1, maka print Pop.
    {
        printf("Playlist Musik Pop:\n");
    }
    printf("===================\n");

    if (S.top != NULL) // Jika stack tidak kosong.
    {
        /* Inisialisasi */
        elemen *bantu = S.top;
        int i = 1;

        while (bantu != NULL) // Selama bantu bukan NULL
        {
            /* Maka print data berikut */
            printf("%d. %s\n", i, bantu->kontainer.name);

            /* Iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else // Jika stack kosong.
    {
        /* Kondisi Jika Stack Kosong */
        if (status == 0)
        {
            printf("BUKAN ANAK ROCK!\n");
        }
        else if (status == 1)
        {
            printf("BUKAN ANAK POP!\n");
        }
    }
}
