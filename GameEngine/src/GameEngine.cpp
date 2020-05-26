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

void GE::GameEngine::addCommand(std::string name, ActionCallback callback, std::string info, std::string desc){
    Command* newCom = new Command({name}, callback, info, desc);
    coms.push_back(newCom);
}

void GE::GameEngine::addCommand(std::vector<std::string> names, ActionCallback callback, std::string info, std::string desc){
    Command* newCom = new Command(names, callback, info, desc);
    coms.push_back(newCom);
}

void GE::GameEngine::addCommand(std::string name, ActionCallbackCtx callback, std::string info, std::string desc){
    Command* newCom = new Command({name}, callback, info, desc);
    coms.push_back(newCom);
}

void GE::GameEngine::addCommand(std::vector<std::string> names, ActionCallbackCtx callback, std::string info, std::string desc){
    Command* newCom = new Command(names, callback, info, desc);
    coms.push_back(newCom);
}

void GE::GameEngine::runCommand(std::string name, std::string arguments){
    Command* chosenCommand = getCommandByName(name);

    if (chosenCommand != NULL){
        if (chosenCommand->hasCtx()){
            chosenCommand->runCtx(arguments, coms);
        } else {
            chosenCommand->run(arguments);
        }
    } else {
        std::cerr << "Unkown command '" << name << "'." << std::endl;
    }
}

bool GE::GameEngine::parseCommand(std::string str){
    std::vector<std::string> result = splitString(str);
    runCommand(result[0], result[1]);

    return true;
}

GE::Command* GE::GameEngine::getCommandByName(std::string name){
    Command* chosenCommand = NULL;
    for (Command* a : coms){
        if (a->hasName(name)){
            chosenCommand = a;
            break;
        }
    }

    return chosenCommand;
}
