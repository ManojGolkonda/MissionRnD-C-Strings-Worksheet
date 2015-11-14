/*nu
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#define NULL 0

char KthIndexFromEnd(char *str, int K) {
	if (str == NULL || str[0] == '\0' || K < 0)
		return '\0';
	int i = 0;
	while (str[i] != '\0')
		i++;
	if (K < i)
		return str[i - K - 1];
	return '\0';
}