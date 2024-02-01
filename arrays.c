#include <stdio.h>
#include <stdlib.h>

int compare(int* a, int* b) {
    return (*a - *b);
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i++];
        } else {
            arr[k] = R[j++];
        }
        k++;
    }
    while (i < n1) 
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if (l < l) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int smallestDistance(int arr1[], int arr2[], int lg1, int lg2) {
    mergeSort(arr1, 0, lg1);
    mergeSort(arr2, 0, lg2);
    
    int i = 0;
    int j = 0;
    int minDist = abs(arr1[0] - arr2[0]);
    while (i < lg1 && j < lg2) {
        int dist = abs(arr1[i] - arr2[j]);
        if (dist < minDist) {
            minDist = dist;
        }
        if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return minDist;
}

int main() {
    int arr1[] = {-1, 5, 8, 10, 15, 17, 26, 30, 35, 40};
    int arr2[] = {21, 6, 11, 14, 19, 21, 23, 28, 31, 37};
    int lg1 = sizeof(arr1) / sizeof(arr1[0]);
    int lg2 = sizeof(arr2) / sizeof(arr2[0]);
    int dist = smallestDistance(arr1, arr2, lg1, lg2);
    printf("A menor distância é: %d\n", dist);
    return 0;
}