// #include <iostream>
// #include<string>
// #include<vector>
// using namespace std;

// int firstOccurrence(int n,vector<int> factorsArray,int k) {
//     int l = 0, r=n-1;
//     while( l<=r ) {
//         int mid = (l+r)/2;
//         if( factorsArray[mid] == k ){
//             if( (mid-1)>=0 && factorsArray[mid] == factorsArray[mid-1] ) r=( mid- 1 );
//             else return mid;
//         }
//         else if( factorsArray[mid] > k ) r = mid-1;
//         else if( factorsArray[mid] < k ) l = mid+1;
//     }
//     return -1;
// }

// int lastOccurrence(int n,vector<int> factorsArray,int k) {
//     int l = 0,r = n -1;
//     while( l<=r ) {
//         int mid = (l+r)/2;
//         if(factorsArray[mid] == k) {
//             if( (mid+1) < n and factorsArray[mid] == factorsArray[mid+1] ) l = mid+1;
//             else return mid;
//         }
//         else if( factorsArray[mid] > k ) r = mid-1;
//         else if( factorsArray[mid] < k ) l = mid+1;
//     }
//     return -1;
// }

// int freq(int n, vector<int> factorsArray, int k) {
//     int l = lastOccurrence(n, factorsArray, k), f=firstOccurrence(n, factorsArray, k);
//     if( l>=0 || f>=0 ) return (l-f+1);
//     return 0;
// }

// vector<vector<int>> powerFunc( vector<int> factorsArray) {
//     vector<vector<int>> powerArray;
//     int n = factorsArray.size();
//     int i=0;
//     while(i<n) {
//         vector<int> temp;
//         int frequency = freq(n, factorsArray, factorsArray[i] );

//         temp.push_back( factorsArray[i] );
//         temp.push_back( frequency );
//         powerArray.push_back( temp );
        
//         i += frequency;
//     }
//     return powerArray;
// }

// vector<int> factors(int n) {
//     vector<int> f;
//     for(int i=2; i<=n; i++) {
//         if( n%i==0 ) {
//             while(n%i == 0) {
//                 f.push_back(i);
//                 n = n/i;
//             }
//         }
//     }
//     for(int i = 0; i<f.size(); i++) {
//         cout << f[i] << ", ";
//     }
//     cout << "\n";
    
//     return f;
// }

// int main() {
//     int n = 180;
//     vector<int> fact = factors(n);
    
    
//     vector<vector<int>> res = powerFunc(fact);
//     for(int i=0; i<res.size() ; i++) {
//         for(int j=0; j < 2  ; j++) {
//             cout<< res[i][j] << " ";
//         }
//         cout<< "\n";
//     }
//     cout<< "yes";
//     return 0;
    
// }
//----------------------------------------------------------------------------------------------------------------------------------

// #include <iostream>
// #include<string>
// #include<vector>
// using namespace std;

// int power(int n, int pow) {
//     if(pow == 0) return 1;
//     int s=1;
//     while(pow>0) {
//         s = s*n;
//         pow = pow-1;
//     }
//     return s;
// }

// int firstOccurrence(int n,vector<int> factorsArray,int k) {
//     int l = 0, r=n-1;
//     while( l<=r ) {
//         int mid = (l+r)/2;
//         if( factorsArray[mid] == k ){
//             if( (mid-1)>=0 && factorsArray[mid] == factorsArray[mid-1] ) r=( mid- 1 );
//             else return mid;
//         }
//         else if( factorsArray[mid] > k ) r = mid-1;
//         else if( factorsArray[mid] < k ) l = mid+1;
//     }
//     return -1;
// }

// int lastOccurrence(int n,vector<int> factorsArray,int k) {
//     int l = 0,r = n -1;
//     while( l<=r ) {
//         int mid = (l+r)/2;
//         if(factorsArray[mid] == k) {
//             if( (mid+1) < n and factorsArray[mid] == factorsArray[mid+1] ) l = mid+1;
//             else return mid;
//         }
//         else if( factorsArray[mid] > k ) r = mid-1;
//         else if( factorsArray[mid] < k ) l = mid+1;
//     }
//     return -1;
// }

// int freq(int n, vector<int> factorsArray, int k) {
//     int l = lastOccurrence(n, factorsArray, k), f=firstOccurrence(n, factorsArray, k);
//     if( l>=0 || f>=0 ) return (l-f+1);
//     return 0;
// }

// vector<vector<int>> powerFunc( vector<int> factorsArray) {
//     vector<vector<int>> powerArray;
//     int n = factorsArray.size();
//     int i=0;
//     while(i<n) {
//         vector<int> temp;
//         int frequency = freq(n, factorsArray, factorsArray[i] );

//         temp.push_back( factorsArray[i] );
//         temp.push_back( frequency );
//         powerArray.push_back( temp );
        
//         i += frequency;
//     }
//     return powerArray;
// }

// vector<int> factors(int n) {
//     vector<int> f;
//     for(int i=2; i<=n; i++) {
//         if( n%i==0 ) {
//             while(n%i == 0) {
//                 f.push_back(i);
//                 n = n/i;
//             }
//         }
//     }
//     for(int i = 0; i<f.size(); i++) {
//         cout << f[i] << ", ";
//     }
//     cout << "\n";
//     return f;
// }

