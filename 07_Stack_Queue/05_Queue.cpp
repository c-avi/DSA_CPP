#include<iostream>
using namespace std;

class Queue{
public:
    int *arr;
    int front;
    int rear;
    int size;

    Queue(int s = 10){ // Default size is set to 10
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~ Queue(){ // Destructor to release memory
        delete[] arr;
    }

    void push(int val){
        if(rear == size-1){
            cout << "Queue overflow" << endl;
            return;
        }
        rear++;
        arr[rear] = val;
        if(front == -1) front = 0; // Ensure front points to the first element;
    }

    void pop(){
        if(front == -1 || front > rear){ // Check empty condition
            cout << "Queue is empty"<< endl;
            front = rear = -1; // Reset queue;
            return;
        }
        front++;
    }

    int peek(){

    }
};

int main(){
    

}
