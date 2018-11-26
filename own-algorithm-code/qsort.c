#include <stdio.h>

void Swap(int *arr, int l, int r) {
    if (l == r) {return;}
    int t = arr[l];
    arr[l] = arr[r];
    arr[r] = t;
}

void InnerSort(int *array, int len) {
    if (len <= 0) {return;}
    if (len < 2) {return;}
    
    int s = 0;  // small index 0
    // piv index 0, select the first one
    int piv = array[0];

    for (int i = 1; i < len; ++i) {
        if (array[i] < piv) {
            Swap(array, i, s + 1);
            ++s;
        }
    }
    
    Swap(array, 0, s);

    if (len == 2) {
        return;
    }


    InnerSort(array, s);
    InnerSort(array + s + 1 , len - s - 1);
    return;
}

void Qsort(int *array, int len) {
    InnerSort(array, len);    
}


int main() {
    int array[8] = {19, 2, 5, 10, 1, -10, 3, 5};
    Qsort(array, 8);

    for (int i = 0; i < 8; ++i) {
        printf("val: %d\n", array[i]);
    }

    return 0;
}
