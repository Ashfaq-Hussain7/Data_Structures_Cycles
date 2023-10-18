//Second Largest Element Of An Array
#include<iostream>
void get_array(int *array,int num)
{
    std::cout<<"Enter the Elements of the Array: "<<std::endl;
    for(int i=0; i<num; i++)
    {
        std::cin>>array[i];
    }
}
void sl_array(int *array,int n)
{
    int largest= array[0];
    int s_largest;
    for(int i=1; i<n; i++)
    {
        if(array[i]>largest)
        {
            s_largest=largest;
            largest=array[i];
        }
        else if(array[i]>s_largest)
        {
            s_largest=array[i];
        }
    }
    std::cout<<"The Second Largest Element is: "<<s_largest<<"\n\n\n"<<std::endl;
}
int main()
{
    int *array;
    int number;
    std::cout<<"Enter the Size of the Array less than or equal to 75: ";
    std::cin>>number;
    array=new int[number];
    get_array(array,number);
    sl_array(array,number);
    return(0);
}

/* OUTPUT
    Enter the Size Of the Array less than or equal to 75: 10
    Enter the Elements of the Array: 
    25
    50
    75
    100
    125
    150
    175
    200
    225
    250
    The Second Largest Element is: 225
*/