//
//  ProjIO.c
//  ProjectAssignment4
//
//  Created by Edward Fominykh on 4/20/21.
//

#include <stdlib.h>
#include <stdio.h>



char* GENERIC_SPACE = "   ";


FILE *file;

pGate
{
    
    int mode;
    char** inputs;
    char** outputs;
    
};

void printPreGate(pGate gate)
{
    
    int gateMode = gate.mode;
    char** input = gate.inputs;
    char** output = gate.outputs;
    
    printf("%s Gate:\n", MODES[gateMode]);
    printf("%sInput: [", GENERIC_SPACE);
    
    for (int i = 0; input[i] != NULL; i++) {
        if(i) putchar(',');
        printf("%s",input[i]);
    }
    printf("]\n%sOutput: [", GENERIC_SPACE);
    for (int i = 0; output[i] != NULL; i++) {
        if(i) putchar(',');
        printf("%s",output[i]);
    }
    putchar(']');
    putchar('\n');
    
}

Gate {

    int outputID;
    int mode;
    int numInput;
    struct gate *input;
    int numOutput;
    struct gate *output;
    
};

char* getInput(int i)
{
    return input[i];
}

char* getOutput(int i)
{
    return output[i];
}

//int getIn(char*** array)
//{
//    int numInput;
//
//        fscanf(file, "INPUT %d", &numInput);
//        if(TESTING)
//        printf("Input: %d\n",numInput);
//
//    *array = malloc(numInput * sizeof(char*));
//    char *inputArray[numInput+1];
//    *array = inputArray;
//    int i;
//    for(i = 0; i < numInput; i++) {
//
//        char* word = malloc(sizeof(char)*16);
//        fscanf(file, " %s", word);
//
//        (*array)[i] = word;
//        if(TESTING)
//        printf("%d: %s\n",i+1,(*array)[i]);
//    }
//    (*array)[i] = NULL;
////    if(key)
//    fscanf(file, "\n");
//
//    return 0;
//
//}
//
//int getOut(char*** array)
//{
//    int numInput;
//
//        fscanf(file, "OUTPUT %d", &numInput);
//        if(TESTING)
//        printf("Output: %d\n",numInput);
//
//    *array = malloc(numInput * sizeof(char*));
//    char *inputArray[numInput+1];
//    *array = inputArray;
//    int i;
//    for(i = 0; i < numInput; i++) {
//
//        char* word = malloc(sizeof(char)*16);
//        fscanf(file, " %s", word);
//
//        (*array)[i] = word;
//        if(TESTING)
//        printf("%d: %s\n",i+1,(*array)[i]);
//    }
//    (*array)[i] = NULL;
//
//    fscanf(file, "\n");
//
//    return 0;
//
//}

int getInNOut(char*** array,int key)
{
    int numInput;
    if(key)    {
        fscanf(file, "INPUT %d", &numInput);
        numberOfInputs = numInput;
        if(TESTING1)
        printf("Input: %d\n",numInput);
    }
    else    {
        fscanf(file, "OUTPUT %d", &numInput);
        if(TESTING1)
        printf("Output: %d\n",numInput);
    }


    *array = malloc((numInput+1) * sizeof(char*));
//    printf("Malloced array\n");
//    char *inputArray[numInput+1];
//    *array = inputArray;
    int i;
    for(i = 0; i < numInput; i++) {

        char* word = (char*) malloc(sizeof(char)*16);
        mallocTrack++;
//        char temp[16];
        fscanf(file, " %s", word);
//        strcpy(word, temp);
        (*array)[i] = word;
        if(TESTING1)
        printf("%d: %s\n",i+1,(*array)[i]);
    }
    (*array)[i] = NULL;
    if(key)
    fscanf(file, "\n");
    
    return 0;

}

int modeS(char* mode)
{
    if(!strcmp(mode, "AND"))
        return AND;
    if(!strcmp(mode, "OR"))
        return OR;
    if(!strcmp(mode, "NAND"))
        return NAND;
    if(!strcmp(mode, "NOR"))
        return NOR;
    if(!strcmp(mode, "XOR"))
        return XOR;
    if(!strcmp(mode, "NOT"))
        return NOT;
    if(!strcmp(mode, "PASS"))
        return PASS;
    if(!strcmp(mode, "DECODER"))
        return DECODER;
    if(!strcmp(mode, "MULTIPLEXER"))
        return MULTIPLEXER;
    
    else
        return -1;
}

