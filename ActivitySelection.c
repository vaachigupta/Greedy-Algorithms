#include<stdio.h>
#define max 10
/*
void merge(int arr1[], int arr2[], int p, int q, int r) {
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
    int L1[n1], L2[n1], R1[n2], R2[n2];
    for (i = 0; i < n1; i++) {
        L1[i] = arr1[p + i];
        L2[i] = arr2[p + i];
    }
    for (j = 0; j < n2; j++) {
        R1[j] = arr1[q + 1 + j];
        R2[j] = arr2[q + 1 + j];
    }
    i = j = 0;
    k = p;
    while (i < n1 && j < n2) {
        if (L2[i] <= R2[j]) {
            arr1[k] = L1[i];
            arr2[k] = L2[i];
            i++;
        } else {
            arr1[k] = R1[j];
            arr2[k] = R2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr1[k] = L1[i];
        arr2[k] = L2[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr1[k] = R1[j];
        arr2[k] = R2[j];
        j++;
        k++;
    }
}
void merge_sort(int arr1[], int arr2[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(arr1, arr2, p, q);
        merge_sort(arr1, arr2, q + 1, r);
        merge(arr1, arr2, p, q, r);
    }
}
int main() {
    int arr1[max] = {1, 2, 3, 4, 7, 8, 9, 9, 11, 12};
    int arr2[max] = {3, 5, 4, 7, 10, 9, 11, 13, 12, 14};
    merge_sort(arr1, arr2, 0, max - 1);
    int i = 0;
    int count = 1;
    for (int j = 1; j < max; j++) {
        if (arr1[j] >= arr2[i]) {
            count++;
            i = j;
        }
    }
    printf("Number of intervals that do not overlap: %d\n", count);
    return 0;
}
*/

#include <stdio.h>
#define max 10

void merge(int arr1[], int arr2[], int p, int q, int r) {
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    int L1[n1], L2[n1], R1[n2], R2[n2];
    for (i = 0; i < n1; i++) {
        L1[i] = arr1[p + i];
        L2[i] = arr2[p + i];
    }
    for (j = 0; j < n2; j++) {
        R1[j] = arr1[q + 1 + j];
        R2[j] = arr2[q + 1 + j];
    }

    i = j = 0;
    k = p;
    while (i < n1 && j < n2) {
        if (L2[i] <= R2[j]) {
            arr1[k] = L1[i];
            arr2[k] = L2[i];
            i++;
        } else {
            arr1[k] = R1[j];
            arr2[k] = R2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr1[k] = L1[i];
        arr2[k] = L2[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr1[k] = R1[j];
        arr2[k] = R2[j];
        j++;
        k++;
    }
}

void merge_sort(int arr1[], int arr2[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(arr1, arr2, p, q);
        merge_sort(arr1, arr2, q + 1, r);
        merge(arr1, arr2, p, q, r);
    }
}

int main() {
    int arr1[max] = {1, 2, 3, 4, 7, 8, 9, 9, 11, 12};
    int arr2[max] = {3, 5, 4, 7, 10, 9, 11, 13, 12, 14};

    merge_sort(arr1, arr2, 0, max - 1);

    printf("Chosen activities (number, start, and end times):\n");
    int count = 1;
    int i = 0;

    printf("Activity %d: Start = %d, End = %d\n", 1, arr1[0], arr2[0]); // First activity is always chosen
    for (int j = 1; j < max; j++) {
        if (arr1[j] >= arr2[i]) {
            count++;
            printf("Activity %d: Start = %d, End = %d\n", j + 1, arr1[j], arr2[j]);
            i = j;
        }
    }

    return 0;
}
