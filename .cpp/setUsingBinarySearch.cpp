#include <iostream>
#include<string>
#include<vector>
using namespace std;

// bool binarySearch(vector<int> a, int u, int target) {
//     int i, mid, l=0;
//     while(l<=u) {
//         mid=(l+(u-l)/2);
//         if ( a[mid] == target ) {
//             return true;
//         }
//         else if (a[mid] > target) u=mid-1;
//         else if (a[mid] < target) l=mid+1;
//     }
//     return false;
// }

bool linearset(string s, char el, int len) {
    for(int i=0; i<len; i++) {
        if(el == s[i]) return false;
    }
    return true;
}


int main() {
    // vector<int> ar;
    // // int n;
    // int a[] = {1,1,1,1,2,3,4,5,5,5,7,7,8};
    // ar.push_back(a[0]);
    // cout<<ar.size()<< "\n";
    // // string s = "asdfaserdfgtfdsadtfdsfhjyhjfdthhf";
    // // cout << "enter:";
    // int n = sizeof(a)/sizeof(int);
    // for(int i=1; i<n; i++) {
    //     // cout<< "Enter element : ";
    //     // cin >> n;
    //     if( !binarySearch(ar, ar.size(), a[i]) ) {
    //         ar.push_back(a[i]);
    //         cout<< "pushed : "<< a[i]<< "\n";
    //     }
    //     else {
    //         continue;
    //     }
    //     // cout<< ar.size()<< "\n";
    // }
    // for(int i=0; i<ar.size(); i++) {
    //     cout<< ar[i]<< ", ";
    // }


    string key = "monarchy";
    key += "abcdefghijklmnopqrdstuvwxyz";
    
    string newKey = "";
    newKey += key[0];
    int nkl = 1;
    for(int i=1; i<key.length(); i++) {
        if( linearset(newKey, key[i], nkl) ) {
            newKey += key[i];
            nkl++;
        }
    }
    cout<< newKey;
    
}