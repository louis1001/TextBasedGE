//
//  GameEngine.hpp
//  GameEngine
//
//  Created by Luis Gonzalez on 7/30/19.
//  Copyright © 2019 Luis Gonzalez. All rights reserved.
//

#ifndef GameEngine_hpp
#define GameEngine_hpp
#include "Command.hpp"
#include <string>
#include <vector>
#include <map>

namespace GE {
//    class Command;
    class GameEngine{
        std::vector<Command> coms;
    public:
        GameEngine();
        void addCommand(std::string, ActionCallback, std::string="", std::string="");
        void addCommand(std::vector<std::string>, ActionCallback, std::string="", std::string="");
        void runCommand(std::string, std::string);
        bool parseCommand(std::string input);

        std::vector<Command>& commands() { return coms; }

        Command* getCommandByName(std::string);
    };
}

#endif /* GameEngine_hpp */
