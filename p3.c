#include<stdio.h>
#include<string.h>

// Function to generate the Vigenère table
void generateVigenereTable(char table[26][26]) {
    for(int i = 0; i < 26; ++i) {
        for(int j = 0; j < 26; ++j) {
            table[i][j] = ((i + j) % 26) + 'A';
        }
    }
}
 
int main() {
    char msg[] = "THECRAZYPROGRAMMER";
    char key[] = "HELLO";
    int msgLen = strlen(msg), keyLen = strlen(key), i, j;

    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
    char vigenereTable[26][26];

    // Generating Vigenère table
    generateVigenereTable(vigenereTable);

    // Generating new key
    for(i = 0, j = 0; i < msgLen; ++i, ++j) {
        if(j == keyLen)
            j = 0;

        newKey[i] = key[j];
    }

    newKey[i] = '\0';

    // Encryption
    for(i = 0; i < msgLen; ++i)
        encryptedMsg[i] = vigenereTable[msg[i] - 'A'][newKey[i] - 'A'];

    encryptedMsg[i] = '\0';

    // Decryption
    for(i = 0; i < msgLen; ++i) {
        for(j = 0; j < 26; ++j) {
            if(vigenereTable[newKey[i] - 'A'][j] == encryptedMsg[i]) {
                decryptedMsg[i] = 'A' + j;
                break;
            }
        }
    }

    decryptedMsg[i] = '\0';

    // Print Vigenère table
    printf("Vigenère Table:\n");
    for(i = 0; i < 26; ++i) {
        for(j = 0; j < 26; ++j) {
            printf("%c ", vigenereTable[i][j]);
        }
        printf("\n");
    }
   
    // Print output
    printf("\nOriginal Message: %s", msg);
    printf("\nKey: %s", key);
    printf("\nNew Generated Key: %s", newKey);
    printf("\nEncrypted Message: %s", encryptedMsg);
    printf("\nDecrypted Message: %s", decryptedMsg);

    return 0;
}
