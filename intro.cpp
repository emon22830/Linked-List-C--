#include<iostream>
using namespace std;


class NODE{
    public:
    int data;
    NODE* next;

    NODE(int val){
        data = val;
        next = NULL;    
    }
};



int main(){
    NODE* HEAD;
    HEAD = new NODE(10);
    cout<<HEAD->data<<endl;

}