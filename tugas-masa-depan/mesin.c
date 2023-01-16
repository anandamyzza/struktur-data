/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

/* Variabel Global */
int spaceDcd[100];
int line;

/* Prosedur untuk Membuat Tree */
void makeTree(char c[], int p, int m, char mats[][200], tree *T)
{
    /* Deklarasi Simpul Node */
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));

    /* Inisialisasi & Mengisi Simpul dengan Data Masukan User */
    strcpy(node->name, c); // Menampung nama inputan user ke simpul node.
    node->descendant = 0;  // Inisialisasi angka keturunan.
    node->price = p;       // Menampung harga inputan user ke simpul node.
    node->totalIngred = m; // Menampung banyaknya bahan inputan user ke simpul node.

    /* Perulangan untuk Menampung Nama Bahan-bahan ke Simpul Node */
    for (int i = 0; i < m; i++)
    {
        strcpy(node->ingredients[i], mats[i]);
    }

    /* Inisialisasi Simpul dengan NULL */
    node->sibling = NULL;
    node->child = NULL;
    node->parent = NULL;
    (*T).root = node; // Menampung data pada node ke root.
}

/* Prosedur untuk Menambahkan Child pada Parent */
void addChild(char c[], int p, int m, char mats[][200], simpul *root)
{
    if (root != NULL) // Jika simpul root tidak kosong.
    {                 // Simpul anak dapat ditambahkan.
        /* Deklarasi Simpul Baru */
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));

        /* Inisialisasi & Mengisi Simpul dengan Data Masukan User */
        strcpy(baru->name, c);                   // Menampung nama inputan user ke simpul baru.
        baru->price = p;                         // Menampung harga inputan user ke simpul baru.
        baru->totalIngred = m;                   // Menampung banyaknya bahan inputan user ke simpul baru.
        baru->descendant = root->descendant + 1; // Menampung dan menambahkan 1 angka keturunan berdasarkan angka keturunan sebelumnya.
        baru->parent = root;                     // Pasangkan simpul parent ke lokasi root, sehingga child memiliki simpul parent.

        /* Perulangan untuk Menampung Nama Bahan-bahan ke Simpul Baru */
        for (int i = 0; i < m; i++)
        {
            strcpy(baru->ingredients[i], mats[i]);
        }
        baru->child = NULL; // NULL untuk child nya.

        /* Kondisi untuk Menambahkan Simpul Anak */
        if (root->child == NULL) // Jika simpul root belum memiliki simpul anak.
        {
            // Maka simpul baru menjadi anak pertama.
            baru->sibling = NULL;
            root->child = baru;
        }
        else // Jika sudah memiliki simpul anak.
        {
            if (root->child->sibling == NULL) // Jika simpul root memiliki anak yang belum memiliki saudara.
            {
                // Maka simpul baru menjadi anak kedua.
                baru->sibling = root->child;
                root->child->sibling = baru;
            }
            else // Jika tidak.
            {
                simpul *last = root->child; // Simpul untuk pointer anak terakhir.

                while (last->sibling != root->child) // Maka, selama simpul anak terakhir tidak memiliki simpul anak pertama (NOTE: Simpul anak terakhir adalah yang memiliki sibling simpul anak pertama).
                {
                    last = last->sibling; // Maka akan mencari simpul anak terakhir. Selama belum sampai pada simpul anak terakhir,
                }                         // Penunjuk last akan berjalan ke simpul anak berikutnya.

                // Simpul anak terakhir dikaitkan dengan simpul baru sebagai simpul anak terakhir yang baru.
                baru->sibling = root->child;
                last->sibling = baru;
            }
        }
    }
}

