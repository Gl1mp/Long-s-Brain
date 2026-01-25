#include <stdio.h>
#include <string.h>

int compare_ints(const void* a, const void* b) {
    int va = *(const int*)a;
    int vb = *(const int*)b;
    return (va > vb) - (va < vb);
}

void Swap(void* a, void* b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

void qbubble_sort(void* base, size_t num, size_t size, int (*cmp)(const void*, const void*)) {
    for (size_t i = 0; i < num; i++) {
        for (size_t j = 0; j < num - 1 - i; j++) {
            void* elem1 = (char*)base + j * size;
            void* elem2 = (char*)base + (j + 1) * size;
            if (cmp(elem1, elem2) > 0) { 
                Swap(elem1, elem2, size);
            }
        }
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    size_t num = sizeof(arr) / sizeof(arr[0]);
    qbubble_sort(arr, num, sizeof(arr[0]), compare_ints);
    for (size_t i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}