#include <iostream>
#include <string>

#include "../Header/function.h"

void fixInput() {
    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    else {
        std::cin.ignore(10000, '\n');
    }
}