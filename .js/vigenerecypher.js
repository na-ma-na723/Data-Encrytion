function keyLength(key, msg) {
    let keyLength = key.length;
    for(let i=0;i < msg.length - keyLength ; i++) {
        key += key[i%keyLength];
    }
    return key;
}

function encrypt(msg, key){
    let table = "abcdefghijklmnopqrstuvwxyz";
    let res = "";
    for(let i=0; i<15; i++) {
        let a = msg.charCodeAt(i);
        let b = key.charCodeAt(i);

        res += table[ ((a-97)+(b-97)) %26]
    }
    return res;
}
    
function decrypt(cypher, key){
    let table = "abcdefghijklmnopqrstuvwxyz";
    let res = "";
    for(let i=0; i<15; i++) {
        let a = cypher.charCodeAt(i);
        let b = key.charCodeAt(i);
        let temp = a-b;
        
        if( temp < 0) {
            temp = 26 + temp;
        }
        res += (table[temp])
    }
    return res;
}

let msg = prompt("Enter your message : ");
msg = msg.toLowerCase();
let key = prompt("Enter your key : ");
key = keyLength(key, msg);
let cyphertext = encrypt(msg, key);
let ori = decrypt(cyphertext, key);

console.log("Cypher text : ", cyphertext);
console.log("origial message : ", ori);
