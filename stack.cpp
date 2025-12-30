
#include<iostream>
#include<string>
using namespace std;

const int STACK_SIZE = 5;

class Cylinder {
    private: 
    string ID;
    int radius, height;


    public: 
      
      Cylinder(string id, int r, int h){
       ID = id ;
       radius = r;
       height = h; 
      }

      string getTD(){
        return ID;
      }

      int volume(){
        return 3.14 * radius * radius * height;
      }
};

class Stack {
    public: 
        int top;
        Cylinder data[STACK_SIZE];




        void createStack(){
            top = -1;
        }


        void push(Cylinder cl){
            if(isFull()){
                cout << "Stack is full. Cannot push Cylinder " << cl.getID() << "\n";
            } else {
                cout << "Push Cylinder " << cl.getID() << " onto stack.\n";
                top++;
                data[top] = cl;
            }
        }
};

int main(){
    return 0;
}