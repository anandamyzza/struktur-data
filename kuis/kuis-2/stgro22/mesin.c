/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi KUIS 2 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

/* Prosedur untuk Membuat Stack */
void createEmpty(stack *S)
{
    (*S).top = -1;
}

/* Prosedur untuk Mencari Tahu Apakah Stack Ada atau Kosong */
int isEmpty(stack S)
{
    int hasil = 0;   // Deklarasi hasil = 0 sebagai penanda.
    if (S.top == -1) // Jika Stack topnya bernilai -1.
    {
        hasil = 1; // Hasil bernilai 1 sebagai tanda bahwa Stack kosong.
    }
    return hasil; // Mengembalikan hasil, 0 = Stack Ada, 1 = Stack Kosong.
}

/* Prosedur untuk Mencari Tahu Apakah Stack Full atau Tidak */
int isFull(stack S)
{
    int hasil = 0;   // Deklarasi hasil = 0 sebagai penanda.
    if (S.top == 99) // Jika Stack top nya bernilai 99.
    {
        hasil = 1; // Hasil bernilai 1 sebagai tanda bahwa Stack full.
    }
    return hasil; // Mengembalikan hasil, 0 = Stack Tidak Full, 1 = Stack Full.
}

/* Prosedur Untuk Memasukan Data ke dalam Stack */
void push(char name[], char expedition[], char region[], int weight, stack *S)
{

    /* Jika Stack Penuh */
    if (isFull(*S) == 1)
    {
        printf("stack penuh\n");
    }
    else // Jika Tidak.
    {
        /* Jika Stack Kosong */
        if (isEmpty(*S) == 1)
        {
            (*S).top = 0;
            strcpy((*S).data[0].name, name);
            strcpy((*S).data[0].expedition, expedition);
            strcpy((*S).data[0].region, region);
            (*S).data[0].weight = weight;
        }
        /* Jika Stack Tidak Kosong */
        else
        {
            (*S).top = (*S).top + 1;
            strcpy((*S).data[(*S).top].name, name);
            strcpy((*S).data[(*S).top].expedition, expedition);
            strcpy((*S).data[(*S).top].region, region);
            (*S).data[(*S).top].weight = weight;
        }
    }
}

/* Prosedur untuk Pop data dari S dan push datanya ke S1 */
void popPush(stack *S, stack *S1)
{
    /* Jika Stack Berisi Satu Elemen*/
    if ((*S).top == 0)
    {
        push((*S).data[0].name, (*S).data[0].expedition, (*S).data[0].region, (*S).data[0].weight, S1);
        (*S).top = -1;
    }
    /* Jika Stack Tidak Kosong*/
    else
    {
        if ((*S).top != -1)
        {
            push((*S).data[(*S).top].name, (*S).data[(*S).top].expedition, (*S).data[(*S).top].region, (*S).data[(*S).top].weight, S1);
            (*S).top = (*S).top - 1;
        }
    }
}

/* Print Data untuk Seluruh Stack yang di Panggil */
void printStack(stack S)
{
    if (S.top != -1)
    {
        int i;
        for (i = S.top; i > 0; i--)
        {
            printf("%s ", S.data[i].name);
            printf("%s ", S.data[i].expedition);
            printf("%s ", S.data[i].region);
            printf("%d\n", S.data[i].weight);
        }
    }
    else
    {
        /* Proses Jika Stack Kosong */
        printf("stack kosong\n");
    }
}