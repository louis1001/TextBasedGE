//
//  Command.cpp
//  GameEngine
//
//  Created by Luis Gonzalez on 10/28/19.
//  Copyright © 2019 Luis Gonzalez. All rights reserved.
//

#include <Command.hpp>

GE::Command::Command(std::vector<std::string> names_, ActionCallback callback_, std::string info="", std::string desc="") :
    names(names_), callback(callback_), help(info), description(desc){
        withCtx = false;
}

GE::Command::Command(std::vector<std::string> names_, ActionCallbackCtx callbackCtx_, std::string info="", std::string desc="") :
    names(names_), callbackCtx(callbackCtx_), help(info), description(desc){
        withCtx = true;
}

void GE::Command::run(std::string arguments){
    callback(arguments, this);
}

void GE::Command::runCtx(std::string arguments, std::vector<Command*> context){
    callbackCtx(arguments, context);
}

std::string GE::Command::joinNames(){
    std::string result = "";
    
    for (int i = 0; i < names.size(); i++){
        result += names[i];
        if (i != names.size()-1){
            result += ", ";
        }
    }

    return result;
}

bool GE::Command::hasName(std::string name){
    bool existsName = false;
    for(std::string n : names){
        if (n == name) {
            existsName = true;
        }
    }

    return existsName;
}

bool GE::Command::hasCtx(){
    return withCtx;
}

std::string GE::Command::getInfo(){
    if (this->help.size() > 0){
        return this->help;
    } else {
        return "***";
    }
}

std::string GE::Command::getDetails(){
    if (this->description.size() > 0){
        return this->description;
    } else {
        return "No details available for this command.";
    }
}

std::string GE::Command::getMainName(){
    return names[0];
}
