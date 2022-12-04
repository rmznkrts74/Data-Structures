#include <stdio.h>
#include <stdlib.h>
int parent;
struct homeW
{
    int id;
    int height;
    struct homeW *left;
    struct homeW *right;
};
int max(int a,int b){
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}
int height(struct homeW *node);
struct homeW *root = NULL;
struct homeW *newN(int id)
{
    struct homeW *temp = (struct homeW *)malloc(sizeof(struct homeW));
    temp->id = id;
    temp->height = 1;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
        root = temp;
    return temp;
};
void inorder1(struct homeW *root)
{
    if (root != NULL)
    {
        inorder1(root->left);
        printf("%d\n", root->id);
        inorder1(root->right);
    }
}
int balance(struct homeW *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct homeW *rightRotate(struct homeW *node)
{
    struct homeW *xleft = node->left;
    struct homeW *yright = left->right;

    // Perform rotation
    xleft->right = node;
    node->left = yright;

    // Update heights
    node->height = max(height(node->left), height(node->right)) + 1;
    xleft->height = max(height(xleft->right), height(xleft->right)) + 1;

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
    node->height = max(height(node->left), height(node->right)) + 1;
    xright->height = max(height(xright->left), height(xright->right)) + 1;

    // Return new root node
    return xright;
}
struct homeW *addEleman(struct homeW *node, int id)
{
    // Perform normal BST insert
    if (node == NULL)
        return newN(id);
    if (id < node->id)
        node->left = addEleman(node->left, id);
    else if (id > node->id)
        node->right = addEleman(node->right, id);
    else
        return node; // Value already exists in the tree

    // Update height of this ancestor node
    node->height = max(height(node->left), height(node->right)) + 1;

    // Check if this node became unbalanced
    int balanceFactor = balance(node);

    // Left Left Case
    if (balanceFactor > 1 && id < node->left->id)
        return rightRotate(node);

    // Right Right Case
    if (balanceFactor < -1 && id > node->right->id)
        return leftRotate(node);

    // Left Right Case
    if (balanceFactor > 1 && id > node->left->id)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
}

void levelOrderandCurrentLevel(struct homeW *root, int high)
{
    if (root == NULL)
    {
        return;
    }
    if (high == 1)
    {
        printf("%d ", root->id);
    }

    else if (high > 1)
    {

        levelOrderandCurrentLevel(root->left, high - 1);
        if(high==2 && root->left!=NULL){
            printf("(%d L) ",root->id);
        }
        levelOrderandCurrentLevel(root->right, high - 1);
        if(high==2 && root->right!=NULL){
            printf("(%d R) ",root->id);
        }
    }
}
int height(struct homeW *node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
int main()
{

    int  id;
    scanf("%d", &id);
    while (id != -1)
    {
        addEleman(root, id);
        scanf("%d", &id);
    }
    inorder1(root);
    puts("");
    int h = height(root);
    for (int i = 0; i <= h; i++)
    {
        levelOrderandCurrentLevel(root, i);
        puts("");
    }
}