/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi KUIS 1 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"
// Program membaca kata satu per satu dari pita menggunakan mesin kata.
int main()
{
    list L;
    list L2, L3, L4;
    list Lr;

    createList(&L);
    createList(&L2);
    createList(&L3);
    createList(&L4);
    int i, n;
    scanf("%d", &n);
    char o[50], p[50], q[50];
    for (i = 0; i < n; i++)
    {
        scanf("%s %s %s", o, p, q);
        addLast(o, p, q, &L);
    }

    // printf("--------------------\n");

    // addToElement(L, )

    if (L.first != NULL)
    {
        /*inisialisasi*/
        elemen *tunjuk = L.first;
        int i = 1;
        while (tunjuk != NULL)
        {
            tunjuk = L.first;
            L.first = tunjuk->next;
            if (strcmp(tunjuk->kontainer.jenis, "action_figure") == 0)
            {
                // printf("1\n");
                // printf("%s\n", tunjuk->kontainer.jenis);
                knockdown(&L, &L2);
            }
            else if (strcmp(tunjuk->kontainer.jenis, "sepatu") == 0)
            {
                // printf("2n");
                knockdown(&L, &L3);
            }
            else if (strcmp(tunjuk->kontainer.jenis, "sepeda") == 0)
            {
                // printf("3\n");
                knockdown(&L, &L4);
            }
            /*proses*/
            // tunjuk = tunjuk->next;
            // tunjuk = L.first;
            /*iterasi*/
            i = i + 1;
        }
    }

    for (i = 0; i < countElement(L); i++)
    {
    }
    // printElement(L);
    printf("==\n");
    printElement(L2);
    printElement(L3);
    printElement(L4);

    return 0;
}