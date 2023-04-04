#include <iostream>
using namespace std;

#define MAX_SIZE 10 // define maximum size of stack

class Stack {
    private:
        int top;
        int arr[MAX_SIZE];
    
    public:
        Stack() { // constructor to initialize top to -1
            top = -1;
        }

        void push(int x) {
            if (isFull()) { // check if stack is full
                cout << "Stack Overflow!" << endl;
                return;
            }
            top++; // increment top
            arr[top] = x; // insert element
            cout << x << " pushed into stack" << endl;
        }

        void pop() {
            if (isEmpty()) { // check if stack is empty
                cout << "Stack Underflow!" << endl;
                return;
            }
            int popped = arr[top]; // get the element to be popped
            top--; // decrement top
            cout << popped << " popped from stack" << endl;
        }

        bool isEmpty() {
            return (top == -1);
        }

        bool isFull() {
            return (top == MAX_SIZE-1);
        }

        int stackTop() {
            if (isEmpty()) { // check if stack is empty
                cout << "Stack is empty!" << endl;
                return -1;
            }
            return arr[top]; // return the topmost element
        }

        void display() {
            if (isEmpty()) { // check if stack is empty
                cout << "Stack is empty!" << endl;
                return;
            }
            cout << "Elements in stack: ";
            for (int i = top; i >= 0; i--) { // loop through the stack
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Stack s;

    s.push(5);
    s.push(10);
    s.push(15);

    s.display(); // display elements in stack

    s.pop();

    cout << "Top element is " << s.stackTop() << endl;

    s.display(); // display elements in stack

    return 0;
}