// VIGENERE CYPHER
#include <iostream>
#include<string>
using namespace std;

int str_length(string s) {
    
    int c = 0;
    while(s[c]) {
        c++;
    }
    return c;
}

string txtUpper(string s, int l) {
    string res = "";

    for(int i=0; i<l; i++) {
        int temp = s[i];
        if( 65<=temp && temp<=90) {
            temp += 32;
        }
        res += temp;
    }
    return res;
}

string keylen(string key, int plain) {
    int temp = str_length(key);

    for(int i=0; i<plain-temp; i++) {
        key += key[i%temp];
    }
    return key;
}

string msgToCypher(string plain, string key, int l) {
    string table = "abcdefghijklmnopqrstuvwxyz";
    
    string res = "";
    
    for(int i=0; i<l; i++) {
        int a = plain[i];
        int b = key[i];
        res += table[ ( (a-97) + (b-97) )%26 ];   /*(110-97) + (99-97) 13+2 = 15%26*/
    }
    
    return res;
}

string cypherToPlain(string cypher, string key, int l) {
    string table = "abcdefghijklmnopqrstuvwxyz";
    
    string res = "";
    
    for(int i=0; i<l; i++) {
        int a = cypher[i];
        int b = key[i];
        int temp = a-b;    
        if( temp < 0) {
            temp = 26 + temp;
        }
        res += table[ temp ];
    }
    
    return res;
}

int main() {
    string msg, key;

    cout << "Enter your message : ";
    cin >> msg;
    cout << "Enter key : ";
    cin >> key;
    
    int l = str_length(msg);
    key = keylen(key, l);
    // cout<< key;

    msg = txtUpper(msg, l);
    key = txtUpper(key, l);

    // cout<< msg << " "<< key;

    string cypher = msgToCypher(msg, key, l);
    string plain = cypherToPlain(cypher, key, l);

    cout<< "CYPHER TEXT -> " << cypher << "\n" << "ORIGINAL TEXT -> "<< plain;
    
    return 0;
}
