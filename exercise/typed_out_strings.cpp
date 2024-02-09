//g++ -O3 typed_out_strings.cpp -o typed_out_strings.exe

#include "typed_out_strings.hpp"
#include "iostream"
int main()
{
    //exemplo 1 -- TRUE
    //std::string s1 = "ab#z";
    //std::string s2 = "az#z";

    //exemplo 2 -- FALSE
    //std::string s1 = "abc#d";
    //std::string s2 = "acc#c";

    //exemplo 3 -- TRUE
    //std::string s1 = "x#y#z#";
    //std::string s2 = "a#";

    //exemplo 4 -- TRUE 
    //std::string s1 = "a###b";
    //std::string s2 = "b";

    //exemplo 5 -- FALSE
    //std::string s1 = "Ab#z";
    //std::string s2 = "ab#z";

    //exemplo 6 -- TRUE
    //std::string s1 = "y#fo##f";
    //std::string s2 = "y#f#o##f";

    //exemplo 7 -- TRUE
    //std::string s1 = "rheyggodcclgstf";
    //std::string s2 = "#rheyggodcclgstf";

    //exemplo 8 -- TRUE
    //std::string s1 = "abc#d";
    //std::string s2 = "abzz##d";

    //exemplo 9 - FALSE
    std::string s1 = "bxj##tw";
    std::string s2 = "bxj###tw";

    // exemplo 10 - TRUE
    //std::string s1 = "ab##";
    //std::string s2 = "c#d#";

    //exemplo 11 - TRUE
    //std::string s1 = "y#fo##f";
    //std::string s2 = "y#fx#o##f";



    /*
    std::string firstString = typed_out_strings(s1);
    std::string secondString = typed_out_strings(s2);

    if(firstString.compare(secondString) == 0)
        std::cout << "True" << std::endl;
    else std::cout << "False" << std::endl;
    
    */

    //typed_out_string_optimal_space(s1);
    //typed_out_string_optimal_space(s2);

    /*
    if(s1.compare(s2) == 0)
        std::cout << "True" << std::endl;
    else std::cout << "False" << std::endl;
    */


    bool a = typed_out_string_final(s1, s2);


    std::cout << a << std::endl;

    //second option
    /*
    if(firstString.length() != secondString.length())
    {
        return false;
    }
    else
    {
        for(int i = 0; i < firstString.length(); ++i)
        {
            if(firstString[i] != secondString[i])
               return false;
        }
        return true;
    }
    */
    return 0;
}