#include <iostream>
#include <vector>
#include<string>
using namespace std;

string encrypt(string s, int n) {
    string res = "";
    for(int i=0; i<n; i++) {
        for(int j=i; j<s.length(); j+=n) {
            res += s[j];
        }
    }
    return res;
}

int main() {
    string s = "CHAOTICMAP";
    int n;
    cout<<"Enter range : ";
    cin>>n;
    string res = encrypt(s,n);
    cout<<"Cypher Text -> "<<res;
    return 0;
}