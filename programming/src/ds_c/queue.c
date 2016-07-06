#include <stdio.h>
#include <stdlib.h>

struct nn {
    int data;
    struct nn * next;
};

typedef struct nn node;
node * front = NULL;
node * rear = NULL;
node * newnode;
node * temp;
node * ptr;

node * create_node (int x) {
    node * result = (node *) malloc(sizeof(node));
    result -> data = x;
    result -> next = NULL;
    return result;
}

void enqueue() {
    int val;
    scanf("%d",&val);
    newnode = create_node(val);
    if ( front == rear && front == NULL ) {
        front = newnode;
        rear = newnode;
    } else {
        rear -> next = newnode;
        rear = rear -> next; 
    }
}

void dequeue() {
    if ( rear == NULL ) {
        printf("No elements in queue\n");
    } else {
        printf("Dequeuing element : %d\n", front -> data);
        if ( front == rear ) {
            front = NULL;
            rear = NULL;
            free(front);
            free(rear);
        } else {
            temp = front;
            front = front -> next;
            free(temp);
        }
    }
}

void printQueue() {
    printf("Queue : ");
    for ( ptr = front; ptr != NULL; ptr = ptr -> next ) {
        printf("%d ",ptr -> data);
    }
    printf("\n");
}

int main(void) {
    int input, x;
    while ( input > 0 ) {
        printf("Queue input options :\n 1. Enqueue\n 2. Dequeue\n 0. Exit\n");
        scanf("%d",&input);
        switch (input) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 0:
                printf("Exiting");
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
        printQueue();
    }
    return 0;
}