/* Prosedur untuk Menghapus Semua Isi Simpul berdasarkan Akar yang menjadi Parameternya */
void delAll(simpul *root)
{
    if (root != NULL) // Jika simpul root tidak kosong.
    {
        if (root->child != NULL) // Dan jika root memiliki child.
        {
            if (root->child->sibling == NULL) // Dan jika hanya memiliki satu simpul anak.
            {
                delAll(root->child); // Maka lakukan proses rekursif untuk menghapus anak yang dimiliki root.
                free(root);          // Lalu free memory.
            }
            else // Jika memiliki sibling.
            {
                /* Deklarasi Variabel untuk Membantu Proses Hapus */
                simpul *bantu, *proses;

                bantu = root->child;                  // Inisialisasi anak dalam root.
                while (bantu->sibling != root->child) // Maka, selama simpul anak terakhir tidak memiliki simpul anak pertama.
                {
                    proses = bantu;         // Menampung alamat bantu pada proses.
                    bantu = bantu->sibling; // Lalu lakukan iterasi pada bantu.
                    delAll(proses);         // Lalu memanggil delAll() untuk mengapus node proses.
                }
                free(root); // Lalu free memory.
            }
        }
        else // Jika tidak.
        {
            free(root); // Lalukan free memory.
        }
    }
}

