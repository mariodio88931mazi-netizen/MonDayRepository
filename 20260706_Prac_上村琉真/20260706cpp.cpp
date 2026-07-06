#include<iostream>
using namespace std;

void Add(int &num)
{
	num += 10;
}

int main(void)
{
	int number;

	cout << "”š‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B" << endl;

	cin >> number;

	Add(number);

	cout << number << "‚Å‚·" << endl;

	return 0;
}