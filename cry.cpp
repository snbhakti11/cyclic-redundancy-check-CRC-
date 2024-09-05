#include <iostream>
#include <string.h>

using namespace std;

void appendZeros(char *op, char *ip, int polyLen) {
    strcpy(op, ip);  // Copy input message to output
    for (int i = 1; i < polyLen; i++)
        strcat(op, "0");  // Append zeros based on polynomial length
}

int crc(char *ip, char *op, const char *poly, int mode) {
    if (mode == 1) {
        appendZeros(op, ip, strlen(poly));  // For encoding, append zeros to input message
    } else {
        strcpy(op, ip);  // Copy the received message to output (no need for appending zeros)
    }

    // Perform XOR on the message with the selected polynomial
    for (int i = 0; i < strlen(ip); i++) {
        if (op[i] == '1') {  // If the current bit is 1, perform XOR with the polynomial
            for (int j = 0; j < strlen(poly); j++) {
                op[i + j] = (op[i + j] == poly[j]) ? '0' : '1';  // XOR operation
            }
        }
    }

    // Check for errors by looking for any '1' in the remainder
    for (int i = 0; i < strlen(op); i++) {
        if (op[i] == '1') {
            return 0;  // Error detected
        }
    }
    return 1;  // No errors detected
}

int main() {
    char ip[50], op[50], recv[50];
    const char poly_8[] = "110000000";   // CRC-CCITT (8-bit) polynomial (x^8 + x^2 + x + 1)
    const char poly_16[] = "10001000000100001";  // CRC-CCITT (16-bit) polynomial (x^16 + x^12 + x^5 + 1)
    
    int choice;
    cout << "Choose CRC Type: 1. CRC-CCITT (8-bit), 2. CRC-CCITT (16-bit)" << endl;
    cin >> choice;

    const char* poly;
    if (choice == 1) {
        poly = poly_8;
        cout << "Using CRC-CCITT (8-bit)" << endl;
    } else {
        poly = poly_16;
        cout << "Using CRC-CCITT (16-bit)" << endl;
    }

    cout << "Enter the input message in binary: ";
    cin >> ip;

    // Perform CRC encoding
    crc(ip, op, poly, 1);
    cout << "The transmitted message is: " << ip << op + strlen(ip) << endl;

    cout << "Enter the received message in binary: ";
    cin >> recv;

    // Perform CRC check on the received message
    if (crc(recv, op, poly, 0)) {
        cout << "No error in data" << endl;
    } else {
        cout << "Error in data transmission has occurred" << endl;
    }

    return 0;
}

