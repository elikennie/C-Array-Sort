
/* Elijah Kennie */
// preprocessor directives
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define ITERATIONS 5 // ITERATIONS is the number of iterations the program will go through

// main function
int main() {
    srand(time(NULL)); // initialization of random number generator

    int size;
    if(ITERATIONS == 1) {
        size = ((rand() % 50) + 50) + 1;
    }
    else {
        size = (rand() % ((50 * ITERATIONS) - 50) +50); // the size of the array we will be working with
    }

    //int size = (rand() % ((50 * ITERATIONS) - 50) +50); // the size of the array we will be working with
    int array [size]; // the actual array that will be manipulated to our specifications
    int maxVal; // maxVal is initialized here so that it can be used to print maximum range if debugging is needed

    printf("\n    Value of random size of array: %d\n", size);
    printf("    Size of array: %d bytes\n", sizeof(array));
    // a for loop that will repeat until the number of iterations is reached
    for(int i = 0; i < ITERATIONS; i++) {
        printf("\n----------------------------------------------------------------------------\n");
        printf("\nTHIS IS ITERATION NUMBER: %d of %d \n\n", i+1, ITERATIONS);

        // populating the array
        for(int j = 0; j <= size; j++) { // add a random number to each index of the array

            double exponent = ITERATIONS - i; // the exponent will be ITERATIONS - i because the max gets smaller every iteration
            maxVal = pow(10, exponent); // the maximum value that we want of the range (add 1 because we want to include the base 10 number in range)
            int randNum = (rand() % maxVal)+1; // our random number is in the range from 0 - the maxVal, this will be added to the array

            array[j] = randNum; // assign each index of the array to a random number
        }
        if(i == 0) {
            printf("This is the original array populated with values in the range of 1 and %d:\n", maxVal);
            printf("Number of elements in the original array is: %d\n", size);
        }

        // print all values of the randomly filled array
        for (int i = 0; i <= size; i++) {
            printf("%d  ", array[i]);
        }
        printf("\n");

#if defined (DEBUG) // first debug statement
            printf("Upper Range Value: %d \n", maxVal);
#endif

        // finding and replacing any duplicates
        for(int val1 = 0; val1 <= size; val1++) {

            int shiftVal = 0;
            for(int shifted = val1+1; shifted < size; shifted++) {
                if(array[val1] == array[shifted]) {
                    shiftVal++;
                }
            }

            int numShifts = 0;

            while(numShifts < shiftVal) {

                for(int val2 = val1+1;val2 < size; val2++) {

                    if(array[val1]==array[val2]) {

#if defined (DEBUG) // second debug statement
                        printf("The value of %d at array index [%d] and the value of %d at array index [%d] are the same.\n",array[val1],val1,array[val2],val2);
#endif
                        // shift is here
                        for(int s = val2; s < size; s++) {
                            array[s] = array[s+1];
                        }
                        array[size] = 0;

                        numShifts++;
                    }
                }

            }
        }

        // print array with all duplicates removed
        int nonZero = 0;
        for(int k = 0; k < size; k++) {
            if(array[k] != 0) {
                nonZero++;
            }
        }
        printf("\n\nThis is the current state of the array with all duplicate, non zero values removed:\n");
        printf("Number of unique (non zero, non duplicate) elements in the array is: %d\n", nonZero);
        // TODO remove all 0 values when printing
        for (int zerosRemoved = 0; zerosRemoved <= size; zerosRemoved++) {
            if(array[zerosRemoved] != 0) {
                printf("%d  ", array[zerosRemoved]);
            }
        }

        printf("\n\nThese are the unique, non zero elements in the array sorted in ascending order: \n\n");
        // print array with all duplicates removed and in ascending order
        for (int l = 0; l < size+1; ++l) {

            for (int m = 0; m < size - i+1; ++m) {
                if (array[m] > array[m + 1]) {
                    int temp = array[m + 1];
                    array[m + 1] = array[m];
                    array[m] = temp;
                }
            }
        }
        for (int sorted = 0; sorted <= size; sorted++) {
            if(array[sorted] != 0) {
                printf("%d  ", array[sorted]);
            }
        }
        printf("\n");

    }
    printf("\n----------------------------------------------------------------------------\n");
    return 0;
}