/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TP4 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

/* Deklarasi Tipe Struktur untuk N-ary Tree */
typedef struct smp *alamatsimpul;
typedef struct smp
{
    char name[100]; // Menampung nama anggota keluarga.
    int descendant; // Menampung angka turunan keberapa dalam tree.
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct
{
    simpul *root;
} tree;

/* Prosedur dan Fungsi yang digunakan di N-ary Tree */
void makeTree(char c[], tree *T);
void addChild(char c[], simpul *root);
void delAll(simpul *root);
void delChild(char delete[], simpul *root);
simpul *findSimpul(char tujuan[], simpul *root);
void printTreePreOrder(simpul *root, simpul *address, int count);
void printTreePostOrder(simpul *root, simpul *address);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);
