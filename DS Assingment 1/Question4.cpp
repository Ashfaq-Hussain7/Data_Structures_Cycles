// Recursive Algorithm For Checking A Pallindrome
#include <iostream>
#include <bits/stdc++.h>
int pallindrome(std::string s, int i, int j)
{
    if (j > i)
    {
        return 1;
    }
    if (s[i] == s[j])
    {
        return pallindrome(s, i++, j--);
    }
    else

    {
        return 0;
    }
}

int main()
{
    std::string str;
    std::cout << "\nEnter the String: ";
    std::cin >> str;
    int x = str.length();
    if (pallindrome(str, 0, x - 1))
    {
        std::cout << "\n***The String Is A Pallindrome***"
                  << "\n\n\n\n"
                  << std::endl;
    }
    else
    {
        std::cout << "***The String Is Not A Pallindrome***"
                  << "\n\n\n\n"
                  << std::endl;
    }
    return 0;
}

/* INPUT
    MALAYALAM
   OUTPUT
    Enter the String: MALAYALAM
    ***The String I A Pallindrome***
*/