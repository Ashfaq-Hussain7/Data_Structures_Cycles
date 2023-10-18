//Recursive Algorithm For Converting Decimal Number Into Binary Expression 
#include<iostream>
int binary_num(int n)
{
    if(n==0)
    {
    return 0;
    }
    else
    {
        return ( (binary_num(n/2))*10 ) + n%2;
    }
}
int main()
{
    int num;
    std::cout<<"Enter the number that needed to be converted: ";
    std::cin>>num;
    std::cout<<"The Binary Number is: "<<binary_num(num)<<"\n\n\n\n\n";
    return(0);
}