//
#include <iostream>
#include <set>

void get_arr(char *array, int num){
    int count = 0;
    std::cout << "\n\nEnter the Character Elements of Array: " << std::endl;
    for(int i = 0; i < num; i++)
    {
        std::cin >> array[i];
    }
}

void duplicate_count(char *array, int n){
    int count = 0;
    std::set <char> frequency;
    for (int i = 0; i < n; i++){
        if (frequency.count(array[i])) count++;
        else frequency.insert(array[i]);
    }
    std::cout<<"\n\n*** "<< count << " duplicates has been found in array ***" <<"\n\n\n"<< std::endl;
}
    
int main()
{
    char *array;
    int number;
    std::cout << "\n\nEnter the Size of the Array less than or equal to 100: ";
    std::cin >> number;
    array = new char[number];
    get_arr(array, number);
    duplicate_count(array, number);
    return (0);
}
/*Enter the Size of the Array less than or equal to 100:  9
Enter the Character Elements of Array:
c
r
i
s
t
i
a
n
o
*** 1 duplicates has been found in array ***
*/
