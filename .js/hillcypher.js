function arrToString(cypher) {
    let s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    let res = "";
    for(let i of cypher ){
        res += s[i];
    }
    return res;
}

function keyMatrix(key, n) {
    let res = [];
    let ch = 0;
    for(let i=0; i<n; i++) {
        let temp = [];
        for(let j=0; j<n; j++) {
            temp.push( key.charCodeAt(ch) - 65 );
            ch++;
        }
        // console.log(temp)
        res.push(temp);
    }
    
    return res;
}

function plainArr(plain) {
    let res = [];
    for(let i=0; i<plain.length; i++) {
        res.push( plain.charCodeAt(i) - 65 );
    }
    return res;
}

function encrypt(key, plain, n) {
    let res = [];
    for(let i=0; i<n; i++) {
        let temp = 0;
        for(let j=0; j<n; j++) {
            temp += plain[j]*key[j][i];
        }
        res.push(temp);
    }
    for(let i=0; i<n; i++) {
        res[i] %= 26;
    }
    let ans = arrToString(res);
    return ans;
}

function encrypt2(key, plain, n) {
    let res = [];
    for(let i=0; i<n; i++) {
        let temp = 0;
        for(let j=0; j<n; j++) {
            temp += key[i][j] * plain[j];
        }
        res.push(temp);
    }
    for(let i=0; i<n; i++) {
        res[i] %= 26;
    }
    let ans = arrToString(res);
    return ans;
}





let key = "GYBNQKURP", plain = "ACT";

let keyMat = keyMatrix(key, 3);
let plainA = plainArr(plain);

let cypher1 = encrypt(keyMat, plainA, plain.length );
let cypher2 = encrypt2(keyMat, plainA, plain.length)
console.log("CYPHER TEXT 1 -> ",cypher1);
console.log("CYPHER TEXT 2 -> ",cypher2)
