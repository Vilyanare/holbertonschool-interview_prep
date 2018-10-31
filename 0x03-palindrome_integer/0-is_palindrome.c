#include "palindrome.h"

int is_palindrome(unsigned long n)
{
	int count = 0;
	unsigned long temp = n, topPower = 1, botPower = 10;

	while (temp != 0)
	{
		temp = temp % 10;
		if (temp > 9)
		{
			topPower *= 10;
		}
		count++;
	}
	temp = n;
	while (topPower >= botPower)
	{
		if (temp / topPower != temp % botPower)
		{
			return (0);
		}
		temp = temp % topPower;
		topPower /= 10;
		botPower *= 10;
	}
}
