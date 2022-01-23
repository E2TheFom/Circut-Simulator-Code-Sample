//
//  main.c
//  ProjectAssignment4
//
//  Created by Edward Fominykh on 4/19/21.
//

//Note to self: Working on freeing mallocs

#include <stdlib.h>
#include <string.h>
#include <math.h>


#define Gate struct gate
#define pGate struct preGate

int numGates = 0;

int mallocTrack = 0;
int freeTrack = 0;

typedef enum { AND, OR, NAND, NOR, XOR, NOT, PASS, DECODER, MULTIPLEXER } kind_t;
const char* const MODES[] = { "AND", "OR", "NAND", "NOR", "XOR", "NOT", "PASS", "DECODER", "MULTIPLEXER" };

pGate* preGateArray = NULL;
Gate* GateArray = NULL;

const int TESTING1 = 0;
const int TESTING2 = 0;

int countRecurOps = 0;

char** input = NULL;
char** output = NULL;

int numberOfInputs = 0;;

#include "ProjIO.h"

enum {IN, OUT};

pGate* findGate();
int getGateOutput(char* outputVal, int* inputValues);

#include "Utilities.h"

int inputIndexOf(char* word)
{
    
    for(int i = 0; input[i] != NULL; i++)
    {
//        printf("Num : %d : %s\n", 0, input[0]);
//        printf("Num : %d : %s\n", i, input[i]);
        char* inputNum = input[i];
//        printf("Word: %s\n", word);
        if(!strcmp(word, inputNum))
            return i;
    }
    return -1;
}

int indexOf(char* word, char** input1)
{
    
    for(int i = 0; input1[i] != NULL; i++)
    {
//        printf("Num : %d : %s\n", 0, input[0]);
//        printf("Num : %d : %s\n", i, input[i]);
        if(!strcmp(word, input1[i]))
            return i;
    }
    return -1;
}

#define gateInput(X) (*findGate(outputVal)).inputs[X]
#define gateInputs (*findGate(outputVal)).inputs

int decoderGate(char* outputVal, int* inputValues, int index)
{
    if(TESTING2)
        printf("Decoder running (%s)\n", outputVal);
//    index;
    if(TESTING2)
        printf("Indexd: %d\n", index);
    int sizeInputs = countValuesInArray(findGate(outputVal)->inputs);
    int position = sizeInputs-1;
    while (position>=0) {
        int lastByte = index%2;
        char* word =gateInput(position);
        int a = (getGateOutput(word, inputValues));
        int b = lastByte;
        int c = (a != b);

        if (c) {
            if(TESTING2)
                printf("Decoder (%s) returned 0\n", outputVal);
            return 0;
        }
        index = index >> 1;
        position--;
    }
    if(TESTING2)
        printf("Decoder (%s) returned 1\n", outputVal);
    return 1;
}

int getGateOutput(char* outputVal, int* inputValues)
{
//    printf("Test inside method: %s\n",(*findGate("OUT1")).inputs[0]);
    countRecurOps++;
    
    if(TESTING2)
        printf("Processing output [ %s ]\n", outputVal);
    
    if (!strcmp(outputVal, "1")) {
        return 1;
    }
    
    if (!strcmp(outputVal, "0")) {
        return 0;
    }

    int index = 0;
    
//    if(TESTING2)
//        for(
//    printArray(input, "Input");
//    printArray(output, "Output");
    index = inputIndexOf(outputVal);
    if(index!=-1)
    {
        int result =
         inputValues[index];
        if(TESTING2)
            printf("%s value: %d\n", outputVal, result);
        return result;
    }
    
//    printf("Index: %d\n", index);

    pGate gate = *findGate(outputVal);
    
    int mode = (gate).mode;
    switch (mode) {
        case AND:
        {
            int result = (getGateOutput(gateInput(0), inputValues) && getGateOutput(gateInput(1), inputValues));
            if(TESTING2)
                printf("%s value: %d\n", outputVal, result);
            return result;
        }
            break;
        case OR:
        {
            int result = (getGateOutput(gateInput(0), inputValues) || getGateOutput(gateInput(1), inputValues));
            if(TESTING2)
                printf("%s value: %d\n", outputVal, result);
            return result;
        }
            break;
        case NAND:
        {
            int result = !(getGateOutput(gateInput(0), inputValues) && getGateOutput(gateInput(1), inputValues));
            if(TESTING2)
                printf("%s value: %d\n", outputVal, result);
            return result;
        }
            break;
        case NOR:
        {
            int result = !(getGateOutput(gateInput(0), inputValues) || getGateOutput(gateInput(1), inputValues));
            if(TESTING2)
                printf("%s value: %d\n", outputVal, result);
            return result;
        }
            break;
        case XOR:
        {
            int result = (getGateOutput(gateInput(0), inputValues) ^ getGateOutput(gateInput(1), inputValues));
            if(TESTING2)
                printf("%s value: %d\n", outputVal, result);
            return result;
        }
            break;
        case NOT:
        {
            int result = !getGateOutput(gateInput(0), inputValues);
            if(TESTING2)
                printf("%s value: %d\n", outputVal, result);
            return result;
        }
            break;
        case PASS:
        {
            int result = getGateOutput(gateInput(0), inputValues);
            if(TESTING2)
                printf("%s value: %d\n", outputVal, result);
            return result;
        }
            break;
        case DECODER:
        {
            int indexLoc = indexOf(outputVal, (*findGate(outputVal)).outputs);
            if(TESTING2)
                printf("Indexs: %d\n", indexLoc);
            
            int result = decoderGate(outputVal, inputValues, indexLoc);
            if(TESTING2)
                printf("%s value: %d\n", outputVal, result);
            return result;
        }
            break;
        case MULTIPLEXER:
        {
            if(TESTING2)
            printf("Multiplexer mode:\n");
            int multIndex = indexMultiplexer(gateInputs, inputValues);
            return getGateOutput(gateInput(multIndex), inputValues);
        }
            break;
            
        default:
            if(TESTING2)
                printf("Gate processing error: mode code not recognized\n");
            break;
    }
    
    
    return -1;
}