/* Prosedur untuk Menghapus Anak pada Parent */
void delChild(simpul *search, simpul *root)
{
    if (root != NULL) // Jika simpul root tidak kosong.
    {
        simpul *hapus = root->child; // Deklarasi simpul hapus yang dikaitkan pada root->child.
        if (hapus != NULL)           // Jika simpul hapus tidak kosong.
        {
            if (hapus->sibling == NULL) // Dan jika hanya mempunyai satu anak.
            {
                if (root->child == search) // Jika simpul root->child sama dengan simpul search.
                {
                    delAll(root->child); // Maka memanggil delAll() untuk menghapus anak tersebut.
                    root->child = NULL;  // Lalu NULL kan.
                }
            }
            else // Namun jika memiliki lebih dari satu simpul anak.
            {
                /* Maka akan Mencari Simpul yang akan Dihapus */
                simpul *prev = NULL; // Deklarasi simpul prev yang NULL.
                int ketemu = 0;      // Variabel kondisi.

                while (hapus->sibling != root->child && ketemu == 0) // Maka, selama simpul anak terakhir tidak memiliki simpul anak pertama.
                {                                                    // Dan variabel ketemu bernilai 0.
                    if (hapus == search)
                    {               // Jika simpul anak yang ditunjuk hapus sama dengan simpul search.
                        ketemu = 1; // Maka kondisi berubah.
                    }
                    else // Jika tidak.
                    {
                        // Lakukan proses iterasi.
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }

                /* Memproses Simpul Anak Terakhir karena Belum Terproses dalam Pengulangan */
                if (ketemu == 0 && hapus == search)
                {               // Jika ketemu bernilai 0 dan pointer hapus memiliki alamat yang sama dengan search.
                    ketemu = 1; // Maka kondisi berubah menjadi 1.
                }

                if (ketemu == 1) // Jika Ketemu bernilai 1.
                {
                    simpul *last = root->child; // Simpul untuk pointer anak terakhir.

                    /* Mencari Simpul Anak Terakhir */
                    /* Untuk Membantu Proses atau Pemeriksaan Jika yang Dihapus adalah Anak Terakhir */
                    while (last->sibling != root->child) // Maka, selama simpul anak terakhir tidak memiliki simpul anak pertama.
                    {
                        last = last->sibling; // Maka akan mencari simpul anak terakhir. Selama belum sampai pada simpul anak terakhir,
                    }                         // Penunjuk last akan berjalan ke simpul anak berikutnya.

                    if (prev == NULL) // Jika simpul yang dihapus anak pertama.
                    {
                        if (hapus->sibling == last && last->sibling == root->child) // Jika hanya ada dua anak.
                        {
                            root->child = last;
                            last->sibling = NULL;
                        }
                        else // Jika memiliki simpul anak lebih dari dua simpul.
                        {
                            root->child = hapus->sibling;
                            last->sibling = root->child;
                        }
                    }
                    else // Jika lainnya.
                    {
                        if (prev->sibling == last && prev == root->child) // Jika hanya ada dua simpul anak dan yang dihapus adalah simpul anak kedua.
                        {
                            root->child->sibling = NULL;
                        }
                        else // Jika yang dihapus bukan simpul anak pertama dan simpul root memiliki simpul anak lebih dari dua simpul.
                        {
                            prev->sibling = hapus->sibling;
                            hapus->sibling = NULL;
                        }
                    }
                    delAll(hapus); // Memanggil delAll() untuk menghapus anak.
                }
            }
        }
    }
}

/* Fungsi untuk Mencari Alamat Simpul pada Tree menggunakan Variabel Character */
simpul *findSimpulChar(char tujuan[], simpul *root)
{
    simpul *hasil = NULL; // Deklarasi variabel untuk menampung alamat simpul yang dicari.

    if (root != NULL) // Jika simpul root tidak kosong.
    {
        if (strcmp(root->name, tujuan) == 0) // Dan jika root memiliki string yang sama dengan tujuan.
        {
            hasil = root; // Maka alamat root ditampung ke hasil.
        }
        else // Jika tidak.
        {
            simpul *bantu = root->child; // Deklarasi variabel untuk membantu mencari alamat simpul yang dicari.

            if (bantu != NULL) // Jika simpul bantu tidak kosong.
            {
                if (bantu->sibling == NULL) // Jika memiliki satu simpul anak.
                {
                    if (strcmp(bantu->name, tujuan) == 0) // Dan jika bantu memiliki string yang sama dengan tujuan.
                    {
                        hasil = bantu; // Maka alamat bantu ditampung ke hasil.
                    }
                    else // Jika tidak.
                    {
                        hasil = findSimpulChar(tujuan, bantu); // Maka menampung hasil findSimpul() ke hasil menggunakan rekursif.
                    }
                }
                else // Jika memiliki banyak simpul anak.
                {
                    int ketemu = 0; // Variabel kondisi.
                    /* Mencari Simpul Anak Terakhir */
                    while (bantu->sibling != root->child && ketemu == 0)
                    {
                        if (strcmp(bantu->name, tujuan) == 0) // Jika bantu memiliki string yang sama dengan tujuan.
                        {
                            hasil = bantu; // Maka alamat bantu ditampung ke hasil.
                            ketemu = 1;    // Dan ubah kondisi ketemu.
                        }
                        else // Jika tidak.
                        {
                            hasil = findSimpulChar(tujuan, bantu); // Maka menampung hasil findSimpulChar() ke hasil menggunakan rekursif.
                            bantu = bantu->sibling;                // Lalu lakukan iterasi pada pointer bantu.

                            if (hasil != 0) // Jika hasil bernilai selain 0.
                            {
                                ketemu = 1; // Maka ubah kondisi ketemu.
                            }
                        }
                    }

                    /* Memproses Simpul Anak Terakhir karena Belum Terproses Dalam Pengulangan */
                    if (ketemu == 0) // Jika ketemu bernilai 0.
                    {
                        if (strcmp(bantu->name, tujuan) == 0) // Dan jika bantu memiliki string yang sama dengan tujuan.
                        {
                            hasil = bantu; // Maka alamat bantu ditampung ke hasil.
                        }
                        else // Jika tidak.
                        {
                            hasil = findSimpulChar(tujuan, bantu); // Maka menampung hasil findSimpulChar() ke hasil menggunakan rekursif.
                        }
                    }
                }
            }
        }
    }
    return hasil; // Mengembalikan alamat simpul yang dicari.
}

/* Fungsi untuk Mencari Alamat Simpul pada Tree menggunakan Variabel Integer */
simpul *findSimpulInt(int tujuan, simpul *root)
{
    simpul *hasil = NULL; // Deklarasi variabel untuk menampung alamat simpul yang dicari.

    if (root != NULL) // Jika simpul root tidak kosong.
    {
        if (root->price < tujuan) // Dan jika harga yang dimiliki root kurang dari tujuan.
        {
            hasil = root; // Maka alamat root ditampung ke hasil.
        }
        else // Jika tidak.
        {
            simpul *bantu = root->child; // Deklarasi variabel untuk membantu mencari alamat simpul yang dicari.

            if (bantu != NULL) // Jika simpul bantu tidak kosong.
            {
                if (bantu->sibling == NULL) // Jika memiliki satu simpul anak.
                {
                    if (root->price < tujuan) // Dan jika harga yang dimiliki root kurang dari tujuan.
                    {
                        hasil = bantu; // Maka alamat bantu ditampung ke hasil.
                    }
                    else // Jika tidak.
                    {
                        hasil = findSimpulInt(tujuan, bantu); // Maka menampung hasil findSimpulInt() ke hasil menggunakan rekursif.
                    }
                }
                else // Jika memiliki banyak simpul anak.
                {
                    int ketemu = 0; // Variabel kondisi.
                    /* Mencari Simpul Anak Terakhir */
                    while (bantu->sibling != root->child && ketemu == 0)
                    {
                        if (root->price < tujuan) // Dan jika harga yang dimiliki root kurang dari tujuan.
                        {
                            hasil = bantu; // Maka alamat bantu ditampung ke hasil.
                            ketemu = 1;    // Dan ubah kondisi ketemu.
                        }
                        else // Jika tidak.
                        {
                            hasil = findSimpulInt(tujuan, bantu); // Maka menampung hasil findSimpulInt() ke hasil menggunakan rekursif.
                            bantu = bantu->sibling;               // Lalu lakukan iterasi pada pointer bantu.

                            if (hasil != 0) // Jika hasil bernilai selain 0.
                            {
                                ketemu = 1; // Maka ubah kondisi ketemu.
                            }
                        }
                    }

                    /* Memproses Simpul Anak Terakhir karena Belum Terproses Dalam Pengulangan */
                    if (ketemu == 0) // Jika ketemu bernilai 0.
                    {
                        if (root->price < tujuan) // Dan jika harga yang dimiliki root kurang dari tujuan.
                        {
                            hasil = bantu; // Maka alamat bantu ditampung ke hasil.
                        }
                        else // Jika tidak.
                        {
                            hasil = findSimpulInt(tujuan, bantu); // Maka menampung hasil findSimpulInt() ke hasil menggunakan rekursif.
                        }
                    }
                }
            }
        }
    }
    return hasil; // Mengembalikan alamat simpul yang dicari.
}

/* Prosedur untuk Print Tree Pre Order */
void printTreePreOrder(simpul *root)
{
    if (root != NULL) // Jika simpul root tidak kosong.
    {
        if (line > 0) // Jika line bernilai lebih dari 0.
        {
            printf("\n"); // Maka print newline.
        }

        /* Print Nama Makanan dan Harganya */
        if (root->descendant != 0) // Jika root->descendant tidak bernilai 0 (akar/angka keturunan 0).
        {
            printSpace(root->descendant); // Maka memanggil prosedur printSpace() dengan parameter root-descendant (Angka keturunan yang memiliki nilai lebih dari 0).
        }
        printf("|%s - %d\n", root->name, root->price); // Lalu print nama serta harga nama makanan.

        /* Print Bahan-bahan yang dimiliki Makanan */
        for (int i = 0; i < root->totalIngred; i++) // Perulangan selama banyaknya bahan-bahan yang ada.
        {
            if (root->descendant != 0) // Jika root->descendant tidak bernilai 0 (akar/angka keturunan 0).
            {
                printSpace(root->descendant); // Maka memanggil prosedur printSpace() dengan parameter root-descendant (Angka keturunan yang memiliki nilai lebih dari 0).
            }
            printf(" - %s\n", root->ingredients[i]); // Lalu print nama bahan-bahan makanannya.
        }
        line++; // Iterasikan jumlah line sebagai penanda untuk proses newline.

        simpul *bantu = root->child; // Deklarasi variabel untuk membantu mencari alamat simpul yang dicari.

        if (bantu != NULL) // Jika simpul bantu tidak kosong.
        {
            if (bantu->sibling == NULL) // Jika memiliki satu simpul anak.
            {
                printTreePreOrder(bantu); // Maka lakukan proses rekursif.
            }
            else // Jika memiliki banyak simpul anak.
            {
                /* Memproses Simpul Anak Terakhir karena Belum Terproses dalam Pengulangan */
                while (bantu->sibling != root->child) // Maka, selama simpul anak terakhir tidak memiliki simpul anak pertama.
                {
                    printTreePreOrder(bantu); // Maka lakukan proses rekursif.
                    bantu = bantu->sibling;   // Setelah rekursif selesai, maka lakukan iterasi pada simpul bantu.
                }
                printTreePreOrder(bantu); // Lakukan proses rekursif lagi.
            }
        }
    }
}

/* Prosedur untuk Mencari String Terpanjang untuk Keperluan Spasi */
void countSpace(simpul *root)
{
    if (root != NULL) // Jika simpul root tidak kosong.
    {
        /* Menghitung Digit pada Harga */
        // ∟ Inisialisasi
        int digit = 0;
        int cost = root->price;
        while (cost > 0) // Selama costnya masih bernilai lebih dari 0.
        {
            cost /= 10; // Cost akan dibagi 10.
            digit++;    // Dan jumlah digit bertambah 1.
        }

        /* Mencari String Terpanjang */
        int lenName = strlen(root->name) + digit + 4; // Deklarasi variabel lenName yang menampung panjang nama serta digit harga makanan.
        for (int i = 0; i < root->totalIngred; i++)   // Perulangan untuk mencari string terpanjang di nama bahan makanan.
        {
            int lenIngred = strlen(root->ingredients[i]) + 4; // Deklarasi variabel lenIngred yang menampung panjang nama bahan makanan.

            if (lenIngred > lenName) // Jika panjang string bahan makanan lebih panjang dari string nama + digit harga makanan.
            {
                if (lenIngred > spaceDcd[root->descendant]) // Dan jika panjang string bahan makanan lebih panjang dari jumlah spasi yang dimiliki keturunan itu.
                {
                    spaceDcd[root->descendant] = lenIngred; // Maka panjang string bahan makanan ditampung ke variabel spaceDcd.
                }
            }
            else // Jika tidak.
            {
                if (lenName > spaceDcd[root->descendant]) // Maka jika panjang string nama + digit makanan lebih panjang dari jumlah spasi yang dimiliki keturunan itu.
                {
                    spaceDcd[root->descendant] = lenName; // Panjang string nama + digit makanan ditampung ke variabel spaceDcd.
                }
            }
        }

        simpul *bantu = root->child; // Deklarasi variabel untuk membantu mencari alamat simpul yang dicari.

        if (bantu != NULL) // Jika simpul bantu tidak kosong.
        {
            if (bantu->sibling == NULL) // Jika memiliki satu simpul anak.
            {
                countSpace(bantu); // Maka lakukan proses rekursif.
            }
            else // Jika memiliki banyak simpul anak.
            {
                /* Memproses Simpul Anak Terakhir karena Belum Terproses dalam Pengulangan */
                while (bantu->sibling != root->child) // Maka, selama simpul anak terakhir tidak memiliki simpul anak pertama.
                {
                    countSpace(bantu);      // Maka lakukan proses rekursif.
                    bantu = bantu->sibling; // Setelah rekursif selesai, maka lakukan iterasi pada simpul bantu.
                }
                countSpace(bantu); // Lakukan proses rekursif lagi.
            }
        }
    }
}

/* Prosedur untuk Print Spasi */
void printSpace(int ancestor)
{
    /* Inisialisasi */
    int i, tempSpace = 0;                  // Untuk for dan menampung banyaknya spasi sementara.
    int lenSpace = spaceDcd[ancestor - 1]; // Variabel yang menampung banyaknya spasi pada keturunan sebelumnya/ancestor.

    for (i = ancestor - 2; i >= 0; i--) // Perulangan untuk menjumlahkan nilai level spasi pada keturunan sebelumnya
    {
        tempSpace += spaceDcd[i]; // Dijumlahkan.
    }
    lenSpace += tempSpace; // Menjumlahkan nilai level yang didapat pada spasi sebelumnya

    for (i = 0; i < lenSpace; i++) // Perulangan untuk print spasi
    {
        printf(" ");
    }
}