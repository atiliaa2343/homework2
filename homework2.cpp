#include <string> 
#include <iostream>  
#include <sstream>
#include <cassert>
using namespace std;  

/// @brief This function finds the most frequent characters in a string
/// @param input A reference to an input stream 
/// @param output A reference to an ouput stream
/// @return A string representing the characters that occur the most in the string
string character(istream& input = cin, ostream& output= cout) 
{ 
    
    string character; 
    int count = 0; 
    int max = 0;
    string maxCharacter; 

    //asks user for string 
    output << "Enter a string: "; 
    input >> character;  

    //traverse through the string and count occurrences 
    for (char q = ' '; q<='~'; q++) { 
        count = 0; 
        for(int i =0; i<character.length(); i++) { 
            if(character[i] == q) 
            count++;
        } 

        //If this character occurs as frequently as the current max, add it
        if(count == max){ 
            maxCharacter +=q;
        } 

        //If this character occurs more frequently, update the max count
        if(count>max){ 
            max = count; 
            maxCharacter = q;
        }
    }
        
       return maxCharacter;
  
} 

//Test functions 
void Tests() { 
    //test case 1 

    { 
        istringstream input("banana") ;
        ostringstream output; 
        assert(character(input, output) == "a"); 
        assert(output.str() == "Enter a string: ");
    } 

    //test case 2 
    { 
        istringstream input("aabbcc"); 
        ostringstream output; 
        assert(character(input,output) == "abc"); 
        assert(output.str() == "Enter a string: ");
    } 

    //test case 3 
    { 
        istringstream input(""); 
        ostringstream output; 
        assert(character(input, output) == ""); 
        assert(output.str() == "Enter a string: ");

    }
}

