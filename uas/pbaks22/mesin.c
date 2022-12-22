/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan UAS dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

/* Membuat Tree */
void makeTree(int c, tree *T)
{
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));

    baru->kontainer = c;
    baru->right = NULL;
    baru->left = NULL;
    (*T).root = baru;
    baru = NULL;
}

/* Menambah Ke Kanan */
void addRight(int c, simpul *root)
{
    if (root != NULL)
    {
        if (root->right == NULL)
        {
            /*jika sub pohon kanan kosong*/
            simpul *baru;
            baru = (simpul *)malloc(sizeof(simpul));

            baru->kontainer = c;
            baru->right = NULL;
            baru->left = NULL;
            root->right = baru;
            baru = NULL;
        }
        else
        {
            printf("sub pohon kanan telah terisi \n");
        }
    }
}

/* Menambah Ke Kiri */
void addLeft(int c, simpul *root)
{
    if (root != NULL)
    {
        if (root->left == NULL)
        {
            /*jika sub pohon kiri kosong*/
            simpul *baru;
            baru = (simpul *)malloc(sizeof(simpul));

            baru->kontainer = c;
            baru->right = NULL;
            baru->left = NULL;
            root->left = baru;
            baru = NULL;
        }
        else
        {
            printf("sub pohon kiri telah terisi \n");
        }
    }
}

/* Print Binary Tree */
void printTreePostOrder(simpul *root, simpul *address)
{

    if (root != NULL)
    {
        printTreePostOrder(root->left, address);
        printTreePostOrder(root->right, address);
        printf("%d", root->kontainer);
        if (root != address)
        {
            printf(" ");
        }
    }
}