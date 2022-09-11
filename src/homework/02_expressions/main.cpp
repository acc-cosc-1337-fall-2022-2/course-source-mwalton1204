//write include statements
#include<iostream>
#include "hwexpressions.h"

//write namespace using statement for cout
using std::cin;
using std::cout;

//main function
int main()
{
	double meal_amount, tip_rate, tip_amount, tax_amount, total;

	cout<<"Enter the cost of the meal: ";
	cin>>meal_amount;

	tax_amount = get_sales_tax_amount(meal_amount);

	cout<<"\nEnter the percentage that you would like to tip: ";
	cin>>tip_rate;
	tip_rate = tip_rate/100; //convert tip rate from integer to decimal

	tip_amount = get_tip_amount(meal_amount, tip_rate);

	total = meal_amount + tax_amount + tip_amount;

	cout<<"\nMeal Amount:   $"<<meal_amount;
	cout<<"\nSales Tax:     $"<<tax_amount;
	cout<<"\nTip Amount:    $"<<tip_amount;
	cout<<"\nTotal:         $"<<total<<"\n\n";

	return 0;
}
