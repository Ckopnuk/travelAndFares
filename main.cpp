#include <iostream>
#include <string>
#include <fstream>
#include "tariff.h"
#include <map>

void travelFares (int km = 0, int time = 0, int wait = 0)
{
    std::fstream file;
    file.open("cost.txt", std::fstream::app);
    if (!file.is_open())
    {
        std::cout << "Open file error!" << std::endl;
    }
    else
    {
        if (wait != 0)
        {
            Tariff tm(wait, time);
            std::cout << tm.getTravelCost() << "P on minut Tariff!";
            file << tm.getTravelCost() << "P on minut Tariff!\n";
        }
        else
        {
            TariffThree t3(km, time);
            TariffSix t6(km, time);
            TariffNine t9(km, time);
            TariffTwelve t12(km, time);
            TariffDay td(km, time);
            std::map<double, std::string> tariffmap;
            // tariffmap.emplace(tm.getTravelCost(), "Tariff per min");
            tariffmap.emplace(t3.getTotalPrice(), "Tariff 3 hours");
            tariffmap.emplace(t6.getTotalPrice(), "Tariff 6 hours");
            tariffmap.emplace(t9.getTotalPrice(), "Tariff 9 hours");
            tariffmap.emplace(t12.getTotalPrice(), "Tariff 12 hours");
            tariffmap.emplace(td.getTotalPrice(), "Tariff 24 hours");
            auto itmap = tariffmap.begin();
            std::cout << "\n" << "it is cost: " << itmap->first << "P on " << itmap->second << std::endl;
            file << "it is cost: " << itmap->first << "P on " << itmap->second << std::endl;
        }
    }

    file.close();
}


int main()
{
    std::fstream file;
    file.open("myFile.txt",std::fstream::in | std::fstream::out | std::fstream::app);
    if (!file.is_open())
    {
        std::cout << "Open file error" << std::endl;
    }
    else
    {
        std::cout << "File is open!" << std::endl;
        std::string str;
        int km = 0;
        int time = 0;
        int wait = 0;
        while (!file.eof())
        {
            file >> str;
            if (str == "drive")
            {
                file >> str;
                km = std::stoi(str);
            }

            if (str == "in")
            {
                file >> str;
                try
                {
                    time = std::stoi(str);
                    //std::cout << km << ' ' << time << std::endl;
                    travelFares(km, time);

                }
                catch (...) {}
            }

            if (str == "for")
            {
                file >> str;
                wait = std::stoi(str);
                file >> str;
                if (str == "hours.")
                {
                    wait = wait * 60;
                    travelFares(0, 0, wait);
                }
                else
                {
                    travelFares(0, 0, wait);
                }
            }
        }
        file.close();
        return 0;
    }
}