pGate* findGate(char* target)
{
    
    for (int i = 0; i < numGates; i++) {
        for(int z = 0; preGateArray[i].outputs[z] != NULL; z++){
         
            char* output = preGateArray[i].outputs[z];
            if (!strcmp(output, target)) {
                return &preGateArray[i];
            }
            
        }
    }
    
    return NULL;
}

//#include "GateProcessor.h"

void printBinaryArray(int* binaryArray, int length)
{
    
    for (int i = 0; i < length; i++) {
        printf("%d ", binaryArray[i]);
    }
    printf("|");
    
}

void printTruthTable()
{
    
    int numInputs = numberOfInputs;
//    printf("%d\n", numInputs);
    int testInputs[numInputs];
    
    for(int i = 0; i < numInputs; i++)
    {
        testInputs[i] = 0;
    }
    
    for (int i = 0; i < pow(2, numInputs); i++) {
        printBinaryArray(testInputs, numInputs);
        
        for (int outputIndex = 0; output[outputIndex] != NULL; outputIndex++) {
            printf(" %d", getGateOutput(output[outputIndex], testInputs));
        }
        
        putchar('\n');
        binaryIteration(testInputs, numInputs);
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    file = fopen(argv[1], "r");
    //char** input;
    getInNOut(&input, 1); // <-------------
    if(TESTING2)
        printf("bNum : %d : %s\nI/O Equal?: %d\n", 0, input[0], output==input);

    //char** output;
    getInNOut(&output, 0); // <-------------
    if(TESTING2)
        printf("bNum : %d : %s\nI/O Equal?: %d\n", 0, input[0], output==input);
    numGates = readGates(1);
    if(TESTING2)
        printAllPreGates();
  
    
//    printf("Num inputs in %d: %d\n", 0, countValuesInArray(findGate("temp20")->inputs));
    
    
    if(TESTING2)
    {
    int inputs[] = {0, 0, 0, 0, 0, 0};
    int testAnswer = getGateOutput("OUT1", inputs);
    printf("Result: %d\n", testAnswer);
    }
    if(!TESTING2)
    printTruthTable();
    
//    int testnum = 1378;
//    int testnum1 = testnum >> 10;
//    printf("Test: %d\n",testnum1);
    
//    int i = findGate("OUT1");
//    pGate gate = preGateArray[i];
//    int test = gate.mode;
//    printf("testMode :%d\n", test);
//    char* wordTest =gate.inputs[0];
//    printf("1st input (%d): %s\n",i,wordTest);
    
//    printf("Global output0: %s", input[0]);
//    printf("Test before method: %s\n",(*findGate("OUT1")).inputs[0]);

//    printf("gate out: %s\n", preGateArray[0].outputs[0]);
//    printf("gate in: %s\n", preGateArray[0].inputs[0]);

    
    
    freeArray(input);
    freeArray(output);
    free(input);
    free(output);
    
    for (int i = 0; i < numGates; i++) {
        freeArray(preGateArray[i].inputs);
        freeArray(preGateArray[i].outputs);
        free(preGateArray[i].inputs);
        free(preGateArray[i].outputs);
    }
    
    free(preGateArray);

    return 0;
}


