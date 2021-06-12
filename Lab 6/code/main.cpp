#include <iostream>

#include <vector>
#include "rubik.h"
void error(std::string &str){
    std::cout << "Некорректная команда";
    std::getline(std::cin, str);
}
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
    std::getline(std::cin, command);
    int a,b;
    while(command!= "exit"){
        if (command.length()>4) {
            error(command);
            continue;
        }//try{
        a = std::stoi(command.substr(0,1));
        command.erase(0, 2);
        b = std::stoi(command);
//        } catch (std::exception &e) {
//            error(command);
//            continue;
//        }
        if (a<0 || a>5 || abs(b)!=1){
            error(command);
            continue;
        }
        cubik.out();
        std::cout<<"\n";
        cubik.rotate_90_degree(a,b);
        cubik.out();
        std::getline(std::cin, command);

    }




    return 0;
}