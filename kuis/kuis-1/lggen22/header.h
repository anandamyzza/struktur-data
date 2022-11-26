/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM3 dalam mata kuliah Struktur Datas
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <string.h>

// struktur dari list
typedef struct
{
    char code[50];
    char parentCode[50];
} gen;

typedef struct
{
    gen kontainer;
    int next;
    int prev;
} elemen;

typedef struct
{
    int first;
    int tail;
    elemen data[100];
} list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char code[], char parentCode[], list *L);
void addAfter(int prev, char code[], char parentCode[], list *L);
void addLast(char code[], char parentCode[], list *L);
void delFirst(list *L);
void delAfter(int prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);
void swap(list *L, list *L2, int num);