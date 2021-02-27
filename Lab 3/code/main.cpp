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
    int nubmber;
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
            std::cout << itt->text().get() << " " << std::endl;
            std::string current = itt->text().get();
            if (j == 0)
                currentInfo.nubmber = std::stoi(current);
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
        for (int k = 0; k < routes_names.size(); k++)
            if (currentInfo.type_of_vehicle == "Автобус")
                info.bus_stations[routes_names[k]]++;
            else if (currentInfo.type_of_vehicle == "Троллейбус")
                info.trolleybus_stations[routes_names[k]]++;
            else
                info.tram_stations[routes_names[k]]++;
    }
    int max = info.bus_stations.begin()->second;
    std::string max_bus = info.bus_stations.begin()->first;
    for (auto ll = info.bus_stations.begin(); ll != info.bus_stations.end(); ll++) {
        if (ll->second>max){
            max = ll->second;
            max_bus = ll->first;
        }
        //std::cout << ll->first << " " << ll->second << "\n";
    }
    std::cout<<"Bus max - Route: "<< max_bus<<", stops "<<max<<"\n";

    //std::cout << "Load result: " << result.description() << ", mesh name: " << doc.child("dataset").child("transport_station").first_child().value() << std::endl;
    return 0;
}
