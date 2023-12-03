// Day 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include <map>
#include <iterator>

std::map<std::vector<int>, int> FindNumbersAroundPosition(std::vector<std::string> lines, int positionToSearch)
{
    //std::vector<int> numbers;
    std::map<std::vector<int>, int> returnValues;

    if (isdigit(lines[0][positionToSearch - 1]))
    {
        std::vector<int> coord;
        coord.push_back(0);
        coord.push_back(positionToSearch - 1);

        //numbers.push_back(lines[0][positionToSearch - 1] - 48);
        //returnValues.insert(std::make_pair((std::vector<int>(0, positionToSearch - 1)), lines[0][positionToSearch - 1] - 48));
        returnValues.insert(std::make_pair(coord, lines[0][positionToSearch - 1] - 48));
    }

    if (isdigit(lines[0][positionToSearch]))
    {
        std::vector<int> coord;
        coord.push_back(0);
        coord.push_back(positionToSearch);

        //numbers.push_back(lines[0][positionToSearch] - 48);
        returnValues.insert(std::make_pair(coord, lines[0][positionToSearch] - 48));
    }

    if (isdigit(lines[0][positionToSearch + 1]))
    {
        std::vector<int> coord;
        coord.push_back(0);
        coord.push_back(positionToSearch + 1);

        //numbers.push_back(lines[0][positionToSearch + 1] - 48);
        returnValues.insert(std::make_pair(coord, lines[0][positionToSearch + 1] - 48));
    }

    if (isdigit(lines[1][positionToSearch - 1]))
    {
        std::vector<int> coord;
        coord.push_back(1);
        coord.push_back(positionToSearch - 1);

        //numbers.push_back(lines[1][positionToSearch - 1] - 48);
        returnValues.insert(std::make_pair(coord, lines[1][positionToSearch - 1] - 48));
    }

    if (isdigit(lines[1][positionToSearch + 1]))
    {
        std::vector<int> coord;
        coord.push_back(1);
        coord.push_back(positionToSearch + 1);

        //numbers.push_back(lines[1][positionToSearch + 1] - 48);
        returnValues.insert(std::make_pair(coord, lines[1][positionToSearch + 1] - 48));
    }

    if (isdigit(lines[2][positionToSearch - 1]))
    {
        std::vector<int> coord;
        coord.push_back(2);
        coord.push_back(positionToSearch - 1);

        //numbers.push_back(lines[2][positionToSearch - 1] - 48);
        returnValues.insert(std::make_pair(coord, lines[2][positionToSearch - 1] - 48));
    }

    if (isdigit(lines[2][positionToSearch]))
    {
        std::vector<int> coord;
        coord.push_back(2);
        coord.push_back(positionToSearch);

        //numbers.push_back(lines[2][positionToSearch] - 48);
        returnValues.insert(std::make_pair(coord, lines[2][positionToSearch] - 48));
    }

    if (isdigit(lines[2][positionToSearch + 1]))
    {
        std::vector<int> coord;
        coord.push_back(2);
        coord.push_back(positionToSearch + 1);

        //numbers.push_back(lines[2][positionToSearch + 1] - 48);
        returnValues.insert(std::make_pair(coord, lines[2][positionToSearch + 1] - 48));
    }

    return returnValues;
}

int ReconstructNumbers(std::vector<std::string> lines, int coordY, int coordX, int number)
{
    std::string s_numberValue = "";
    char m_currentValue = lines[coordY][coordX];
    int movement = 0;

    //Go Right
    while (isdigit(m_currentValue))
    {
        movement++;
        s_numberValue = s_numberValue + m_currentValue;

        try
        {
            m_currentValue = lines.at(coordY).at(coordX + movement);
        }
        catch (...)
        {
            m_currentValue = '.';
        }
    }

    m_currentValue = lines[coordY][coordX-1];
    movement = 1;

    //Go left
    while (isdigit(m_currentValue)) 
    {
        movement++;
        s_numberValue = m_currentValue + s_numberValue; 

        try
        {
            m_currentValue = lines.at(coordY).at(coordX - movement);
        }
        catch (...)
        {
            m_currentValue = '.';
        }
    }
    //std::cout << s_numberValue << std::endl;

    return stoi(s_numberValue);
}

