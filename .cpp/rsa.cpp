#include <iostream>
#include<string>
#include<vector>
using namespace std;

int str_length(string s) {
    int c = 0;
    while(s[c]) {
        c++;
    }
    return c;
}

string arrToString(vector<int> ori) {
    string s = "abcdefghijklmnopqrstuvwxyz";
    string res = "";
    for(int i=0; i<ori.size(); i++) {
        int temp = ori[i]%26;
        res += s[ temp ];
    }
    return res;
}

int power(int n, int pow) {
    if(pow == 0) return 1;
    int s=1;
    while(pow>0) {
        s = s*n;
        pow = pow-1;
    }
    return s;
}

int closestPower(int p) {
    for(int i=0; i <= p; i++) {
        if( power(2,i) > p ) {
            // cout << "returned -> " << power(2,i-1) << "\n";
            return power(2,i-1);
        }
    }
    return 1;
} 

int bigPowerMod(int a ,int p, int n) {
    int ar[p], i;
    ar[1] = a%n;
    for(i=2; i<p; i*=2) {
        ar[i] = ( ar[i/2] * ar[i/2] ) % n;
    }
    // cout << "\npowers : ";
    // for(int i=1; i<p; i*=2) {
    //     cout << ar[i] << ", ";
    // }
    // cout << "yes";
    
    int temp = 1;
    // cout << "Variables used for "<< p << " -> ";
    while( p>0 ) {
        i = closestPower(p);
        // cout << i << ", ";
        temp = ( temp * power( ar[i], p/i ) ) % n;
        p = p%i;
        i /= 2;
    }
    return temp;

}

int firstOccurrence(int n,vector<int> factorsArray,int k) {
    int l = 0, r=n-1;
    while( l<=r ) {
        int mid = (l+r)/2;
        if( factorsArray[mid] == k ){
            if( (mid-1)>=0 && factorsArray[mid] == factorsArray[mid-1] ) r=( mid- 1 );
            else return mid;
        }
        else if( factorsArray[mid] > k ) r = mid-1;
        else if( factorsArray[mid] < k ) l = mid+1;
    }
    return -1;
}

int lastOccurrence(int n,vector<int> factorsArray,int k) {
    int l = 0,r = n -1;
    while( l<=r ) {
        int mid = (l+r)/2;
        if(factorsArray[mid] == k) {
            if( (mid+1) < n and factorsArray[mid] == factorsArray[mid+1] ) l = mid+1;
            else return mid;
        }
        else if( factorsArray[mid] > k ) r = mid-1;
        else if( factorsArray[mid] < k ) l = mid+1;
    }
    return -1;
}

int freq(int n, vector<int> factorsArray, int k) {
    int l = lastOccurrence(n, factorsArray, k), f=firstOccurrence(n, factorsArray, k);
    if( l>=0 || f>=0 ) return (l-f+1);
    return 0;
}

vector<vector<int>> powerFunc( vector<int> factorsArray) {
    vector<vector<int>> powerArray;
    int n = factorsArray.size();
    int i=0;
    while(i<n) {
        vector<int> temp;
        int frequency = freq(n, factorsArray, factorsArray[i] );

        temp.push_back( factorsArray[i] );
        temp.push_back( frequency );
        powerArray.push_back( temp );
        
        i += frequency;
    }
    return powerArray;
}

//----------------------------------------------------------------------------------------------

bool primeCheck(int n) {
    for( int i=2; i<n; i++) {
        if( n%i==0 ) {
            return false;
        }
    }
    return true;
}

vector<int> factors(int n) {
    vector<int> f;
    for(int i=2; i<=n; i++) {
        if( n%i==0 ) {
            while(n%i == 0) {
                f.push_back(i);
                n = n/i;
            }
        }
    }
    // for(int i = 0; i<f.size(); i++) {
    //     cout << f[i] << ", ";
    // }
    // cout << "\n";
    return f;
}

int euler(int n) {
    if(n==1) return 0;
    if(primeCheck(n)) {
        return n-1;
    }
    
    int phi_n = 1;
    vector<int> factorsArray = factors(n);
    vector<vector<int>> powerArray = powerFunc(factorsArray);

    for(int i=0; i<powerArray.size(); i++) {
        phi_n *= ( power( powerArray[i][0], powerArray[i][1] ) - power(powerArray[i][0], powerArray[i][1]-1));
    }

    return phi_n;  
}

