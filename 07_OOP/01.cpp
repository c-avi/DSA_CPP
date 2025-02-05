//OOPS: Scalable code likhne mein mdd krta hai
    //OBJECT : will be considered as real life entity
    //CLASS: a structure where i define attributes and behaviour
        //ATTRIBUTES:Properties(e.g., car ki noof window,seats,wheels)
        //BEHAVIOUR: e.g., this car can fly

//Classes and objects
#include<iostream>
using namespace std;

class Car{
    //Attributes -> data members -> variables
    public: //Access modifiers: Initially class k andr sb cheeze private hai
    string color;
    int speed;
    int price;

//Constructor:  is a special type of method that is same name as that of class
                    //no return type.
                    //ye to chalega hi  chalega
                    //initializing the values so that jb koi value defined na ho to default values call ho
                    //jb jb object call  hoga tb constructor envoke hoga
                    //jb bhi class ka object call hoga for sure constructor a default constructor is called chahe tum constructor bulao ya nhi
                    //you can have multiple constructors
    Car(){
        cout << "This is from Constructor method " << endl;
    }

    

    //Behaviours -> member functions -> functions
    void boostUp(){

    }
};

int main(){
    Car car1;//An object car1 is created as Car 
    //Car class koi space nhi le rha memory mein , sirf entity space leti hai
    car1.color = "Black"; 
    car1.speed = 100;

    // cout << car1.price << endl;
    //when price is not defined to garbage value display hoti hai.
    

    Car car2;
    car2.color = "Red";
    // cout << car2.color << endl;
}