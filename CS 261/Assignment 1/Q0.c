/* CS261- Assignment 1 - Q. 0*/
/* Name:	Brendan Jang
 * Date:	04/13/2019
 * Solution description:	Program that meets the requirements of
 *							Assignment 1 Q0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr) {

	/*Print the value and address of the integer pointed to by iptr*/
	printf("%d\n", *iptr);
	printf("%p\n", iptr);

	/*Increment the value of the integer pointed to by iptr by 5*/
	(*iptr) += 5;

	/*Print the address of iptr itself*/
	printf("%p\n", (&iptr));

	/*Dummy variable, ignore the warning*/
	int c = 5;
}


void fooB(int* jptr) {

	/*Print the value and address of the integer pointed to by jptr*/
	printf("%d\n", *jptr);
	printf("%p\n", jptr);

	/*Decrement the address by 1 pointed to by jptr using jptr */
	(jptr) -= 1;

	/*Print the address of jptr itself*/
	printf("%p\n", (&jptr));
}


int main() {

	/*Declare an integer x and initialize it randomly to a value in [0,10]*/
	srand(time(0));
	int x;
	x = rand() % 11;

	/*Print the value and address of x*/
	printf("%d\n", x);
	printf("%p\n", &x);

	/*Call fooA() with the address of x*/
	fooA(&x);

	/*Print the value of x*/
	printf("%d\n", x);

	/*Call fooB() with the address of x*/
	fooB(&x);

	/*Print the value and address of x*/
	printf("%d\n", x);
	printf("%p\n", &x);

	return 0;
}
