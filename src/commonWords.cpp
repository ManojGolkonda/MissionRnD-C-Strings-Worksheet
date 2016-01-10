/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".
INPUTS: Two strings.
OUTPUT: common words in two given strings, return 2D array of strings.
ERROR CASES: Return NULL for invalid inputs.
NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

char * wordExists(char * word, int start, int end, char * string) 
{
	int i = 0, j;
	while (string[i] && string[i] == ' ') 
		i++;
	while (string[i]) 
	{
		for (j = start; j <= end && word[j] == string[i] && string[i]; j++, i++);
		if (j == end + 1 && (string[i] == ' ' || !string[i])) 
		{
			// copying word to a new string and returning it
			char *str = (char *)malloc(sizeof(char)* SIZE);
			str[end - start + 1] = 0;
			while (start <= end)
				str[(end--) - start] = word[end];
			return str;
		}
		if (string[i] == ' ') 
			while (string[i] && string[i] == ' ') 
				i++;
		else 
		{
			while (string[i] && string[i] != ' ') 
				i++;
			while (string[i] && string[i] == ' ') 
				i++;
		}
	}
	return NULL;
}


char ** commonWords(char *str1, char *str2) 
{
	if (!str1 || !str1 || !(*str1) || !(*str2))
		return NULL;
	int i = -1, beginWord, count = 0;
	char **result = (char **)calloc(SIZE, sizeof(char*)), *temp;
	while (str1[++i]) 
	{
		if (str1[i] != ' ') 
		{
			beginWord = i;
			while (str1[++i] && str1[i] != ' ');
			if (temp = wordExists(str1, beginWord, i - 1, str2))
				*(result + count++) = temp;
		}
	}
	if (count > 0)
		return result;
	else
		return NULL;
}