#include <iostream>
#include <set>

/*

    This file generates all permutations of an input string

*/
std::set<std::string> generatePermutations(std::string str);

int main() {

    std::string str = "AB";

    for (std::string s : generatePermutations(str) ) {

        std::cout << s<< "\n";

    }

    return 0;

}


/*

    Function: generatePermutations
    Usage:  Set<string> permutations  =  generatePermutations (str)
    ________________________________________________________________
    Returns a set consisting of all permutations of the specified string
    This impolementation uses the recursive insight that you can generate 
    all permutations of a string by selecting each character in turn, 
    generating all permutations of the string without that character, 
    and the concatenating the selected character on the front of each string generated

*/



std::set<std::string>  generatePermutations(std::string str) {

    std::set<std::string> result;

    if(str == "") {

        result.insert("");

    } else {

            for (int i = 0; i < str.length();  i++){
                
                char ch = str[i];
                std::string rest = str.substr(0, i) + str.substr(i+1);
                
                for (std::string s : generatePermutations(rest) ) {
                    result.insert(ch +s) ;
                }

            }

    }

    return result;

} //End std::set<std::string> generatePermutations


