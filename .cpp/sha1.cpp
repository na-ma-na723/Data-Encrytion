#include <iostream>
#include<string>
#include<vector>
using namespace std;

long int power(int n, int pow) {
    if(pow == 0) return 1;
    long int s=1;
    while(pow>0) {
        s = s*n;
        pow = pow-1;
    }
    return s;
}

long int binaryToInt(string binary) {
    vector<int> binaryVector;
    for(int i=0; i<binary.length(); i++) {
        int temp = int(binary[i]) - 48;
        binaryVector.push_back(temp);
    }
    int i=0, n=binaryVector.size()-1;
    long int s = 0;
    while(n>=0) {
        s += binaryVector[i]*power(2, n);
        i++;
        n--;
    }
    // cout << s << "\n";
    return s;
}

string intToBinary(long int n) {
    vector<int> temp;
    string binary = "";
    
    while(n>0) {
        temp.push_back(n%2);
        n /= 2;
    }
    for(int i= temp.size()-1; i>=0; i--) {
        binary += to_string(temp[i]);
    }

    return binary;
}

string binaryToHex(string binary) {
    vector<string> binary4Bit;
    int j=0;
    for(int i=0; i<binary.length(); i+=4) {
        string temp = "";
        while( temp.length() < 4 ) {
            temp += binary[j];
            j++;
        }
        binary4Bit.push_back(temp);
    }
    string hexCode = "";
    for(int i=0; i<binary4Bit.size(); i++) {
        int temp = binaryToInt(binary4Bit[i]);
        if( temp > 9 ) {
            hexCode += char(temp - 10 + 97);
        }
        else{
            hexCode += to_string( temp );
        }
    }
    
    return hexCode;
}

vector<string> binary8BitArray(string text) {
    vector<string> binaryArray;
    for(int i=0; i<text.length(); i++) {
        int temp = text[i];
        
        string binary = intToBinary(temp);
        while( binary.length() < 8 ) {
            binary = '0' + binary;
        }
        binaryArray.push_back(binary);
    }

    return binaryArray;
}

string binaryArrayLengthInBinary(int n) {
    string binary = intToBinary(n);
    
    while( binary.length() < 64 ) {
        binary = '0' + binary;
    }
    
    // cout << binary << "\n" << binary.length();
    return binary;
}

vector<string> numStringBlocks(string numString, int bitSize) {
    vector<string> blocks;
    int j=0;
    for(int i=0; i<numString.length(); i+= bitSize) {
        string temp = "";
        while( temp.length() < bitSize ) {
            temp += numString[j];
            j++;
        }
        blocks.push_back(temp);
    }

    // for(int i=0; i<blocks.size(); i++) {
    //     cout << blocks[i] << ",";
    // }
    // cout << "\n" << j << "\n";

    return blocks;
}

string xorString(string a, string b) {
    string xorString = "";
    for(int i=0; i<a.length(); i++) {
        if( a[i] == b[i] ) xorString += '0';
        else xorString += '1';
    }
    
    return xorString;
}

string andString(string a, string b) {
    string andString = "";
    for(int i=0; i<a.length(); i++) {
        if( a[i] == '1' && b[i] == '1' ) andString += '1';
        else andString += '0';
    }
    
    return andString;
}

string orString(string a, string b) {
    string orString = "";
    for(int i=0; i<a.length(); i++) {
        if( a[i] == '0' && b[i] == '0' ) orString += '0';
        else orString += '1';
    }
    
    return orString;
}

string notString(string a) {
    string notString = "";
    for(int i=0; i<a.length(); i++) {
        if( a[i] == '1' ) notString += '0';
        else notString += '1';
    }
    
    return notString;
}

string leftRotate(string s, int n) {
    string rotatedString = "";
    for(int i=n; i<s.length(); i++) {
        rotatedString += s[i];
    }
    for(int i=0; i<n; i++) {
        rotatedString += s[i];
    }
    return rotatedString;
}

string addWords(string a, string b) {
    long int addedNumbers = binaryToInt(a) + binaryToInt(b);
    string newWord = intToBinary(addedNumbers);
    // cout << binaryToInt(a) + binaryToInt(b) << "\n";
    // cout << "newWord -> " << newWord << "\n" ;
    while (newWord.length() < a.length()) {
        newWord = '0' + newWord;
    }

    if(newWord.length() == a.length()) {
        return '1' + newWord;
    }
    return newWord;
    
}

string truncate(string a, int length) {
    string res = "";
    for(int i=a.length() - length; i<a.length(); i++) {
        res += a[i];
    }
    return res;
}

