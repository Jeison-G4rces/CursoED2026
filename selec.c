#include  <stdio.h>

void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menorIndex = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[menorIndex]) {
                menorIndex = j;
            } 
        }
        int temp = arr[i];
        arr[i] = arr[menorIndex];
        arr[menorIndex] = temp;
    }
}

void mostarArreglo(int arr[],int n) {
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

}
int main() {
    int arr[] = {4,2,5,12,5,71,32,1};
    int n = 8;
    SelectionSort(arr,n);
    mostarArreglo(arr,n);
    }
