//
//  main.cpp
//  TestGame
//
//  Created by Luis Gonzalez on 7/30/19.
//  Copyright © 2019 Luis Gonzalez. All rights reserved.
//

#include <iostream>
//#include <iomanip>
#include <vector>
#include "GameEngine.hpp"
#include "utils.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    GE::GameEngine a;

    a.addCommand("eat", [](string food, GE::Command& nothing){
        cout << "eating " << food << "\n";
    },
    "Eat some food to rise your health.",
    "The games has a variety of meals that rise you health in varying ammounts."
     "Eat one to regain HP, until it gets to it's maximum. Eating more wont"
     " have any effect, and wont waste the item.");

    a.addCommand("call", [&](string nothing, GE::Command&){
        std::cout << "Calling!" << std::endl;
    },
    "Call. No one, just call.",
    "Literally useless.");

    a.addCommand({"go", "g", "walk", "head"}, [](std::string direction, GE::Command&){
        if (direction == "north" ||
            direction == "south" ||
            direction == "east"  ||
            direction == "west") {
            std::cout << "going " << direction << "\n";
        } else {
            std::cerr << "cannot walk to " << direction << "\n";
        }
    },
    "Walk towards a direction.",
    "If possible, the player moves towards the specified direction.");

    a.addCommand(
    {"help", "h", "info"},
    [&](string args, vector<GE::Command>& context){
        if (args.size() <= 0){
            cout << "Commands Available:" << endl;
            for (auto com : context){
                string comInfo = com.getInfo();
                cout <<
                GE::padLeft(com.joinNames(), 25) <<
                " = " << comInfo <<
                endl << endl;
            }
        } else {
            auto chosen = a.getCommandByName(args);
            
            if (chosen != nullptr){
                cout << "Details of " << chosen->getMainName() << endl << endl;
                cout << "\t" << chosen->getDetails() << endl;
            } else {
                cout << "Unknown command '" << args << "'." << endl;
            }
        }
    },
    "Shows the help and commands available.",
    "Displays a list of the commands in the game. Use `help [command]` "
     "to get the details of a specific command.");

    a.addCommand(vector<string>{"exit", "q", "quit"}, [](string args, vector<GE::Command>& context){
        cout << "Goodbye!" << endl;
        exit(0);
    },
    "Quits the application",
    "Ends the game. All changes and progress is saved and loaded on the next boot of the game.");

    std::string inp;
    while(true){
        std::cout << "> ";

        std::string line;
        std::string start = "";
        std::cin >> start;
        std::getline(std::cin, line);
        a.parseCommand(start + line);

        std::cout << "\n";
    }

    return 0;
}
