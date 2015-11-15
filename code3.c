/*****************************************************************************
 * Copyright (C) VARUN PATIL varunpat75@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include"111.h"
char *countfileissue = "countfileissue.txt";
/*prints the issue tree in sorted order */
void inorder(tree1 t) {
	if(t == NULL)
		return;
	inorder(t->left);
	printf("%s\t", t->name);
	printf("%s\t", t->sname);
	printf("%d\t", t->MIS);		
	inorder(t->right);
}
/*prints the tree in the sorted order*/
void print(tree t) {
	if(t == NULL)
		return;
	print(t->left);
	printf("%s\t", t->name);
	printf("%s\t", t->Author);
	printf("%d\t", t->Id);
	printf("%d\t", t->quantity);
	printf("%f\n", t->price);		
	print(t->right);
}
void remov(tree *t, char* name ) {
	nodestore *p, *q, *r, *rprev;
	int direction;
	p = *t;
	while(p) {
		if(strcmp(p->name, name) < 0) {
			q = p;
			p = p->right;
			direction = RIGHT;	
		} 
		else if(strcmp(p->name, name) > 0) {
			q = p;
			p = p->left;
			direction = LEFT;	
		}
		 else {  
			break;
		}
	}
	if(!p)
		return;
	if((*t)->left == (*t)->right) {
		free(*t);
		*t = NULL;
		return;
	}
	if(p->left == p->right) {
		if(direction == LEFT)
			q->left = NULL;
		else
			q->right = NULL;
		free(p);
		return;
	}
	if(p->left == NULL && p->right != NULL) {
		if(direction == LEFT)
			q->left = p->right;
		else
			q->right = p->right;
		free(p);
		return;
	}
	if(p->left != NULL && p->right == NULL) {
		if(direction == LEFT)
			q->left = p->left;
		else
			q->right = p->left;
		free(p);
		return;
	}
	r = p->right;
	while(r->left) {
		rprev = r;
		r = r->left;
	}
	strcpy(p->name, r->name);
	strcpy(p->Author, r->Author);
	p->Id = r->Id;
	p->price = r->price;
	p->rackno = r->rackno;
	p->quantity = r->quantity;
	if(r == p->right) {
		p->right = r->right;	
	} else {
		rprev->left = r->right;
	}
	free(r);
}

