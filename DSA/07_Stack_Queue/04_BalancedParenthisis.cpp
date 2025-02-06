#include<iostream>
#include<stack>
using namespace std;

bool balancedParenthesis(string s){
    stack<char>st;

    for(char ch : s){
        if(ch == '{' || ch == '[' || ch == '('){
            st.push(ch);
        }else{
            if(st.empty()){ // Ensure stack is not empty before checking top
                return false;
            }
            if((ch == ']' && st.top() == '[' ) ||
            (ch == '}' && st.top() == '{' ) ||
            (ch == ')' && st.top() == '(' )){
                st.pop();
            }else{
                return false;
            
            }
        }
    }
    return st.empty();
}

int main(){
    string str;
    cout << "Enter the parenthesis string: ";
    cin >> str;
    if(balancedParenthesis(str)){
        cout << "balanced";
    }else{
        cout<<"not balanced";
    }
}
