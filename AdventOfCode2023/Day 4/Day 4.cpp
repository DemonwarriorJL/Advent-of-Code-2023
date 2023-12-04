// Day 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

int main()
{
    std::fstream newfile;

    newfile.open("Text4.txt", std::ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) {
        std::string line;
        int total = 0;
        int totalNumber = 0;

        while (getline(newfile, line)) 
        {
            totalNumber++;
        }

        while (getline(newfile, line)) //read data from file object and put it into string.
        {
            std::vector<int> winningNumbers;
            std::vector<int> playingNumbers;
            int lineTotal = 0;
            std::string m_line = line.substr(line.find(": ") + 2);
            std::cout << m_line << std::endl;
            int j = 0;

            bool searchWinningNumbers = true;

            //    while (m_line != "") 
            //    {
            //        if (searchWinningNumbers) //searching numbers before |
            //        {
            //            if (m_line[0] == '|') //gets to seperator between winning and playing numbers
            //            {
            //                m_line = m_line.substr(m_line.find("| ") + 2);
            //                searchWinningNumbers = false;

            //                std::string m_info = m_line.substr(0, 3);
            //                playingNumbers.push_back(stoi(m_info));
            //            }
            //            else //winning numbers
            //            {
            //                std::string m_info = m_line.substr(0, 3);
            //                winningNumbers.push_back(stoi(m_info));
            //            }
            //        }
            //        else //searching numbers after |
            //        {
            //            std::string m_info = m_line.substr(0, 3);
            //            playingNumbers.push_back(stoi(m_info));
            //        }

            //        if ((m_line.size() == 2)) //end of the line
            //        {
            //            m_line = "";
            //        }
            //        else //refresh line for next int
            //        {
            //            m_line = m_line.substr(3);
            //        }
            //    }
            //    
            //    
            //    bool addingBegun = false;
            //    for (int number : winningNumbers)
            //    {
            //        for (int playnumber : playingNumbers) 
            //        {
            //            if (number == playnumber)
            //            {
            //                if (addingBegun)
            //                {
            //                    lineTotal *= 2;
            //                }
            //                else
            //                {
            //                    lineTotal = 1;
            //                    addingBegun = true;
            //                }
            //            }
            //        }
            //    }
            //    total += lineTotal;
            //}



            std::map<int, int> gameRepeats;
            
            //Setup Map for tracking number of games repeats

            for (int i = 0; i < totalNumber; i++) 
            {
                gameRepeats.insert(i, 1);
            }

            while (m_line != "") 
            {
                for(int k = 0; k < gameRepeats[j]; k++)
                {
                    if (searchWinningNumbers) //searching numbers before |
                    {
                        if (m_line[0] == '|') //gets to seperator between winning and playing numbers
                        {
                            m_line = m_line.substr(m_line.find("| ") + 2);
                            searchWinningNumbers = false;

                            std::string m_info = m_line.substr(0, 3);
                            playingNumbers.push_back(stoi(m_info));
                        }
                        else //winning numbers
                        {
                            std::string m_info = m_line.substr(0, 3);
                            winningNumbers.push_back(stoi(m_info));
                        }
                    }
                    else //searching numbers after |
                    {
                        std::string m_info = m_line.substr(0, 3);
                        playingNumbers.push_back(stoi(m_info));
                    }

                    if ((m_line.size() == 2)) //end of the line
                    {
                        m_line = "";
                    }
                    else //refresh line for next int
                    {
                        m_line = m_line.substr(3);
                    }
                }
                j++;

                int posNumberToAddOn = 1;
                for (int number : winningNumbers)
                {
                    for (int playnumber : playingNumbers)
                    {
                        if (number == playnumber)
                        {
                            gameRepeats[j + posNumberToAddOn] += 1;
                        }
                    }
                }
                winningNumbers.clear();
                playingNumbers.clear();
            }
                
           
            total += lineTotal;


            // printing map gquiz1
            std::map<int, int>::iterator itr;
            std::cout << "\nThe map gquiz1 is : \n";
            std::cout << "\tKEY\tELEMENT\n";
            for (itr = gameRepeats.begin(); itr != gameRepeats.end(); ++itr) {
                std::cout << '\t' << itr->first << '\t' << itr->second
                    << '\n';
                total += itr->second;
            }
            std::cout << std::endl;
        }
        std::cout << total << std::endl;
        newfile.close(); //close the file object.
    }
}
