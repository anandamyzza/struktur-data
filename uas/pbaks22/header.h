/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan UAS dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <malloc.h>
#include <math.h>

/* Deklarasi Typedef Struct untuk Binary Tree */
typedef struct smp *alamatsimpul;
typedef struct smp
{
    int kontainer;
    alamatsimpul right;
    alamatsimpul left;
} simpul;

typedef struct
{
    simpul *root;
} tree;

/* Prosedur untuk Binary Tree */
void makeTree(int c, tree *T);
void addRight(int c, simpul *root);
void addLeft(int c, simpul *root);
void printTreePostOrder(simpul *root, simpul *address);