#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 3

bool isLoShuSquare(int square[SIZE][SIZE]) {
    int magicSum = 15;
    int diag1 = square[0][0] + square[1][1] + square[2][2];
    int diag2 = square[0][2] + square[1][1] + square[2][0];

    for (int i = 0; i < SIZE; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < SIZE; j++) {
            rowSum += square[i][j];
            colSum += square[j][i];
        }
        if (rowSum != magicSum || colSum != magicSum) {
            return false;
        }
    }
    if (diag1 != magicSum || diag2 != magicSum) {
        return false;
    }
    return true;
}

int randomization(int *arr, int size) {
    int index = rand() % size;
    int val = arr[index];
    arr[index] = arr[size - 1];  // swap with the last element
    return val;
}

int main() {
    srand(time(NULL));
    int square[SIZE][SIZE] = {0};
    int attempts = 0;

    while (true) {
        int evens[] = {2, 4, 6, 8};
        int odds[] = {1, 3, 7, 9};
        int evenSize = 4, oddSize = 4;

        square[1][1] = 5;  // Center is always 5

// Four corners must be even numbers
        square[0][0] = randomization(evens, evenSize--);
        square[0][2] = randomization(evens, evenSize--);
        square[2][0] = randomization(evens, evenSize--);
        square[2][2] = randomization(evens, evenSize--);

// Four sides must be odd numbers
        square[0][1] = randomization(odds, oddSize--);
        square[1][0] = randomization(odds, oddSize--);
        square[1][2] = randomization(odds, oddSize--);
        square[2][1] = randomization(odds, oddSize--);

        attempts++;

        if (isLoShuSquare(square)) {
            break;
        }
    }

    // printf("Found a Lo Shu Square after %d attempts:\n", attempts);
    printf("%d attempts to find the Lo Shu Square \n", attempts);
    for (int i = 0; i < SIZE; i++) {
        printf("[ ");
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", square[i][j]);
        }
        printf("]\n");
    }

    return 0;
}