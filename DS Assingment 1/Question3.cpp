#include <iostream>

//RECURRENCE FUNCTION FOR REVRSING STRING
void reverse(int i, std::string str){
    if (str[i] == '\0') std::cout << ("");
    else{
        reverse(i+1, str);
        std::cout << str[i];
    }
}

int main(){
    std::string s;

    std::cout << "\nEnter a string: ";
    std::getline(std::cin, s);
    std::cout<<"The Reversed String is: ";
    reverse(0, s);
    std::cout<<"\n\n\n";
    return 0;
}
//INPUT: HELLO WORLD
//OUTPUT: DLROW OLLEH