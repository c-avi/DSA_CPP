//4 pillars of oops(encapsulation,polymorphism,abstraction)
  //1.Encapsulation:capsule, closed entity, we r binding together data members and member functions
  //we cannot access any data or function from the class directly
  //this will increase the security of the data
  //this will also help to control the modification of our data members
  //bind mtlb class k andr wrap krke rkhenge for security

#include<iostream>
using namespace std;

class Encapsulation
{
private:
    int salary;

public:
    Encapsulation(int val){
        salary=val;
    }

    //getter
    //proper way hua kisi cheez ko access krne ka
    //you won't keep member variables vulnerable
    int getSalary(){
        return salary;
    }

    //setter 
    void setSalary(int amount){
        salary=amount;
    }


};




int main(){
    Encapsulation e1(1000);

    cout << e1.getSalary()<<endl;

    e1.setSalary(2000);

    cout<<e1.getSalary()<<endl;
}