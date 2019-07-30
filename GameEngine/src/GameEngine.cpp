//
//  GameEngine.cpp
//  GameEngine
//
//  Created by Luis Gonzalez on 7/30/19.
//  Copyright © 2019 Luis Gonzalez. All rights reserved.
//

#include "GameEngine.hpp"
#include "utils.cpp"
#include <iostream>

void sayHi(std::string message){
    std::cout << "c: " << message << std::endl;
}

GE::GameEngine::GameEngine(){}

GE::GameEngine::GameEngine(std::map<std::string, ActionCallback> commands){
    this->commands = commands;
}

GE::GameEngine::GameEngine(std::vector<std::string> comms, std::vector<ActionCallback> callbacks){
    if (comms.size() != callbacks.size()){
        std::cerr << "The number of commands doesn't match the number of callbacks." << std::endl;
    }

    for(int i = 0; i < comms.size(); i++){
        auto name = comms[i];
        auto callback = callbacks[i];
        commands[name] = callback;
    }
}

void GE::GameEngine::addCommand(std::string name, ActionCallback callback){
    commands[name] = callback;
}

void GE::GameEngine::runCommand(std::string name, std::string arguments){
    ActionCallback commandAction = commands[name];

    if (commandAction != NULL)
        commandAction(arguments);
    else
        std::cerr << "Unkown command '" << name << "'." << std::endl;
}

bool GE::GameEngine::parseCommand(std::string str){
//    std::cout << "> " << result[0] << " <" << std::endl;

    std::vector<std::string> result = splitString(str);

    return true;
}

