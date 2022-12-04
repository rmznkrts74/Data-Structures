#include <stdio.h>
#include <stdlib.h>
struct homeW *rightRotate(struct homeW *node);
struct homeW *leftRotate(struct homeW *node);
int max(int a, int b);
struct homeW *newN(int id);
int heightof(struct homeW *n);
int balance(struct homeW *newNode2);
void inorder1(struct homeW *root);
void printsamelevel(struct homeW *n, int level, int parent, int order, int rst);
void printlayers(struct homeW *n);

struct homeW
{
    int id;
    struct homeW *right;
    struct homeW *left;
    int height;
};
struct homeW *rightRotate(struct homeW *node)
{
    struct homeW *xleft = node->left;
    struct homeW *yright = xleft->right;

    // Perform rotation
    xleft->right = node;
    node->left = yright;

    // Update heights
    node->height = max(heightof(node->left), heightof(node->right)) + 1;
    xleft->height = max(heightof(xleft->right), heightof(xleft->right)) + 1;

    // Return new root node
    return xleft;
}
struct homeW *leftRotate(struct homeW *node)
{
    struct homeW *xright = node->right;
    struct homeW *xleft = xright->left;

    // Perform rotation
    node->right = xleft;
    xright->left = node;

    // Update heights
    node->height = max(heightof(node->left), heightof(node->right)) + 1;
    xright->height = max(heightof(xright->left), heightof(xright->right)) + 1;

    // Return new root node
    return xright;
}
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
struct homeW *newN(int id)
{
    struct homeW *newNode = (struct homeW *)malloc(sizeof(struct homeW));
    newNode->id = id;
    newNode->height = 1;
    newNode->right = NULL;
    newNode->left = NULL;
}
int heightof(struct homeW *node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = heightof(node->left);
        int rheight = heightof(node->right);

        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
struct homeW *insert(struct homeW *node, int id)
{
    if (node == NULL)
        return newN(id);
    if (id < node->id)
        node->left = insert(node->left, id);
    else if (id > node->id)
        node->right = insert(node->right, id);
    else
        return node;

    node->height = max(heightof(node->left), heightof(node->right)) + 1;

    int balanceFactor = balance(node);

    if (balanceFactor > 1 && id < node->left->id)
        return rightRotate(node);

    if (balanceFactor < -1 && id > node->right->id)
        return leftRotate(node);

    if (balanceFactor > 1 && id > node->left->id)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (-1 > balanceFactor && node->right->id > id)
    {
        node->right = rightRotate(node);
    }
    return node;
}
int balance(struct homeW *newNode2)
{
    if (newNode2 == NULL)
    {
        return 0;
    }
    else
    {
        return (heightof(newNode2->left) - heightof(newNode2->right));
    }
}
void inorder1(struct homeW *root)
{
    if (root != NULL)
    {
        inorder1(root->left);
        printf("%d\n", root->id);
        inorder1(root->right);
    }
}
void printlayers(struct homeW *n)
{
    int height = heightof(n);
    for (int i = 1; i <= height; i++)
    {
        printsamelevel(n, i, n->id, 2, 1);
        puts("");
    }
}
void printsamelevel(struct homeW *n, int level, int parent, int order, int rst)
{
    static int isnl = 1;
    if (rst)
    {
        isnl = 1;
    }
    if (n == NULL)
    {
        return;
    }
    if (isnl)
    {

        if (level == 1 && order == 3)
        {
            printf("%d (%d R) (%d B)", n->id, parent, balance(n));
            isnl = 0;
        }
        if (level == 1 && order == 2)
        {
            printf("%d (%d B)", n->id, balance(n));
            isnl = 1;
        }
        if (level == 1 && order == 1)
        {
            printf("%d (%d L) (%d B)", n->id, parent, balance(n));
            isnl = 0;
        }
    }
    else
    {
        if (level == 1 && order == 3)
        {
            printf(" %d (%d R) (%d B)", n->id, parent, balance(n));
        }
        if (level == 1 && order == 1)
        {
            printf(" %d (%d L) (%d B)", n->id, parent, balance(n));
        }
    }
    if (level > 1)
    {
        printsamelevel(n->left, level - 1, n->id, 1, 0);
        printsamelevel(n->right, level - 1, n->id, 3, 0);
    }
}
int main()
{
    struct homeW *root = NULL;
    int id;
    scanf("%d", &id);
    while (id != -1)
    {
        root = insert(root, id);
        scanf("%d", &id);
    }
    inorder1(root);
    puts("");
    int h = heightof(root);
    printlayers(root);

}