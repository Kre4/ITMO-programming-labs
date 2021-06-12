#include <iostream>

#include <vector>
#include "rubik.h"
int main(){
    system("chcp 65001");
//    cube rubik;
//    rubik.out();
//    rubik.turn_90_degree_minus(rubik.left_side);
//    rubik.out();
    rubik cubik;
    std::cout<<"Обозначения граней:\n"
               "0 верхняя   1 нижняя\n"
               "4 передняя  5 задняя\n"
               "2 левая     3 правая\n"
               "Команды:\n"
               "a b - где a[0,6]- номер грани, b - либо 1, либо -1(по часовй и против)\n"
               "exit - выход из программы\n";
    std::string command;
    std::cin>>command;
    int a,b;
    while(command!= "exit"){
        a = std::stoi(command.substr(0,1));

        std::cin>>command;
        cubik.out();
    }




    return 0;
}