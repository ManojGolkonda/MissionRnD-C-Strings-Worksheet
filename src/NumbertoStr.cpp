/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>


void number_to_str(float number, char *str,int afterdecimal){
	int i = 0, temp, a[10], j = 0;
	if (number < 0)
	{
		str[i++] = '-';
		number *= -1;
	}
	temp = (int)number;
	while (temp)
	{
		a[j++] = temp % 10;
		temp /= 10;
	}
	while (j)
	{
		str[i++] = '0' + a[--j];
	}
	if (afterdecimal > 0)
	{
		str[i++] = '.';
		int temp1 = (int)number;
		while (afterdecimal)
		{
			temp1 *= 10;
			number *= 10;
			afterdecimal--;
		}
		temp = (int)(number - temp1);
		while (temp)
		{
			a[j++] = temp % 10;
			temp /= 10;
		}
		while (j)
		{
			str[i++] = '0' + a[--j];
		}
	}
}
