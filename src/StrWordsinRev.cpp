/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void reverse(char *str, int start, int end)
{
	while (start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

void str_words_in_rev(char *input, int len){
	int i = 0, j = 0;
	reverse(input, 0, len - 1);
	while (input[j] != '\0')
	{
		if (input[j] == ' ')
		{
			reverse(input, i, j - 1);
			i = j + 1;
		}
		j++;
	}
	reverse(input, i, j - 1);
}
