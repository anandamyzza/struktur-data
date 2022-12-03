/* Saya Ananda Myzza Marhelio NIM 2100702 mengerjakan evaluasi TM8 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

int main()
{
    tree T;
    int i;
    char alphabet[14];

    for (i = 0; i < 14; i++)
    {
        scanf(" %c", &alphabet[i]);
    }

    makeTree(alphabet[0], &T);

    addLeft(alphabet[1], T.root);
    addRight(alphabet[2], T.root);

    addLeft(alphabet[3], T.root->right);
    addRight(alphabet[4], T.root->left);
    addRight(alphabet[5], T.root->right);

    addLeft(alphabet[6], T.root->left->right);
    addRight(alphabet[7], T.root->right->left);
    addRight(alphabet[8], T.root->left->right);
    addRight(alphabet[9], T.root->right->right);
    addLeft(alphabet[10], T.root->right->right);

    addLeft(alphabet[11], T.root->left->right->left);
    addLeft(alphabet[12], T.root->right->left->right);
    addRight(alphabet[13], T.root->right->left->right);

    printf("Pre Order:\n");
    printTreePreOrder(T.root, T.root);
    printf("\n");

    delLeft(T.root->left->right->left);
    printf("In Order:\n");
    printTreeInOrder(T.root);
    printf("\n");

    delRight(T.root->right->right);
    printf("Post Order:\n");
    printTreePostOrder(T.root, T.root);
    printf("\n");

    return 0;
}