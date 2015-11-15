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
#include<stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
#include<fcntl.h>      
#include<time.h>
#include"11.h"
typedef struct issue
{
 char name1[16];
 char sname1[16];
 char time1[16];
}issue;
issue *st;
extern FILE *fg, *fp;
extern FILE *fl;
extern FILE *datafile[10];
extern FILE *datafileissue[10];
extern nodestore *temp;
int maintry(int elogin) {
int i;
int j = 0;
int x[10];
int y[10];
/*files for storing the library data for different branches in different files*/
char *filename[8];
	filename[1] = "countcomp22.dat";
	filename[2] = "countmech12.dat";
	filename[3] = "countinstru12.dat";
	filename[4] = "countprod12.dat";
	filename[5] = "countelec12.dat";
	filename[6] = "countentc12.dat";
	filename[7] = "countmeta12.dat";
	char *countfile = "countfile.txt";
char *filenameissue[8];
	filenameissue[1] = "countcomp2issue2.txt";
	filenameissue[2] = "countmech2issue2.txt";
	filenameissue[3] = "countinstru2issue2.txt";
	filenameissue[4] = "countprod2issue2.txt";
	filenameissue[5] = "countelec2issue2.txt";
	filenameissue[6] = "countentc2issue2.txt";
	filenameissue[7] = "countmeta2issue2.txt";
int chsearch,  chmodify;
char c, z;
/*Declaration of all trees with name as key*/
	tree t1[8];
/*Declaration of all trees with id as key*/
	tree t2[8];
/*Declaration of all trees issued*/
	tree t3[8];
/*declaration of trees storing time*/
	tree1 t4[8];
int Id;
char name[16];
tree1 tr;
initissue(&tr);
tree searchnode, p, g;
tree1 m; 
issuestore *ia;
issuestore *tmp;
int  chissue;
char str[16];
int k = 0, l = 1;
/* initialises all trees*/
for(i = 1;i < 8; i++){	
	init(&t1[i]);
	init(&t2[i]);
	init(&t3[i]);
	initissue(&t4[i]);
}
int d, h;
fp = fopen("abe.txt", "r");
	for(k = 1; k < 8; k++){
		fread(&d, sizeof(int), 1, fp);
		x[k] = d;
	}
for(i = 1; i < 8; i++) {
	datafile[i] = fopen(filename[i], "r");
	if(datafile[i])	 
		{
		j = 0;	      		
		rewind(datafile[i]);			
	    	while(j < x[i]) 
     	    	{
		   	temp = (nodestore *)malloc(sizeof(nodestore));
			fread(temp, sizeof(nodestore), 1, datafile[i]);	
		   	insertname(&t1[i], temp);
			insertId(&t2[i], temp);	
			j++;		
		}   
		fclose(datafile[i]);
	}
}
	    		 // close file - good practice to close files after use
fg = fopen("abm.txt", "r");
	for(l = 1; l < 8; l++) {
		fscanf(fg, "%d", &h); 
		y[l] = h;
	}
fclose(fg);	 
for(l = 1; l < 8; l++) {
	fl = fopen(filenameissue[l], "r");
	if(fl){
		k  = 0;
		rewind(fl);
		while(k < 5) {
			tmp = (issuestore *)malloc(sizeof(issuestore));
			fscanf(fl, "%s %s %s %d", tmp->name, tmp->sname, tmp->time, &(tmp->MIS));
			tmp->left = tmp->right = NULL;
			insertissue(&t4[l], tmp);
			k++;			
		}		   			 		    
	        fclose(fl);
	}
}
/*stores the information of the book in the node of tree*/
nodestore* addbooks()
{	
	int i = 0;
	printf("\033[2J\033[1;1H");
	nodestore *ta;
	ta = (nodestore*)malloc(sizeof(nodestore));
	gotoxy(15, 10);
	printf("Book name: ");
	scanf("%s", ta->name);
	gotoxy(15, 11);
	printf("Author name: ");
	scanf("%s", ta->Author);
	gotoxy(15, 12);
	printf("Quantity: ");
	scanf("%d", &(ta->quantity));
	gotoxy(15, 13);
	printf("Book Id: ");
	scanf("%d", &(ta->Id));
	gotoxy(15, 14);
	printf("Rack no: ");
	scanf("%d", &(ta->rackno));
	gotoxy(15, 15);
	printf("Price: ");
	scanf("%f", &(ta->price));
	ta->left = ta->right = NULL;
	return ta;
}
/*fuction for date of issue*/ 
char* date()
{
	time_t now;
	struct tm *tm_now;
	char buff[32];
	now = time(NULL);
	tm_now = localtime(&now);
	strftime(buff, sizeof buff, "%a-%d-%m-%Y", tm_now);
	strcpy(str, buff);
	return str;
}
/*saves all the data including modifications, deletions in the file*/
void save() { 				
	datafile[i] = fopen(filename[i], "w");
	norecur(t1[i], i);
	fclose(datafile[i]);
	int g;
	fp = fopen("abe.txt", "w");
	for(i = 1;i < 8; i++) {
	g = count(t1[i]);				
	fwrite(&g, sizeof(int), 1, fp);
	}
	fclose (fp);
}
/*checks if the system login was done by admins*/
if(elogin == 1){		     	        	
while(1) {
	printmenu();
	int ch, v;
	char c = 'y';
	gotoxy(10,21);
	printf("enter your choice");
	scanf("%d", &i);

		if(i == 8)
			break;	
		while(1) {
			system("clear");
			gotoxy(5, 1);
			printsection(i);
			gotoxy(10,3);
			printf("1. Insertion\n");
			gotoxy(10,5);
        		printf("2. Deletion\n");
			gotoxy(10,7);
			printf("3. Search \n");
			gotoxy(10,9);
			printf("4. Modify\n");
			gotoxy(10,11);
			printf("5. IssueBooks\n");
			gotoxy(10,13);
			printf("6. View Books\n");
			gotoxy(10,15);
			printf("7. Save And Quit\n");
			gotoxy(10,19); 
			printf("Enter Your Choice");
			scanf("%d", &ch); 	
			switch(ch) {		
				case 1:	 /*insert the node in the tree according to the branch*/
					{	
					nodestore *sa;	
					sa = addbooks();			
					insertname(&t1[i], sa);
					insertId(&t2[i], sa);
					}
					break;
				case 2: /*removes the node in the tree*/
					printf("Book name ");
					scanf("%s", name);
					print(t1[i]);
					searchnode = searchname(&t1[i], name);
					remov(&t1[i], name);
					removId(&t2[i], searchnode->Id);
					break;
				 case 3:  {/*searches the books in the tree. two trees are used for more efficiency*/
					char c = 'y';
					while(c == 'y') {	
						system("clear");
						gotoxy(10, 5);						
						printf("1. Search BY Id\n");
						gotoxy(10, 7);
						printf("2. Search By Name\n");
						gotoxy(10, 9);
						printf("enter your choice");
						scanf("%d", &chsearch); 
						switch(chsearch){
							case 1:	/*Search the book by Id*/
								gotoxy(10, 11);
    								printf("enter the book id: ");
								scanf("%d", &Id);
								searchnode = searchId(&t2[i], Id);
								inorder(t1[i]);
								if(searchnode) 
									printsearch(searchnode);			       					
								else
									printf("Record Not Found");							
	                					break;
							case 2:/*Search the book by name*/
								gotoxy(10, 11);
							 	printf("enter the book name: ");
								scanf("%s", name);
								searchnode = searchname(&t1[i], name);
								if(searchnode)
									printsearch(searchnode);			       						
								else
									printf("Record Not Found");
								printf("\n");
								break;
						}
						printf("Try for another search? (Y/N/)");
						getchar();
						scanf("%c", &c);
					}
			}
						break;	     	
                         		case 4:/*modifies the book information */
						while(c == 'y') {
							system("clear");
							gotoxy(10, 5);
							printf("1. Modify By Name\n");
							gotoxy(10, 7);
							printf("2. Modify By Id\n");
							gotoxy(10, 9);
							printf("enter your choice");
							scanf("%d", &chmodify);
							switch(chmodify) {
								case 1: //modify books by searching for Name..
									gotoxy(10, 11);
									printf("enter the book name to modify");
									scanf("%s", name);
									modifyname(&t1[i], &t2[i], name);
									break;
								case 2: //modify books by searching for id..
									gotoxy(10, 11);
									printf("enter the book Id to modify");
									scanf("%d", &Id);
									modifyId(&t2[i], &t2[i], Id);
									break;
							}
								printf("Try for another Update? (Y/N/) ");
								getchar();
								scanf("%c", &c);
						}
								break;
					case 5: {
						char c = 'y';
						while(c == 'y') {	
							system("clear");	
							printf("\n********Issue Book section******\n");
							gotoxy(10, 3);
							printf(" 1. Issue a Book\n");
							gotoxy(10, 5);
    							printf(" 2. Remove Issued Book\n");
							gotoxy(10, 7);
    							printf(" 3. Search Issued Book\n");
							gotoxy(10, 9);
    							printf(" 4. Save And Quit\n");
							gotoxy(10, 11);
    							printf("Enter a Choice:");
    							scanf("%d", &chissue);
    							switch(chissue)
    								{
								case 1:  /*issue book in  a issue tree*/
									printf("enter the book name");
									scanf("%s", str);
									preorderissue(t4[i]);
									int a = 0;
									searchnode = searchname(&t1[i], str);
									if(searchnode) {
										printsearch(searchnode);
										if(searchnode->quantity <= 0) {
											printf("Sorry! All books are already issued.\n");
											a = 1;
										}
										if(a == 1)
											break;
										ia = (issuestore*)malloc(sizeof(issuestore));
				      						printf("Student Name :");
				      						scanf("%s", ia->sname);
										printf("MIS :");	
										scanf("%d" ,&(ia->MIS));	
										strcpy(ia->name, searchnode->name);
										strcpy(ia->Author, searchnode->Author);
										strcpy(str, date());
										strcpy(ia->time, str);
										insertissue(&t4[i], ia);
										preorderissue(t4[i]);
										printf("%s", ia->time);	
										/*reduces quantity of avilable books as it is issued*/	
										searchnode->quantity = (searchnode->quantity) - 1;
				     					}
									else {
										printf("No record available");
									}						
									break;
								case 2: /* return issued book*/			
									printf("enter the book name to delete");
									scanf("%s", str);
									remov(&t4[i], str);
									p->quantity = p->quantity + 1; /*updates the quantity  of book after returning*/
									break;
								case 3:
						    			/* search issued books by Name*/
									printf("Book Name\n");
									scanf("%s", str);
									m = searchissuename(&t4[i], str); 
									if(m)
										printissue(m);   	
									else {
										printf("No Such record issued");
									}	
									break;
								case 4:					
									fl = fopen(filenameissue[i], "w");
									norecurissue(t4[i], i);
									fclose(fl);
									break;
								default:
                                					printf("U have entered wrong option!!\n");
                                					break;
								}
							if(chissue == 4)
								break;
							printf("Try For Another Issue? (Y/N/)");
							getchar();
							scanf("%c", &c);
						}
					}	
							break;
					case 6:
						/*shows the entire books of this branch*/
						system("clear");
						print(t1[i]);
						printf("Press c to Continue (c)");
						getchar();
						scanf("%c", &z);
						break;
					case 7:
						save();
						break;			
					default:
                                		printf("U have entered wrong option!!\n");
                                		break;		
					}	
					if(ch == 7)
						break;					
			   	 }
					
			}
	}
	/*if the sysytem login was done by user*/
	else if(elogin == 0){									
		printmenu();
		int ch, v;
		char c = 'y';
		gotoxy(10,21);
		printf("enter your choice");
		scanf("%d", &i);
		printf("\033[2J\033[1;1H");		
		printsection(i);
			while(c == 'y') {	
					if(i == 8)
						break;			
						printf("\033[2J\033[1;1H");
						gotoxy(10, 1);
						printf("SEARCH BOOKS");
						gotoxy(10, 5);						
						printf("1. Search BY Id\n");
						gotoxy(10, 7);
						printf("2. Search By Name\n");
						gotoxy(10, 9);
						printf("enter your choice");
						scanf("%d", &chsearch); 
						switch(chsearch){
							case 1:	
								gotoxy(10, 11);
    								printf("enter the book id\n");
								scanf("%d", &Id);
								searchnode = searchId(&t2[i], Id);
								if(searchnode) 
									printsearch(searchnode);			       					
								else
									printf("Record Not Found");							
	                					break;
							case 2:
								gotoxy(10, 11);
							 	printf("enter the book name: ");
								scanf("%s", name);
								searchnode = searchname(&t1[i], name);
								if(searchnode)
									printsearch(searchnode);			       						
								else
									printf("Record Not Found");
								printf("\n");
								break;
							}
						printf("try for another search? (Y/N/)");
						getchar();
						scanf("%c", &c);
					}
		return;	
		}	
									
    	      return 0;
	
 }      
