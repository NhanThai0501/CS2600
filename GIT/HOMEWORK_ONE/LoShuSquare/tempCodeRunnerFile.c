void shuffleArray(int arr[], int n) {
//     // This function shuffles numbers excluding the center number (5)
//     for (int i = n - 1; i > 0; i--) {
//         if (arr[i] == 5) continue; // skip number 5
//         int j;
//         do {
//             j = rand() % n;
//         } while (arr[j] == 5); // ensure we don't swap with 5
//         int temp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = temp;
//     }
// }


// int main() {
//     srand(time(NULL));
//     int square[SIZE][SIZE];
//     int attempts = 0;

//     while (true) {
//         int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//         shuffleArray(numbers, 9);

//         int index = 0;
//         for (int i = 0; i < SIZE; i++) {
//             for (int j = 0; j < SIZE; j++) {
//                 square[i][j] = numbers[index++];
//             }
//         }

//         attempts++;

//         if (isLoShuSquare(square)) {
//             break;
//         }
//     }

//     printf("Found a Lo Shu Square after %d attempts:\n", attempts);
//     for (int i = 0; i < SIZE; i++) {
//         for (int j = 0; j < SIZE; j++) {
//             printf("%d ", square[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }