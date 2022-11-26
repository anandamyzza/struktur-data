/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TP2 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

/* Prosedur untuk Membuat List Dinamis Ganda */
void createList(list *L)
{
    (*L).first = NULL;
    (*L).tail = NULL;
}

/* Prosedur untuk Proses Menghitung Berapa Banyak Elemen pada List */
int countElement(list L)
{
    int hasil = 0;
    /* Jika List Tidak Kosong */
    if (L.first != NULL)
    {
        /* Inisialisasi */
        elemen *tunjuk;
        tunjuk = L.first;

        while (tunjuk != NULL) // Selama tunjuk tidak NULL.
        {
            // Maka lakukan proses iterasi.
            hasil = hasil + 1;
            tunjuk = tunjuk->next;
        }
    }

    /* Mengembalikan Banyaknya Elemen pada List */
    return hasil;
}

/* Prosedur untuk Proses Menambahkan Elemen di Awal List */
void addFirst(char name[], int date, list *L)
{
    /* Deklarasi List Baru */
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    /* Memasukan Nama dan Tanggal ke Dalam Elemen */
    strcpy(baru->kontainer.name, name);
    baru->kontainer.date = date;

    if ((*L).first == NULL) // Jika list kosong.
    {
        // Maka pasangkan list baru dengan NULL.
        baru->prev = NULL;
        baru->next = NULL;
        // Lalu pasangkan L.tail dengan list baru.
        (*L).tail = baru;
    }
    else // Jika tidak.
    {
        // Maka pasangkan list baru dengan elemen pertama.
        baru->next = (*L).first;
        baru->prev = NULL;
        // Lalu pasangkan L.first->prev dengan list baru.
        (*L).first->prev = baru;
    }
    // Lalu pasangkan L.first dengan list baru, dan buat pointer baru di NULL kan.
    (*L).first = baru;
    baru = NULL;
}

/* Prosedur untuk Proses Menghapus Elemen Pertama */
void delFirst(list *L)
{

    /* Jika List Bukan List Kosong*/
    if ((*L).first != NULL)
    {
        elemen *hapus = (*L).first; // Deklarasi elemen hapus lalu pasangkan dengan L.first.

        if (countElement(*L) == 1) // Jika hanya ada 1 elemen dalam list.
        {
            // Maka pasangkan L.first dan L.tail dengan NULL.
            (*L).first = NULL;
            (*L).tail = NULL;
        }
        else // Jika selainnya.
        {
            // Maka pasangkan L.first dengan elemen selanjutnya, dan lepaskan prev dengan di NULL kan.
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            // Lalu lepas pointer next yang hapus tunjuk dengan di NULL kan.
            hapus->next = NULL;
        }
        // Lalu panggil fungsi untuk menghapus data pada memori.
        free(hapus);
    }
}

/* Prosedur untuk Proses Print Elemen pada Data List secara Descending menggunakan Tail */
void printReverse(list L)
{
    if (L.tail != NULL) // Jika list bukan list kosong.
    {
        // Deklarasi dan inisialisasi elemen bantu lalu pasangkan dengan L.tail.
        elemen *bantu = L.tail;
        while (bantu != NULL) // Selama bantunya bukan NULL.
        {
            /* Maka Akan Melakukan Proses Berikut */
            if (bantu->kontainer.date < 10) // Jika tanggalnya kurang dari tanggal 10.
            {
                // Maka '0' akan di print di depan tanggal tersebut.
                printf("0%d ", bantu->kontainer.date);
            }
            else // Jika tidak.
            {
                // Maka akan lakukan print tanggal saja.
                printf("%d ", bantu->kontainer.date);
            }
            // Print nama bahan.
            printf("%s\n", bantu->kontainer.name);

            /* Iterasi */
            bantu = bantu->prev;
        }
    }
    else // Jika listnya kosong.
    {
        printf("-\n"); // Maka print tanda berikut.
    }
}

