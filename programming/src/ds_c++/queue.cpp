#include <iostream>
#define SIZE 5

using namespace std;

class queue {
    int arr[SIZE];
    int front;
    int rear;

    public:

    queue() {
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        if ( front == rear ) {
            return true;
        } else {
            return false;
        }
    }

    bool isFull() {
        if ( rear == SIZE ) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(int x) {
        if ( !isFull() ) {
            arr[rear] = x;
            rear++;
        } else {
            cout << "Queue already full!!" << endl;
        }
    }

    int dequeue() {
        if ( !isEmpty() ) {
            return arr[front++];
        } else {
            cout << "Queue is already empty" << endl;
            return 0;
        }
    }

};

int main (void) {
    queue q;
    int input = 1, num;
    while ( input > 0 ) {
        cout << "Queue Operations Menu : " << endl;
        cout << "1 Enqueue " << endl;
        cout << "2 Dequeue " << endl;
        cout << "3 Is Empty " << endl;
        cout << "4 Is Full " << endl;
        cout << "0 Exit " << endl;
        cin >> input;
        if ( input == 0 ) {
            break;
        }
        if ( input == 1 ) {
            cin >> num;
            q.enqueue(num);
        } else if ( input == 2 ) {
            cout << " Popping Element : " << q.dequeue() << endl;
        } else if ( input == 3 ) { 
            cout << "Queue is Empty : " << q.isEmpty() << endl;
        } else if ( input == 4 ) {
            cout << "Queue is Full : " << q.isFull() << endl;
        }
    }
    return 0;
}
