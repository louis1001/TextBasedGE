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
#include "Map.hpp"
#include "utils.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    GE::GameEngine a;

    a.addCommand(
    {"help", "h", "info"},
    [&](string args, GE::Command){
        if (args.size() <= 0){
            cout << "Commands Available:" << endl;
            for (auto com : a.commands()){
                string comInfo = com.info();
                cout <<
                GE::padLeft(com.joinNames(), 25) <<
                " = " << comInfo <<
                endl << endl;
            }
        } else {
            auto chosen = a.getCommandByName(args);
            
            if (chosen != nullptr){
                cout << "Details of " << chosen->mainName() << endl << endl;
                cout << "\t" << chosen->details() << endl;
            } else {
                cout << "Unknown command '" << args << "'." << endl;
            }
        }
    },
    "Shows the help and commands available.",
    "Displays a list of the commands in the game. Use `help [command]` "
     "to get the details of a specific command.");

    a.addCommand(vector<string>{"exit", "q", "quit"}, [](string args, auto){
        cout << "Goodbye!" << endl;
        exit(0);
    },
    "Quits the application",
    "Ends the game. All changes and progress is saved and loaded "
     "on the next boot of the game.");

    GE::Map m(a);

    GE::Node entrance("entrance",
                      "It's raining heavily.\n"
                      "\tThere's a big door in front of you, going north, inside the house.");

    GE::Node main("main hall",
                  "A big hall... Too big, maybe. Who could live in this place?\n"
                  "\tThere's a high chandelier with actual candels lighting the room.\n"
                  "\tThere are doors on all four walls.\n"
                  "\tThe door to the south takes you back to the entrance.\n"
                  "\tThe one to the north is bellow the stairs. Looks like a red bathroom door.");

    GE::Node bathroom("bathroom",
                      "A smelly bathroom... You don't wanna be here.\n"
                      "\tThe red door takes you back south, to the main hall.");
    
    GE::Node upstairs("attic",
                      "This is really empty... Wow");

    m.setCurrent(&entrance);

    GE::Connection::connect(
        { {"north", "big door", "house"}, &main      },
        { {"south", "big door", "exit" }, &entrance  }
    );

    GE::Connection::connect(
        { {"north", "red door"}, &bathroom  },
        { {"south", "red door"}, &main      }
    );
    
    GE::Connection::connect(
        { {"up", "stairs"},     &upstairs   },
        { {"down", "stairs"},   &main       }
    );

    a.registerModule(m);

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
