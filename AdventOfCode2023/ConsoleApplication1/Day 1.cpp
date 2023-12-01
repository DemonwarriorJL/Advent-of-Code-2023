// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::cout << "Hello World!\n";

    std::fstream newfile;

    newfile.open("Text.txt", std::ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) {


        std::string line;
        std::vector<std::string> numbers{ "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
        std::vector<int> calibration_values;
        

        while (getline(newfile, line)) //read data from file object and put it into string.
        {
            std::vector<int> token;
            for (int charWeLookingAtIndex = 0; charWeLookingAtIndex < line.size(); charWeLookingAtIndex++) //Loop through each char
            {
                const char c = line[charWeLookingAtIndex]; //get the char we looking at
                if (c >= '0' && c <= '9') { //is between 0 and 9 (chars are glorified ints)
                    token.push_back(c - 48); //-48 cause char cringe (all letters for ascii code)
                }
                for (int j = 0; j < numbers.size(); j++) { //Loop through each spelt out number
                    const std::string& n = numbers[j]; // get the spelt out number we looking at
                    if (line.size() >= charWeLookingAtIndex + n.size()) { //if spelt out number can fit into position along line we are at
                        if (line.substr(charWeLookingAtIndex, n.size()) == n) { //if spelt out number is in the substring of the line to the char index we are looking at
                            token.push_back(j + 1);
                        }
                    }
                }
            }

            calibration_values.push_back(token.front() * 10 + token.back()); //*10 cause first digit is 10s
            //std::cout << (token[0] * 10 + token.back()) << std::endl;
        }

        int total = 0;
        for (int value : calibration_values) 
        {
            total += value;
        }
        std::cout << total << std::endl;

        newfile.close(); //close the file object.
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
