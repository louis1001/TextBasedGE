//
//  utils.cpp
//  GameEngine
//
//  Created by Luis Gonzalez on 7/30/19.
//  Copyright © 2019 Luis Gonzalez. All rights reserved.
//

#include "utils.hpp"

std::vector<std::string> GE::splitString(std::string str){
    std::vector<std::string> result;
    std::string lastToken = "";
    for(size_t i = 0; i < str.length(); i++){
        char c = str[i];
        if( c == ' ' ){
            result.push_back(lastToken);
            lastToken = "";
            continue;
        }else if(c == '\"' ){
            i++;
            while(i < str.length() && str[i] != '\"'){ lastToken += str[i]; i++; }
        }else if(c == '\'' ){
            i++;
            while(str[i] != '\''){ lastToken += str[i]; i++; }
        }else{
            lastToken += c;
        }
    }
    result.push_back(lastToken);

    return result;
}

std::string GE::padLeft(std::string og, int sz){
    std::string result = og;
    
    if (og.size() > 0 && og.size() < sz){
        result.insert(result.begin(), sz - result.size(), ' ');
    }
    return result;
}
