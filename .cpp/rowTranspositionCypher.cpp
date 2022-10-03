#include<iostream>
#include <vector>
#include<string>
using namespace std;

int indexOf(int key[], int el, int size) {
    for(int i=0; i<size; i++) {
        if( el == key[i] ) {
            return i;
        }
    }
    return -1;
}

string newPlain(string plain, int key) {
    int lp=plain.length(), lk = key;

    if( !(lp%lk == 0) ) {
        int ch = 90 - (lk-(lp%lk)-1);

        for(int i=0; i<(lk-(lp%lk)); i++ ) {
            plain += ch;
            ch++;
        }
    }
    return plain;
}

vector<vector<int>> mat(int key[], int row, string plain, int size) {
    vector<vector<int>> res;
    int ch = 0;

    // int r = (sizeof(key))/(sizeof(key[0])); //check size (debug)
    // cout<< "size -> " << r<< "\n";
    
    for(int i=0; i<row; i++) {
        vector<int> temp;
        for(int j=0; j < size ; j++) {
            temp.push_back(plain[ch]);
            ch++;
        }
        res.push_back(temp);
    }

    // MATRIX CHECK
    // for(int i=0; i<row; i++) {
    //     for(int j=0; j < size ; j++) {
    //         cout<< res[i][j] << " ";
    //     }
    //     cout<< "\n";
    // }

    return res;
}

string encrypt(vector<vector<int>> msg, int key[] ,int size, int row) {
    string res = "";
    for(int i=1; i<size+1; i++) {
        int in = indexOf(key, i, size) ;
        for(int j=0; j<row ; j++) {
            res += msg[j][in];
        }
    }
    return res;
}

string decrypt(string cypher, int key[], int row, int size) {
    vector<vector<int>> ori;

    // for(int i=0; i<row; i++) {
    //     vector<int> temp;
    //     for(int j=0; j<size; j++) {
    //         temp.push_back(0);
    //     }
    //     ori.push_back(temp);
    // }

    for(int i = 0;i<row;i++){
        ori.push_back({});
        for(int j = 0;j<size;j++){
            ori[i].push_back(j);
        }
    }

    int ch=0;
    for(int i=1; i<size+1; i++) {
        int in = indexOf(key, i, size);
        for(int j=0; j<row; j++) {
            ori[j][in] = cypher[ch];
            ch++;
        }
    }

    string res = "";

    for(int i=0; i<row; i++) {
        for(int j=0; j<size; j++) {
            res += ori[i][j];
        }
    }
    return res;
}

int main()
{
    int key[] = {3, 4, 2, 1, 5, 6, 7};
    string plain = "ATTACKPOSTPONEDUNTILTWOAM";
    int size = sizeof(key)/sizeof(int);

    plain = newPlain(plain, 4);

    int row = plain.length() / size;

    vector<vector<int>> m = mat(key, row, plain, size);

    string cypher = encrypt(m, key, size, row ), originalText = decrypt(cypher, key, row, size);
    cout<< "CYPHER TEXT -> " <<cypher<< "\nORIGINAL TEXT -> " << originalText;
    return 0;
}