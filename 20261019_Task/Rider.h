#pragma once
using namespace std;
#include "Servant.h"
class Rider :public Servant
{
public:
	void Attack() override;
	void ShowProfile() override;
};

