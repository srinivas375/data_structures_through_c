// bst implementation using pointers and recursion
// insertion,traversal(inorder,preorder,postorder),deletion operations are performed .
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} node;

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

node *newnode(int x)
{
    node *new;
    new = (node *)malloc(sizeof(node));
    new->data = x;
    new->left = new->right = NULL;
    return new;
}

node *insert(node *root, int key)
{
    if (root == NULL)
    {
        root = newnode(key);
    }

    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    return root;
}

int search(node *root, int val)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        if (val == root->data)
        {
            return 1;
        }
        else if (val < root->data)
        {
            return search(root->left, val);
        }
        else if (val > root->data)
        {
            return search(root->right, val);
        }
    }
}

node *find_min(node *temp)
{
    if (temp->left == NULL)
    {
        return temp;
    }
    else
    {
        return find_min(temp->left);
    }
}

node *delete(node *root, int val)
{
    node *temp;
    if (root == NULL)
    {
        return NULL;
    }
    else if (val < root->data)
    {
        root->left = delete (root->left, val);
    }
    else if (val > root->data)
    {
        root->right = delete (root->right, val);
    }
    else if (root->left != NULL && root->right != NULL) // two child
    {
        temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    else // one or no child.
    {
        temp = root;
        if (root->left == NULL)
        {
            root = root->right;
        }
        else if (root->right == NULL)
        {
            root = root->left;
        }
        free(temp);
    }
    return root;
}

int main()
{
    node *root = NULL;
    root = insert(root, 5);
    insert(root, 13);
    insert(root, 10);
    insert(root, 12);
    insert(root, 4);
    insert(root, 8);
    
    inorder(root);
    printf("\n");

    printf("enter a value to search : ");
    int val;
    scanf("%d", &val);
    if (search(root, val))
    {
        printf("%d is found.\n", val);
    }
    else
    {
        printf("%d is not found.\n", val);
    }

    printf("enter a value to delete : ");
    int val2;
    scanf("%d", &val);
    root = delete (root, val);

    inorder(root);
    printf("\n");

    return 0;
}