/* CS261- Assignment 1 - Q. 2*/
/* Name:	Brendan Jang
 * Date:	04/13/2019
 * Solution description:	Program that meets the requirements of
 *							Assignment 1 Q2.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c) {
	/*Swap the addresses stored in the pointer variables a and b*/
	int *temp;
	temp = a;
	a = b;
	b = temp;

	/*Decrement the value of integer variable c*/
	c -= 1;

	/*Return c*/
	return c;
}

int main() {
	/*Declare three integers x,y and z and initialize them randomly 
	 * to values in [0,10] */
	srand(time(0));
	int x;
	int y;
	int z;

	x = rand() % 11;
	y = rand() % 11;
	z = rand() % 11;

	/*Print the values of x, y and z*/
	printf("x: %d y: %d z: %d\n", x, y, z);

	/*Call foo() appropriately, passing x,y,z as parameters*/
	int val = foo(&x, &y, z);

	/*Print the values of x, y and z*/
	printf("x: %d y: %d z: %d\n", x, y, z);

	/*Print the value returned by foo*/
	printf("value returned by foo: %d", val);

	return 0;
}

/* 4a. The return value is different that the value of integer z because z was 
passed by value into function foo and decremented while x and y were passed by 
reference. This means that the random value assigned to z is used and modified 
by foo, while the value of z is unchanged because the foo is unable to access 
it.
   4b. No, the value of x and y are the same after foo is called because the
the scope of a and b is local to function foo. The addresses are swapped
inside the function but will not reflect outside of it.*/
