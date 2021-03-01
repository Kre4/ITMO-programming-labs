#include <iostream>
#include "xml/pugixml.h"
#include "Info.h"

//автобус, троллейбус, трамвай
bool find_symbol(const std::string &str) {
    for (char i : str)
        if (i == '.' || i == ',')
            return true;
    return false;
}

struct Current_info {
    int number = -1;
    std::string type_of_vehicle;
    std::string object_type;
    std::string name_stopping;
    std::string the_official_name;
    std::string location;
    std::string routes;
    std::string coordinates;
};

int main() {
    system("chcp 65001");
    Info info;
    pugi::xml_document doc;
    Current_info currentInfo;
    doc.load_file("data.xml");
    pugi::xml_node data = doc.child("dataset");
    int i = 0;

    for (pugi::xml_node_iterator it = data.begin(); it != data.end(); ++it, i++) {
        int j = 0;

        for (pugi::xml_node_iterator itt = it->begin(); itt != it->end(); ++itt, j++) {
            //std::cout << itt->text().get() << " " << std::endl;
            std::string current = itt->text().get();
            if (j == 0)
                currentInfo.number = std::stoi(current);
            if (j == 1)
                currentInfo.type_of_vehicle = current;
            if (j == 2)
                currentInfo.object_type = current;
            if (j == 3)
                currentInfo.name_stopping = current;
            if (j == 4)
                currentInfo.the_official_name = current;
            if (j == 5)
                currentInfo.location = current;
            if (j == 6)
                currentInfo.routes = current;
            if (j == 7)
                currentInfo.coordinates = current;
            //if ()
        }
        std::vector<std::string> routes_names = info.split(currentInfo.routes, '.');
        if (find_symbol(routes_names[0]))
            routes_names = info.split(currentInfo.routes, ',');
        //широта_долгота
        std::vector<std::string> lon_lat = info.split(currentInfo.coordinates, ',');
        for (int k = 0; k < routes_names.size(); k++)
            if (currentInfo.type_of_vehicle == "Автобус") {
                info.bus_stations[routes_names[k]]++;
                info.bus_distance[routes_names[k]].push_back(
                        std::make_pair(std::stod(lon_lat[0]), std::stod(lon_lat[1])));
            } else if (currentInfo.type_of_vehicle == "Троллейбус") {
                info.trolleybus_stations[routes_names[k]]++;
                info.trolleybus_distance[routes_names[k]].push_back(
                        std::make_pair(std::stod(lon_lat[0]), std::stod(lon_lat[1])));
            } else {
                info.tram_stations[routes_names[k]]++;
                info.tram_distance[routes_names[k]].push_back(
                        std::make_pair(std::stod(lon_lat[0]), std::stod(lon_lat[1])));

            }
        routes_names.clear();
        lon_lat.clear();
        std::vector<std::string> streets = info.split(currentInfo.location, ',');
        for (int k = 0; k < streets.size(); k++) {
            int index = streets[k].find(' ');
            if (index == 0)
                streets[k].erase(streets[k].find(' '), 1);
            info.streets_strops[streets[k]]++;
        }
    }
    std::string res1;
    int res2;
    double res3;
    //task1
    info.find_max_stops(info.bus_stations, res1, res2);
    std::cout << "Bus max - Route: " << res1 << ", stops " << res2 << "\n";
    info.find_max_stops(info.tram_stations, res1, res2);
    std::cout << "Tram max - Route: " << res1 << ", stops " << res2 << "\n";
    info.find_max_stops(info.trolleybus_stations, res1, res2);
    std::cout << "Trolleybus max - Route: " << res1 << ", stops " << res2 << "\n";
    info.end_first_task();
    //task2
    info.find_max_distance(info.bus_distance, res1, res3, 0);
    std::cout << "Bus max distance - Route: " << res1 << ", distance " << res3 << "\n";
    info.find_max_distance(info.tram_distance, res1, res3, -1);
    std::cout << "Tram max distance - Route: " << res1 << ", distance " << res3 << "\n";
    info.find_max_distance(info.trolleybus_distance, res1, res3, 1);
    std::cout << "Trolleybus max distance - Route: " << res1 << ", distance " << res3 << "\n";
    info.end_second_task();
    //task3
    info.find_max_streets_stops(res1, res2);
    std::cout << "Street with max stops: " << res1 << " Stops: " << res2;
    //std::cout << "Load result: " << result.description() << ", mesh name: " << doc.child("dataset").child("transport_station").first_child().value() << std::endl;
    return 0;
}