/* Prosedur untuk Proses Print Elemen untuk Bahan Kadaluarsa */
void printExpired(list L)
{
    /* Deklarasi Variabel */
    int i;
    int count = 0; // Untuk menghitung jumlah data kadaluarsa dalam data bahan.

    if (L.tail != NULL) // Jika list bukan list kosong.
    {
        // Deklarasi dan inisialisasi elemen bantu lalu pasangkan dengan L.tail.
        elemen *bantu = L.tail;
        while (bantu != NULL) // Selama bantunya bukan NULL.
        {
            /* Maka Akan Melakukan Proses Berikut */
            if (bantu->kontainer.date < 9) // Jika tanggalnya kurang dari tanggal 9.
            {
                // Maka data akan di print di bagian bahan kadaluarsa.
                printf("0%d ", bantu->kontainer.date);
                printf("%s\n", bantu->kontainer.name);
                count++; // Iterasi untuk menghitung data kadaluarsa.
            }

            /* Iterasi */
            bantu = bantu->prev;
        }
    }

    /* Jika count atau jumlah bahan kadaluarsanya 0 */
    if (count == 0)
    {
        printf("-\n"); // Maka print tanda berikut.
    }
}

/* Prosedur untuk Proses Print Semua Elemen pada List */
void printAll(list L)
{
    if (L.first != NULL) // Jika list bukan list kosong.
    {
        // Deklarasi dan inisialisasi elemen bantu lalu pasangkan dengan L.first.
        elemen *bantu = L.first;
        while (bantu != NULL) // Selama bantunya bukan NULL.
        {
            /* Maka Akan Melakukan Proses Berikut */
            if (bantu->kontainer.date < 10) // Jika tanggalnya kurang dari tanggal 10.
            {
                // Maka '0' akan di print di depan tanggal tersebut.
                printf("0%d ", bantu->kontainer.date);
            }
            else // Jika tidak.
            {
                // Maka akan lakukan print tanggal saja.
                printf("%d ", bantu->kontainer.date);
            }
            // Print nama bahan.
            printf("%s\n", bantu->kontainer.name);

            /* Iterasi */
            bantu = bantu->next;
        }
    }
    else // Jika list kosong.
    {
        printf("-\n"); // Maka print tanda berikut.
    }
}

/* Prosedur untuk Menghapus Data Bahan Kadaluarsa dari List */
void deleteExpired(list *L)
{
    if ((*L).first != NULL) // Jika list bukan list kosong.
    {
        // Deklarasi dan inisialisasi elemen bantu lalu pasangkan dengan L.first.
        elemen *bantu = (*L).first;
        while (bantu != NULL) // Selama bantunya bukan NULL.
        {
            /* Maka Akan Melakukan Proses Berikut */
            if (bantu->kontainer.date < 9) // Jika tanggal data kurang dari 9.
            {
                delFirst(L);        // Maka panggil delFirst untuk menghapus datanya.
                bantu = (*L).first; // Lalu pasangkan bantu dengan L.first.
            }
            else // Jika selain tanggal kurang dari 9.
            {
                // Maka iterasikan pointer bantu.
                bantu = bantu->next;
            }
        }
    }
}

/* Prosedur untuk Sorting Bahan Secara Ascending dari Urutan Tanggal */
void ascSort(list *L)
{
    /* Deklarasi Variabel untuk Membantu Proses Sorting */
    int swap; // Penanda untuk sorting bubble.
    elemen *after;
    elemen *before;

    /* Proses Pengulangan untuk Sorting Bubble */
    do
    {
        /* Inisialisasi */
        swap = 0;
        before = (*L).first;      // Pasangkan before dengan L.first.
        after = (*L).first->next; // Dan after dengan L.first->next.

        while (after != NULL) // Selama after bukan NULL.
        {
            // Jika elemen 'sebelum' lebih besar tanggalnya dibandingkan elemen 'setelah'.
            if (before->kontainer.date > after->kontainer.date)
            {
                /* Maka Akan Melakukan Proses Berikut */
                if (before == (*L).first) // Jika before bersama L.first.
                {
                    (*L).first = after; // Maka L.first akan dipasangkan dengan after, atau elemen setelah before.

                    /* Syarat Apabila Hanya Ada 2 Elemen pada List */
                    if (after == (*L).tail) // Jika after bersama L.tail.
                    {
                        (*L).tail = before; // Maka L.tail akan dipasangkan dengan before, atau elemen sebelum after.
                    }
                }
                else if (after == (*L).tail) // Jika before berada di tengah list dan after berada di L.tail.
                {
                    (*L).tail = before; // Maka L.tail akan dipasangkan dengan before, atau elemen sebelum after.
                }
                before->next = after->next; // Pasangkan pointer before->next ke pointer after->next (Elemen setelah after).

                if (after->next != NULL) // Jika pointer after->next tidak menunjuk ke NULL.
                {
                    after->next->prev = before; // Maka pasangkan prev elemen setelah after (after->next->prev) ke before.
                }
                after->next = before; // Lalu pasangkan pointer after->next ke before.

                if (before->prev == NULL) // Jika before->prev NULL (Before berada di awal list).
                {
                    after->prev = NULL; // Maka after->prev di NULL kan.
                }
                else // Jika tidak (Before berada di tengah list)
                {
                    after->prev = before->prev; // Maka pointer after->prev akan ditunjukan ke before->prev (Elemen sebelum before)
                    after->prev->next = after;  // Dan after->prev->next ditunjukan ke elemen yang after tunjuk (Sebelumnya menunjuk ke before).
                }

                before->prev = after; // Pasangkan pointer before->prev (Menunjuk ke elemen sebelum after) ke elemen yang after tunjuk.
                after = before->next; // Pindahkan after ke before->next (Elemen setelah before)
                swap = 1;             // Rubah status swap menjadi 1.
            }
            else // Jika elemen 'sebelum' TIDAK lebih besar tanggalnya dibandingkan elemen 'setelah'.
            {
                /* Iterasikan Before dan After */
                before = before->next;
                after = after->next;
            }
        }
    } while (swap == 1); // Pengulangan dilakukan selama status swap bernilai 1.
}