// int euler(int n) {
//     if(n==1) return 0;
//     // if(primeCheck(n)) {
//     //     return n-1;
//     // }
    
//     int e = 1;
//     vector<int> factorsArray = factors(n);
    
//     vector<vector<int>> powerArray = powerFunc(factorsArray);
    
//     // for(int i=0; i<powerArray.size() ; i++) {
//     //     for(int j=0; j < 2  ; j++) {
//     //         cout<< powerArray[i][j] << " ";
//     //     }
//     //     cout<< "\n";
//     // }

//     for(int i=0; i<powerArray.size(); i++) {
        
//         e *= ( power( powerArray[i][0], powerArray[i][1] ) - power(powerArray[i][0], powerArray[i][1]-1));
//         cout<< powerArray[i][0] << " " << powerArray[i][1] << " " << e;
//         cout<< "\n";

//     }

//     return e;  
// }

// int main() {
//     int n = 240;
    
//     int e = euler(n);
//     cout << e;
    
//     return 0;
    
// }


//-------------------------------------------------------------------------------------------------------

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
// int str_length(string s) {
    
//     int c = 0;
//     while(s[c]) {
//         c++;
//     }
//     return c;
// }

// vector<vector<char>> newKey(string key) {
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
//     vector<vector<char>> keyMatrix;
//     int index = 0;
//     for(int i=0; i<5; i++) {
//         vector<char> temp;
//         for(int j=0 ;j<5; j++) {
//             if( newKey[index] == 'i' ) {
//                 temp.push_back('i');
//                 index += 2;
//                 continue;
//             }
//             temp.push_back( newKey[index] );
//             index++;
//         }
//         keyMatrix.push_back(temp);
//     }
//     cout << "KEY MATRIX :-\n";
//     for(int i=0; i<5; i++) {
//         cout << "[";
//         for(int j=0; j<5 ; j++) {
//             cout << "'" << keyMatrix[i][j] << "' " ;
//         }
//         cout << "]";
//         cout<< "\n";
//     }
//     return keyMatrix;
// }

// void position(vector<vector<char>> keyMatrix, char el, int* x, int* y) {
//     for(int i=0; i<5; i++) {
//         for(int j=0; j<5; j++) {
//             if(el == keyMatrix[i][j]) {
//                 *x = i;
//                 *y = j;
//                 return;
//             }
//         }
//     }
// }

// string encrypt(vector<vector<char>> keyMatrix, string plain) {
//     string cypher = "";
//     int firstRow,firstColumn,secondRow,secondColumn;

//     for(int i=0; i < str_length(plain); i+=2) {
//         position( keyMatrix, plain[i], &firstRow, &firstColumn );
//         position( keyMatrix, plain[i+1], &secondRow, &secondColumn );

//         if( firstRow == secondRow ) {
//             cypher += keyMatrix[firstRow][(firstColumn+1)%5];
//             cypher += keyMatrix[secondRow][(secondColumn+1)%5];
//         }
//         else if( firstColumn == secondColumn ) {
//             cypher += keyMatrix[ (firstRow+1)%5 ][ firstColumn ];
//             cypher += keyMatrix[ (secondRow+1)%5 ][ secondColumn ];
//         }
//         else {
//             cypher += keyMatrix[ firstRow][ secondColumn ];
//             cypher += keyMatrix[ secondRow ][ firstColumn ];
//         }
//     }
//     return cypher;
// }

// string decrypt(vector<vector<char>> keyMatrix, string cypher) {
//     string originalMessage = "";
//     int firstRow,firstColumn,secondRow,secondColumn;

//     for(int i=0; i < str_length(cypher); i+=2) {
//         position( keyMatrix, cypher[i], &firstRow, &firstColumn );
//         position( keyMatrix, cypher[i+1], &secondRow, &secondColumn );

//         if( firstRow == secondRow ) {
//             originalMessage += keyMatrix[firstRow][(firstColumn+4)%5];
//             originalMessage += keyMatrix[secondRow][(secondColumn+4)%5];
//         }
//         else if( firstColumn == secondColumn ) {
//             originalMessage += keyMatrix[ (firstRow+4)%5 ][ firstColumn ];
//             originalMessage += keyMatrix[ (secondRow+4)%5 ][ secondColumn ];
//         }
//         else {
//             originalMessage += keyMatrix[ firstRow][ secondColumn ];
//             originalMessage += keyMatrix[ secondRow ][ firstColumn ];
//         }
//     }
//     return originalMessage;
// }

// int main() {
//     string plain, key;

//     cout << "Enter your message : ";
//     cin >> plain;
//     cout << "Enter key : ";
//     cin >> key;
    
//     vector<vector<char>> keyMatrix = newKey(key);

//     string cypher = encrypt(keyMatrix, plain), originalMessage = decrypt(keyMatrix, cypher);
//     cout << "\nCypher Text : " << cypher << "\nOriginal Message : " << originalMessage;  
//     return 0;
// }




