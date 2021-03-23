#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int length;
    char arr[27];
    int index;
    // bad argument
	if (argc < 2)
    {
        exit(0);
    }
	// set up array of legal characters
    for (size_t i = 0; i < 26; i++)
    {
        arr[i] = 'A' + i;
    }
    arr[26] = ' ';        
	
	// get size of the key
    length = atoi(argv[1]);

	// generate the key
    for (size_t i = 0; i < length; i++)
    {
        index = rand() % 27;
        fprintf(stdout, "%c", arr[index]);
    }
	// print it to screen with a new line character
    fprintf(stdout, "\n");

    return 0;
}
