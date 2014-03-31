//animal.h
//interface file for animal program

#ifndef ANIMAL_H 
#define ANIMAL_H

typedef struct animal_tree
{
	char *classification; //either a question or animal name
	struct animal_tree *left; //left child
	struct animal_tree *right; //right child
	
} animal_tree; 

animal_tree new_tree(char *class);

void update_tree(animal_tree *t, animal_tree *left, animal_tree *right); //update the tree's left and right node

void add_question(animal_tree *t, char *new_q, animal_tree *new_animal, animal_tree *old_animal); //add question to the tree


#endif
