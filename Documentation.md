# DOCUMENTATION FOR Gautam_Ahuja_Huffman_Code_Compression.c 

Gautam Ahuja
CS-1203: Data Structures
Debayan Gupta

December 22, 2022

# Final Project: COMPRESSION ALGORITHM (HUFFMAN CODING + RUN-LENGTH ENCODING + MIN-HEAP)

## HEADER FILES USED:
1. stdio.h
2. stdlib.h
3. string.h
4. ctype.h

## STRUCTURES USED:
1. MinHeapNode
2. MinHeap

## FUNCTIONS USED:
1. MinHeapNode* newNode(char data, unsigned freq)
2. MinHeap* createMinHeap(unsigned capacity)
3. void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b)
4. void minHeapify(MinHeap* minHeap, int idx)
5. int isSizeOne(MinHeap* minHeap)
6. MinHeapNode* extractMin(MinHeap* minHeap)
7. void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode)
8. void buildMinHeap(MinHeap* minHeap)
9. void printArr(int arr[], int n)
10. int isLeaf(MinHeapNode* root)
11. MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)
12. void printCodes(MinHeapNode* root, int arr[], int top)
13. void HuffmanCodes(char data[], int freq[], int size)
14. int main()

## TIME COMPLEXITY:
1. MinHeapNode* newNode(char data, unsigned freq) - O(1)
2. MinHeap* createMinHeap(unsigned capacity) - O(1)
3. void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) - O(1)
4. void minHeapify(MinHeap* minHeap, int idx) - O(log n)
5. int isSizeOne(MinHeap* minHeap) - O(1)
6. MinHeapNode* extractMin(MinHeap* minHeap) - O(log n)
7. void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) - O(log n)
8. void buildMinHeap(MinHeap* minHeap) - O(n)
9. void printArr(int arr[], int n) - O(n)
10. int isLeaf(MinHeapNode* root) - O(1)
11. MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) - O(n log n)   
12. void printCodes(MinHeapNode* root, int arr[], int top) - O(n)
13. void HuffmanCodes(char data[], int freq[], int size) - O(n log n)
14. int main() - O(n log n)
### For complete Program: O(n log n)

## SPACE COMPLEXITY:
1. MinHeapNode* newNode(char data, unsigned freq) - O(1)
2. MinHeap* createMinHeap(unsigned capacity) - O(1)
3. void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) - O(1)
4. void minHeapify(MinHeap* minHeap, int idx) - O(1)
5. int isSizeOne(MinHeap* minHeap) - O(1)
6. MinHeapNode* extractMin(MinHeap* minHeap) - O(1)
7. void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) - O(1)
8. void buildMinHeap(MinHeap* minHeap) - O(1)
9. void printArr(int arr[], int n) - O(1)
10. int isLeaf(MinHeapNode* root) - O(1)
11. MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) - O(n)
12. void printCodes(MinHeapNode* root, int arr[], int top) - O(n)
13. void HuffmanCodes(char data[], int freq[], int size) - O(n)
14. int main() - O(n)
### For complete Program: O(n)