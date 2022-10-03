#include <iostream>
#include<string>
#include<vector>
using namespace std;

int inverse(int n, int r2) {
    int r1 = n, t1 = 0, t2 = 1, t, r, q;
    while( r2>0 ) {
        q = r1/r2;
        r = r1%r2;
        r1 = r2;
        r2 = r;
        t = t1 - (q*t2);
        t1 = t2;
        t2 = t;
    }
    if( r1 == 1 ) {
        if( t1<0 ) {
            return ( n - abs(t1)%n );
        }
    }
    return -1;
}


int main() {
    int n = 100;
    int b = 23;
    cout << inverse(n,b);

}