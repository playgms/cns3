#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the plaintext using the Rail Fence Cipher
void Encryption(int row, int col, char arr[row][col], char* encryptedText) {
    int k = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] != '\0') {
                encryptedText[k++] = arr[i][j];
            }
        }
    }\
    encryptedText[k] = '\0'; // Null-terminate the encrypted string
}

// Function to decrypt the ciphertext using the Rail Fence Cipher
void Decryption(int row, int col, char arr[row][col], char* decryptedText) {
    int i = 0, j = 0;
    int k = 0;
    int down = 1; // 1 means moving down, 0 means moving up

    while (j < col) {
        if (arr[i][j] != '\0') {
            decryptedText[k++] = arr[i][j];
        }
        if (i == 0) { 
            down = 1; 
        } else if (i == row - 1) { 
            down = 0; 
        }

        if (down) {
            i++;
        } else {
            i--;
        }

        j++;
    }
    decryptedText[k] = '\0'; // Null-terminate the decrypted string
}

// Function to print the Rail Fence Cipher matrix
void PrintMatrix(int row, int col, char arr[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] == '\0') { // If index of array is empty
                printf(" ");
            } else {
                printf("%c", arr[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    char message[100];
    int depth;

    printf("Enter the plaintext: ");
    fgets(message, sizeof(message), stdin);

    // Remove newline character from the input string
    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n') {
        message[len - 1] = '\0';
    }

    // Convert message to uppercase and remove spaces
    for (int i = 0; message[i]; i++) {
        if (isspace(message[i])) {
            memmove(&message[i], &message[i + 1], strlen(message) - i);
            i--;
        } else {
            message[i] = toupper(message[i]);
        }
    }

    printf("Enter the depth: ");
    scanf("%d", &depth);

    int row = depth, col = strlen(message);
    char arr[row][col];
    memset(arr, '\0', sizeof(arr)); // Initialize the array with null characters

    int i = 0, j = 0;
    int down = 1; // 1 means moving down, 0 means moving up

    for (int k = 0; k < col; k++) {
        arr[i][j++] = message[k];

        if (i == 0) {
            down = 1;
        } else if (i == row - 1) {
            down = 0;
        }

        if (down) {
            i++;
        } else {
            i--;
        }
    }

    // Print the Rail Fence Cipher matrix
    PrintMatrix(row, col, arr);

    // Encryption
    char encryptedText[col + 1];
    Encryption(row, col, arr, encryptedText);
    printf("Encrypted string: %s\n", encryptedText);

    // Decryption
    char decryptedText[col + 1];
    Decryption(row, col, arr, decryptedText);
    printf("Decrypted string: %s\n", decryptedText);

    return 0;
}
