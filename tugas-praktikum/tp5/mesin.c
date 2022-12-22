/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TP5 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

/* Prosedur untuk Membuat Graph Kosong */
void createEmpty(graph *G)
{
    (*G).first = NULL;
}

/* Prosedur untuk Menambahkan Simpul pada Graph */
void addSimpul(char c, graph *G)
{
    /* Deklarasi Simpul Baru */
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));

    /* Inisialisasi */
    baru->kontainer = c;
    baru->next = NULL;
    baru->arc = NULL;

    if ((*G).first == NULL) // Jika graf kosong.
    {
        (*G).first = baru; // Maka baru ditampung ke graph pertama.
    }
    else // Jika tidak.
    {
        simpul *last = (*G).first; // Deklarasi dan Inisialisasi simpul last untuk mencari simpul akhir.

        /* Maka Menambahkan Simpul Baru pada Akhir Graph */
        while (last->next != NULL) // Selama simpul last->next bukan NULL.
        {
            last = last->next; // Maka iterasikan last.
        }
        last->next = baru; // Baru ditampung ke graph terakhir.
    }
}

/* Prosedur untuk Menambahkan Jalur pada Graph */
void addJalur(simpul *awal, simpul *tujuan, int beban)
{
    /* Deklarasi Jalur Baru */
    jalur *baru;
    baru = (jalur *)malloc(sizeof(jalur));

    /* Inisialisasi */
    baru->kontainer_jalur = beban; // Menambahkan jarak dari kedua node.
    baru->next_jalur = NULL;
    baru->tujuan = tujuan;

    if (awal->arc == NULL) // Jika list jalur kosong.
    {
        awal->arc = baru; // Maka baru ditampung ke arc awal.
    }
    else // Jika tidak.
    {
        jalur *last = awal->arc; // Deklarasi dan Inisialisasi simpul last untuk mencari simpul akhir.

        /* Maka Menambahkan Jalur Baru pada Akhir List Jalur */
        while (last->next_jalur != NULL) // Selama simpul last->next_jalur bukan NULL.
        {
            last = last->next_jalur; // Maka iterasikan last.
        }
        last->next_jalur = baru; // Baru ditampung ke akhir list jalur.
    }
}

/* Prosedur untuk Mencari Simpul pada Graph */
simpul *findSimpul(char c, graph G)
{
    /* Deklarasi dan Inisialisasi Simpul */
    simpul *hasil = NULL;
    simpul *bantu = G.first;
    int ketemu = 0; // Variabel untuk status pada pencarian simpul.

    /* Perulangan untuk Mencari Simpul */
    while (bantu != NULL && ketemu == 0) // Selama simpul bantu bukan NULL dan ketemu bernilai 0.
    {
        if (bantu->kontainer == c) // Jika kontainer bantu memiliki char yang sama dengan parameter.
        {
            hasil = bantu; // Maka ubah hasil menjadi bantu.
            ketemu = 1;    // Dan ubah status ketemu.
        }
        else // Jika tidak.
        {
            bantu = bantu->next; // Iterasikan.
        }
    }

    return hasil; // Mengembalikan alamat simpul.
}

/* Prosedur untuk Mencari Jalur yang Mungkin untuk Dilewati oleh Techi untuk Mencapai Node Ibu */
void possibleLane(char awal, char akhir, char path[], int index, int len, graph G)
{
    /* Deklarasi dan Inisialisasi Variabel */
    int status = 0;                      // Variabel untuk penanda apakah node sudah ter-explore atau belum.
    simpul *bantu = findSimpul(awal, G); // Variabel simpul bantu yang menampung alamat node awal.

    path[index] = awal; // Menampung nama node awal pada array path.
    index++;            // Iterasi index.

    if (awal == akhir) // Jika nama node awal sudah sama dengan akhir.
    {
        /* Print Jalur Node yang Dilewati oleh Techi */
        for (int i = 0; i < index; i++)
        {
            printf("%c ", path[i]);
        }
        printf("%d\n", len); // Serta print jaraknya.
    }
    else // Jika masih belum sama.
    {
        jalur *bantu_jalur = bantu->arc; // Deklarasi dan inisialisasi bantu jalur.

        /* Perulangan Mencari Jalur menuju Tujuan */
        while (bantu_jalur != NULL) // Maka Selama Bantu Jalur bukan NULL.
        {
            for (int i = 0; i < index; i++) // Perulangan for sebanyak nilai index.
            {
                /* Syarat untuk Mencari Apakah Node Sudah di Explore atau Belum */
                if (bantu_jalur->tujuan->kontainer == path[i])
                {
                    status = 1; // Jika sudah di explore, maka ubah status.
                }
            }

            if (status == 0) // Jika status bernilai 0, atau belum ada node yang sudah di explore.
            {
                /* Maka Lakukan Proses Rekursif untuk Mencari Node yang Mungkin Menjadi Jalur */
                len = len + bantu_jalur->kontainer_jalur;                                 // Menambahkan jarak sesuai dengan bobot jalur.
                possibleLane(bantu_jalur->tujuan->kontainer, akhir, path, index, len, G); // Rekursif.
                len -= bantu_jalur->kontainer_jalur;                                      // Setelah rekursif selesai, maka jarak dikurangi dengan bobot jalur itu.
            }
            bantu_jalur = bantu_jalur->next_jalur; // Iterasikan bantu_jalur.
        }
    }
    index--; // Kurangi index setiap proses rekursif selesai.
}