//void CheckNumbers(std::map<std::vector<int>, int> coords, int number)
//{
//    std::map<std::vector<int>, int>::iterator itr;
//
//    for (int i = 0; i < )
//}

int main()
{
    std::fstream newfile;
    
    newfile.open("Text3.txt", std::ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) {

        std::string lineAbove = "";
        std::string line = "";
        std::string lineBelow = "";
        std::string readLine = "";
        std::vector<int> rebuiltValues;
        int total1 = 0;
        int total2 = 0;

        while (getline(newfile, readLine)) //read data from file object and put it into string.
        {
            lineAbove = line;
            line = lineBelow;
            lineBelow = readLine;
            
            if (lineAbove != "") 
            {
                std::cout << lineAbove << std::endl;
                std::cout << line << std::endl;
                std::cout << lineBelow << std::endl;
                std::cout << "\n";

                for (int i = 0; i < line.size(); i++) //Move through each line char by char (i is index of current char)
                {
                    //if (!isdigit(line[i]) && line[i] != '.') //if char is a symbol
                    //{
                    //    //std::cout << line[i] << std::endl;
                    //    std::map<std::vector<int>, int> numbers;
                    //    std::vector<std::string> lines{ lineAbove, line, lineBelow };
                    //    numbers = FindNumbersAroundPosition(lines, i);
                    //    std::map<std::vector<int>, int>::iterator itr;

                    //    int lastcoordY = 9999;
                    //    int lastcoordX = 9999;

                    //    for (itr = numbers.begin(); itr != numbers.end(); ++itr)
                    //    {
                    //        if (!(lastcoordY == itr->first[0] && lastcoordX == itr->first[1] - 1))
                    //        {
                    //            rebuiltValues.push_back(ReconstructNumbers(lines, itr->first[0], itr->first[1], itr->second));
                    //        }
                    //        std::cout << ReconstructNumbers(lines, itr->first[0], itr->first[1], itr->second) << std::endl;

                    //        lastcoordY = itr->first[0];
                    //        lastcoordX = itr->first[1];
                    //    }
                    //}

                    if (line[i] == '*') 
                    {
                        std::map<std::vector<int>, int> numbers;
                        std::vector<std::string> lines{ lineAbove, line, lineBelow };
                        numbers = FindNumbersAroundPosition(lines, i);
                        std::map<std::vector<int>, int>::iterator itr;
                        std::vector<int> numbersPerChar;

                        int lastcoordY = 9999;
                        int lastcoordX = 9999;

                        for (itr = numbers.begin(); itr != numbers.end(); ++itr)
                        {
                            if (!(lastcoordY == itr->first[0] && lastcoordX == itr->first[1] - 1))
                            {
                                numbersPerChar.push_back(ReconstructNumbers(lines, itr->first[0], itr->first[1], itr->second));
                            }
                            std::cout << ReconstructNumbers(lines, itr->first[0], itr->first[1], itr->second) << std::endl;

                            lastcoordY = itr->first[0];
                            lastcoordX = itr->first[1];
                        }

                        if (numbersPerChar.size() == 2)
                        {
                            for (int number : numbersPerChar) 
                            {
                                rebuiltValues.push_back(number);
                            }
                        }
                    }
                }
            }            
        }
        std::cout << std::endl;

        for (int thing : rebuiltValues)
        {
            //std::cout << thing << std::endl;
            total1 += thing;
        }
        std::cout << total1 << std::endl;

        for (int i = 0; i < rebuiltValues.size(); i += 2)
        {
            total2 += rebuiltValues[i] * rebuiltValues[i + 1];
        }

        
        std::cout << total2 << std::endl;
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
