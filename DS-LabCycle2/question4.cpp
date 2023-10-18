#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);

    for (int i = 0; i < n1; ++i) 
    {
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) 
    {
        rightArray[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) 
    {
        if (leftArray[i] <= rightArray[j]) 
        {
            arr[k] = leftArray[i];
            ++i;
        } else {
            arr[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) 
    {
        arr[k] = leftArray[i];
        ++i;
        ++k;
    }

    while (j < n2) 
    {
        arr[k] = rightArray[j];
        ++j;
        ++k;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() 
{
    int n;
    std::cout << "\nEnter the Size of the Array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "\nEnter the elements: "<<std::endl;
    for (int i = 0; i < n; ++i) 
    {
        std::cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    std::cout << "The Sorted Array is : ";
    for (int i = 0; i < n; ++i) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout<<"\n\n\n\n";
    return 0;
}
