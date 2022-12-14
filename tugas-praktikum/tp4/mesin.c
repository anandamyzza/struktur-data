/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TP4 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

/* Prosedur untuk Membuat Tree */
void makeTree(char c[], tree *T)
{
    /* Deklarasi Simpul Node */
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));

    /* Inisialisasi */
    strcpy(node->name, c); // Menampung nama inputan user ke simpul node.
    node->descendant = 0;  // Inisialisasi angka keturunan.
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node; // Menampung data pada node ke root.
}

/* Prosedur untuk Menambahkan Child pada Parent */
void addChild(char c[], simpul *root)
{
    if (root != NULL) // Jika simpul root tidak kosong.
    {                 // Simpul anak dapat ditambahkan.
        /* Deklarasi Simpul Baru */
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));

        strcpy(baru->name, c);                   // Menampung nama inputan user ke simpul baru.
        baru->descendant = root->descendant + 1; // Menampung dan menambahkan 1 angka keturunan berdasarkan angka keturunan sebelumnya.
        baru->child = NULL;                      // NULL untuk child nya.

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

/* Prosedur untuk Menghapus Semua Isi Tree */
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
                simpul *bantu;
                simpul *proses;

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
void delChild(char delete[], simpul *root)
{
    if (root != NULL) // Jika simpul root tidak kosong.
    {
        simpul *hapus = root->child; // Deklarasi simpul hapus yang dikaitkan pada root->child.
        if (hapus != NULL)           // Jika simpul hapus tidak kosong.
        {
            if (hapus->sibling == NULL) // Dan jika hanya mempunyai satu anak.
            {
                if (strcmp(root->child->name, delete) == 0) // Jika nama anak sama dengan string delete.
                {
                    delAll(root->child); // Maka memanggil delAll() untuk menghapus anak tersebut.
                    root->child = NULL;  // Lalu NULL kan.
                }
                else // Jika tidak.
                {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            }
            else // Namun jika memiliki lebih dari satu simpul anak.
            {
                /* Maka akan Mencari Simpul yang akan Dihapus */
                simpul *prev = NULL; // Deklarasi simpul prev yang NULL.
                int ketemu = 0;      // Variabel kondisi.

                while (hapus->sibling != root->child && ketemu == 0) // Maka, selama simpul anak terakhir tidak memiliki simpul anak pertama.
                {                                                    // Dan variabel ketemu bernilai 0.
                    if (strcmp(hapus->name, delete) == 0)
                    {               // Jika nama anak yang ditunjuk hapus sama dengan string delete.
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
                if (ketemu == 0 && strcmp(hapus->name, delete) == 0)
                {               // Jika ketemu bernilai 0 dan pointer hapus memiliki string yang sama dengan delete.
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
                else // Jika ketemu bernilai 0.
                {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            }
        }
    }
}

/* Fungsi untuk Mencari Alamat Simpul pada Tree */
simpul *findSimpul(char tujuan[], simpul *root)
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
                        hasil = findSimpul(tujuan, bantu); // Maka menampung hasil findSimpul() ke hasil menggunakan rekursif.
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
                            hasil = findSimpul(tujuan, bantu); // Maka menampung hasil findSimpul() ke hasil menggunakan rekursif.
                            bantu = bantu->sibling;            // Lalu lakukan iterasi pada pointer bantu.

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
                            hasil = findSimpul(tujuan, bantu); // Maka menampung hasil findSimpul() ke hasil menggunakan rekursif.
                        }
                    }
                }
            }
        }
    }
    return hasil; // Mengembalikan alamat simpul yang dicari.
}

