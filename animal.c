//animal.c
//animal functions

#include "animal.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h> 

//create new tree
animal_tree new_tree(char *classification) 
{
	animal_tree *result = malloc(sizeof(animal_tree)); 
	assert(result != NULL); 
	result->classification = classification; 
	result->left = NULL;
	result->right = NULL; 
	animal_tree new;
	new = *result;
	
	return new; 
} 

//update tree
void update_tree(animal_tree *t, animal_tree *left, animal_tree *right)
{
	t->left = left;
	t->right = right;
	
}

