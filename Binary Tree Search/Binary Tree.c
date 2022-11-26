#include <stdio.h>
#include <stdlib.h>
int parent;
struct homeW
{
    int id;
    int point;
    struct homeW *left;
    struct homeW *right;
};
struct homeW *root = NULL;
struct homeW *newN(int id, int point)
{
    struct homeW *temp = (struct homeW *)malloc(sizeof(struct homeW));
    temp->id = id;
    temp->point = point;
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
        printf("%d %d\n", root->id, root->point);
        inorder1(root->right);
    }
}
void levelOrderandCurrentLevel(struct homeW *root, int high);
int height(struct homeW *node);
struct homeW *addEleman(struct homeW *node, int id, int point)
{
    if (node == NULL)
    {
        return newN(id, point);
    }
    if (point < node->point)
    {
        node->left = addEleman(node->left, id, point);
    }
    else if (point > node->point)
    {
        node->right = addEleman(node->right, id, point);
    }
    return node;
}
void levelOrderandCurrentLevel(struct homeW *root, int high)
{
    if (root == NULL)
    {
        return;
    }
    if (high == 1)
    {
        printf("%d %d ", root->id, root->point);
    }

    else if (high > 1)
    {

        levelOrderandCurrentLevel(root->left, high - 1);
        if(high==2 && root->left!=NULL){
            printf("(%d L) ",root->point);
        }
        levelOrderandCurrentLevel(root->right, high - 1);
        if(high==2 && root->right!=NULL){
            printf("(%d R) ",root->point);
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

    int choose, id, point;
    scanf("%d", &id);
    while (id != -1)
    {

        scanf("%d", &point);
        addEleman(root, id, point);
        scanf("%d", &id);
    }
    inorder1(root);
    int h = height(root);
    for (int i = 0; i <= h; i++)
    {
        levelOrderandCurrentLevel(root, i);
        puts("");
    }
}
