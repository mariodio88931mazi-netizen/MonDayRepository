#pragma once
#include "Character.h"
#include <iostream>
using namespace std;

class Player : public Character
{
public:
    void Attack() override;
};