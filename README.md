# Huffman-RL-Encoding-Compression-Algorithm

Gautam Ahuja
CS-1203: Data Structures
Debayan Gupta
December 22, 2022

## Final Project: COMPRESSION ALGORITHM (HUFFMAN CODING + RUN-LENGTH ENCODING + MIN-HEAP)

### LOGIC:
- If a string has repeatition of characters, then note down the frequency and create a string with single character.
- This is the new compressed string
- Now, create a Huffman Tree using the frequencies of each character using min-heap data structure.
- When decompressing, note down the frequencies and produce the original srings.
- If the string has no repeatition, then this compression doesn't work well.


### IMPLEMENTATION:
- A C program to compress the user input string using Huffman Coding
- The program takes a string as input and output the compressed string
- The program outputs the compressed string in bits format.
- The porgam also perform Run-Length_Encoding to prevent the problem of Huffman Coding when the input string is too long or have repeatition.
- The Huffman Coding is implemented using a min-heap data structure.
- The Huffman Code works as follows:
    1. The user is prompted to enter a string.
    2. The program then counts the frequency of each character in the string.
    3. The program then creates a Huffman Tree using the frequencies of each character using min-heap data structure.
    4. The program then creates a Huffman Code for each character using the Huffman Tree.
    5. The program then encodes the string using RL-encoding and Huffman Coding.
    6. The program then outputs the encoded string in bits format.
    7. The program then decodes the encoded string and outputs the decoded string.
    8. The program outputs the compression ratio.

### DATA STRUCTURE CONCEPTS USED:
- Min-Heap 
    = Heapify, Insert, ExtractMin, Delete, DecreaseKey
- Huffman Tree
- Huffman Code
- Strings, pointers, arrays, structs, etc.
    = Pointers to Pointers (2D arrays/Strings), Pointers to structs, etc.
- Run-Length Encoding

### CONSTRAINS:
- String Must be less than 256 characters
- String should not contain any numerical characters

### ADDITIONAL NOTES:
- Huffman Coding is a lossless data compression algorithm.
- Huffman Coding is a prefix code.
- The above compression algorithm is most effective for data that is not uniformly distributed. And if there are pattens of repeatition in the data.
- For example, if the input string is "aaaaa", then the compression ratio will be 1/5 = 20%.
- For unique strings (no repeatition), the algorithm might produce a larger string than the original string.
- If: Compression Ratio < 1, then the compression algorithm is effective.
- If: Compression Ratio > 1, then the compression algorithm is not effective.


### OUTCOME:
- Intermixing of concepts mentioned below to create a compression algorithm (Huffman Coding + Run-Length Encoding + Min-Heap)
- Proper implementation of Heaps and Concepts of heaps (Heapify, Insert, ExtractMin, Delete, DecreaseKey)
- Proper implementation of Huffman Tree and Huffman Code
- Proper implementation of Run-Length Encoding
- Proper implementation of Strings, pointers, arrays, structs, etc.
    = Pointers to Pointers (2D arrays/Strings), Pointers to structs, etc.
- Und3rstanding of the working of the compression algorithm and encoding/decoding algorithms.

### TESTING:
- The above code has been tested for approx 50 strings with repeatition.
- The above code has been tested for approx 50 strings with no repeatition.
- The algorithm is most effective for strings with repeatition.
- The algorithm and all its concepts (min-heap, Huffman Tree, Huffman Code, Run-Length Encoding) works for all inputs.

### INSTRUCTIONS TO RUN THE CODE:
- The code is written in C language and can  be compiled on gcc compiler.
- The code can be run on any IDE or on the terminal.
Command to run the code on terminal:
    gcc -o Output_File Gautam_Ahuja_Huffman_Code_Compression.c
    ./Output_File

### On Runtime:
- The user is prompted to enter a string.
- Input a string which is less than 256 characters and does not contain any numerical characters.
- The program then outputs the  RL-encoded string, string in bits format, compressed string in bits format.
- The program prints the frequencies of each character in the string
- It also outputs the decompressed string along with decoded string.
- It also outputs the compression ratio.

<!-- Link file "Documentation" -->
### Read the [Documentation](./Documentation.md) for more details.