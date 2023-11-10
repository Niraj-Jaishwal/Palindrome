#include "PalindromeR.hpp"
#include <iostream>

int PalindromeR::test_string(const std::string& s)
{
    //Base case: String of length 1 or less are palindrome
    if(s.length() <= 1)
    {
        return -1; //Palindrome
    }

    //Find the indices of the first and last alphanumeric characters
    size_t firstIndex = 0;
    while (firstIndex < s.length() && !std::isalnum(s[firstIndex]))
    {
        ++firstIndex;
    }

    size_t lastIndex = s.length() - 1;
    while(lastIndex > 0 && !std::isalnum(s[lastIndex]))
    {
        --lastIndex;
    }

    //check if the first and last charecters match
    if (std::tolower(s[firstIndex]) == std::tolower(s[lastIndex]))
    {
        //change the positon from first and last characters and test the remaining
        return test_string(s.substr(firstIndex + 1, lastIndex - firstIndex - 1));
    }
    else
    {
        return 1; //Not a palindrome
    }
}

