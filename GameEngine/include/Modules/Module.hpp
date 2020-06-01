//
//  Module.hpp
//  GameEngine
//
//  Created by Luis Gonzalez on 5/26/20.
//  Copyright © 2020 Luis Gonzalez. All rights reserved.
//

#ifndef Module_hpp
#define Module_hpp
#include "../Command.hpp"

namespace GE {
    class Module {
        std::string name;

    public:
        std::string getName() { return name; }
        Module(std::string the_name = "module"): name(the_name) {}
    };
}

#endif /* Module_hpp */
