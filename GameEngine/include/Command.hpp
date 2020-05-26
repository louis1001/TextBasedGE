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

    typedef std::function<void(std::string, Command*)> ActionCallback;
    typedef std::function<void(std::string, std::vector<Command*>)> ActionCallbackCtx;
    class Command {
        std::vector<std::string> names;
        ActionCallback callback;
        ActionCallbackCtx callbackCtx;
        std::string help;
        std::string description;
        bool withCtx;

    public:
        Command(
            std::vector<std::string>,
            ActionCallback,
            std::string,
            std::string
        );

        Command(
            std::vector<std::string>,
            ActionCallbackCtx,
            std::string,
            std::string
        );

        void run(std::string);
        void runCtx(std::string, std::vector<Command*>);
        std::string joinNames();
        bool hasName(std::string);
        bool hasCtx();
        std::string getInfo();
        std::string getDetails();
        std::string getMainName();
    };
}

#endif /* Command_h */
