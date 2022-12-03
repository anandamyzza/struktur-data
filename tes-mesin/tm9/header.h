/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM9 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char name[100];
    int score;
} nilai;

typedef struct smp *alamatsimpul;
typedef struct smp
{
    nilai kontainer;
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct
{
    simpul *root;
} tree;

void makeTree(nilai kontainer, tree *T);
void addChild(nilai kontainer, simpul *root);
void delAll(simpul *root);
void delChild(simpul *delete, simpul *root);
simpul *findSimpul(char tujuan[], simpul *root);
void printTreePreOrder(simpul *root, simpul *address);
void printTreePostOrder(simpul *root, simpul *address);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);
