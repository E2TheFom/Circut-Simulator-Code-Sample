//
//  GateProcessor.h
//  ProjectAssignment4
//
//  Created by Edward Fominykh on 4/20/21.
//


//int bitshift(int a)
//{
//    int i;
//    
//    while (<#condition#>) {
//        <#statements#>
//    }
//    
//    
//}



int countValuesInArray(char** array)
{
    
    int i;
    
    for (i = 0; array[i] != NULL; i++) {
        
    }
    
    return i;
}

void binaryIteration(int* binaryArray, int length)
{
    int carryOver = 1;
    for(int i = length-1; i >= 0; i--)
    {
        
        int bit = binaryArray[i];
        switch (carryOver+bit) {
            case 1:
                binaryArray[i] = 1;
                carryOver = 0;
                break;
            case 2:
                binaryArray[i] = 0;
                carryOver = 1;
                break;
            default:
                break;
        }
        
    }
    
}

int multiplexerInputEquation(int test)
{
    return (pow(2, test) + test);
}

int indexMultiplexer(char** input1, int* inputValues)
{
    int size = countValuesInArray(input1);
    int subIndex = 0;
    while(multiplexerInputEquation(subIndex)!=size)
    {
        subIndex++;
    }
    
    int index = 0;
    int power = 0;
    for(int i = size-1; i >= size-subIndex; i--)
    {
        char* word = input1[i];
        int isAdding = getGateOutput(word, inputValues);
        if (isAdding) {
            index += pow(2, power);
        }
        
        power++;
    }
    return index;
}

void printArray(char** input, char* whichone)
{
    printf("%s Array: \n", whichone);
    int i = 0;
    char* word = input[i];
    while (word != NULL) {
        printf("%d: %s\n", i, input[i]);
        i++;
        word = input[i];
    }
}

void freeArray(char** input)
{
    int i = 0;
    char* word = input[i];
    while (word != NULL) {
        free(input[i]);
        freeTrack++;
        i++;
        word = input[i];
    }
}

//void freeGate(pGate* gate)
//{
//    
//    int mode = gate -> mode;
//    switch (mode) {
//        case AND:
//        {
//            int result = (getGateOutput(gateInput(0), inputValues) && getGateOutput(gateInput(1), inputValues));
//            return result;
//        }
//            break;
//        case OR:
//        {
//            int result = (getGateOutput(gateInput(0), inputValues) || getGateOutput(gateInput(1), inputValues));
//        }
//            break;
//        case NAND:
//        {
//            int result = !(getGateOutput(gateInput(0), inputValues) && getGateOutput(gateInput(1), inputValues));
//        }
//            break;
//        case NOR:
//        {
//            int result = !(getGateOutput(gateInput(0), inputValues) || getGateOutput(gateInput(1), inputValues));
//        }
//            break;
//        case XOR:
//        {
//            int result = (getGateOutput(gateInput(0), inputValues) ^ getGateOutput(gateInput(1), inputValues));
//        }
//            break;
//        case NOT:
//        {
//            int result = !getGateOutput(gateInput(0), inputValues);
//        }
//            break;
//        case PASS:
//        {
//            int result = getGateOutput(gateInput(0), inputValues);
//        }
//            break;
//        case DECODER:
//        {
//            int indexLoc = indexOf(outputVal, (*findGate(outputVal)).outputs);
//            if(TESTING2)
//                printf("Indexs: %d\n", indexLoc);
//            
//            int result = decoderGate(outputVal, inputValues, indexLoc);
//            if(TESTING2)
//                printf("%s value: %d\n", outputVal, result);
//            return result;
//        }
//            break;
//        case MULTIPLEXER:
//        {
//            if(TESTING2)
//            printf("Multiplexer mode:\n");
//            int multIndex = indexMultiplexer(gateInputs, inputValues);
//            return getGateOutput(gateInput(multIndex), inputValues);
//        }
//            break;
//            
//        default:
//            if(TESTING2)
//                printf("Gate processing error: mode code not recognized\n");
//            break;
//    }
//    
    


