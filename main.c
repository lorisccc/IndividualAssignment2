/****************************************************
 *                                                  *
 *  Created by 2056314 - Loris Coccia on 08/03/2022 *
 *  C compiler used: mingw-w64                      *
 *                                                  *
 * **************************************************/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define STUDENT_ID 2056314
#define OUTFILE "result.txt"
#define Addition 0
#define Subtraction 1
#define Multiplication 2
#define Division 3

int randomNumber( int lower, int upper );

int main( int argc, char *argv[] ) {

    if (argc == 2) {
        // Use current time as seed for random generator
        srand(time(0));

        // Open file
        FILE *fpout;
        // Define variables
        int n, operator, num_oper;
        float number, prevnum;


        fpout = fopen(OUTFILE, "w");
        if (fpout == NULL) {
            puts("File path or name invalid");
            return (-1);
        }

        // Print student id in the file
        fprintf(fpout, "%d\n", STUDENT_ID);
        // Read number from command line
        sscanf(argv[1], "%d", &n);

        // Generate n-channel exercises
        for (int i = 0; i < n; i++) {

            // Generate the first random number between 0 and 100 and write it in the file
            prevnum = randomNumber(0, 100);
            fprintf(fpout, "%.0f", prevnum);
            // Generate number of operator for the current exercise
            num_oper = randomNumber(3, 5);

            for (int j = 0; j < num_oper; j++) {
                operator = randomNumber(0,3);
                // Generate the second number
                number = randomNumber(0, 100);
                // Using a switch to distinguish between the four operators
                switch (operator) {

                    case Addition:
                        // Write the symbol in the file
                        fprintf(fpout,"+%.0f", number);
                        // Compute the partial total
                        prevnum += number;
                        break;

                    case Subtraction:
                        // Write the symbol in the file
                        fprintf(fpout,"-%.0f", number);
                        // Compute the partial total
                        prevnum -= number;
                        break;

                    case Multiplication:
                        // Write the symbol in the file
                        fprintf(fpout,"*%.0f", number);
                        // Compute the partial total
                        prevnum *= number;
                        break;

                    case Division:
                        // Write the symbol in the file
                        fprintf(fpout,"/%.0f", number);
                        // Compute the partial total
                        prevnum /= number;
                        break;

                    default:
                        break;
                }
            }
            // Print the result
            fprintf(fpout, "=%.2f\n", prevnum);
        }
        // Close file
        fclose(fpout);
    }
    else if ( argc > 2 ) {
        printf("Too many arguments supplied.\n");
    }
    else {
        printf("One argument expected.\n");
    }

    return 0;
}

// The function generates a random number in a given range
// lower is the lower limit of the range
// upper is the upper limit of the range
int randomNumber(int lower, int upper) {
    int num;
    num = (rand() % (upper - lower + 1)) + lower;
    return num;
}
