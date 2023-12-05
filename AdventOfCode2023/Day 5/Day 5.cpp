// Day 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cinttypes>

uint64_t ProcessMap(std::vector<std::vector<uint64_t>> map, uint64_t input)
{
    uint64_t output = 0;
    for (std::vector<uint64_t> line : map)
    {
        if (input >= line[1] && input <= (line[1] + line[2]) - 1)
        {
            std::cout << input << " is greater than " << line[1] << " and " << input << " less than " << (line[1] + line[2]) << std::endl;
            output = input + ((line[0] - line[1]));
            return output;
        }
    }
    return input;
}

int main()
{
    std::cout << "Hello World!\n";

    std::fstream newfile;
    std::string line;

    std::vector<uint64_t> seeds;
    std::vector<std::vector<uint64_t>> seedToSoil;
    std::vector<std::vector<uint64_t>> soilToFert;
    std::vector<std::vector<uint64_t>> fertToWater;
    std::vector<std::vector<uint64_t>> watertoLight;
    std::vector<std::vector<uint64_t>> lightToTemp;
    std::vector<std::vector<uint64_t>> tempToHumid;
    std::vector<std::vector<uint64_t>> humidToLoca;

    bool foundSeeds = false;
    bool lookingMap1 = false;
    bool lookingMap2 = false;
    bool lookingMap3 = false;
    bool lookingMap4 = false;
    bool lookingMap5 = false;
    bool lookingMap6 = false;
    bool lookingMap7 = false;

    std::vector<std::string> file;

    newfile.open("Text5.txt", std::ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) {
        while (getline(newfile, line)) //read data from file object and put it into string.
        {
            file.push_back(line);
        }
        newfile.close();
    }

    for (int lineNumber = 0; lineNumber < file.size(); lineNumber++) 
    {
        std::cout << lineNumber << std::endl;
        //std::cout << file[lineNumber] << std::endl;

        //if (file[lineNumber].find("seeds:") != std::string::npos)
        //{
        //    std::string m_info = file[lineNumber].substr(file[lineNumber].find("seeds:") + 7);
        //    while(m_info != "")
        //    {
        //        uint64_t number = _atoi64(m_info.substr(0, m_info.find(" ")).c_str());
        //        seeds.push_back(number);
        //        //std::cout << number << std::endl;
        //        if (m_info == m_info.substr(m_info.find(" ") + 1)) { m_info = ""; }
        //        else { m_info = m_info.substr(m_info.find(" ") + 1); }
        //    }
        //}

        if (file[lineNumber].find("seeds:") != std::string::npos)
        {
            std::string m_info = file[lineNumber].substr(file[lineNumber].find("seeds:") + 7);
            while(m_info != "")
            {
                uint64_t number1 = _atoi64(m_info.substr(0, m_info.find(" ")).c_str());
                //std::cout << number << std::endl;
                seeds.push_back(number1);
                m_info == m_info.substr(m_info.find(" ") + 1);
                uint64_t number2 = _atoi64(m_info.substr(0, m_info.find(" ")).c_str());

                for (int i = 0; i < number2; i++) 
                {
                    number1++;
                    seeds.push_back(number1);
                }

                if (m_info == m_info.substr(m_info.find(" ") + 1)) { m_info = ""; }
                else { m_info = m_info.substr(m_info.find(" ") + 1); }
            }
        }

        if (file[lineNumber].find("seed-to-soil map:") != std::string::npos) { lookingMap1 = true; }
        if (file[lineNumber].find("soil-to-fertilizer map:") != std::string::npos) { lookingMap1 = false; lookingMap2 = true; }
        if (file[lineNumber].find("fertilizer-to-water map:") != std::string::npos) { lookingMap2 = false; lookingMap3 = true; }
        if (file[lineNumber].find("water-to-light map:") != std::string::npos) { lookingMap3 = false; lookingMap4 = true; }
        if (file[lineNumber].find("light-to-temperature map:") != std::string::npos) { lookingMap4 = false; lookingMap5 = true; }
        if (file[lineNumber].find("temperature-to-humidity map:") != std::string::npos) { lookingMap5 = false; lookingMap6 = true; }
        if (file[lineNumber].find("humidity-to-location map:") != std::string::npos) { lookingMap6 = false; lookingMap7 = true; }

        if (lookingMap1)
        {
            //std::cout << "STUFF" << std::endl;
            //std::cout << isdigit(file[lineNumber][0]) << std::endl;
            if(isdigit(file[lineNumber][0]))
            {
                uint64_t num;
                std::vector<uint64_t> lineInput;
                std::string m_info = file[lineNumber];

                while (m_info != "")
                {
                    //std::cout << m_info.substr(0, m_info.find(" ")) << std::endl;
                    num = _atoi64(m_info.substr(0, m_info.find(" ")).c_str());
                    //std::cout << num << std::endl;
                    lineInput.push_back(num);
                    if(m_info == m_info.substr(m_info.find(" ") + 1)) { m_info = ""; }
                    else { m_info = m_info.substr(m_info.find(" ") + 1); }
                }
                seedToSoil.push_back(lineInput);
            }
        }
        else if (!lookingMap1 && lookingMap2)
        {
            if (isdigit(file[lineNumber][0]))
            {
                uint64_t num;
                std::vector<uint64_t> lineInput;
                std::string m_info = file[lineNumber];

                while (m_info != "")
                {
                    //num = stoi(m_info.substr(0, m_info.find(" ")));
                    num = _atoi64(m_info.substr(0, m_info.find(" ")).c_str());
                    //std::cout << num << std::endl;
                    lineInput.push_back(num);
                    if (m_info == m_info.substr(m_info.find(" ") + 1)) { m_info = ""; }
                    else { m_info = m_info.substr(m_info.find(" ") + 1); }
                }
                soilToFert.push_back(lineInput);
            }
        }
        else if (!lookingMap2 && lookingMap3)
        {
            if (isdigit(file[lineNumber][0]))
            {
                uint64_t num;
                std::vector<uint64_t> lineInput;
                std::string m_info = file[lineNumber];

                while (m_info != "")
                {
                    //num = stoi(m_info.substr(0, m_info.find(" ")));
                    num = _atoi64(m_info.substr(0, m_info.find(" ")).c_str());
                    //std::cout << num << std::endl;
                    lineInput.push_back(num);
                    if (m_info == m_info.substr(m_info.find(" ") + 1)) { m_info = ""; }
                    else { m_info = m_info.substr(m_info.find(" ") + 1); }
                }
                fertToWater.push_back(lineInput);
            }
        }
        else if (!lookingMap3 && lookingMap4)
        {
            if (isdigit(file[lineNumber][0]))
            {
                uint64_t num;
                std::vector<uint64_t> lineInput;
                std::string m_info = file[lineNumber];

                while (m_info != "")
                {
                    //num = stoi(m_info.substr(0, m_info.find(" ")));
                    num = _atoi64(m_info.substr(0, m_info.find(" ")).c_str());
                    //std::cout << num << std::endl;
                    lineInput.push_back(num);
                    
                    if (m_info == m_info.substr(m_info.find(" ") + 1)) { m_info = ""; }
                    else { m_info = m_info.substr(m_info.find(" ") + 1); }
                }
                watertoLight.push_back(lineInput);
            }
        }
        else if (!lookingMap4 && lookingMap5)
        {
            if (isdigit(file[lineNumber][0]))
            {
                uint64_t num;
                std::vector<uint64_t> lineInput;
                std::string m_info = file[lineNumber];

                while (m_info != "")
                {
                    //num = stoi(m_info.substr(0, m_info.find(" ")));
                    num = _atoi64(m_info.substr(0, m_info.find(" ")).c_str());
                    //std::cout << num << std::endl;
                    lineInput.push_back(num);
                    if (m_info == m_info.substr(m_info.find(" ") + 1)) { m_info = ""; }
                    else { m_info = m_info.substr(m_info.find(" ") + 1); }
                }
                lightToTemp.push_back(lineInput);
            }
        }
        else if (!lookingMap5 && lookingMap6)
        {
            if (isdigit(file[lineNumber][0]))
            {
                uint64_t num;
                std::vector<uint64_t> lineInput;
                std::string m_info = file[lineNumber];

                while (m_info != "")
                {
                    //num = stoi(m_info.substr(0, m_info.find(" ")));
                    num = _atoi64(m_info.substr(0, m_info.find(" ")).c_str());
                    //std::cout << num << std::endl;
                    lineInput.push_back(num);
                    
                    if (m_info == m_info.substr(m_info.find(" ") + 1)) { m_info = ""; }
                    else { m_info = m_info.substr(m_info.find(" ") + 1); }
                }
                tempToHumid.push_back(lineInput);
            }
        }
        else if (!lookingMap6 && lookingMap7)
        {
            if (isdigit(file[lineNumber][0]))
            {
                uint64_t num;
                std::vector<uint64_t> lineInput;
                std::string m_info = file[lineNumber];

                while (m_info != "")
                {
                    //num = stoi(m_info.substr(0, m_info.find(" ")));
                    num = _atoi64(m_info.substr(0, m_info.find(" ")).c_str());
                    //std::cout << num << std::endl;
                    lineInput.push_back(num);
                    if (m_info == m_info.substr(m_info.find(" ") + 1)) { m_info = ""; }
                    else { m_info = m_info.substr(m_info.find(" ") + 1); }
                }
                humidToLoca.push_back(lineInput);
            }
        }
    }
    ////prints all seeds
    /*std::cout << "seeds" << std::endl;
    for (int seed : seeds)
    {
        std::cout << seed << std::endl;
    }*/

    ////print all map1
    //std::cout << "map 1" << std::endl;
    //std::cout << seedToSoil.size() << std::endl;
    //for (std::vector<int> line : seedToSoil)
    //{
    //    std::cout << line[0] << "\t" << line[1] << "\t" << line[2] << "\t" << std::endl;
    //}
    std::vector<uint64_t> end;
    uint64_t smallest = 9999999999999999999;

    for (int64_t seed : seeds)
    {
        std::cout << "SEED" << std::endl;
        //std::cout << seed << std::endl;
        int64_t input = seed;
        std::cout << input << std::endl;

        input = ProcessMap(seedToSoil, input);
        std::cout << input << std::endl;
        input = ProcessMap(soilToFert, input);
        std::cout << input << std::endl;
        input = ProcessMap(fertToWater, input);
        std::cout << input << std::endl;
        input = ProcessMap(watertoLight, input);
        std::cout << input << std::endl;
        input = ProcessMap(lightToTemp, input);
        std::cout << input << std::endl;
        input = ProcessMap(tempToHumid, input);
        std::cout << input << std::endl;
        input = ProcessMap(humidToLoca, input);
        std::cout << input << std::endl;

        end.push_back(input);
    }

    for (uint64_t finals : end)
    {
        if (finals < smallest) { smallest = finals; }
    }

    std::cout << smallest << std::endl;
}


