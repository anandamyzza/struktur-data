/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan UAS dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

int main()
{
    /* Deklarasi Variabel */
    tree T;
    int i = 0, j = 0, k, num;
    simpul *kanan; // Simpul kanan dan kiri untuk iterasi.
    simpul *kiri;

    scanf("%d", &num);    // Meminta masukan angka dari user
    makeTree(num, &T);    // Membuat Binary Tree
    int temp = sqrt(num); // Menampung akar kuadrat temporary sebagai penanda agar dapat memasuki syarat while.

    /* Perulangan Mencari Akar Kuadrat */
    while (temp > 1) // Selama temp bernilai lebih dari 1, maka jalankan perintah dalam while.
    {
        temp = sqrt(num); // Menampung nilai kuadrat num pada temp.
        kanan = T.root;   // Deklarasikan simpul kanan dan kiri ke akar.
        kiri = T.root;    // Simpul akan terus kembali ke akar selama perulangan ada.

        if (temp % 2 == 0) // Jika hasil temp adalah genap.
        {
            /* Maka Akan Ditambah ke Simpul Kanan */
            if (i == 0) // Jika i bernilai 0, yang artinya berada di paling awal.
            {
                addRight(temp, kanan); // Maka panggil saja addRight.
            }
            else // Jika selain 0.
            {
                // Maka lakukan perulangan selama banyaknya i, untuk interasi simpul kanan.
                for (k = 0; k < i; k++)
                {
                    kanan = kanan->right;
                }
                addRight(temp, kanan); // Lalu panggil addRight.
            }
            i++; // Iterasikan i sebagai penanda bertambahnya simpul.
        }
        else if (temp % 2 != 0) // Jika hasil temp adalah ganjil.
        {
            /* Maka Akan Ditambah ke Simpul Kiri */
            if (j == 0) // Jika j bernilai 0, yang artinya berada di paling awal.
            {
                addLeft(temp, kiri); // Maka panggil saja addLeft.
            }
            else // Jika selain 0.
            {
                // Maka lakukan perulangan selama banyaknya i, untuk interasi simpul kanan.
                for (k = 0; k < j; k++)
                {
                    kiri = kiri->left;
                }
                addLeft(temp, kiri); // Lalu panggil addLeft.
            }
            j++; // Iterasikan i sebagai penanda bertambahnya simpul.
        }
        num = sqrt(num); // Akar kuadratkan num.
    }

    /* Print Binary Tree */
    printTreePostOrder(T.root, T.root);
    printf("\n");

    return 0;
}