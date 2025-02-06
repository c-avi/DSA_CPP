#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int prefixEval(string s) {
    stack<int> st;

    for (int i = s.length() - 1; i >= 0; i--) {
        if (isdigit(s[i])) {
            st.push(s[i] - '0');
        } else {
            int operand1 = st.top(); st.pop();
            int operand2 = st.top(); st.pop();

            switch (s[i]) {
                case '+': st.push(operand1 + operand2); break;
                case '-': st.push(operand1 - operand2); break;
                case '*': st.push(operand1 * operand2); break;
                case '/': 
                    if (operand2 == 0) {
                        cout << "Error: Division by zero\n";
                        return -1;
                    }
                    st.push(operand1 / operand2);
                    break;
                case '^': st.push(pow(operand1, operand2)); break;
            }
        }
    }
    return st.top();
}

int postfixEval(string s) {
    stack<int> st;

    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            st.push(s[i] - '0');
        } else {
            int operand2 = st.top(); st.pop();
            int operand1 = st.top(); st.pop();

            switch (s[i]) {
                case '+': st.push(operand1 + operand2); break;
                case '-': st.push(operand1 - operand2); break;
                case '*': st.push(operand1 * operand2); break;
                case '/': 
                    if (operand2 == 0) {
                        cout << "Error: Division by zero\n";
                        return -1;
                    }
                    st.push(operand1 / operand2);
                    break;
                case '^': st.push(pow(operand1, operand2)); break;
            }
        }
    }
    return st.top();
}

int main() {
    string prefix = "-+7*45+20"; // Correct prefix expression
    string postfix = "74*5+20+-"; // Correct postfix expression

    cout << "Prefix Evaluation: " << prefixEval(prefix) << endl;
    cout << "Postfix Evaluation: " << postfixEval(postfix) << endl;

    return 0;
}
