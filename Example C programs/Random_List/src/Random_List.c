/*
 ============================================================================
 Name        : Random_List.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int students = 0;
int groupSize = 0;
int randomList[80];			// Array to hold the list of groups
int loopCount = 0;// This variable will count how many students we have put in the array
int loopCountInner = 0;	// This variable will count the students in each group
int thisRandomNumber;

void userdata(void) {
			setbuf(stdin, NULL); // this with the other setbuf is a workaround to resolve the printf not being displayed before scanf issue
			setbuf(stdout, NULL);

			printf( "Enter the number of students: \n");
				fflush(stdout);// needs to typed after every printf statement
			scanf("%d",&students);
				printf( "Enter the number that each team will consist of: \n");
			fflush(stdout);// needs to typed after every printf statement
				scanf("%d",&groupSize);
		}

void randlist(void) {

	while (loopCount < students) {
		thisRandomNumber = ((unsigned) rand() % students) + 1; // Modulus % will limit the random number to our range
															   // +1 so we can count from 1 in the class
		for (loopCountInner = 0; loopCountInner < loopCount; loopCountInner++) {
			if (randomList[loopCountInner] == thisRandomNumber) {// if this number has been used, do not add it twice
				break;
			}
		}
		if (loopCountInner == loopCount) {// if the loop above has finished this is a new number
			randomList[loopCount] = thisRandomNumber;
			loopCount++;
		}
		}
	}
void print(void) {

	for (loopCount = 0; loopCount < students;
			loopCount = loopCount + groupSize) {
		for (loopCountInner = 0;
				(loopCountInner < groupSize)
						&& ((loopCount + loopCountInner) < students);
				loopCountInner++) {
			printf("\t%i", randomList[loopCount + loopCountInner]);
		}
		printf("\n");
		}
		}

int main(void)

{
	// Take user values
	userdata();

	// Create random list
	randlist();

	// print list
	print();

	return 0;
}
