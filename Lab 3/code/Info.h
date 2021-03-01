//
// Created by Денис on 26.02.2021.
//

#ifndef CODE_INFO_H
#define CODE_INFO_H


#include <map>
#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>

struct useFullInfo {
    int busStop = 0;
    std::vector<std::pair<double, double>> l_;
};


class Info {
public:
    std::map<std::string, int> bus_stations;
    std::map<std::string, int> trolleybus_stations;
    std::map<std::string, int> tram_stations;

    std::map<std::string, std::vector<std::pair<double, double>>> bus_distance;
    std::map<std::string, std::vector<std::pair<double, double>>> tram_distance;
    std::map<std::string, std::vector<std::pair<double, double>>> trolleybus_distance;

    std::map<std::string, unsigned> streets_strops;

    std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    void find_max_stops(std::map<std::string, int> &m, std::string &route, int &result) {
        int max = m.begin()->second;
        std::string max_bus = m.begin()->first;
        for (auto ll = m.begin(); ll != m.end(); ll++) {
            if (ll->second > max) {
                max = ll->second;
                max_bus = ll->first;
            }
        }
        route = max_bus;
        result = max;
    }

    void find_max_distance(std::map<std::string, std::vector<std::pair<double, double>>> &m, std::string &route,
                           double &result, short type) {
        //
        double max = 0, curr_dist;
        std::string max_route;
        int j = 0;
        int kkk = 0;
        for (auto ll = m.begin(); ll != m.end(); ll++, j++) {
            curr_dist = 0;
            for (int i = 0; i < ll->second.size() - 1; i++) {
                curr_dist += len(ll->second[i], ll->second[i + 1], type);
            }
            if (curr_dist > max) {
                route = ll->first;
                max = curr_dist;
            }

        }
        result = max;
    }

    void find_max_streets_stops(std::string &route, int &result) {
        int max = 0;
        for (auto i = streets_strops.begin(); i != streets_strops.end(); i++) {
            if (i->second > max) {
                max = i->second;
                route = i->first;
            }
        }
        result = max;
    }

    void end_first_task() {
        bus_stations.clear();
        trolleybus_stations.clear();
        tram_stations.clear();
    }

    void end_second_task() {
        bus_distance.clear();
        trolleybus_distance.clear();
        tram_distance.clear();
    }

private:
    double len(std::pair<double, double> &point_1, std::pair<double, double> &point_2, short type) {
        double dLat = point_2.first - point_1.first;
        double dLon = point_2.second - point_1.second;
        double a = sin(dLat / 2) * sin(dLat / 2) +
                   cos(point_1.first) * cos(point_2.first) *
                   sin(dLon / 2) * sin(dLon / 2);
        return (2 * asin(sqrt(a)) * 6378.137 * (0.76 + float(type) / 10) / 1000);
    }
};

#endif //CODE_INFO_H
