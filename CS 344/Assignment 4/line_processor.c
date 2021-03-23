#include <stdlib.h>
#include <stdio.h>
#include <string.h>




int main(void) {
	char* str1 = "Foo";
	char* str2 = "FooBar";
	int n = strlen(str1) < strlen(str2) ? strlen(str1) : strlen(str2);
	printf("%d, %d\n", n, strncmp(str1, str2, n));


}