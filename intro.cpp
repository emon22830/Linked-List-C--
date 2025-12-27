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
    HEAD = NULL;
    // cout<<HEAD->data<<endl;
    // cout<<HEAD->next<<endl;


    int arr[] = {1,2,3,4,5};


    //Insert the Node at beginning 

    for(int i=0; i<5; i++){
        
    //Linked List doesn,t exist
    if(HEAD == NULL){
        HEAD = new NODE(arr[i]);
       
    }

    //lINKED LIST EXISTS
    else{
        NODE* temp = new NODE(arr[i]);
        temp->next = HEAD;
        HEAD = temp;
    }
    }

  //Print the linked list
    NODE *temp = HEAD;
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }


    return 0;

}