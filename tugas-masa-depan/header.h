/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

/* Deklarasi Tipe Struktur untuk N-ary Tree */
typedef struct smp *alamatsimpul;
typedef struct smp
{
    char name[200];             // Menampung nama makanan.
    char ingredients[100][200]; // Menampung nama bahan-bahan untuk membuat makanan.
    int totalIngred;            // Menampung banyaknya bahan-bahan yang diperlukan.
    int price;                  // Menampung harga makanan.
    int descendant;             // Menampung angka turunan ke berapa dalam 1 tree.

    alamatsimpul sibling; // Menampung simpul sibling.
    alamatsimpul child;   // Menampung simpul anak.
    alamatsimpul parent;  // Menampung simpul orang tua.
} simpul;

typedef struct
{
    simpul *root;
} tree;

/* Variabel Global */
extern int spaceDcd[100]; // Menampung banyaknya spasi pada setiap string dari inputan user (Singkatan dari Space Descendant).
extern int line;          // Menampung banyaknya baris untuk membantu print newline.

/* Prosedur dan Fungsi yang digunakan di N-ary Tree */
void makeTree(char c[], int p, int m, char mats[][200], tree *T);
void addChild(char c[], int p, int m, char mats[][200], simpul *root);
void delAll(simpul *root);
void delChild(simpul *search, simpul *root);
simpul *findSimpulChar(char tujuan[], simpul *root);
simpul *findSimpulInt(int tujuan, simpul *root);
void printTreePreOrder(simpul *root);
void countSpace(simpul *root);
void printSpace(int ancestor);
