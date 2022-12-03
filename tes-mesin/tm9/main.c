/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM9 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

int main()
{
    tree T;
    nilai string[9];
    int i;
    char find[100];

    for (i = 0; i < 9; i++)
    {
        scanf("%s %d", string[i].name, &string[i].score);
    }
    scanf("%s", find);

    /* Step 1 */
    makeTree(string[0], &T);
    addChild(string[1], T.root);
    addChild(string[2], T.root);
    addChild(string[3], T.root);
    addChild(string[4], T.root->child);
    addChild(string[5], T.root->child);

    printf("Step 1:\n");
    printf("================\n");
    printTreePreOrder(T.root, T.root);
    printf("\n");
    printTreePostOrder(T.root, T.root);
    printf("\n");
    delChild(T.root->child->child->sibling, T.root->child);
    printTreePreOrder(T.root, T.root);
    printf("\n");
    printTreePostOrder(T.root, T.root);
    printf("\n");

    addChild(string[6], T.root->child->sibling);
    addChild(string[7], T.root->child->sibling);
    addChild(string[8], T.root->child->sibling->sibling);
    printTreePreOrder(T.root, T.root);
    printf("\n");

    /* Step 2 */
    tree T2;
    printf("Step 2:\n");
    printf("================\n");
    copyTree(T.root, &T2.root);
    if (isEqual(T.root, T2.root) == 1)
    {
        printf("Sama\n");
    }
    else
    {
        printf("Tidak Sama\n");
    }

    /* Step 3 */
    printf("Step 3:\n");
    printf("================\n");
    simpul *node = findSimpul(find, T.root->child->child);
    if (node != NULL)
    {
        printf("%s ditemukan\n", find);
    }
    else
    {
        printf("%s tidak ditemukan\n", find);
    }

    node = findSimpul(find, T.root->child->sibling);
    if (node != NULL)
    {
        printf("%s ditemukan\n", find);
    }
    else
    {
        printf("%s tidak ditemukan\n", find);
    }

    node = findSimpul(find, T.root);
    if (node != NULL)
    {
        printf("%s ditemukan\n", find);
    }
    else
    {
        printf("%s tidak ditemukan\n", find);
    }

    return 0;
}