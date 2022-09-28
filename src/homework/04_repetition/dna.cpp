//add include statements
#include "dna.h"

//function for calculating factorials
int get_factorial(int num1)
{
    int factorial = 1;
    while(num1 > 0)
    {
        factorial = num1 * factorial;
        num1--;
    }
    return factorial;
}

//function for calculating greatest common divisors
int get_greatest_common_divisor(int num1, int num2)
{
    while(num1 != num2)
    {
        if (num1 < num2)
        {
            num1 = num1+num2;
            num2 = num1-num2;
            num1 = num1-num2;
        }
        if (num1 > num2)
        {
            num1 = num1-num2;
        }
    }

    return num1;
}