// problem requires us to check if only the letters in the string form a palindromic sequence, ignoring digits, special characters, and spaces,
//  while not using extra space. Below is the C++ code to solve this:
#include<iostream>
#include<string>
using namespace std;

bool isLetter(char ch){
    return (ch >= 'a' && ch <= 'z');
}

char toLowerCase(char ch){
    if (ch >= 'A' && ch <= 'Z'){
        return ch+32;
    }
    return ch;
}

bool isLetterPalindrome(const string& str){
    int left = 0, right = str.length()-1;

    while(left < right){
        while(left < right && !isLetter(str[left])){
            left++;
        }

        while(left < right && !isLetter(str[right])){
            right --;
        }

        if(toLowerCase(str[left]) != toLowerCase(str[right])){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main(){
    string str;
    cout << "Enter a string: ";
    getline(cin,str);

    if(isLetterPalindrome(str)){
        cout << "YES" << endl;
    }else{
        cout<< "NO" << endl;
    }

    return 0;
}