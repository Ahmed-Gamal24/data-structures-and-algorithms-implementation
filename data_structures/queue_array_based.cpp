#include <iostream>
#include <optional>
using namespace std;


class clsQueue{
    
private:
    int* head;
    int* tail;
    #define size 10
    int arr[size];

public:
    clsQueue(){
        head = NULL;
        tail = NULL;
    }

    bool isEmpty(){
        return head == NULL && tail == NULL;
    }

    bool isFull(){
        return tail == &arr[size-1];
    }

    void enqueue(int num){
        if(isFull())
            return;
        else if (isEmpty()){
            arr[0] = num;
            head = tail = &arr[0];
        }
        else{
            ++tail;
            *tail = num;
        }
    }

    std::optional<int> dequeue(){
        if(isEmpty()) return {};
        else if(head == tail){
            int temp = *head;
            head = tail = NULL;
            return temp;
        }
        else{
            int temp = *head;
            head++;
            return temp;
        }
    }
    
    void display(){
        if(isEmpty())
            cout << "Queue is Empty" << endl;
        else{
            int* tempPtr = head;
            while(tempPtr <= tail){
                cout << *tempPtr << " ";
                tempPtr++;
            }
            cout << endl;
        }
    }

};


int main(){

    clsQueue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);

    q1.display(); // 1 2 3 4

    q1.dequeue();
    q1.dequeue();

    q1.display(); // 3 4


    return 0;
}