//----------------------------EXTENDED SEPERATE GCD CHECK------------------------------------
int gcd(int a, int b) {
    int g;
    for(int i=1; i<=a && i<=b; i++) {
        if(a%i==0 && b%i==0) {
            g = i;
        }
    }
    return g;
}

int extendedEuclidean(int n, int e) {
    int r1 = n, r2 = e, t1 = 0, t2 = 1, t , q, r;
    while( r2 > 0 ) {
        q = r1/r2;
        r = r1%r2;
        r1 = r2;
        r2 = r;
        t = t1 - (q*t2);
        t1 = t2;
        t2 = t;
    }
    if(r1 == 1) {
        if( t1 < 0 ) {
            return n - (abs(t1) % n);
        }
        else {
            return t1%n;
        }
    }
    return 0;
}

//----------------------------------------------------------------------------------------------

// vector<int> euclidean(int n, int b) {
//     int r1 = n, r2 = b, q, r;
//     vector<int> a;
//     a.push_back(0);
//     while( r2 > 0 ) {
//         q = r1/r2;
//         r = r1%r2;
//         r1 = r2;
//         r2 = r;
//         a.push_back(q);
//     }
//     if(r1 == 1) {
//         a[0] = 1;
//         return a;
//     }
//     else {
//         return a;
//     }
// }

// int extended(vector<int> q, int n) {
//     int t1 = 0, t2 = 1, t;
//     for(int i=1; i<q.size(); i++) {
//         t = t1 - (q[i]*t2);
//         t1 = t2;
//         t2 = t;     
//     }
//     if( t1 < 0 ) {
//         return n - (abs(t1) % n);
//     }
//     else {
//         return t1%n;
//     }
// }
//----------------------------------------------------------------------------------------------


int main() {
    int p, q, e, n, phi_n, d;
    cout << "Enter two co-prime integers :-\nEnter p : ";
    cin >> p;
    cout << "Enter q : ";
    cin >> q;
    
    
    n = p*q;
    phi_n = euler(n);
    
    while(true) {
        cout << "Enter a number between 1 and " << phi_n << " : ";
        cin >> e;
        if( gcd(phi_n,e) == 1 ) {
            d = extendedEuclidean(phi_n,e);
            cout << "Inverse : " << d;
            break;
        }
        else cout << "Inverse does not exist. Enter e again";
    }
    
    string message, cypher, originalMessage;
    cout << "\nEnter message  : ";
    cin >> message;
    
    
    vector<int> messageVector, originalMessageVector, cypherVector;
    int msgSize = str_length(message);
    
    for(int i=0; i<msgSize; i++) {
        int temp = message[i];
        messageVector.push_back( temp-97 );
    }

    // for(int i=0; i<msgSize; i++) {
    //     cout << messageVector[i] << ", ";
    // }
    // cout << "\n";
    
    for(int i=0; i<msgSize; i++) {
        cypherVector.push_back(bigPowerMod(messageVector[i], e, n));
    }
    
    // for(int i=0; i<msgSize; i++) {
    //     cout << cypherVector[i] << ", ";
    // }
    // cout << "\n";
    
    cypher = arrToString(cypherVector);
    
    for(int i=0; i<msgSize; i++) {
        originalMessageVector.push_back( bigPowerMod(cypherVector[i], d, n) );
    }

    // for(int i=0; i<msgSize; i++) {
    //     cout << originalMessageVector[i] << ", ";
    // }
    // cout << "\n";


    originalMessage = arrToString(originalMessageVector);

    cout << "\nCypher : " << cypher << "\nOriginal Message : " << originalMessage;
    
    //----------------------------------------------------------------------------------------------
    // vector<int> q = euclidean(n,b);
    // if( q[0] == 1 ) {
    //     in = extended(q, n);
    //     cout << "Inverse : " << in;
    // }
    // else cout << "Inverse does not exist.";
    // return 0;
}


// n = p*q

// phi( n ) = (p-1)(q-1)

// gcd( e, phi(n) ) = 1

// d = e^(-1) mod phi(n)

// r1 = phi(n) , r2 = e