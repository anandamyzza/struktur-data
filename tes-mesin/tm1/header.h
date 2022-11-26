/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM1 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <string.h>

// struktur dari list
typedef struct
{
    char nama[50];
    char level[10];
    char game[50];
} character;

typedef struct
{
    character kontainer;
    int next;
} elemen;

typedef struct
{
    int first;
    elemen data[10];
} list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char nama[], char level[], char game[], list *L);
void addAfter(int prev, char nama[], char level[], char game[], list *L);
void addLast(char nama[], char level[], char game[], list *L);
void delFirst(list *L);
void delAfter(int prev, list *L);
void delLast(list *L);
void printElement(list L);
void delAll(list *L);