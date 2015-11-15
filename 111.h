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
#define RIGHT 1
#define LEFT  2

#define MAXQ 128
#ifndef __tree_h
#define __tree_h
typedef struct nodestore{
        char name[100];
        char Author[100];
        int rackno;
	int Id;
        int quantity;
        float price;
	struct nodestore *left, *right;
}nodestore;
typedef struct store
	{
          char name[100];
          char Author[100];
          int rackno;
          int Id;
       	  int quantity;
          float price;
       }store;	
typedef struct nodestore *tree;
#endif 
#define SIZE 128
typedef struct stack
{
	nodestore *a[SIZE];
	int i;
}stack;

#ifndef __tree1_h
#define __tree1_h
typedef struct issuestore{
	char sname[100];
        char name[100];
        char Author[100];
	char time[16];
	int MIS;
	struct issuestore *left, *right;
}issuestore;	
typedef struct issuestore *tree1;
void initissue(tree1 *t);
void insertissue(tree1 *t, issuestore* a);
void preorderissue(tree1 t);
int countissue(tree1 t); 
#endif 
typedef struct issuestack
{
	issuestore *a[SIZE];
	int i;
}issuestack;
void issueinit(issuestack *s);
void issuepush(issuestack *s, issuestore*);
issuestore* isspop(issuestack *s);
int issueempty(issuestack *s);
