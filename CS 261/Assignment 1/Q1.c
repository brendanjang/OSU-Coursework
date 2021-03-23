/* CS261- Assignment 1 - Q. 1*/
/* Name:	Brendan Jang
 * Date:	04/13/2019
 * Solution description:	Program that meets the requirements of
 *							Assignment 1 Q1.
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student {
	int id;
	int score;
};

struct student* allocate() {
	/*Allocate memory for ten students*/
	struct student *students = (struct student*) malloc(sizeof(struct student) * 10);

	/*Return the pointer*/
	return students;
}

void generate(struct student* students) {
	/*Generate random and unique IDs and random scores for ten students,
IDs being between 1 and 10, scores between 0 and 100*/
	int ids[10];

	for (int i = 0; i < 10; i++) {
		ids[i] = i + 1;
	}

	for (int i = 0; i < 10; i++) {
		int index = rand() % 10;
		while (ids[index] == 0) {
			index = rand() % 10;
		}
		students[i].id = ids[index];
		students[i].score = rand() % 101;
		ids[index] = 0;
	}

}

void output(struct student* students) {
	/*Output information about the ten students in the format:
			 ID1 Score1
			 ID2 score2
			 ID3 score3
			 ...
			 ID10 score10*/
	for (int i = 0; i < 10; i++) {
		printf("%d %d\n", students[i].id, students[i].score);
	}
}

void summary(struct student* students) {
	/*Compute and print the minimum, maximum and average scores of the
ten students*/
	int min = 100;
	int max = 0;
	int total = 0;
	float avg = 0.00;

	for (int i = 0; i < 10; i++) {
		if (min > students[i].score) {
			min = students[i].score;
		}
		if (max < students[i].score) {
			max = students[i].score;
		}
		total += students[i].score;
	}
	
	avg = total / 10.00;

	printf("The minimum score is: %d\n", min);
	printf("The maximum score is: %d\n", max);
	printf("The average score is: %.2f\n", avg); // Set precision to 2
}

void deallocate(struct student* stud) {
	/*Deallocate memory from stud*/
	if (stud != NULL) {
		free(stud);
	}
}

int main() {
	struct student* stud = NULL;

	/*Call allocate*/
	stud = allocate(stud);

	/*Call generate*/
	generate(stud);

	/*Call output*/
	output(stud);

	/*Call summary*/
	summary(stud);

	/*Call deallocate*/
	deallocate(stud);

	return 0;
}