/* Prosedur untuk Print Tree Pre Order */
void printTreePreOrder(simpul *root, simpul *address, int count)
{
    if (root != NULL) // Jika simpul root tidak kosong.
    {
        if (root == address) // Dan jika simpul yang ditunjuk adalah root utama,
        {
            // Print Hasil.
            printf("Output %d:\n=========\n", count);
            printf("%s\n", root->name);
        }
        else // Jika simpul yg ditunjuk bukan root utama.
        {
            // Maka lakukan proses pengulangan berdasarkan angka keturunan simpul.
            for (int i = 0; i < root->descendant; i++)
            {
                // Untuk print panah berikut.
                printf("->");
            }
            printf("%s\n", root->name); // Lalu print nama.
        }

        simpul *bantu = root->child; // Deklarasi variabel untuk membantu mencari alamat simpul yang dicari.

        if (bantu != NULL) // Jika simpul bantu tidak kosong.
        {
            if (bantu->sibling == NULL) // Jika memiliki satu simpul anak.
            {
                printTreePreOrder(bantu, address, count); // Maka lakukan proses rekursif.
            }
            else // Jika memiliki banyak simpul anak.
            {
                /* Memproses Simpul Anak Terakhir karena Belum Terproses dalam Pengulangan */
                while (bantu->sibling != root->child)
                {
                    printTreePreOrder(bantu, address, count);
                    bantu = bantu->sibling;
                }
                printTreePreOrder(bantu, address, count);
            }
        }
    }
}

/* Prosedur untuk Print Tree Post Order */
void printTreePostOrder(simpul *root, simpul *address)
{
    if (root != NULL)
    {
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL) // Jika memiliki satu simpul anak.
            {
                printTreePostOrder(bantu, address);
            }
            else // Jika memiliki banyak simpul anak.
            {
                /* Memproses Simpul Anak Terakhir karena Belum Terproses dalam Pengulangan */
                while (bantu->sibling != root->child)
                {
                    printTreePostOrder(bantu, address);
                    bantu = bantu->sibling;
                }
                printTreePostOrder(bantu, address);
            }
        }
        printf("%s", root->name);

        if (root != address) // Jika bukan elemen root utama.
        {
            printf("-");
        }
    }
    else
    {
        printf("Kosong\n");
    }
}

/* Prosedur untuk Copy Tree */
void copyTree(simpul *root1, simpul **root2)
{
    if (root1 != NULL)
    {
        (*root2) = (simpul *)malloc(sizeof(simpul));

        strcpy((*root2)->name, root1->name);
        (*root2)->sibling = NULL;
        (*root2)->child = NULL;

        if (root1->child != NULL)
        {
            if (root1->child->sibling == NULL) // Jika memiliki satu simpul anak.
            {
                copyTree(root1->child, &(*root2)->child);
            }
            else // Jika memiliki banyak simpul anak.
            {
                simpul *bantu1 = root1->child;
                simpul *bantu2 = *root2;

                /* Memproses Simpul Anak Terakhir karena Belum Terproses dalam Pengulangan */
                while (bantu1->sibling != root1->child)
                {
                    if (bantu2 == (*root2))
                    {
                        copyTree(bantu1, &bantu2->child);
                        bantu2 = bantu2->child;
                    }
                    else
                    {
                        copyTree(bantu1, &bantu2->sibling);
                        bantu2 = bantu2->sibling;
                    }
                    bantu1 = bantu1->sibling;
                }
                copyTree(bantu1, &bantu2->sibling);
                bantu2->sibling->sibling = (*root2)->child;
            }
        }
    }
}

/* Prosedur untuk Mencari Tahu Aakah TreeA sama dengan TreeB */
int isEqual(simpul *root1, simpul *root2)
{
    int hasil = 1;
    if (root1 != NULL && root2 != NULL)
    {
        if (strcmp(root1->name, root2->name) != 0)
        {
            hasil = 0;
        }
        else
        {
            if (root1->child != NULL && root2->child != NULL)
            {
                if (root1->child->sibling == NULL) // Jika memiliki satu simpul anak.
                {
                    hasil = isEqual(root1->child, root2->child);
                }
                else // Jika memiliki banyak simpul anak.
                {
                    simpul *bantu1 = root1->child;
                    simpul *bantu2 = root2->child;

                    /* Memproses Simpul Anak Terakhir karena Belum Terproses dalam Pengulangan */
                    while (bantu1->sibling != root1->child)
                    {
                        if (bantu1 != NULL && bantu2 != NULL)
                        {
                            hasil = isEqual(bantu1, bantu2);
                            bantu1 = bantu1->sibling;
                            bantu2 = bantu2->sibling;
                        }
                        else
                        {
                            hasil = 0;
                            break;
                        }
                    }
                    hasil = isEqual(bantu1, bantu2);
                }
            }
        }
    }
    else
    {
        if (root1 != NULL || root2 != NULL)
        {
            hasil = 0;
        }
    }
    return hasil;
}