/* Prosedur untuk Sorting Bahan Secara Ascending dari Urutan Nama Bahan */
void ascSortName(list *L)
{
    /* Deklarasi Variabel untuk Membantu Proses Sorting */
    int swap; // Penanda untuk sorting bubble.
    elemen *after;
    elemen *before;

    /* Proses Pengulangan untuk Sorting Bubble */
    do
    {
        /* Inisialisasi */
        swap = 0;
        before = (*L).first;      // Pasangkan before dengan L.first.
        after = (*L).first->next; // Dan after dengan L.first->next.

        while (after != NULL) // Selama after bukan NULL.
        {
            // Jika elemen 'sebelum' lebih besar urutan alfabetnya dibandingkan elemen 'setelah'.
            if (strcmp(before->kontainer.name, after->kontainer.name) > 0)
            {
                /* Maka Akan Melakukan Proses Berikut */
                if (before == (*L).first) // Jika before bersama L.first.
                {
                    (*L).first = after; // Maka L.first akan dipasangkan dengan after, atau elemen setelah before.

                    /* Syarat Apabila Hanya Ada 2 Elemen pada List */
                    if (after == (*L).tail) // Jika after bersama L.tail.
                    {
                        (*L).tail = before; // Maka L.tail akan dipasangkan dengan before, atau elemen sebelum after.
                    }
                }
                else if (after == (*L).tail) // Jika before berada di tengah list dan after berada di L.tail.
                {
                    (*L).tail = before; // Maka L.tail akan dipasangkan dengan before, atau elemen sebelum after.
                }
                before->next = after->next; // Pasangkan pointer before->next ke pointer after->next (Elemen setelah after).

                if (after->next != NULL) // Jika pointer after->next tidak menunjuk ke NULL.
                {
                    after->next->prev = before; // Maka pasangkan prev elemen setelah after (after->next->prev) ke before.
                }
                after->next = before; // Lalu pasangkan pointer after->next ke before.

                if (before->prev == NULL) // Jika before->prev NULL (Before berada di awal list).
                {
                    after->prev = NULL; // Maka after->prev di NULL kan.
                }
                else // Jika tidak (Before berada di tengah list)
                {
                    after->prev = before->prev; // Maka pointer after->prev akan ditunjukan ke before->prev (Elemen sebelum before)
                    after->prev->next = after;  // Dan after->prev->next ditunjukan ke elemen yang after tunjuk (Sebelumnya menunjuk ke before).
                }

                before->prev = after; // Pasangkan pointer before->prev (Menunjuk ke elemen sebelum after) ke elemen yang after tunjuk.
                after = before->next; // Pindahkan after ke before->next (Elemen setelah before)
                swap = 1;             // Rubah status swap menjadi 1.
            }
            else // Jika elemen 'sebelum' TIDAK lebih besar urutan alfabetnya dibandingkan elemen 'setelah'.
            {
                /* Iterasikan Before dan After */
                before = before->next;
                after = after->next;
            }
        }
    } while (swap == 1); // Pengulangan dilakukan selama status swap bernilai 1.
}