#include<iostream>
using namespace std;

void reachDest(int s, int e){
    //base case
    if(s==e){
        cout<<"Destination reached";
        return;
    }

    s++;

    reachDest(s,e);
}

int sol(int n){
    //base case
    if(n == 0){
        return 1;
    }
    //relation
    return 2*sol(n-1);

}

int factorial(int n){
    //base case
    if (n==0) return 1;

    n*factorial(n-1);
    
}

int recursivefibonacci(int n) {
    // Base case
    if (n == 0) return 0; 
    if (n == 1) return 1; 

    // Recursive relation
    return recursivefibonacci(n - 1) + recursivefibonacci(n - 2); 
}

int iterativeFibonacci(int n){
    if(n==1 || n==2) return -1;
    int a=0,b=1;
    int ans;
    for(int i=3;i<=n;i++){
        ans=a+b;
        a=b;
        b=ans;
    }
    return ans;

}

int main(){
    // reachDest()
}