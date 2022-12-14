/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TP4 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

int main()
{
    /* Deklarasi Variabel */
    char query[100], // Menampung query masukan user.
        child[100],  // Menampung masukan user untuk nama anak.
        parent[100]; // Menampung masukan user untuk nama orang tua.
    int count = 0;   // Menampung banyaknya output yang dilakukan oleh user.

    tree T;       // Membuat tree kosong.
    simpul *node; // Membuat simpul sebagai alamat untuk proses CHILD dan DELLCHILD.

    /* Proses Pengulangan untuk Meminta Masukan User */
    do
    {
        scanf("%s", query); // Meminta query yang ingin digunakan user.

        /* Kondisi untuk Query dalam Program */
        if (strcmp(query, "MAKETREE") == 0) // Jika query yang diminta adalah "MAKETREE".
        {
            scanf("%s", parent);               // Maka meminta masukan nama orang tua sebagai root dalam tree.
            parent[strlen(parent) - 1] = '\0'; // Mengganti ";" menjadi '\0'.
            makeTree(parent, &T);              // Memanggil prosedur makeTree() untuk membuat tree baru.
        }
        else if (strcmp(query, "CHILD") == 0 || strcmp(query, "DELLCHILD") == 0) // Jika query yang diminta adalah "CHILD/DELLCHILD".
        {
            scanf("%s %s", child, parent);     // Maka meminta masukan nama anak dan orang tuanya.
            parent[strlen(parent) - 1] = '\0'; // Mengganti ";" menjadi '\0'.
            node = findSimpul(parent, T.root); // Mencari alamat simpul dari orang tuanya dalam tree, dan menampungnya ke variabel node.

            if (strcmp(query, "CHILD") == 0) // Jika query yang diminta adalah "CHILD".
            {
                addChild(child, node); // Maka memanggil prosedur addChild() menggunakan alamat node.
            }
            else if (strcmp(query, "DELLCHILD") == 0) // Jika query yang diminta adalah "DELLCHILD".
            {
                delChild(child, node); // Maka memanggil prosedur delChild() menggunakan alamat node.
            }
        }
        else if (strcmp(query, "PREORDER;") == 0) // Jika query yang diminta adalah "PREORDER".
        {
            count++;                                  // Maka jumlah count bertambah 1, sebagai tanda output.
            printTreePreOrder(T.root, T.root, count); // Dan memanggil printTreePreOrder() untuk hasil.
        }
    } while (strcmp(query, "DONE;") != 0); // Pengulangan akan berhenti jika user mengisi query "DONE".
    printf("=========\n");

    return 0;
}