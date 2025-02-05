//Constructor

#include<iostream>
using namespace std;

class Room{
    public:
    int height;
    int width;

    Room(){
        //defaut constructor
        cout<<"From default  constructor"<<endl;
    }

    Room(int h){
        cout << "1";
        cout<<"From parameter cons"<<endl;
    }

//CONTRUCTOR OVERLOADING: same name diff parameter
    Room(int height, int width){
        //this is used in ambiguity . pta nhi kon si height hai
        this->height = height;
        this->width = width;
        cout<<"Fro para2 constr"<<endl;
    }

//COPY CONSTRUCTOR
//constructor values ko copy kr rha hai
    Room(Room &obj){
        this->height = obj.height;
        this->width=obj.width;
        cout<<"From copy constructor"<<endl;
    }

    //DESTRUCTOR
    //jb object ko dstroy krna hota hai kaam hone k baad
    ~Room(){
        cout<<"This is a destructor"<<endl;
    }
};




int main(){
    Room r1(3,5); //Paramiterized constructor bna diya to parameter to pass krna hi hoga
    // cout<<r1.height;

    // Room r2(r1);
    Room r2 = r1;

    cout<<r2.height<<endl;
}

