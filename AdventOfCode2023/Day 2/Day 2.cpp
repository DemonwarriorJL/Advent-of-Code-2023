// Day 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

bool ExtractInfoPT1(std::string input) //Deals with each line
{
    std::string m_info;
    std::string m_str;
    std::string m_line = input;

    while (m_line != "")
    {
        m_str = m_line.substr(0, m_line.find(";")); //Gets current Set Info in Game

        //Modifies m_line for next pass
        if (m_line == m_line.substr(m_line.find(";") + 1)) { m_line = ""; } // if its same
        else { m_line = m_line.substr(m_line.find(";") + 2); } //if not the same

        while (m_str != "") //Splits set into 1 colour and number
        {
            m_info = m_str.substr(0, m_str.find(",")); //Gets current Colour Info in Set

            if ((m_info.substr((m_str.find(" ") + 1)) == "red") && (std::stoi(m_info.substr(0, (m_str.find(" ")))) > 12)) { return false; }
            else if ((m_info.substr((m_str.find(" ") + 1)) == "blue") && (std::stoi(m_info.substr(0, (m_str.find(" ")))) > 14)) { return false; }
            else if ((m_info.substr((m_str.find(" ") + 1)) == "green") && (std::stoi(m_info.substr(0, (m_str.find(" ")))) > 13)) { return false; }

            if (m_str == m_str.substr(m_str.find(",") + 1)) { m_str = ""; } // if its same
            else { m_str = m_str.substr(m_str.find(",") + 2); } //if not the same
        }
    }
    return true;
}

int ExtractInfoPT2(std::string input) //Deals with each line
{
    std::string m_info;
    std::string m_str;
    std::string m_line = input;
    int red = 0;
    int green = 0;
    int blue = 0;

    while (m_line != "")
    {
        m_str = m_line.substr(0, m_line.find(";")); //Gets current Set Info in Game

        //Modifies m_line for next pass
        if (m_line == m_line.substr(m_line.find(";") + 1)) { m_line = ""; } // if its same
        else { m_line = m_line.substr(m_line.find(";") + 2); } //if not the same

        while (m_str != "") //Splits set into 1 colour and number
        {
            m_info = m_str.substr(0, m_str.find(",")); //Gets current Colour Info in Set

            //meets red conditions
            if ((m_info.substr((m_str.find(" ") + 1)) == "red") && (std::stoi(m_info.substr(0, (m_str.find(" ")))) > red)) { red = std::stoi(m_info.substr(0, (m_str.find(" ")))); }
            //meets blue conditions
            else if ((m_info.substr((m_str.find(" ") + 1)) == "blue") && (std::stoi(m_info.substr(0, (m_str.find(" ")))) > blue)) { blue = std::stoi(m_info.substr(0, (m_str.find(" ")))); }
            //meets green conditions
            else if ((m_info.substr((m_str.find(" ") + 1)) == "green") && (std::stoi(m_info.substr(0, (m_str.find(" ")))) > green)) { green = std::stoi(m_info.substr(0, (m_str.find(" ")))); }
            /*std::cout << xdd << " " << lol << std::endl;*/

            if (m_str == m_str.substr(m_str.find(",") + 1)) { m_str = ""; } // if its same
            else { m_str = m_str.substr(m_str.find(",") + 2); } //if not the same
        }
    }
    int totalLine = red * blue * green;
    return totalLine;
}

int main()
{
    std::fstream newfile;
    std::string line;
    int total = 0;

    newfile.open("Text2.txt", std::ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) {

        int lineIndex = 0;
        
        while (getline(newfile, line)) //read data from file object and put it into string.
        {
            lineIndex++; //Track what game
            std::cout << lineIndex << std::endl;

            std::string str = line.substr(line.find(":") + 2); //Creates substring only of game info

            bool doIAdd = false;
            doIAdd = ExtractInfoPT1(str);
            std::cout << doIAdd << std::endl;
            std::cout << std::endl;
            if (doIAdd) { total += lineIndex; }

            total += ExtractInfoPT2(str);
        }
    }
    std::cout << total << std::endl;
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
