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

    h.minHeapInsert(50);
    h.minHeapInsert(30);
    h.minHeapInsert(40);
    h.minHeapInsert(10);
    h.minHeapInsert(5);
    h.minHeapInsert(20);
    h.minHeapInsert(60);

    cout << "Min Heap Elements: ";
    h.print();

    return 0;
}