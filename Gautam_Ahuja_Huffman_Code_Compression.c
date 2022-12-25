#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum height of the Huffman tree
#define MAX_TREE_HT 100

// Define a structure for Huffman Tree Node, It will be in form of minHeap
struct MinHeapNode {
    // One of the input characters
    char data;
    // Frequency of the character
    unsigned freq;
    // Left and right child of this node
    struct MinHeapNode *left, *right;
};

// Define a structure for Min Heap. It is a collection of Huffman leaf nodes
struct MinHeap {
    // Current size of min heap
    unsigned size;
    // capacity of min heap
    unsigned capacity;
    // Array of minheap node pointers
    struct MinHeapNode** array;
};

// A utility function allocate a new min heap node with given character and frequency of the character
struct MinHeapNode*  newNode(char data, unsigned freq)
{
    struct MinHeapNode* temp = (struct MinHeapNode* )malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// A utility function to create a min heap of given capacity
struct MinHeap* createMinHeap(unsigned capacity)
{
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    // current size is 0
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// A utility function to swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode** a,struct MinHeapNode** b){
  struct MinHeapNode* t = *a;
  *a = *b;
  *b = t;
}

// The standard minHeapify function
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// A utility function to check if size of heap is 1 or not
int isSizeOne(struct MinHeap* minHeap)
{
    return (minHeap->size == 1);
}

// A standard function to extract minimum value node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// A utility function to insert a new node to Min Heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// A standard function to build min heap
void buildMinHeap(struct MinHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// A utility function to print an array of size n
int printArr(int arr[], int n)
{
  int i;
  for (i = 0; i < n; ++i)
    printf("%d", arr[i]);
 
  printf("\n");
}

// Utility function to check if this node is leaf
int isLeaf(struct MinHeapNode* root)
{
    return !(root->left) && !(root->right);
}

// Creates a min heap of capacity equal to size and inserts all character of data[] in min heap. Initially size of min heap is equal to capacity
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)
{
    struct MinHeap* minHeap = createMinHeap(size);
    int i;
    for (i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// The main function that builds Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size){
    struct MinHeapNode *left, *right, *top;
    // Step 1: Create a min heap of capacity equal to size. Initially, there are modes equal to size.
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    // Iterate while size of heap doesn't become 1
    while (!isSizeOne(minHeap)) {
        // Step 2: Extract the two minimum freq items from min heap
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        // Step 3: Create a new internal node with frequency equal to the sum of the two nodes frequencies. Make the two extracted node as left and right children of this new node. Add this node to the min heap
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    // Step 4: The remaining node is the root node and the tree is complete.
    return extractMin(minHeap);
}

// Prints huffman codes from the root of Huffman Tree. It uses arr[] to store codes
// Huffman codes are used to compress data to make it smaller. Huffman coding is a lossless data compression algorithm.
void printCodes(struct MinHeapNode* root, int arr[], int top)
{
    // Assign 0 to left edge and recur
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    // Assign 1 to right edge and recur
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    // If this is a leaf node, then it contains one of the input characters, print the character and its code from arr[]
    if (isLeaf(root)) {
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}

// The main function that builds a Huffman Tree and print codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
    // Construct Huffman Tree
    struct MinHeapNode* minHeap = buildHuffmanTree(data, freq, size);
    // Print Huffman codes using the Huffman tree built above
    int arr[MAX_TREE_HT], top = 0;
    printCodes(minHeap, arr, top);
}

// Function to get the Huffman codes for each character
// Codes are generated by traversing the Huffman tree. If we go to left edge, we append 0 to the code. If we go to the right edge, we append 1 to the code. We assign codes to leaves (nodes with the data) only. Internal nodes don’t have any code assigned to them.
void getCodes(struct MinHeapNode* root, char* codes[256],int arr[], int top){
    if (isLeaf(root)) {
        codes[root->data] = (char*)malloc(top + 1);
        for (int i = 0; i < top; i++)
            codes[root->data][i] = arr[i] + '0';
        codes[root->data][top] = '\0';
    }

    // If the current node has a left child,
    // add a '0' to the code and recursively
    // get the codes for the left child
    else {
        arr[top] = 0;
        getCodes(root->left, codes, arr, top + 1);
    }

    // If the current node has a right child,
    // add a '1' to the code and recursively
    // get the codes for the right child
    if (root->right) {
        arr[top] = 1;
        getCodes(root->right, codes, arr, top + 1);
    }
}

// Function to compress the string
char* compress(char* str, char* codes[256])
{
  // Calculate size of the compressed string
  int size = 0;
  for (int i = 0; str[i]; i++)
    size += strlen(codes[str[i]]);
 
  // Allocate memory for the compressed string
  char* compressed = (char*)malloc(size + 1);
 
  // Compress the string
  int j = 0;
  for (int i = 0; str[i]; i++) {
 
    strcpy(&compressed[j], codes[str[i]]);
    j += strlen(codes[str[i]]);
  }
 
  // Add a null character at the end
  // of the compressed string
  compressed[size] = '\0';
 
  // Return the compressed string
  return compressed;
}

// Decompression function
char* decompress(char* str, struct MinHeapNode* root)
{
  // Allocate memory for the decompressed string
  char* decompressed = (char*)malloc(strlen(str) + 1);
 
  // Keep track of the current position in the decompressed string
  int j = 0;
 
  // Start from the root of the Huffman Tree
  struct MinHeapNode* current = root;
 
  // Iterate through the compressed string
  for (int i = 0; str[i]; i++) {
 
    // If the current character is a '0',
    // move to the left child of the current node
    if (str[i] == '0')
      current = current->left;
 
    // If the current character is a '1',
    // move to the right child of the current node
    else
      current = current->right;
 
    // If the current node is a leaf node,
    // add its data to the decompressed string
    if (isLeaf(current)) {
 
      decompressed[j++] = current->data;
      current = root;
    }
  }
 
  // Add a null character at the end
  // of the decompressed string
  decompressed[j] = '\0';
 
  // Return the decompressed string
  return decompressed;
}

// Function to print the binary representation
void printBits(char* str)
{
  for (int i = 0; str[i]; i++) {
    // Convert the character to an int and
    // print its binary representation
    int val = (int)str[i];
    for (int j = 7; j >= 0; j--)
      printf("%d", (val >> j) & 1);
    printf(" ");
  }
  printf("\n");
}

// Run Lenth encoding function
char* runLengthEncode(char* str)
{
  // Allocate memory for the encoded string
  char* encoded = (char*)malloc(strlen(str) * 2 + 1);
 
  // Initialize variables
  int count = 1;
  char last = str[0];
 
  // Iterate through the string
  int j = 0;
  for (int i = 1; str[i]; i++) {
 
    // If the current character is different
    // from the previous one, add the count
    // and the character to the encoded string
    if (str[i] != last || count == 9 ) {
      if (count >= 2) {
        encoded[j++] = count + '0';
      }
      encoded[j++] = last;
      count = 1;
      last = str[i];
    }
 
    // If the current character is the same
    // as the previous one, increment the count
    else
      count++;
  }
 
  // Add the final count and character
  // to the encoded string
  if (count >= 3) {
    encoded[j++] = count + '0';
  }
  encoded[j++] = last;
 
  // Add a null character at the end
  // of the encoded string
  encoded[j] = '\0';
 
  // Return the encoded string
  return encoded;
}


// Decoder Function
char* runLengthDecode(char* str)
{
  // Allocate memory for the decoded string
  char* decoded = (char*)malloc(strlen(str) / 2 + 1);
 
  // Initialize variables
  int count = 0;
  char last = '\0';
 
  // Iterate through the string
  int j = 0;
  for (int i = 0; str[i]; i++) {
 
    // If the current character is a digit,
    // update the count
    if (isdigit(str[i]))
      count = count * 10 + str[i] - '0';
 
    // If the current character is a letter,
    // add it to the decoded string
    else {
      // If the count is 0, add the character
      // to the decoded string once
      if (count == 0)
        decoded[j++] = str[i];
 
      // If the count is 1, add the character
      // to the decoded string twice
      else if (count == 1) {
        decoded[j++] = str[i];
        decoded[j++] = str[i];
      }
 
      // If the count is greater than 1,
      // add the character to the decoded
      // string the specified number of times
      else {
        for (int k = 0; k < count; k++)
          decoded[j++] = str[i];
      }
      count = 0;
    }
  }
 
  // Add a null character at the end
  // of the decoded string
  decoded[j] = '\0';
 
  // Return the decoded string
  return decoded;
}

int check(char* str){
    if(strlen(str) > 100 || strlen(str) < 1){
        return 1;
    }
    for (int i = 0; str[i]; i++) {
        if(isdigit(str[i])){
            return 1;
        }
    }
    return 0;
}

// Driver Program
int main(int argc, char const *argv[])
{
    char* str;
    // Enter a String
    printf("Enter non-numeric string (256 character max): ");
    gets(str);

    if(check(str)){
        printf("Invalid Input");
        return 0;
    }


    // Calculate size of original string
    int original_size = strlen(str)*8;
    printf("\nOriginal size: %d bits", original_size);

    // Print the original string in bits
    printf("\nOriginal string in bits: ");
    printBits(str);
    
    // Run Time Encoding
    str = runLengthEncode(str);
    printf("\nRun Length Encoded string: %s", str);

    // calculating frequency of each character
    int freq[256] = {0};
    for(int i=0;str[i]!='\0';i++){
        freq[str[i]]++;
    }
    // Print Frequency of each character
    printf("\nFrequency of each character: ");
    for (int i = 0; i < 256; i++)
        if (freq[i])
            printf("%c: %d ", i, freq[i]);
    printf("\n");


    // Build Huffman Tree
    struct MinHeapNode* root = buildHuffmanTree(str, freq, strlen(str));

    // Getting Huffman Codes
    int arr[MAX_TREE_HT], top = 0;
    // Store the codes in an array
    char* codes[256];
    getCodes(root, codes, arr, top);


    // Compress the string 
    char* compressed = compress(str, codes);
    printf("\nCompressed string: %s", compressed);

    // Calculate the length of the compressed string in bits
    int compressed_size = strlen(compressed);
    printf("\nCompressed string length: %d bits", compressed_size);

    // Decompress the string
    char* decompressed = decompress(compressed, root);
    printf("\nDecompressed string: %s", decompressed);

    // Perform run timr decoding
    decompressed = runLengthDecode(decompressed);
    // Print the Decoded string
    printf("\nDecoded string: %s", decompressed);

    // Compression Ratio
    double ratio = (double)compressed_size / (double)original_size;
    printf("\nCompression Ratio: %f", ratio);

    return 0;
}
