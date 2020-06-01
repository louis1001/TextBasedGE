//
//  Map.cpp
//  GameEngine
//
//  Created by Luis Gonzalez on 5/26/20.
//  Copyright © 2020 Luis Gonzalez. All rights reserved.
//

#include "Map.hpp"
#include "GameEngine.hpp"
#include <iostream>

GE::Map::Map(GameEngine& ge): Module("map") {
    ge.addCommand("where", [&](auto, auto){
        std::cout << "You are at the " << current()->getName() << "\n";
    },
    "Check what room you're in.",
    "Tells you the name of this room. If you want more info on the room, use `describe`.");
    
    ge.addCommand({"go", "g", "walk", "head"}, [&](std::string direction, auto){
        moveTo(direction);
    },
    "Walk towards a direction.",
    "If possible, the player moves towards the specified direction.");
    
    ge.addCommand("describe", [&](auto, auto) {
        std::cout << "You are at the " << current()->getName() << "\n";
        std::cout << "\t" << current()->getDescription();
    },
    "Check what is in the current room",
    "Get a quick look at your position. Exits, items...");
}

void GE::Map::moveTo(std::string dir) {
    std::vector<Connection*> possible_connections;

    if (dir == "back") {
        if (has_moved) {
            possible_connections.push_back(last_movement);
        } else {
            std::cout << "You come from nowhere... Where do you wanna go back to?\n";
            return;
        }
    } else {
        for(Connection& con : current()->connections()) {
            if (con.matches(dir)) {
                possible_connections.push_back(&con);
            }
        }
    }

    if (possible_connections.size() == 0) {
        std::cout << "You cannot go " << dir << ". It doesn't exist 0_0 Sorry.\n";
        return;
    }

    if (possible_connections.size() > 1) {
        std::cout << "There are many paths like " << dir << ". Please specify.\n";
        return;
    }

    auto picked = possible_connections[0];

    std::cout << "You move into the " << picked->target()->getName() << "\n";

    currentNode = picked->target();
    last_movement = picked->equivalent();
    std::cout << "The way back would be " << picked->target()->getName() << "\n";
    has_moved = true;
}

GE::Node::Node(std::string title, std::string desc): name(title), description(desc) {}

GE::Connection& GE::Node::addConnection(Connection con) {
    my_connections.push_back(std::move(con));

    return my_connections[my_connections.size()-1];
}

GE::Connection::Connection(std::vector<std::string> trigs, GE::Node* one, GE::Node* two):
    triggers(trigs), from(one), to(two) {}

void GE::Connection::connect(std::pair<std::vector<std::string>, Node*> a, std::pair<std::vector<std::string>, Node*> b) {
    auto& forward = a.second->addConnection({
        /*.triggers = */ std::move(b.first),
        /*.from     = */           a.second,
        /*.to       = */           b.second
    });

    auto& backward = b.second->addConnection({
        /*.triggers = */ std::move(a.first),
        /*.from     = */           b.second,
        /*.to       = */           a.second
    });

    forward.setEquivalent(&backward);
    backward.setEquivalent(&forward);
}

bool GE::Connection::matches(std::string name) {
    for (auto s : triggers){
        if (s == name) return true;
    }
    
    return false;
}
