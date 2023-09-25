#include<iostream>
#include<ctime>
#include<unistd.h>
#include<cstdlib>
#include<sys/time.h>
#include<vector>
#include<list>

#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; ++i) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

void MergeSort_list(std::vector<int>& arr) {
    int n = arr.size();

    for (int currSize = 1; currSize <= n - 1; currSize *= 2)
    {
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize) {
            int mid = std::min(leftStart + currSize - 1, n - 1);
            int rightEnd = std::min(leftStart + 2 * currSize - 1, n - 1);
            merge(arr, leftStart, mid, rightEnd);
        }
    }
}

int main() {
    std::vector<int> arr;
    srand((unsigned) time(NULL));
    for (size_t i = 0; i < 15; i++)
    {
        int random = rand();
        arr.push_back(random);
    }
    mergeSort(arr);

    std::cout << "Sorted array: ";
 std::vector<int>::iterator it;
    for (it = arr.begin(); it != arr.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}
