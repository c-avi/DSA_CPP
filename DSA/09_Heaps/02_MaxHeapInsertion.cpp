#include <bits/stdc++.h>
using namespace std;

class heap{
public:
    int arr[100]; // Fixed-size array for heap storage
    int size;

    heap(){
        arr[0] = -1; // Not used, just a placeholder
        size = 0;
    }

    void maxHeapInsert(int val){ // time complexity worst: O(log N)
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1){
            int parent = index / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else{
                return;
            }

        }
    }

    void minHeapInsert(int val){ // time complexity worst: O(log N)
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1){
            int parent = index / 2;
            if(arr[parent] > arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else{
                return;
            }

        }
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    heap h;
    h.maxHeapInsert(50);
    h.maxHeapInsert(30);
    h.maxHeapInsert(40);
    h.maxHeapInsert(10);
    h.maxHeapInsert(5);
    h.maxHeapInsert(20);
    h.maxHeapInsert(60);

    cout << "Max Heap Elements: ";
    h.print();

    

    return 0;
}