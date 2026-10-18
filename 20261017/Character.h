#pragma once
#include <iostream>
using namespace std;

class Character {
public:
    virtual void Attack() = 0;
    virtual ~Character() = default;
};

