//
//  Map.hpp
//  GameEngine
//
//  Created by Luis Gonzalez on 5/26/20.
//  Copyright © 2020 Luis Gonzalez. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include "Module.hpp"
#include <string>
#include <vector>

namespace GE {
class GameEngine;
class Connection;

class Node {
    std::string name;
    std::string description;

    std::vector<Connection> my_connections;
public:
    Node(std::string title, std::string desc = "Nothing to see here");

    Connection& addConnection(Connection);

    std::string getName() { return name; }
    std::string getDescription() { return description; }

    std::vector<Connection>& connections() { return my_connections; }
};

class Connection {
    std::vector<std::string> triggers;
    Node* from { nullptr };
    Node* to { nullptr };

    Connection(std::vector<std::string>, Node*, Node*);

    Connection* other_way;
public:

    static void connect(std::pair<std::vector<std::string>, Node*> a, std::pair<std::vector<std::string>, Node*> b);

    Node* origin() { return from; }
    Node* target() { return to; }

    Connection* equivalent() { return other_way; }
    void setEquivalent(Connection* other) { other_way = other; }
    bool matches(std::string);
};

class Map: public Module {
    Node* currentNode { nullptr };

    std::vector<Connection> connections;

    Connection* last_movement;
    bool has_moved {false};
public:
    explicit Map(GameEngine& gm);

    Node* current() { return currentNode; }
    void setCurrent(Node* n) { currentNode = n; }

    void moveTo(std::string);
};
}

#endif /* Map_hpp */
