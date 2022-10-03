// OPERATORS IN C


#include <stdio.h>

int count(int n) {
    int c =0;
    while(n>0) {
        c += 1;
        n /= 10;
    }
    return c;
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

int binaryToInt(int n) {
    int i=0,s=0;
    while(n>0) {
        s = s+ (n%10)*power(2,i);
        n /= 10;
        i++;
    }
    // printf("%d",s);
    return s;
}

int intToBinary(int n) {
    int a[10],i=0;
    while(n>0) {
        a[i] = n%2;
        n /= 2;
        i++;
    }
    int l = 0, r= i-1;
    while(l<r) {
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;
        l++;
        r--;
    }
    l = 0;
    for(int j=0; j<i; j++) {
        l = l*10 + a[j];
    }
    return l;
}

int andOp(int a, int b, int mc) {
    
    int temp = mc;
    int res[mc];
    mc -= 1;
    while(a>0 || b>0) {
        
        if( a%10==1 && b%10==1 ){
            res[mc] = 1;
        } else {
            res[mc] = 0;
        }
        mc -= 1;
        a /= 10;
        b /= 10;
    }
    
    mc = 0;
    for(int i=0; i<temp; i++) {
        mc = mc*10 + res[i];
    }
    return mc;
}

int xorOp(int a, int b, int mc) {
    
    int temp = mc;
    int res[mc];
    mc -= 1;
    while(a>0 || b>0) {
        
        if( a%10 == b%10 ){
            res[mc] = 0;
        } else {
            res[mc] = 1;
        }
        mc -= 1;
        a /= 10;
        b /= 10;
    }
    
    mc = 0;
    for(int i=0; i<temp; i++) {
        mc = mc*10 + res[i];
    }
    
    return mc;
}

int orOp(int a, int b, int mc) {
    
    int temp = mc;
    int res[mc];
    mc -= 1;
    while(a>0 || b>0) {
        
        if( a%10 == 0 && b%10 == 0 ){
            res[mc] = 0;
        } else {
            res[mc] = 1;
        }
        mc -= 1;
        a /= 10;
        b /= 10;
    }
    
    mc = 0;
    for(int i=0; i<temp; i++) {
        mc = mc*10 + res[i];
    }
    
    return mc;
}


int main() {
    
    int a, b, binA, binB;
    
    printf("Enter a : ");
    scanf("%d",&a);
    printf("Enter b : ");
    scanf("%d",&b);

    binA = intToBinary(a);
    binB = intToBinary(b);
    
    int mc=0;
    int ac = count(binA);
    int bc = count(binB);
    if(ac > bc) mc = ac;
    else mc = bc;
    
    int AND = andOp(binA,binB,mc);
    int XOR = xorOp(binA,binB,mc);
    int OR = orOp(binA,binB,mc);
    
    printf("Binary of %d -> %d\n",a,binA);
    printf("Binary of %d -> %d\n",b,binB);
    printf("AND -> %d\n",binaryToInt(AND));
    printf("XOR -> %d\n",binaryToInt(XOR));
    printf("OR -> %d\n",binaryToInt(OR));
    
    
    return 0;
}









