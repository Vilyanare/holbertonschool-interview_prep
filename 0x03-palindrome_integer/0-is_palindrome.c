#include "palindrome.h"

/**
 * is_palindrome - Check if a number is a palindrome
 * @n: Number to check
 * Return: 1 if palindrome otherwise 0
 */
int is_palindrome(unsigned long n)
{
	int count = 0;
	unsigned long temp = n, topPower = 1, botPower = 10;

	while (temp != 0)
	{
		if (temp > 9)
		{
			topPower *= 10;
		}
		temp = temp / 10;
		count++;
	}
	temp = n;
	while (topPower >= botPower)
	{
		if (temp / topPower != temp % botPower)
		{
			return (0);
		}
		temp %= topPower;
		temp /= 10;
		topPower /= 100;
	}
	return(1);
}
