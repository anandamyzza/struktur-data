/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan UAS dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <malloc.h>

/* Deklarasi Typedef Struct untuk Graph */
typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;
typedef struct smp
{
    char kontainer;
    alamatsimpul next;
    alamatjalur arc;
} simpul;

typedef struct jlr
{
    int kontainer_jalur;
    alamatjalur next_jalur;
    simpul *tujuan;
} jalur;

typedef struct
{
    simpul *first;
} graph;

// Integer untuk jarak terpanjang.
extern int jarakTerpanjang;

/* Prosedur yang Digunakan di Graph */
void createEmpty(graph *G);
void addSimpul(char c, graph *G);
void addJalur(simpul *awal, simpul *tujuan, int beban);
simpul *findSimpul(char c, graph G);
void searching(char awal, char akhir, char path[], int index, int len, graph G);