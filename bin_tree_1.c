// binary tree implementation using recursion.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create()
{
    int x;
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("enter a value(-1 for no node) : ");
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }
    newnode->data = x;
    printf("enter the left child value of %d.\n", x);
    newnode->left = create();
    printf("enter the right child value of %d.\n", x);
    newnode->right = create();
    return newnode;
}

void preorder(node *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main()
{
    node *root = NULL;
    root = create();
    printf("the preorder of the binary tree is : ");
    preorder(root);
    printf("\n");
    printf("the inorder of the tree is : ");
    inorder(root);
    printf("\n");
    printf("the postorder of the tree is : ");
    postorder(root);
    printf("\n");
    return 0;
}