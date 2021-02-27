//
// Created by Денис on 26.02.2021.
//

#ifndef CODE_INFO_H
#define CODE_INFO_H


#include <map>
#include <iostream>
#include <vector>
#include <sstream>

struct useFullInfo {
    int busStop = 0;
    std::vector<std::pair<double,double>> l_;
};


class Info{
public:
    std::map<std::string, int> bus_stations;
    std::map<std::string,  std::vector<std::pair<double,double>>> bus_;
    std::map<std::string, int> trolleybus_stations;
    std::map<std::string, int> tram_stations;
    static std::vector<std::string> split(const std::string &s, char delim)
    {
        std::vector<std::string> elems;
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

};
#endif //CODE_INFO_H
