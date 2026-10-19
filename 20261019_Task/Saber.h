#pragma once
using namespace std;
#include "Servant.h"
class Saber :public Servant
{
public:
	void Attack() override;

	void ShowProfile() override;
};

