#include <iostream>
#include <string>
using namespace std;


class CarSale {
    public:
        string model;
        string brand;
        int unitSale;



        CarSale* next;
        CarSale* prev;

        CarSale(string m, string b, int us)
        {
            model = m;
            brand =b;
            unitSale =us;
            next=NULL;
            prev=NULL;
        }

        void printSaleInfo(){
            cout << model << "(" << brand <<")" << " - " << unitSale << "units\n";
        }

        ~CarSale(){
            cout << "Destroy CarSale: "<<model <<"\n";
        }
        
}; //end of CarSale Class

class DoublyLinkedList {
    private:
        CarSale* head;
        CarSale* tail;


        public: 
        DoublyLinkedList(){
            head = NULL;
            tail = NULL;
        }

        void initializeList(CarSale *sales[], int size){
                for (int i = 0; i < size; ++i) {
                 CarSale* stf = sales[i] ;
                 cout << "Add" <<stf->model <<"to the list...\n";
                 
                 

                 if(!head){
                    head = tail = stf;
                 } else {
                    tail->next = stf;
                    stf->prev= tail;
                    tail = stf;
                 }
                }
        }


        //Task-1
        void displayForward(){
            CarSale* curr = head;
            while(curr !=NULL){
                curr->printSaleInfo();
                curr = curr->next;
            }
        }


        //Task-2
        void displayBackward(){
            CarSale* curr = tail;

            while(curr !=NULL){
                curr -> printSaleInfo();
                curr = curr -> prev;
            }
        }

        //Task-3
        void addBetween(){
            CarSale* newCarsSale = new CarSale("Hilux", "Toyta",11508);
            CarSale* vios = head -> next;

            head ->next = newCarsSale;
            newCarsSale ->prev =head;

            newCarsSale->next = vios;
            vios->prev = newCarsSale;
        }

        //Task 4
        void deleteLast(){
            CarSale* temp = tail;
            tail = tail -> prev;
            tail -> next = nullptr;
            delete temp;
        }

        //Task 5
        void replaceFirst(){
            CarSale* temp = tail;
            tail = tail -> prev;
            tail -> next = nullptr;
            delete temp;
        }

        //Task6
        void replaceFirst(){
            CarSale* newCarSale = new CarSale("Bezza", "PERODUA", 8963);
            CarSale* temp = head;

            newCarSale -> next = head -> next;
            head -> next ->prev = newCarSale;
            head = newCarSale;

            delete temp;
        }

        //Display-
        void displayAndTotal(){
            float totalUnitSales = 0;
            CarSale* curr = head;

            while(curr){
                CarSale* temp = curr;

                curr = curr->next;
                temp->printSaleInfo();
                totalUnitSales += temp->unitSale;
                delete temp;
            }
            head = NULL; tail = NULL;
            cout << "\n TOTAL SAFE =" << totalUnitSales << " units\n";
        }



};

int main(){
    DoublyLinkedList dll;

    CarSale* sales[]={
        new CarSale("Axia", "PERODUA", 12030),
        new CarSale("Myvi", "PERODUA", 11050),
    };

   int size = sizeof(sales)/sizeof(sales[0]);
   dll.initializeList(sales, size);

    //Task 1: Display forward
    cout << "\n Task1: Display forward\n";
    dll.displayForward();

    //Task 2: Display backward
    cout << "\n Task2: Display backward\n";
    dll.displayBackward();

    //Task3:
    cout << "\n Task3 : Add Hilux Between Saga and vios\n";
    dll.addBetween();

    cout << "\n Display Forward:\n";
    dll.displayForward();
}






int main(){
    return 0;
}