/*C++ solution that efficiently answers queries about the frequency of a given character in the string. The approach preprocesses the frequency of each character in the string and answers each query in constant time 
O(1).*/
#include <iostream>
#include <unordered_map>
using namespace std;

void preprocessFrequency(const string& str, unordered_map<char, int>& freq){
    for (char ch : str){
        freq[ch]++;
    }
}

int main(){
    string str = "abacabde"; // Given string "abacabde"
    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    unordered_map<char, int> freq;
    preprocessFrequency(str, freq);

    while (q--){
        char ch;
        cout << "Enter character to find: ";
        cin >> ch;

        if (freq.find(ch) != freq.end()){
            cout << "Frequency of '" << ch << "' is: " << freq[ch] << endl;
        } else{
            cout << "Character '" << ch << "' not found in the string." << endl;
        }
    }

    return 0;
}