char** readIO(int numIOWords)
{

    char **words = malloc(sizeof(char*) * (numIOWords+1));
//    char* words[numIOWords+1];
//    printf("Size: %d\n", sizeof(words)/(numIOWords+1));
//    printf("Size: %d\n", sizeof(char*));
    int i;
    for(i = 0; i < numIOWords; i++) {

        char* word = malloc(sizeof(char) * 16);
        mallocTrack++;
        fscanf(file, " %s", word);
        words[i] = word;
        if(TESTING1)
        printf("%s%s%d: %s\n",GENERIC_SPACE,GENERIC_SPACE,i,(words)[i]);
    }
    words[i] = NULL;
    if(TESTING1)
    printf("Gate input0 (): %s\n", words[0]);
    return words;
}

void GENERIC_OUTPUT_MESSAGE()
{
    printf("%sOutput:\n", GENERIC_SPACE);
}

void readGateIO(int mode, char*** input, char*** output)
{
    
    switch (mode) {
        case AND:
            *input = readIO(2);
            if(TESTING1)
            GENERIC_OUTPUT_MESSAGE();
            *output = readIO(1);
            break;
        case OR:
            *input = readIO(2);
            if(TESTING1)
            GENERIC_OUTPUT_MESSAGE();
            *output = readIO(1);
            break;
        case NAND:
            *input = readIO(2);
            if(TESTING1)
            GENERIC_OUTPUT_MESSAGE();
            *output = readIO(1);
            break;
        case NOR:
            *input = readIO(2);
            if(TESTING1)
            GENERIC_OUTPUT_MESSAGE();
            *output = readIO(1);
            break;
        case XOR:
            *input = readIO(2);
            if(TESTING1)
            GENERIC_OUTPUT_MESSAGE();
            *output = readIO(1);
            break;
        case NOT:
            *input = readIO(1);
            if(TESTING1)
            GENERIC_OUTPUT_MESSAGE();
            *output = readIO(1);
//            putchar(getc(file));
//            fscanf(file, "\n");
            break;
        case PASS:
            *input = readIO(1);
            if(TESTING1)
            GENERIC_OUTPUT_MESSAGE();
            *output = readIO(1);
            break;
        case DECODER:
            {
            int numInput;
            fscanf(file, " %d ", &numInput);
                *input = readIO(numInput);
                if(TESTING1)
                printf("    Output:\n");
                *output = readIO(pow(2, numInput));
            }
            break;
        case MULTIPLEXER:
        {
            int numInput;
            fscanf(file, " %d ", &numInput);
            *input = readIO(pow(2, numInput)+numInput);
            if(TESTING1)
            printf("    Output:\n");
            *output = readIO(1);
        }
            break;
            
        default:
            printf("Gate input error: mode code not recognized\n");
            break;
    }
    
}

int readGates(int lines)
{

    
    char mode[16];

    for(int i = 0; i < 16; i++)
    {
        mode[i] = NULL;
    }

    char** inputs;
    char** outputs;
    fscanf(file, "%s", mode);
    if(TESTING1)
    printf("Mode: %s ",mode);
    int modeNum = modeS(mode);
    if(TESTING1)
    printf("(%d)\n    Input:\n",modeNum);

    if(modeNum==-1)
    {
        numGates = lines-1;
        if(TESTING1)
        printf("\nNumber of Gates is %d\n", numGates);
        preGateArray = malloc(sizeof(pGate)*numGates);
        return 0;
    }
    
    readGateIO(modeNum, &inputs, &outputs);
    fscanf(file, " ");
//    if (getc(file) == EOF)
//    {
//        numGates = lines;
//        printf("End of file");
//        return;
//    }
    readGates(lines+1);
    
    pGate gate;
    
    gate.inputs = inputs;
    if(TESTING1)
    printf("Gate input0 (%d): %s\n", modeNum, inputs[0]);
    if(TESTING1)
    printf("Gate output0 (%d): %s\n", modeNum, outputs[0]);
    gate.outputs = outputs;
    gate.mode = modeNum;
    
    
    
//    printf("Adding Gate\n");
    preGateArray[numGates-lines] = gate;
    
    // free(mode);
    
    return numGates;
//    printf("input[0]: %s\n", preGateArray[numGates-lines].inputs[0]);
//    printf("Newly added gate at %d mode: %d\n", numGates-lines, preGateArray[numGates-lines].mode);
}

void printAllPreGates()
{
    
    for (int i = 0; i < numGates; i++) {
        printf("%d: ", i);
        printPreGate(preGateArray[i]);
    }
    
}
