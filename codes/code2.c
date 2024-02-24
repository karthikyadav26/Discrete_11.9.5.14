#include <stdio.h>
#include <math.h>

int main() {
    // Given GP parameters
    double firstTerm = 0.5;
    double commonRatio = 0.33;
    
    // Number of terms to generate
    int numTerms = 6;

    // Array to store coordinates
    double coordinates[numTerms][2];

    // Generate coordinates for the stem plot
    for (int i = 0; i < numTerms; ++i) {
        // x-coordinate is the term number
        coordinates[i][0] = i + 1;

        // y-coordinate is the value of the GP term
        coordinates[i][1] = firstTerm * pow(commonRatio, i);
    }

    // Open the file for writing
    FILE *file = fopen("data1.txt", "w");

    // Check if the file was opened successfully
    if (file != NULL) {
        // Write coordinates to the file
        for (int i = 0; i < numTerms; ++i) {
            fprintf(file, "%0.2lf %0.2lf\n", coordinates[i][0], coordinates[i][1]);
        }

        // Close the file
        fclose(file);

        printf("Coordinates written to data1.txt successfully.\n");
    } else {
        // Print an error message if file opening fails
        printf("Error opening file for writing.\n");
    }

    return 0;
}

