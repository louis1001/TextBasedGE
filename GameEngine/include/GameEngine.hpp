//
//  GameEngine.hpp
//  GameEngine
//
//  Created by Luis Gonzalez on 7/30/19.
//  Copyright © 2019 Luis Gonzalez. All rights reserved.
//

#ifndef GameEngine_hpp
#define GameEngine_hpp
#include <string>
#include <vector>
#include <map>

namespace GE {
    typedef void (*ActionCallback)(std::string);
    class GameEngine{
    std::map<std::string, ActionCallback> commands;
    public:
        GameEngine();
        GameEngine(std::map<std::string, ActionCallback>);
        GameEngine(std::vector<std::string>, std::vector<ActionCallback>);
        void addCommand(std::string, ActionCallback);
        void runCommand(std::string, std::string);
        bool parseCommand(std::string input);
    };
}

#endif /* GameEngine_hpp */
