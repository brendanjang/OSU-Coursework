/* CS261- Assignment 2 - Part 3 stackapp.c*/
/* Name:	Brendan Jang
 * Date:	04/21/2019
 * Solution description:	Write a function that solves Part 3 using
 *							a stack.
 */

 /*	stack.c: Stack application.*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"
/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: 	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
	printf("String input: %s\n", s);

	if (s == NULL) {
		return 1;
	}

	char c = nextChar(s), top;
	DynArr* str = newDynArr(8);
	while (c != '\0') {
		if (!isEmptyDynArr(str)) {
			top = topDynArr(str);
		}
		if (c == '(' || c == '[' || c == '{') {
			pushDynArr(str, c);
		}
		if (c == ')' && top == '(') {
			if (isEmptyDynArr(str)) {
				return 0;
			}
			popDynArr(str);
		}
		if (c == ']' && top == '[') {
			if (isEmptyDynArr(str)) {
				return 0;
			}
			popDynArr(str);
		}
		c = nextChar(s);
	}
	if (isEmptyDynArr(str)) {
		deleteDynArr(str);
		str = 0;
		return 1;
	}
	else {
		deleteDynArr(str);
		str = 0;
		return 0;
	}
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");
	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

