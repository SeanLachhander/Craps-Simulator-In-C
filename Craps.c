/* This C program will simulate the game of craps
 * Sean Lachhander
 * February 23, 2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 7
#define numFACES 6

int main (void)
{
	int i, dieOne, dieTwo, total, Attempt=1, sum, first;
	int frequency[SIZE];  // Declares array of frequency of SIZE
	for(i=0; i<numFACES; i++)
	{
		frequency[i] = 0;
	}
	srand(time(NULL));   // Random number generator


	while(1)
	{
		dieOne = (1+rand() % numFACES);   // Random number from 1-6 for dieOne
		dieTwo = (1+rand() % numFACES);   // Random number from 1-6 for dieTwo
		total = dieOne + dieTwo;    // gives variable total the sum of dieOne and dieTwo
		sum = total;   // sum is equal to total.



	if(Attempt==1 && (total == 7 || total == 11))  // When the attempt is the first attempt, this if statement is run. It will declare the user a winner if it is a 7 or 11.
	{
		printf("You rolled: %d\n", total);
		printf("YOU WIN!\n");     // Prints to the user he/she won.
		exit(0);    // exits the program.
	}

	else if(Attempt==1 && (total == 2 || total == 3 || total == 12)) // If in Attempt 1, the total is equal to 2, 3, or 12, it will tell the user he/she lost.
	{
		printf("You rolled: %d\n", total);
		printf("YOU LOSE!\n");
		exit(0);
	}

	else if(Attempt==1)   // If none of the above cases apply, this if statement will be ran, it will tell the user what he rolled, and store the total in frequency[attempt].
	{
		printf("You rolled: %d\n", total);
		frequency[Attempt] = total;
		first = sum;  // The first variable is now also equal to the sum variable.
		printf("You point is %d\n", sum);
		Attempt++; // Increments Attempt by one.
	}


	else if(Attempt>1 && (sum!=first && sum!=7))   // If attempt is greater than 1, and sum is not equal to the variable first and not equal to 7, this will be ran.
	{
		printf("You rolled: %d\n", total); // Prints to the user what he/she rolled.
	}

	else if(Attempt>1 && (sum==first || sum == frequency[Attempt])) // if the attempt is greater than 1, AND (the sum is the same value of first OR the sum is equivalent to the value in frequency[Attempt]
	{
		printf("You rolled: %d\n", total);  // prints what you rolled.
		printf("YOU WIN!\n");  // prints to the user you win!
		exit(0);  // exits the program.
	}

	else if(Attempt>1 && sum==7)   // If the attempt is greater than one, AND the sum is equal to 7 this will run.
	{
		printf("You rolled: %d\n", total);   // Prints what the user rolled.
		printf("YOU LOSE!\n");   // Prints to the user to let him know he lost.
		exit(0);
	}
	}
}