vector<string> extendArrayTo80(vector<string> subBlockPart) {
    for(int i=16; i<80; i++ ) {
        string wordA = subBlockPart[i-3];
        string wordB = subBlockPart[i-8];
        string wordC = subBlockPart[i-14];
        string wordD = subBlockPart[i-16];

        string xorA = xorString(wordA, wordB);
        string xorB = xorString(xorA, wordC);
        string xorC = xorString(xorB, wordD);

        string newWord = leftRotate(xorC, 1);

        subBlockPart.push_back(newWord);
    }
    
    // for(int i=0; i<subBlockPart.size(); i++) {
    //     cout << subBlockPart[i] << ",";
    // }

    return subBlockPart;
}


string sha1(string text) {

    string h0 = "01100111010001010010001100000001",h1 = "11101111110011011010101110001001",h2 = "10011000101110101101110011111110",h3 = "00010000001100100101010001110110",h4 = "11000011110100101110000111110000";

    vector<string> binary8Bit = binary8BitArray(text);
    string numString = "";
    
    for(int i=0; i<binary8Bit.size(); i++) {
        numString += binary8Bit[i];
    }
    int binaryArrayLength = numString.length();
    numString += '1';
    while( numString.length() % 512 != 448 ) {
        numString += '0';
    }
    
    numString += binaryArrayLengthInBinary(binaryArrayLength);
    
    vector<string> blocks = numStringBlocks(numString, 512);

    // cout << "\n" << blocks.size();
    vector<vector<string>> SubBlocks32Bit;

    for(int i=0; i<blocks.size(); i++) {
        SubBlocks32Bit.push_back(numStringBlocks(blocks[i], 32 ));
    }

    for(int i=0; i<SubBlocks32Bit.size(); i++) {
        SubBlocks32Bit[i] = extendArrayTo80(SubBlocks32Bit[i]);
    }

    // cout <<SubBlocks32Bit.size();
    for(int i=0; i<SubBlocks32Bit.size(); i++) {
        string a=h0, b=h1, c=h2, d=h3, e=h4;

        for(int j=0; j<80; j++) {
            string f = "", k="";
            if( j < 20 ) {
                f = orString(andString(b, c), andString(notString(b), d) );
                k = "01011010100000100111100110011001";
                // cout << "f" << j << "-> "  << f << "\n";
                
                // cout << "a" << j << "-> "  << a << "\n";
                // cout << "b" << j << "-> "  << b << "\n";
                // cout << "c" << j << "-> "  << c << "\n";
                // cout << "d" << j << "-> "  << d << "\n";
                // cout << "e" << j << "-> "  << e << "\n\n";
                
                // cout << "h0 -> " << h0 << "\n";
                // cout << "h1 -> "<< h1 << "\n";
                // cout << "h2 -> "<< h2 << "\n";
                // cout << "h3 -> "<< h3 << "\n";
                // cout << "h4 -> "<< h4 << "\n";
            }
            else if( j < 40 ) {
                f = xorString( d, xorString( b, c) );
                k = "01101110110110011110101110100001";
            }
            else if( j<60 ) {
                f = orString( andString(c,d) , orString( andString(b, c), andString(b, d)) );
                k = "10001111000110111011110011011100";
            }
            else if (j<80) {
                f = xorString( xorString( b, c), d );
                k = "11001010011000101100000111010110";
            }
            
            
            
            // cout << "f" << j << "-> "  << f << "\n";
            string word = SubBlocks32Bit[i][j];
            string leftA = leftRotate(a, 5);
            string tempA = addWords(leftA,f);
            string tempB = addWords(tempA, e);
            string tempC = addWords(tempB, k);
            string temp =  addWords(tempC, word);
            // if(j<20) cout << "leftA -> " << leftA << "\n";
            // if(j<20) cout <<"tempA" << tempA << "\n";
            
            
            // string temp = truncate(addWords(addWords(addWords(addWords(leftRotate(a, 5),f),e),k),SubBlocks32Bit[i][j]), 32);
            temp = truncate(temp, 32);
            e = d;
            d = c;
            c = leftRotate(b, 30);
            b = a;
            a = temp;
        }
        h0 = truncate(addWords(h0,a), 32);
        h1 = truncate(addWords(h1,b), 32);
        h2 = truncate(addWords(h2,c), 32);
        h3 = truncate(addWords(h3,d), 32);
        h4 = truncate(addWords(h4,e), 32);
        
        // cout << h0 << "\n";
        // cout << h1 << "\n";
        // cout << h2 << "\n";
        // cout << h3 << "\n";
        // cout << h4 << "\n";
    }

    // cout << h0 << "\n";
    // cout << h1 << "\n";
    // cout << h2 << "\n";
    // cout << h3 << "\n";
    // cout << h4 << "\n";
    
    string hexCode = binaryToHex(h0+h1+h2+h3+h4);
    return hexCode;
}

int main() {
    string text;
    cout << "Enter text to generate hash code : "; 
    getline(cin, text);
    string hashCode = sha1(text);

    cout << "Generated Hash Code : " << hashCode;
}