//
//  main.cpp
//  TestGame
//
//  Created by Luis Gonzalez on 7/30/19.
//  Copyright © 2019 Luis Gonzalez. All rights reserved.
//

#include <iostream>
#include "GameEngine.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    GE::GameEngine a;

    a.addCommand("eat", [](std::string food){
        std::cout << "c: eating " << food << "\n";
    });

    a.addCommand("call", [](auto nothing){
        std::cout << "Calling!" << std::endl;
    });

    std::string inp;
    while(true){
        std::cout << "> ";
        std::cin >> inp;

        a.parseCommand(inp);

        std::cout << "\n";
    }

    return 0;
}
