
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
#include<string.h>
#include"111.h"
typedef struct rec {
	tree array[MAXQ];
	int front, rear;
}queue;
void init(tree *t) {
	(*t) = NULL;	
}
void initissue(tree1 *t) {
	(*t) = NULL;	
}

int count(tree t) {
	if(t == NULL)
		return 0;
	return 1 + count(t->left) + count(t->right);
}
int countissue(tree1 t) {
	if(t == NULL)
		return 0;
	return 1 + countissue(t->left) + countissue(t->right);
}

void preorder(tree t) {
	if(t == NULL)
		return;
	printf("%s ", t->name);	
	preorder(t->left);
	preorder(t->right);
}
void preorderissue(tree1 t) {
	if(t == NULL)
		return;
	printf("%s ", t->name);	
	preorderissue(t->left);
	preorderissue(t->right);
}
void insertissue(tree1 *t1, issuestore *y)
{
 	issuestore *p, *q;
	int direction;
	issuestore *tmp;
	tmp = (issuestore *)malloc(sizeof(issuestore));
	strcpy(tmp->name, y->name);
	strcpy(tmp->Author, y->Author);
	strcpy(tmp->time, y->time);
	strcpy(tmp->sname, y->sname);
	tmp->MIS = y->MIS;
	tmp->left = tmp->right = NULL;
	if(*t1 == NULL) {
		*t1 = tmp;
		return;
	}
	p = (*t1);
	while(p) {
		q = p;
		if(strcmp(p->name, y->name) < 0) {
			direction = RIGHT;
			p = p->right;
		}
		else {
			direction = LEFT;
			p = p->left;	
		}
	}
	if(direction == RIGHT)
		q->right = tmp;
	else
		q->left = tmp;
}
void insertname(tree *t, nodestore* y) {	
	nodestore *p, *q;
	int direction;
	nodestore *tmp;
	tmp = (nodestore *)malloc(sizeof(nodestore));
	strcpy(tmp->name, y->name);
	strcpy(tmp->Author, y->Author);
	tmp->price = y->price;
	tmp->Id = y->Id;
	tmp->quantity = y->quantity;
	tmp->rackno = y->rackno;
	tmp->left = tmp->right = NULL;
	if(*t == NULL) {
		*t = tmp;
		return;
	}
	p = (*t);
	while(p) {
		q = p;
		if(strcmp(p->name, y->name) < 0) {
			direction = RIGHT;
			p = p->right;
		}
		else {
			direction = LEFT;
			p = p->left;	
		}
	}
	if(direction == RIGHT)
		q->right = tmp;
	else
		q->left = tmp;
}
void removId(tree *t, int Id ) {
	nodestore *p, *q, *r, *rprev;
	int direction;
	p = *t;
	while(p) {
		if(p->Id < Id) {
			q = p;
			p = p->right;
			direction = RIGHT;	
		} 
		else if(p->Id > Id) {
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
	p->Id = r->Id;
	strcpy(p->name, r->name);
	strcpy(p->Author, r->Author);
	p->rackno = r->rackno;
	p->price = r->price;
	p->quantity = r->quantity;
	if(r == p->right) {
		p->right = r->right;	
	} else {
		rprev->left = r->right;
	}
	free(r);
}

void insertId(tree *t, nodestore* y) {
	nodestore *p, *q;
	int direction;
	nodestore *tmp;
	tmp = (nodestore *)malloc(sizeof(nodestore));
	strcpy(tmp->name, y->name);
	strcpy(tmp->Author, y->Author);
	tmp->price = y->price;
	tmp->Id = y->Id;
	tmp->rackno = y->rackno;
	tmp->left = tmp->right = NULL;
	if(*t == NULL) {
		*t = tmp;
		return;
	}
	p = (*t);
	while(p) {
		q = p;
		if(p->Id < y->Id) {
			direction = RIGHT;
			p = p->right;
		}
		else {
			direction = LEFT;
			p = p->left;	
		}
	}
	if(direction == RIGHT)
		q->right = tmp;
	else
		q->left = tmp;
}
tree1 searchissuename(tree1 *t, char* str)
{
	issuestore *temp;
	temp = *t;
	if(strcmp(temp->name, str) == 0)
	  {
	     printf("%s", str);
	     return temp;
	  }
	     if(temp == 0)
	        return NULL;
		   
	  if(strcmp(temp->name, str) < 0) {
	     searchissuename(&(temp->right), str);
	  }
	  else {
	  	 searchissuename(&(temp->left), str);
	  }		   
	     	
}

#define MAX(a,b) ((a)>(b)?(a):(b))
int depth(tree t) {
	if(t == NULL)
		return 0;
	return 1 + MAX(depth(t->left),depth(t->right));
}
tree searchname(tree *t, char* str)
{
	nodestore *temp;
	temp = *t;
	  if(temp == 0)
	        return NULL;
	if(strcmp(temp->name, str) == 0)
	  {
	     printf("%s", str);
	     return temp;
	  }	   
	  if(strcmp(temp->name, str) < 0) {
	     searchname(&(temp->right), str);
	  }
	  else {
	  	 searchname(&(temp->left), str);
	  }		   
	     	
}
tree searchId(tree *t, int Id)
{
	nodestore *temp;
	temp = *t;
	if(temp == 0)
	       return NULL;
	     
	
	if(temp->Id == Id)
	{
	     return temp;
	}
	  if(temp->Id < Id)
	  { 
	     searchId(&(temp->right), Id);
	 }
	  else
	  	 searchId(&(temp->left), Id);	   
	     	
}
int prompt()
{
	int ch;
	printf("PRESS 1 TO UPDATE\n");
	scanf("%d", &ch);
	if(ch == 1)
	   return 1;
	return 0;
}

tree modifyId(tree *t, tree* t1, int Id)
{
 	tree p, k;
	char str[80];
 	p = searchId(t1, Id);
	k = searchname(t, p->name); 
 	if(prompt()){	
		printf("\tBook Name :");
		scanf("%s", str);
		strcpy(k->name, str);
		strcpy(p->name, str);
		printf("\tAuthor name :");
		scanf("%s", p->Author);
		strcpy(k->Author, p->Author);
		printf("\tBook Id: ");
		scanf("%d", &(p->Id));
		k->Id = p->Id;
		printf("\tRack no: ");
		scanf("%d", &(p->rackno));
		k->rackno = p->rackno;
		printf("\tPrice: ");
		scanf("%f", &(p->price));
		k->price = p->price;
		printf("\tQuantity: ");
		scanf("%d", &(p->quantity));
		k->quantity = p->quantity;
	}												
}
tree modifyname(tree *t1, tree *t2, char* name)
{
 	tree p, k;
	char str[80];
 	p = searchname(t1, name);
	k = searchId(t2, p->Id);
 	if(prompt()){
			printf("\tBook Name :");
			scanf("%s", str);
			strcpy(p->name, str);
			strcpy(k->name, str);
			printf("\tAuthor name :");
			scanf("%s", p->Author);
			strcpy(k->Author, p->Author);
			printf("\tBook Id: ");
			scanf("%d", &(p->Id));
			k->Id = p->Id;
			printf("\tRack no: ");
			scanf("%d", &(p->rackno));
			k->rackno = p->rackno;
			printf("\tPrice: ");
			scanf("%f", &(p->price));
			k->price = p->price;
			printf("\tQuantity: ");
			scanf("%d", &(p->quantity));
			k->quantity = p->quantity;
	}												
}
