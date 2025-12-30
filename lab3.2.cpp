// Test 2 - SECJ2013 - 24251 (Test2-2cl.cpp)
// Name: MD EMON
// Matric No.: A24CS4023
// Section: 2

#include <iostream>
#include <string>

using namespace std;

const int STACK_SIZE = 5;

class Cylinder {
    private:
        string ID;
        int radius, height;

    public:
        Cylinder() {}

        Cylinder(string id, int r, int h) {
            ID = id;
            radius = r;
            height = h;
        }

        string getID() {
            return ID;
        }

        int volume() {
            return 3.14 * radius * radius * height;
        }

        void printCylinderInfo() {
            cout << ID << ", " << volume() << "\n";
        }
};

class Stack {
    public:
        int top;
        Cylinder data[STACK_SIZE];

        // Task 1: Complete the createStack() function
        void createStack() {
            top = -1;

        }

        // Task 2: Complete the push() function
        void push(Cylinder cl) {
            if(isFull()){
                cout << "Stack is full. Cannot push Cylinder " << cl.getID() << "\n";
                       
            }
            else{
                cout<< "Push Cylinder " << cl.getID() << " onto stack.\n";
                top++;
                data[top] = cl;
            }

        }

        // Task 3: Complete the pop() function
        void pop() {
            if(isEmpty()){
                cout << "Stack is empty. Cannot pop Cylinder.\n";

            }
            else{
                Cylinder topItem = stackTop();
                top--;
                cout << "Pop Cylinder " << topItem.getID() << " from stack.\n";
            }

        }

        // Task 4: Modify the stackTop(), isEmpty(), and isFull() functions
        Cylinder stackTop() { 
            return data[top];
        }
        bool isEmpty() {
              return (top == -1 );
             }
        bool isFull() {
              return (top == STACK_SIZE - 1 );
             }

        void checkContent() {
            cout << "Current stack content:\n";

            if (!isEmpty()) {
                for (int i = top; i > -1 ; i--) {
                    if (i == top) { 
                        cout << "Top -> ";
                    } else {
                        cout << "       ";
                    }

                    data[i].printCylinderInfo();
                }
            }
        }
};


// main function
int main() {
    Cylinder cylinders[6] = { Cylinder("CL3215", 60, 20),
                              Cylinder("CL9253", 15, 42),
                              Cylinder("CL4399", 15, 12),
                              Cylinder("CL3200", 19, 18),
                              Cylinder("CL8480", 75, 30),
                              Cylinder("CL4350", 12, 35),
                            };

    Stack cylinderStack;
    cylinderStack.createStack();

    cout << "Try to push all cylinders onto the stack:\n";
    for (int i = 0; i < 6; i++) {
        cylinderStack.push(cylinders[i]);
    }
    cout << "\n";

    cout << "Cylinder at top => ";
    cylinderStack.stackTop().printCylinderInfo();
    cout << "\n";

    cylinderStack.checkContent();
    cout << "\n\n";

    cout << "Pop stack until Cylinder 'CL4399' becomes the top and \n";
    cout << "then push Cylinder 'CL4350' onto the stack... \n";

// Task 5:
    // pop cylinder objects using 'while' loop until 
    // Cylinder 'CL4399' becomes the top
    // ???
    // ???
    // ???

    // push Cylinder 'CL4350' onto stack
    // ???
    while(cylinderStack.stackTop().getID() != "CL4399") {
        cylinderStack.pop();
    }

    cylinderStack.push( cylinders[5] ); // Push Cylinder 'CL4350'
    cout << "\n";

    cout << "pop all cylinders from stack:\n";
    while (!cylinderStack.isEmpty()) {
        cylinderStack.pop();
    }

    cout << "\nTry to pop Cylinder even stack is empty:\n";
    cylinderStack.pop();
    return 0;



    

    cylinderStack.checkContent();
    cout << "\n";

    cout << "Pop all cylinders from stack:\n";
    while (!cylinderStack.isEmpty()) {
        cylinderStack.pop();
    }
    cout << "\n";

    cout << "Try to pop Cylinder even stack is empty:\n";
    cylinderStack.pop();
     
    return 0;
}