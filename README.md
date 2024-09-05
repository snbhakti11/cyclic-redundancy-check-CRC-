## README: CRC-CCITT (8-bit and 16-bit) Error Detection Program

### Overview

This C++ program implements **Cyclic Redundancy Check (CRC)** error detection using two variations:
1. **CRC-CCITT (8-bit)**: Uses an 8-bit polynomial \(x^8 + x^2 + x + 1\).
2. **CRC-CCITT (16-bit)**: Uses a 16-bit polynomial \(x^{16} + x^{12} + x^5 + 1\).

The program allows the user to:
- Select between 8-bit and 16-bit CRC for error detection.
- Input a binary message.
- Compute and append the CRC code to the message for transmission.
- Input the received message and check whether an error occurred during transmission.

### How It Works

1. **CRC Calculation**:
   The program uses a generator polynomial (depending on 8-bit or 16-bit selection) to perform a series of **XOR operations** between the input message and the polynomial. The remainder of this operation is the CRC code.
   
   - For **transmission**, zeros are appended to the input message (equal to the length of the polynomial), and the XOR operation is performed. The remainder (CRC code) is appended to the original message.
   - For **error detection**, the received message is checked against the same polynomial. If the remainder contains any `1`, an error is detected.

2. **Steps**:
   - The user enters a message in binary.
   - The program calculates the CRC (based on the user's selection of 8-bit or 16-bit) and appends it to the message.
   - The user then inputs the received message, and the program checks for errors.

### How to Use the Program

1. **Compilation**:
   To compile the program, use a C++ compiler such as `g++`. Run the following command in your terminal:
   ```
   g++ crc_program.cpp -o crc_program
   ```

2. **Running the Program**:
   After compilation, run the program using:
   ```
   ./crc_program
   ```

3. **User Input/Interaction**:
   - The program will ask you to choose between **CRC-CCITT (8-bit)** or **CRC-CCITT (16-bit)**:
     ```
     Choose CRC Type: 1. CRC-CCITT (8-bit), 2. CRC-CCITT (16-bit)
     ```
     Enter `1` for 8-bit CRC or `2` for 16-bit CRC.

   - Next, you will be asked to enter the **input message** in binary (e.g., `101101`):
     ```
     Enter the input message in binary:
     ```

   - The program will then display the **transmitted message** (input message + CRC code).

   - Afterward, you will be prompted to enter the **received message** in binary (this could be the same as the transmitted message or altered to simulate an error):
     ```
     Enter the received message in binary:
     ```

4. **Output**:
   The program will then check for errors in the received message and display one of the following:
   - `No error in data` if no errors were detected.
   - `Error in data transmission has occurred` if an error is found.

### Example Usage

#### Example 1 (Using CRC-CCITT 8-bit):
```
Choose CRC Type: 1. CRC-CCITT (8-bit), 2. CRC-CCITT (16-bit)
1
Using CRC-CCITT (8-bit)
Enter the input message in binary: 101101
The transmitted message is: 10110101100000
Enter the received message in binary: 10110101100000
No error in data
```

#### Example 2 (Using CRC-CCITT 16-bit):
```
Choose CRC Type: 1. CRC-CCITT (8-bit), 2. CRC-CCITT (16-bit)
2
Using CRC-CCITT (16-bit)
Enter the input message in binary: 101101
The transmitted message is: 1011011000001000000001001
Enter the received message in binary: 1011011000001000000001001
No error in data
```

### Key Features
- **Dual CRC Support**: Choose between CRC-CCITT 8-bit or 16-bit for different applications.
- **Error Detection**: Detects transmission errors in a simple binary message.
- **User-Friendly**: Accepts user input and provides clear feedback on data transmission integrity.

### Requirements
- **Compiler**: You need a C++ compiler (e.g., `g++`).
- **Platform**: This program can run on any platform (Linux, macOS, or Windows) with the appropriate C++ compiler installed.

### CRC Polynomials Used:
- **CRC-CCITT (8-bit)**: Polynomial `x^8 + x^2 + x + 1` → `110000000`
- **CRC-CCITT (16-bit)**: Polynomial `x^{16} + x^{12} + x^5 + 1` → `10001000000100001`

### Limitations
- This program only works for **binary messages**.
- For simplicity, the program assumes error-free user input (i.e., binary strings are correctly formatted).

### Further Development Ideas
- Extend the program to work with larger messages or support other CRC variants.
- Add error-handling for invalid input.
