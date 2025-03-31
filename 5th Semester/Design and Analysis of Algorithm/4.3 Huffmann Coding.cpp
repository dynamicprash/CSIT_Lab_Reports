#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HuffNode {
    char symbol;
    unsigned weight;
    struct HuffNode *left, *right;
};

struct HuffHeap {
    unsigned size;
    unsigned capacity;
    struct HuffNode** elements;
};

int iterationCount = 0;

struct HuffNode* createHuffNode(char symbol, unsigned weight) {
    struct HuffNode* temp = (struct HuffNode*)malloc(sizeof(struct HuffNode));
    temp->left = temp->right = NULL;
    temp->symbol = symbol;
    temp->weight = weight;
    return temp;
}

struct HuffHeap* createHuffHeap(unsigned capacity) {
    struct HuffHeap* heap = (struct HuffHeap*)malloc(sizeof(struct HuffHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->elements = (struct HuffNode**)malloc(heap->capacity * sizeof(struct HuffNode*));
    return heap;
}

void swapHuffNodes(struct HuffNode** a, struct HuffNode** b) {
    struct HuffNode* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct HuffHeap* heap, int idx) {
    int smallest = idx;
    int leftChild = 2 * idx + 1;
    int rightChild = 2 * idx + 2;

    if (leftChild < heap->size && heap->elements[leftChild]->weight < heap->elements[smallest]->weight)
        smallest = leftChild;

    if (rightChild < heap->size && heap->elements[rightChild]->weight < heap->elements[smallest]->weight)
        smallest = rightChild;

    if (smallest != idx) {
        swapHuffNodes(&heap->elements[smallest], &heap->elements[idx]);
        heapify(heap, smallest);
    }
}

int isSingleNode(struct HuffHeap* heap) {
    return (heap->size == 1);
}

struct HuffNode* extractMin(struct HuffHeap* heap) {
    struct HuffNode* temp = heap->elements[0];
    heap->elements[0] = heap->elements[heap->size - 1];
    --heap->size;
    heapify(heap, 0);
    return temp;
}

void insertHuffHeap(struct HuffHeap* heap, struct HuffNode* node) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->weight < heap->elements[(i - 1) / 2]->weight) {
        heap->elements[i] = heap->elements[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->elements[i] = node;
}

void buildHuffHeap(struct HuffHeap* heap) {
    int n = heap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        heapify(heap, i);
}

void printHuffCodes(struct HuffNode* root, int codeArray[], int level) {
    if (root->left) {
        codeArray[level] = 0;
        printHuffCodes(root->left, codeArray, level + 1);
    }

    if (root->right) {
        codeArray[level] = 1;
        printHuffCodes(root->right, codeArray, level + 1);
    }

    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->symbol);
        for (int i = 0; i < level; ++i)
            printf("%d", codeArray[i]);
        printf("\n");
    }

    iterationCount++;
}

struct HuffNode* generateHuffmanTree(char symbols[], int weights[], int size) {
    struct HuffNode *left, *right, *top;
    struct HuffHeap* heap = createHuffHeap(size);

    for (int i = 0; i < size; ++i)
        heap->elements[i] = createHuffNode(symbols[i], weights[i]);

    heap->size = size;
    buildHuffHeap(heap);

    while (!isSingleNode(heap)) {
        left = extractMin(heap);
        right = extractMin(heap);

        top = createHuffNode('$', left->weight + right->weight);
        top->left = left;
        top->right = right;

        insertHuffHeap(heap, top);
    }

    return extractMin(heap);
}

int main() {
    int numSymbols;
    printf("--------HUFFMAN CODING--------\n\n");
    printf("Developed by: Prashant Paudel\n");
    printf("Enter the number of unique characters: ");
    scanf("%d", &numSymbols);

    char symbols[numSymbols];
    int weights[numSymbols];

    printf("Enter characters and their frequencies (format: character frequency):\n");
    for (int i = 0; i < numSymbols; ++i) {
        printf("Input %d: ", i + 1);
        scanf(" %c %d", &symbols[i], &weights[i]);
    }

    struct HuffNode* root = generateHuffmanTree(symbols, weights, numSymbols);

    int codeArray[100], level = 0;
    printf("\nHuffman Codes:\n");
    printHuffCodes(root, codeArray, level);

    printf("Total Iterations: %d\n", iterationCount);
    printf("\nThank you! - Prashant Paudel\n");
    return 0;
}
