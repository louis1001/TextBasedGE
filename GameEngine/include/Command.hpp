//
//  Command.hpp
//  GameEngine
//
//  Created by Luis Gonzalez on 10/28/19.
//  Copyright © 2019 Luis Gonzalez. All rights reserved.
//

#ifndef Command_h
#define Command_h
#include <string>
#include <map>
#include <vector>
#include <functional>

namespace GE {
    class Command;

    typedef std::function<void(std::string, Command&)> ActionCallback;
    class Command {
        std::vector<std::string> names;
        ActionCallback callback;
        std::string help;
        std::string description;

    public:
        Command(
            std::vector<std::string>,
            ActionCallback,
            std::string,
            std::string
        );

        void run(std::string);
        std::string joinNames();
        bool hasName(std::string);
        std::string info();
        std::string details();
        std::string mainName();
    };
}

#endif /* Command_h */
