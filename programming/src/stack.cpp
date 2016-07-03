#include <iostream>
#define SIZE 5

using namespace std;

class stack {
    int arr[SIZE];
    int tos;

    public:

    stack() {
        tos = 0;
    }

    bool isEmpty() {
        if ( tos == 0 ) {
            return true;
        } else {
            return false;
        }
    }

    bool isFull() {
        if ( tos == SIZE ) {
            return true;
        } else {
            return false;
        }
    }

    void push(int x) {
        if ( !isFull() ) {
            arr[tos] = x;
            tos++;
        } else {
            cout << "Stack Overflow error!!" << endl;
        }
    }

    int pop() {
        if ( !isEmpty() ) {
            return arr[--tos];
        } else {
            cout << "Stack is empty" << endl;
            return 0;
        }
    }

};

int main (void) {
    stack s;
    int input = 1, num;
    while ( input > 0 ) {
        cout << "Stack Operations Menu : " << endl;
        cout << "1 Push " << endl;
        cout << "2 Pop " << endl;
        cout << "3 Is Empty " << endl;
        cout << "4 Is Full " << endl;
        cout << "0 Exit " << endl;
        cin >> input;
        if ( input == 0 ) {
            break;
        }
        if ( input == 1 ) {
            cin >> num;
            s.push(num);
        } else if ( input == 2 ) {
            cout << " Popping Element : " << s.pop() << endl;
        } else if ( input == 3 ) { 
            cout << "Stack is Empty : " << s.isEmpty() << endl;
        } else if ( input == 4 ) {
            cout << "Stack is Full : " << s.isFull() << endl;
        }
    }
    return 0;
}
