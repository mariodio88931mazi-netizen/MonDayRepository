#pragma once
#include <iostream>
#include "Character.h"

class Enemy : public Character {
public:
    void Attack() override;
};
