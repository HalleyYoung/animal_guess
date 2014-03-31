#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "animal.h"


int main (int argc, char **argv)
{
	char yn[3]; //stores yes/no answers in game	
	char again[3];//stores whether will play again

	printf("Welcome to the animal game!  Think of an animal, and I will try to guess it.\n");

	//build initial question tree
	animal_tree t = new_tree("Does the animal bark?"); //first question
	animal_tree l = new_tree("horse"); //first "no" answer
	animal_tree r = new_tree("dog"); //first "yes" answer
	update_tree(&t, &l, &r);

	do 
	{

		animal_tree *p = &t; //pointer used for traversing tree
		char *bottom = t.classification;

		do //while there are children elements
		{
			printf("%s (y/n)\n", bottom); //ask the question
			fgets(yn, 3, stdin); //get the answer
			//the left child contains the "no answer", while the right contains the yes answer
			if (strcmp("n\n", yn) == 0)
			{
				p = p->left; 
			}
			else if (strcmp("y\n", yn) == 0)
			{
				p = p->right;
			}
			bottom = p->classification;
		} while (p->left != NULL); //stop when there are no more child elements
	
		printf("Your animal is a %s.\nIs this correct? (y/n)\n", bottom); //checking answer
		fgets(yn, 3, stdin);
		if (strcmp("y\n", yn) == 0)
			printf("I win!\n");
		else
		{
			printf("I lose.\nWhat was the correct answer?\n");
			char correct_answer[100]; 
			fgets(correct_answer, 100, stdin);
			strtok(correct_answer, "\n"); //necessary in order to avoid storing the new animal with the newline
			//request something that is true for the animal the user was considering but not the stored animal
			printf("What is a question where the answer is yes for a %s but not for a %s?\n", correct_answer, bottom); 
			char *new_question = (char *) calloc(100, sizeof(char));
			fgets(new_question, 100, stdin);
			strtok(new_question, "\n");

			//update the animal_tree
			animal_tree old_animal = new_tree(p->classification);
			animal_tree new_animal = new_tree(correct_answer);
			p ->classification = new_question;
			p->left = &old_animal;
			p->right = &new_animal;
		}
		
		printf("\nDo you want to play again? (y/n) ");
		fgets(again, 3, stdin);	
	
	} while (strcmp("y\n", again) == 0);

	exit(0);
}	
