/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM8 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct smp
{
    char kontainer;
    alamatsimpul right;
    alamatsimpul left;
} simpul;

typedef struct
{
    simpul *root;
} tree;

void makeTree(char c, tree *T);
void addRight(char c, simpul *root);
void addLeft(char c, simpul *root);
void delAll(simpul *root);
void delRight(simpul *root);
void delLeft(simpul *root);
void printTreePreOrder(simpul *root, simpul *address);
void printTreeInOrder(simpul *root);
void printTreePostOrder(simpul *root, simpul *address);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);