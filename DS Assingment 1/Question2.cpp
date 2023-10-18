//Recursive Algorithm For Finding Sum Of Digits
#include<iostream>
int dgt_sum(int n)
{
    if(n/10==0)
    {
        return n%10;
    }
    else
    {
        return n%10 + dgt_sum(n/10);
    }
}
int main()
{
    int x;
    std::cout<<"Enter the required number: ";
    std::cin>>x;
    std::cout<<"The Sum of Digits of the number "<<x<<" : "<<dgt_sum(x)<<"\n\n\n\n\n";
    return(0);
}

/* INPUT
    567
   OUTPUT
    Enter the required number: 567
    The Sum of Digits of the number 567 : 18
*/