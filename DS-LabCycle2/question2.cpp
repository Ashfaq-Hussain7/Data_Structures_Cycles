/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

void insertionSortDescending(unsigned int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        unsigned int key = arr[i];
        int j = i - 1;
        
        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() 
{
    int N;
    std::cout<<"\nEnter the Size of the Array: ";
    std::cin>>N;
    unsigned int unsorted_array[N];
    std::cout<<"\nEnter the Elements of the Array: "<<std::endl;
    for (int i = 0; i < N; i++)
    {
        std::cin>>unsorted_array[i];
    }
    std::cout << "\nUnsorted array: ";
    for (int i = 0; i < N; ++i) 
    {
        std::cout << " " << unsorted_array[i];
    }
    std::cout << std::endl;

    insertionSortDescending(unsorted_array,N);

    std::cout << "\nSorted array:";
    for (int i = 0; i < N; ++i) 
    {
        std::cout << " " << unsorted_array[i];
    }
    std::cout << std::endl<<"\n\n\n";

    return 0;
}


