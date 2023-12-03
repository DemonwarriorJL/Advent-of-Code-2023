// Day 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

std::fstream& GotoLine(std::fstream& file, unsigned int num)
{
    file.seekg(std::ios::beg);
    for (int i = 0; i < num - 1; ++i)
    {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
}

int main()
{
    std::fstream newfile;
    
    newfile.open("Text3.txt", std::ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) {

        std::string lineAbove = "";
        std::string line = "";
        std::string lineBelow = "";
        
        int numberOfLines = 0;

        //Gets number of lines
        while (getline(newfile, line))
        {
            ++numberOfLines;
        }

        for (int j = 2; j < numberOfLines; j++) //Loops through lines starting at 3rd row
        {
            GotoLine(newfile, j);
            newfile >> lineBelow;

            GotoLine(newfile, j-1);
            newfile >> line;

            GotoLine(newfile, j-2);
            newfile >> lineAbove;

            std::cout << lineAbove << std::endl;
            std::cout << line << std::endl;
            std::cout << lineBelow << std::endl;
            std::cout << "\n" << std::endl;
        }

        std::cout << "Hello World!\n";
        //while (getline(newfile, line)) //read data from file object and put it into string.
        //{
        //    if (lineBelow == "" || lineBelow == line) 
        //    {

        //    }

        //    for (int i = 0; i < line.size(); i++) //Move through each line char by char (i is index of current char)
        //    {
        //        if (!isdigit(line[i]) || line[i] == '.') //if char is a symbol
        //        {

        //        }
        //    }
        //}
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
