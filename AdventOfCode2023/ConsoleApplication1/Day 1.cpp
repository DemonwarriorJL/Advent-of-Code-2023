// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::cout << "Hello World!\n";

    std::fstream newfile;

    newfile.open("Text.txt", std::ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) {
        std::cout << "TROLL" << std::endl; //checking whether the file is open
        std::string tp;
        while (getline(newfile, tp)) { //read data from file object and put it into string.

            std::cout << tp << "\n"; //print the data of the string
        }
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
