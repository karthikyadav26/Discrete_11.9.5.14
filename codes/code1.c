#include <stdio.h>

// Function to generate coordinates for stem plot of GP
void generateGPStemPlot(int firstTerm, int commonRatio, int numTerms, int coordinates[][2]) {
    int i, term = firstTerm;

    for (i = 0; i < numTerms; i++) {
        coordinates[i][0] = i + 1;      // X-coordinate is the term number
        coordinates[i][1] = term;       // Y-coordinate is the value of the GP term
        term *= commonRatio;            // Calculate the next term in the GP
    }
}

// Function to store coordinates in a text file
void storeCoordinatesToFile(int numTerms, int coordinates[][2]) {
    FILE *file = fopen("data.txt", "w");

    if (file != NULL) {
        fprintf(file, "Term\tValue\n");
        for (int i = 0; i < numTerms; i++) {
            fprintf(file, "%d\t%d\n", coordinates[i][0], coordinates[i][1]);
        }
        fclose(file);
        printf("Coordinates have been stored in data.txt.\n");
    } else {
        printf("Error opening file for writing.\n");
    }
}

int main() {
    // Define parameters for the GP
    int firstTerm = 2;
    int commonRatio = 3;
    int numTerms = 6; // Changed to 6 coordinates

    // Array to store coordinates [term_number, term_value]
    int coordinates[numTerms][2];

    // Generate coordinates for stem plot
    generateGPStemPlot(firstTerm, commonRatio, numTerms, coordinates);

    // Store the generated coordinates in a text file
    storeCoordinatesToFile(numTerms, coordinates);

    return 0;
}

