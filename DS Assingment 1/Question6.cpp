#include <iostream>
void get_array(int *array, int a);
void print_array(int *array, int b);
void search_array(int *array, int n, int element);
void get_maximum(int *array, int x);
void get_minimum(int *array, int y);


int main()
{
    int *array;
    int num;
    int choice;
    std::cout << "\n-----MENU-----" << std::endl;
    std::cout << "1. Enter the Size and Elements of Array" << std::endl;
    std::cout << "2. Print the Elements of Array" << std::endl;
    std::cout << "3. Search an Element in the Array" << std::endl;
    std::cout << "4. Print Largest and Smallest Element of Array" << std::endl;
    std::cout << "5. Exit" << std::endl;
    do
    {
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Enter the Size of the Array less than 100: ";
            std::cin >> num;
            array = new int[num];
            get_array(array, num);
            break;
        
        case 2:
            std::cout<< "The Elements of Array are: " << std::endl;
            print_array(array, num);
            break;
        case 3:
            int elmnt;
            std::cout << "Enter element to search :";
            std::cin >> elmnt;
            search_array(array, num, elmnt);
            break; 
        case 4:
            get_maximum(array, num);
            get_minimum(array, num);
            break;
        case 5:
            std::cout << "THANK YOU " << std::endl;
            break;
        default:
            std::cout << "ERROR!!!" << std::endl;
            break;
        }
        std::cout<< "-------------------------" << std::endl;
    }while(choice != 5);
    return 0;
}

void get_array(int *array, int a)
{
    std::cout << "Enter the Elements of the Array " << std::endl;
    for(int i = 0; i < a; i++)
    {
        std::cin >> array[i];
    }
    std::cout << "Array of size " << a << " is created" << std::endl;
}

void print_array(int *array, int b)
{
    for (int i = 0; i < b; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void search_array(int *array, int n, int element)
{
    bool found = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] == element)
        {
            found = 1;
            std::cout << "FOUND" << std::endl;
            break;
        }
    }
    if (found == 0) std::cout << "NOT FOUND!!!" << std::endl;
}

void get_maximum(int *array, int x)
{
    int max = array[0];
    for (int i = 1; i < x; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    std::cout << max << " is the largest element" << std::endl;
}

void get_minimum(int *array, int y)
{
    int min = array[0];
    for (int i = 1; i < y; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    std::cout << min << " is the smallest element" << std::endl;
}

/*-----MENU-----
1. Enter size and elements of array
2. Print elements of array
3. Search an element in array
4. Print largest and smallest element of array
5. Exit
Enter your choice: 1
Enter size of array less than 100: 6
Enter elements of array
1
2
3
4
5
6
Array of size 6 is created
--------------------------
Enter your choice: 2
The Elements of the Array are: 
1 2 3 4 5 6 
-------------------------
Enter your choice: 3
Enter the Element to Search : 3
FOUND
-------------------------
Enter choice: 4
6 is the largest element
1 is the smallest element
-------------------------
Enter choice: 5
THANK YOU 
-------------------------*/