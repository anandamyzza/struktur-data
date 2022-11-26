/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM1 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"
// Program membaca kata satu per satu dari pita menggunakan mesin kata.
int main()
{
    list L;
    int i, j, k;
    int n, m, p;
    /* Main */
    char code[20], name[50];
    /* Sub */
    char codeCorp[20], zat[50];
    int month, year;
    /* Move */
    char zatMove[50];
    int monthMove, yearMove;
    createList(&L);

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s%s", code, name);
        addLastB(code, name, &L);

        // eBaris *tunjuk = L.first;
        eBaris *tunjuk = i == 0 ? L.first : tunjuk->next;
        scanf("%d", &m);
        for (j = 0; j < m; j++)
        {
            scanf("%s%s%d%d", codeCorp, zat, &month, &year);
            addLastK(codeCorp, zat, month, year, tunjuk);
        }
        // tunjuk = tunjuk->next;
    }
    addLastB("org", "OrganisasiPengawas", &L);

    scanf("%d", &p);

    for (k = 0; k < p; k++)
    {
        scanf("%s%d%d", zatMove, &monthMove, &yearMove);
        // printf("%s %d %d\n", zatMove, monthMove, yearMove);

        // eBaris *temp = L.first;
        // if (L.first != NULL)
        // {
        //     /*jika list tidak kosong*/
        //     /*inisialisasi*/
        //     int i = 1;
        //     while (temp->next != NULL)
        //     {
        //         /*proses*/
        //         eKolom *bantu = getKolom(temp, zat, month, year);
        //         if (bantu != NULL)
        //         {
        //             switchKol(temp, bantu, &L);
        //         }
        //         /*iterasi*/
        //         temp = temp->next;
        //         i = i + 1;
        //     }
        // }
    }

    printElement(L);
    // addFirstB("1", "Orang_1", &L);
    // addFirstK("IF40K1", "A", L.first);
    // addAfterK(L.first->col, "IF40Z1", "A");
    // addLastK("IF40Z2", "A", L.first);

    // addAfterB(L.first, "2", "Orang_2");
    // addFirstK("TI5141", "A", L.first->next);
    // addLastK("IF5021", "A", L.first->next);

    // addFirstK("IF5321", "A", L.first->next->next);
    // printElement(L);

    // printf("=================\n");
    // delAllB(&L);
    // printElement(L);
    // printf("=================\n");

    return 0;
}