/*B. Skibidus and Ohio
time limit per test1 second
memory limit per test256 megabytes
Skibidus is given a string s
 that consists of lowercase Latin letters. If s
 contains more than 1
 letter, he can:

Choose an index i
 (1≤i≤|s|−1
, |s|
 denotes the current length of s
) such that si=si+1
. Replace si
 with any lowercase Latin letter of his choice. Remove si+1
 from the string.
Skibidus must determine the minimum possible length he can achieve through any number of operations.

Input
The first line contains an integer t
 (1≤t≤100
) — the number of test cases.

The only line of each test case contains a string s
 (1≤|s|≤100
). It is guaranteed s
 only contains lowercase Latin letters.

Output
For each test case, output an integer on the new line, the minimum achievable length of s
.

Example
InputCopy
4
baa
skibidus
cc
ohio
OutputCopy
1
8
1
4
Note
In the first test case, Skibidus can:

Perform an operation on i=2
. He replaces s2
 with b and removes s3
 from the string. Then, s
 becomes bb.
Perform an operation on i=1
. He replaces s1
 with b and removes s2
 from the string. Then, s
 becomes b.
Because s
 only contains 1
 letter, Skibidus cannot perform any more operations.
Therefore, the answer is 1
 for the first test case.

In the second test case, he cannot perform an operation on any index. Therefore, the answer is still the length of the initial string, 8
.*/

#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s1, string s2) {
    int i = 0, j = 0;
    int len1 = s1.length(), len2 = s2.length();

    // Traverse s2 and match characters from s1 in order
    while (i < len1 && j < len2) {
        if (s1[i] == s2[j]) {
            i++; // Move pointer in s1 if a match is found
        }
        j++; // Always move pointer in s2
    }

    // If we matched all characters of s1 in s2, return true
    return (i == len1);
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    if (isSubsequence(s1, s2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        solve();
    }

    return 0;
}
