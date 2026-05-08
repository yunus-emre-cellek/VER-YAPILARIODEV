inclu#de <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500

void bubbleSort(int arr[]) {
    int i, j, temp;

    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[]) {
    int i, j, minIndex, temp;

    for (i = 0; i < SIZE - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void copyArray(int source[], int destination[]) {
    int i;

    for (i = 0; i < SIZE; i++) {
        destination[i] = source[i];
    }
}

int main() {
    int original[SIZE];
    int bubbleArray[SIZE];
    int selectionArray[SIZE];
    int i;

    clock_t start, end;
    double bubbleTime, selectionTime;

    srand(time(NULL));

    for (i = 0; i < SIZE; i++) {
        original[i] = rand() % 1001;
    }

    copyArray(original, bubbleArray);
    copyArray(original, selectionArray);

    start = clock();
    bubbleSort(bubbleArray);
}