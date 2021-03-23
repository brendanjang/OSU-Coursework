/* CS261- Assignment 1 - Q. 3
 * Name:	Brendan Jang
 * Date:	04/13/2019
 * Solution description:	Program that meets the requirements of
 *							Assignment 1 Q3.
 */


#include <stdio.h>
#include <stdlib.h>

int isValidCharacter(int c) {
	if (('a' <= c && c <= 'z')
		|| ('A' <= c && c <= 'Z')
		|| c == '_') {
		return 1;
	}
	return 0;
}

/*Convert ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch) {
	return ch - 32;
}

/*Convert ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch) {
	return ch + 32;
}

/*Return the length of the string*/
int stringLength(char s[]) {
	int len = 0;
	while (s[len] != '\0') {
		len++;
	}
	return len;
}

/*Convert to camelCase*/
void camelCase(char *word) {
	int len = stringLength(word);

	int i = 0;
	int j = 0;

	/*Ignore suffix of invalid characters by decreasing len value*/
	while (len > 0 && !isValidCharacter(word[len - 1])) {
		len--;
	}

	/*Ignore prefix of invalid characters in word*/
	while (i < len && !isValidCharacter(word[i])) {
		i++;
	}

	/*Move to the end of the string and replace characters appropriately*/
	while (i < len) {
		if ('A' <= word[i] && word[i] <= 'Z') {
			word[j] = toLowerCase(word[i]);
			j++;
		}
		else if (word[i] == '_' || !isValidCharacter(word[i])) {
			if (j == 0 || word[j - 1] != '_') {
				word[j] = '_';
				j++;
			}
		}
		else {
			word[j] = word[i];
			j++;
		}
		i++;
	}
	len = j;
	word[len] = '\0';

	 /*Convert from snake case to camelCase*/
	int wordBegin = 0;
	i = 0;
	j = 0;
	while (i < len) {
		if (word[i] == '_') {
			/* discard underscore */
			wordBegin = 1;
		}
		else if (wordBegin) {
			wordBegin = 0;
			word[j] = toUpperCase(word[i]);
			j++;
		}
		else {
			word[j] = word[i];
			j++;
		}
		i++;
	}
	len = j;
	word[len] = '\0';
}

int main(void) {
	char word[1024];

	/*Read the string from the keyboard*/
	fgets(&word[0], sizeof word, stdin);

	for (int i = 0; word[i] != '\0'; i++) {
		if (word[i] == '\n' || word[i] == '\r') {
			word[i] = '\0';
		}
	}


	/*Call camelCase*/
	camelCase(&word[0]);

	/*Print the new string */
	int haveUpper = 0;
	for (int i = 0; word[i] != '\0'; i++) {
		if ('A' <= word[i] && word[i] <= 'Z') {
			haveUpper = 1;
			}
		}

	if (!haveUpper) {
		printf("invalid input string\n");
	}
	else {
		printf("%s\n", &word[0]);
	}
	return 0;
}
