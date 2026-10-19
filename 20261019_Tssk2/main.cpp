#include <iostream>
#include "Homura.h"
#include "Madoka.h"
using namespace std;

int main(void)
{
	Madoka madoka;
	Homura homura;

	MagicalGirl* girls[2] = { &madoka,&homura };

	for (int i = 0; i < 2; i++)
	{
		girls[i]->Fight();
		girls[i]->ShowProfile();
	}
	return 0;
}