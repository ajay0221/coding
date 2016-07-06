#include <stdio.h>
#include <stdlib.h>

struct nn {
    int data;
    struct nn * next;
};

typedef struct nn node;
node * head = NULL;
node * temp;
node * newnode;

node * create_node (int x) {
    node * result = (node *) malloc (sizeof(node));
    result -> data = x;
    result -> next = NULL;
    return result;
}

void push() {
    int val;
    scanf("%d",&val);
    newnode = create_node(val);
    if ( head == NULL ) {
        head = newnode;
    } else {
        newnode -> next = head;
        head = newnode;
    }
}

void pop() {
    if ( head == NULL ) {
        printf("No elements in Stack\n");
    } else {
        printf("Popping element : %d\n", head -> data);
        temp = head;
        head = head -> next;
        free(temp);
    }
}

void top() {
    printf("Element at the top of Stack is : %d\n", head -> data);
}

void printStack() {
    printf("Stack : ");
    for ( temp = head; temp != NULL; temp = temp -> next ) {
        printf("%d ",temp -> data);
    }
    printf("\n");
}

int main(void) {
    int input;
    while ( input > 0 ) {
        printf("Stack input options :\n 1. Push\n 2. Pop\n 3. Top\n 0. Exit\n");
        scanf("%d",&input);
        switch (input) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                top();
                break;
            case 0:
                printf("Exiting");
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
        printStack();
    }
    return 0;
}
