#include <iostream>
#include<string>
#include<vector>
using namespace std;

bool linearset(string s, char el, int len) {
    for(int i=0; i<len; i++) {
        if(el == s[i]) return false;
    }
    return true;
}
int str_length(string s) {
    
    int c = 0;
    while(s[c]) {
        c++;
    }
    return c;
}

vector<vector<char>> newKey(string key) {
    key += "abcdefghijklmnopqrdstuvwxyz";
    string newKey = "";
    int nkl = 0;
    for(int i=0; i<key.length(); i++) {
        if( linearset(newKey, key[i], nkl) ) {
            if( key[i] == 'i' || key[i] == 'j' ) {
                newKey += "ij";
                nkl+=2;
                continue;
            }
            newKey += key[i];
            nkl++;
        }
    }
    vector<vector<char>> keyMatrix;
    int index = 0;
    for(int i=0; i<5; i++) {
        vector<char> temp;
        for(int j=0 ;j<5; j++) {
            if( newKey[index] == 'i' ) {
                temp.push_back('i');
                index += 2;
                continue;
            }
            temp.push_back( newKey[index] );
            index++;
        }
        keyMatrix.push_back(temp);
    }
    for(int i=0; i<5; i++) {
        cout << "[";
        for(int j=0; j<5 ; j++) {
            cout << "'" << keyMatrix[i][j] << "'," ;
        }
        cout << "]";
        cout<< "\n";
    }
    return keyMatrix;
}

void position(vector<vector<char>> keyMatrix, char el, int* x, int* y) {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(el == keyMatrix[i][j]) {
                *x = i;
                *y = j;
                return;
            }
        }
    }
}

string encrypt(vector<vector<char>> keyMatrix, string plain) {
    string cypher = "";
    int firstRow,firstColumn,secondRow,secondColumn;

    for(int i=0; i < str_length(plain); i+=2) {
        position( keyMatrix, plain[i], &firstRow, &firstColumn );
        position( keyMatrix, plain[i+1], &secondRow, &secondColumn );

        if( firstRow == secondRow ) {
            cypher += keyMatrix[firstRow][(firstColumn+1)%5];
            cypher += keyMatrix[secondRow][(secondColumn+1)%5];
            // cout << keyMatrix[firstRow][(firstColumn+1)%5] << keyMatrix[secondRow][(secondColumn+1)%5];
        }
        else if( firstColumn == secondColumn ) {
            cypher += keyMatrix[ (firstRow+1)%5 ][ firstColumn ];
            cypher += keyMatrix[ (secondRow+1)%5 ][ secondColumn ];
            // cout << keyMatrix[ (firstRow+1)%5 ][ firstColumn ] << keyMatrix[ (secondRow+1)%5 ][ secondColumn ];
        }
        else {
            cypher += keyMatrix[ firstRow][ secondColumn ];
            cypher += keyMatrix[ secondRow ][ firstColumn ];
            // cout << keyMatrix[ firstRow][ secondColumn ] << keyMatrix[ secondRow ][ firstColumn ];
        }
    }
    return cypher;
}

string decrypt(vector<vector<char>> keyMatrix, string cypher) {
    string originalMessage = "";
    int firstRow,firstColumn,secondRow,secondColumn;

    for(int i=0; i < str_length(cypher); i+=2) {
        position( keyMatrix, cypher[i], &firstRow, &firstColumn );
        position( keyMatrix, cypher[i+1], &secondRow, &secondColumn );

        if( firstRow == secondRow ) {
            originalMessage += keyMatrix[firstRow][(firstColumn+4)%5];
            originalMessage += keyMatrix[secondRow][(secondColumn+4)%5];
            // cout << keyMatrix[firstRow][(firstColumn+4)%5] << keyMatrix[secondRow][(secondColumn+4)%5];
        }
        else if( firstColumn == secondColumn ) {
            originalMessage += keyMatrix[ (firstRow+4)%5 ][ firstColumn ];
            originalMessage += keyMatrix[ (secondRow+4)%5 ][ secondColumn ];
            // cout << keyMatrix[ (firstRow+1)%5 ][ firstColumn ] << keyMatrix[ (secondRow+1)%5 ][ secondColumn ];
        }
        else {
            originalMessage += keyMatrix[ firstRow][ secondColumn ];
            originalMessage += keyMatrix[ secondRow ][ firstColumn ];
            // cout << keyMatrix[ firstRow][ secondColumn ] << keyMatrix[ secondRow ][ firstColumn ];
        }
    }
    return originalMessage;
}

int main() {
    string plain = "abhaykalez", key = "monarchy";
    
    // key = newKey(key);

    vector<vector<char>> keyMatrix = newKey(key);

    string cypher = encrypt(keyMatrix, plain);
    cout << "Cypher Text : " << cypher << "\n";  


    string originalMessage = decrypt(keyMatrix, cypher);
    cout << "Original Message : " << originalMessage;  
    return 0;
}

//-------------------------------------------------------------------------------------------------

// #include <iostream>
// #include<string>
// #include<vector>
// using namespace std;

// bool linearset(string s, char el, int len) {
//     for(int i=0; i<len; i++) {
//         if(el == s[i]) return false;
//     }
//     return true;
// }

// vector<vector<string>> newKey(string key) {
//     key += "abcdefghijklmnopqrdstuvwxyz";
//     string newKey = "";
//     int nkl = 0;
//     for(int i=0; i<key.length(); i++) {
//         if( linearset(newKey, key[i], nkl) ) {
//             if( key[i] == 'i' || key[i] == 'j' ) {
//                 newKey += "ij";
//                 nkl+=2;
//                 continue;
//             }
//             newKey += key[i];
//             nkl++;
//         }
//     }
//     vector<vector<string>> keyMatrix;
//     int index = 0;
//     string n;
//     for(int i=0; i<5; i++) {
//         vector<string> temp;
//         for(int j=0 ;j<5; j++) {
//             n = "";
//             n += newKey[index];
//             if( newKey[index] == 'i' ) {
//                 temp.push_back("ij");
//                 index += 2;
//                 continue;
//             }
//             temp.push_back( n );
//             index++;
//         }
//         keyMatrix.push_back(temp);
//     }
//     for(int i=0; i<5; i++) {
//         cout << "[";
//         for(int j=0; j<5 ; j++) {
//             cout << "'" << keyMatrix[i][j] << "'," ;
//         }
//         cout << "]";
//         cout<< "\n";
//     }
//     return keyMatrix;
// }

// string encrypt(vector<vector<string>> keyMatrix, string plain) {
//     string cypher = "";

//     for(int i=0; i<5; i++) {

//     }

//     return cypher;
// }

// int main() {
//     string plain = "btechthirdyear", key = "student";
    
//     // key = newKey(key);

//     vector<vector<string>> keyMatrix = newKey(key);
    
//     return 0;
// }