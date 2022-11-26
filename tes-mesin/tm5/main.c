/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM5 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"
// Program membaca kata satu per satu dari pita menggunakan mesin kata.
int main()
{
    list L;
    createList(&L);

    int i, j, n;
    char o[50], p[50], q[50];
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {

        scanf("%s %s", &o, &p);
        addLastB(o, p, &L);

        eBaris *tunjuk;
        if (i == 0)
        {
            tunjuk = L.first;
        }
        else
        {
            tunjuk = tunjuk->next;
        }

        scanf("%s", &q);
        addFirstK(q, tunjuk);
        scanf("%s", &q);
        addLastK(q, tunjuk);
        scanf("%s", &q);
        addAfterK(tunjuk->col->next_kol, q);
        scanf("%s", &q);
        addFirstK(q, tunjuk);
    }

    delAfterK(L.first->next->col->next_kol);
    delFirstB(&L);
    delFirstK(L.first);
    printElement(L);
    delAllB(&L);
    printElement(L);

    return 0;
}