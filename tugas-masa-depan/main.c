/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

int main()
{
    /* Deklarasi Variabel */
    char child[200],           // Menampung masukan user untuk nama anak yang akan dipisah dari string utama.
        parent[200];           // Menampung masukan user untuk nama orang tua yang akan dipisah dari string utama.
    int status = 0, n, m;      // Menampung status pemisahan, banyaknya makanan, dan banyaknya bahan yang dimiliki makanan.
    int price, temp, priceDel; // Menampung harga makanan, harga makanan sementara, dan harga makanan dibawah harga makanan inputan user yang akan dihapus.
    int i, j, k, l;            // Variabel untuk membantu proses for dan pemisahan string.

    tree T;         // Membuat tree kosong.
    simpul *node;   // Membuat simpul node sebagai alamat untuk proses addChild.
    simpul *search; // Membuat simpul search sebagai alamat untuk proses menghapus simpul yang harganya kurang dari harga inputan user.

    scanf("%d", &n);        // Meminta masukan user untuk banyaknya makanan.
    char str[n][200],       // String utama sebanyak masukan user.
        material[100][200]; // String yang menampung bahan makanan.

    /* Perulangan untuk Meminta Masukan User dan Proses Memisahkan String */
    for (i = 0; i < n; i++)
    {
        scanf("%s", str[i]); // Meminta masukan data makanan dari user.

        /* Proses Memisahkan Nama, Nama Orang Tua, Harga, dan Jumlah Bahan */
        // ∟ Inisialisasi
        status = 0;
        k = 0, l = 0;
        for (j = 0; j < strlen(str[i]); j++) // Perulangan sebanyak panjang string utama.
        {
            if (status == 0) // Jika status bernilai 0 (Proses mendapatkan Child).
            {
                if (str[i][j] != '#') // Dan jika char bukan '#'.
                {
                    child[j] = str[i][j]; // Maka tampung char tersebut ke variabel child.
                }
                else // Jika char merupakan '#'.
                {
                    child[j] = '\0'; // Maka tutup akhir child dengan '\0' agar child menjadi string.
                    status = 1;      // Dan ubah status menjadi 1.
                }
            }
            else if (status == 1) // Dan jika status bernilai 1 (Proses mendapatkan Parent).
            {
                if (str[i][j] != '#') // Dan jika char bukan '#'.
                {
                    parent[k] = str[i][j]; // Maka tampung char tersebut ke variabel parent.
                }
                else // Jika char merupakan '#'.
                {
                    parent[k] = '\0'; // Maka tutup akhir parent dengan '\0' agar parent menjadi string.
                    status = 2;       // Dan ubah status menjadi 2.
                }
                k++; // Iterasikan k agar array of char bertambah.
            }
            else if (status == 2) // Dan jika status bernilai 2 (Proses mendapatkan Harga).
            {
                if (str[i][j] != '#') // Dan jika char bukan '#'.
                {
                    if (l == 0) // Dan jika l bernilai 0.
                    {
                        price = str[i][j] - 48; // Maka ASCII string main dikurangi 48 (Karena pada bagian 3 merupakan harga, dan angka hanya berada di ASCII 48-57).
                        l++;                    // Iterasikan l sebagai penanda bahwa harga lebih dari satuan.
                    }
                    else // Jika l bernilai lebih dari 0.
                    {
                        price *= 10;           // Harga yang sudah didapatkan sebelumnya dikali 10.
                        temp = str[i][j] - 48; // Lalu tampung digit angka yang didapatkan sekarang ke harga sementara (pengurangan angka menggunakan ASCII).
                        price += temp;         // Lalu jumlahkan harga dengan harga sementara untuk mendapatkan harga aslinya.
                    }
                }
                else // Jika char merupakan '#'.
                {
                    status = 3; // Ubah status menjadi 3.
                }
            }
            else if (status == 3) // Dan jika status bernilai 3 (Proses mendapatkan banyaknya bahan makanan).
            {
                m = str[i][j] - 48; // Kurangi string (Nilai ASCII) dengan 48.
            }
        }

        /* Meminta Masukan Nama Bahan-bahan Makanan Sebanyak Total Bahan Makanan Inputan User */
        for (j = 0; j < m; j++)
        {
            scanf("%s", material[j]);
        }

        /* Syarat untuk Memasukan Data ke dalam Tree */
        if (strcmp(parent, "null") == 0) // Jika inputan parentnya "null".
        {
            makeTree(child, price, m, material, &T); // Maka panggil makeTree() dengan child sebagai rootnya.
        }
        else // Dan jika selainnya.
        {
            node = findSimpulChar(parent, T.root);     // Maka cari dulu alamat parent yang dimiliki child.
            addChild(child, price, m, material, node); // Lalu panggil addChild() dengan simpul node sebagai alamat tujuannya.
        }
    }
    scanf("%d", &priceDel); // Meminta masukan user untuk harga dibawah inputan user yang akan dihapus.

    /* Inisialisasi Variabel Global */
    line = 0;
    for (i = 0; i < 100; i++)
    {
        spaceDcd[i] = 0;
    }

    /* Memanggil Prosedur untuk Proses Print Data N-ary Tree Inputan User */
    countSpace(T.root);
    printTreePreOrder(T.root);

    /* Proses Menghapus Data yang memiliki Harga di Bawah Harga Inputan User */
    search = findSimpulInt(priceDel, T.root); // Mencari alamat simpul.
    while (search != NULL)                    // Selama hasil pencarian alamat yang di return bukan NULL.
    {
        delChild(search, search->parent);         // Maka hapus simpul tersebut.
        search = findSimpulInt(priceDel, T.root); // Lalu cari lagi alamat simpul yang perlu dihapus.
    }

    printTreePreOrder(T.root); // Lalu print hasil akhir N-ary Tree yang sudah dihapus berdasarkan harga inputan user.

    return 0;
}