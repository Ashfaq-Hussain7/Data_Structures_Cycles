#include <iostream>
#include <string>
#include <vector>

void selectionSort(std::vector<std::string>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

int main() 
{
    int n;
    std::cout<<"\nEnter the number of strings: ";
    std::cin >> n;

    std::vector<std::string> strings(n);
    std::cout<<"\nEnter the strings:" <<std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> strings[i];
    }

    selectionSort(strings);

    std::cout<<"\nThe Sorted Array of Strings: ";
    for (const std::string& str : strings) 
    {
        std::cout << str << " ";
    }
    std::cout<<"\n\n\n";
    return 0;
}
