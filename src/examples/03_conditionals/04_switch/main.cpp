#include<iostream>
#include "switch.h"

using std::cout;
using std::cin;

int main() 
{
	auto option = 0;

	cout<<"Enter number: ";
	cin>>option;

	auto result = menu(option);

	cout<<"Result: "<<result<<"\n";

	return 0;
}