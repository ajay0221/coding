#include <stdio.h>
#include <stdlib.h>

struct nn {
    int data;
    struct nn * next;
};

typedef struct nn node;
node * first = NULL;
node * last = NULL;
node * newnode;
node * ptr;
node * nxt;
node * prev;
node * temp;

node * create_node (int x) {
    node * result = (node *) malloc(sizeof(node));
    result -> data = x;
    result -> next = NULL;
    return result;
}

void insert_at_first() {
    int val;
    printf("Enter the value : ");
    scanf("%d",&val);
    newnode = create_node(val);
    if ( first == last && first == NULL ) {
        first = newnode;
        last = newnode;
    } else {
        temp = first;
        first = newnode;
        first -> next = temp;
    }
}

void insert_at_end() {
    int val;
    printf("Enter the value : ");
    scanf("%d",&val);
    newnode = create_node(val);
    if ( last == first && last == NULL ) {
        first = newnode;
        last = newnode;
    } else {
        last -> next = newnode;
        last = newnode;
    }
}

node * get_ith_node_from_start(int index) {
    int i = 0;
    for ( ptr = first; ptr != NULL && i < index; ptr = ptr -> next ) i++;
    return ptr;
}

void insert_at_position() {
    int val, index;
    printf("Enter the value : ");
    scanf("%d",&val);
    printf("Enter the position : ");
    scanf("%d",&index);
    newnode = create_node(val);
    int length = 0;
    for ( ptr = first; ptr != NULL; ptr = ptr -> next ) length++;
    if ( index == 1 ) {
        if ( first == last && first == NULL ) {
            first = newnode;
            last = newnode;
        } else {
            temp = first;
            first = newnode;
            first -> next = temp;
        }
    } else if ( index > 1 && index <= length ) {
        ptr = first;
        for ( int i = 1; i < index; i++ ) {
            prev = ptr;
            ptr = ptr -> next;
        }
        prev -> next = newnode;
        newnode -> next = ptr;
    } else {
        printf("Out of range\n");
    }
}

void sort() {
    if ( first == NULL ) {
        printf("No elements to sort\n");
    } else {
        for ( ptr = first; ptr != NULL; ptr = ptr -> next ) {
            for ( nxt = ptr -> next; nxt != NULL; nxt = nxt -> next ) {
                if ( ptr -> data > nxt -> data ) {
                    int tmpData = ptr -> data;
                    ptr -> data = nxt -> data;
                    nxt -> data = tmpData;
                }
            }
        }
    }
}

void delete_at_position() {
    int index;
    printf("Enter the position : ");
    scanf("%d",&index);
    int length = 0;
    for ( ptr = first; ptr != NULL; ptr = ptr -> next ) length++;
    if ( index == 1 ) {
        if ( first == last && first == NULL ) {
            printf("Nothing to delete\n");
        } else {
            temp = first;
            first = first -> next;
            free(temp);
        }
    } else if ( index > 1 && index <= length ) {
        ptr = first;
        for ( int i = 1; i < index; i++ ) {
            prev = ptr;
            ptr = ptr -> next;
        }
        prev -> next = ptr -> next;
        free(ptr);
    }
}

void printList() {
    if ( first == NULL ) {
        printf("List is empty \n");
    } else {
        printf("Current Linked List : ");
        for ( ptr = first; ptr != NULL; ptr = ptr -> next ) {
            printf("%d ",ptr -> data);
        }
        printf("\n");
        printf("====================\n");
    }
}

void reversePrint (node * root) {
    if ( root == NULL ) {
        return;
    } else {
        reversePrint(root -> next);
        printf("%d ",root -> data);
    }
}

int main(void) {
    int input, x;
    while ( input > 0 ) {
        printf("LL input options :\n 1. Insert at begining\n 2. Insert at end\n 3. Insert at Position\n 4. Sort in Ascending Order\n 5. Delete at Position\n 6. Recursively Print Reverse List\n 0. Exit\n");
        scanf("%d",&input);
        switch (input) {
            case 1:
                insert_at_first();
                break;
            case 2:
                insert_at_end();
                break;
            case 3:
                insert_at_position();
                break;
            case 4:
                sort();
                break;
            case 5:
                delete_at_position();
                break;
            case 6:
                reversePrint(first);
                printf("\n");
                break;
            case 0:
                printf("Exiting");
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
        printList();
    }
    return 0;
}
