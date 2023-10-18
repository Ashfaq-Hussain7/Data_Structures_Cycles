//Recursive Algorithm For Finding Factorial//
#include<iostream>
int factorial(int a)
{
    if(a>1)
    {
        return a*factorial(a-1);
    }
    else
    {
        return 1;
    }
}
int main()
{
    int n;
    std::cout<<"Enter the number to find the factorial: ";
    std::cin>>n;
    std::cout<<"The factorial of the number "<<n<<" : "<<factorial(n)<<"\n\n\n\n"<<std::endl;
    return(0);
}

/* INPUT
    6
   OUTPUT 
    Enter the number to find the factorial: 6
    The factorial of the number 6 : 720
*/