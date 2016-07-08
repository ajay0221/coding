#include <stdio.h>
#include <stdlib.h>

struct nn {
    int data;
    struct nn * left;
    struct nn * right;
};

typedef struct nn node;

node * insert (node * root, int x) {
    if ( root == NULL ) {
        node * temp = (node *) malloc (sizeof(node));
        temp -> data = x;
        temp -> left = NULL;
        temp -> right = NULL;
        return temp;
    } else {
        if ( root -> data >= x ) {
            root -> left = insert(root -> left, x);
        } else {
            root -> right = insert(root -> right, x);
        }
    }
    return root;
}

int search(node * root, int x) {
    if ( root == NULL ) return 0;
    if ( root -> data == x ) return 1;
    if ( root -> data > x ) return search(root -> left, x);
    return search(root -> right, x);
}

void inorder(node * root) {
    if ( root == NULL ) return;
    inorder(root -> left);
    printf("%d ",root -> data);
    inorder(root -> right);
}

void preorder(node * root) {
    if ( root == NULL ) return;
    printf("%d ",root -> data);
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(node * root) {
    if ( root == NULL ) return;
    postorder(root -> left);
    postorder(root -> right);
    printf("%d ",root -> data);
}

int findmin(node * root) {
    if ( root == NULL ) return -1098;
    if ( root -> left == NULL ) return root -> data;
    return findmin(root -> left);
}

node * delete(node * root, int x) {
    if ( root == NULL ) return NULL;
    if ( root -> data > x ) {
        root -> left = delete(root -> left, x);
        return root;
    } else if ( root -> data < x ) {
        root -> right = delete(root -> right, x);
        return root;
    }
    if ( root -> left == NULL && root -> right == NULL ) {
        node * temp = root;
        free(temp);
        return NULL;
    } else if ( root -> right == NULL ) {
        node * temp = root;
        root = root -> left;
        free(temp);
        return root;
    } else if ( root -> left == NULL ) {
        node * temp = root;
        root = root -> right;
        free(temp);
        return root;
    } else {
        int val = findmin(root -> right);
        root -> data = val;
        root -> right = delete(root -> right, val);
        return root;
    }
}

int main(void) {
    int input = -1;
    int val;
    node * root = NULL;
    while ( input != 0 ) {
        printf("Tree Options :\n 1. Insert\n 2. Search\n 3. Delete\n0. Exit\n");
        scanf("%d",&input);
        switch(input) {
            case 1:
                scanf("%d",&val);
                root = insert(root, val);
                break;
            case 2:
                scanf("%d",&val);
                printf("Element found : %d\n",search(root, val));
                break;
            case 3:
                scanf("%d",&val);
                root = delete(root, val);
                break;
            case 0:
                printf("Exiting !!\n");
                break;
            default:
                printf("Invalid Option\n");
                break;
        }
        printf("Tree Inorder : ");
        inorder(root);
        printf("\n");
        printf("Tree Preorder : ");
        preorder(root);
        printf("\n");
        printf("Tree Postorder : ");
        postorder(root);
        printf("\n");
    }
    return 0;
}
