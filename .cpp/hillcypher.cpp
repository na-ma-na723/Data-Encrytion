#include <iostream>
#include <vector>
#include<string>
using namespace std;

string arrToString(vector<int> ori) {
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string res = "";
    for(int i=0; i<ori.size(); i++) {
        res += s[ ori[i] ];
    }
    return res;
}

vector<vector<int>> keymatrix(string key,int n) {
    
    int ch=0;
    vector<vector<int>> res;
    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<n; j++) {
            int t = key[ch];
            temp.push_back(t - 65);
            ch++;
        }
        res.push_back(temp);
    }
    return res;
}

string encrypt1(vector<vector<int>> res, vector<int> msg , int n ) {
    vector<int> ori;
    for(int i=0; i<n; i++) {
        int temp = 0;
        for(int j=0; j<n; j++) {
            temp += msg[j]*res[j][i];
        }
        ori.push_back(temp); 
    }
    for(int i=0; i<n; i++) {
        ori[i] %= 26;
    }
    string r = arrToString(ori);
    return r;
}

string encrypt2(vector<vector<int>> res, vector<int> msg , int n ) {
    vector<int> ori;
    for(int i=0; i<n; i++) {
        int temp = 0;
        for(int j=0; j<n; j++) {
            temp += msg[j]*res[i][j];
        }
        ori.push_back(temp); 
    }
    for(int i=0; i<n; i++) {
        ori[i] %= 26;
    }
    string r = arrToString(ori);
    return r;
}

int main() {
    string key = "GYBNQKURP", plain = "ACT";
    
    vector<int> msg, ori;
    
    int l = plain.length();
    
    for(int i=0; i<l; i++) {
        int temp = plain[i];
        msg.push_back(temp - 65);
    }
    
    vector<vector<int>> res = keymatrix("GYBNQKURP", 3 );

    string cypher1 = encrypt1(res, msg, l), cypher2 = encrypt2(res, msg, l);
    
    cout<<"Cypher Text 1 -> "<<cypher1<< "\n" <<"Cypher Text 2 -> "<<cypher2;
    
    return 0;
}