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
/*header files */
#include<stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
#include<fcntl.h>      
#include<time.h>
#include"111.h"
#include"stack.h"
int cnt = 0;
FILE *datafile[10];
FILE *datafileissue[10];
FILE *fp;
FILE *fg;
FILE *fl;
int l, k;
int issuecnt = 0;
nodestore *temp, *current;
FILE *fpq,*fpa,*fp1,*fp2;
typedef struct{		//for user profile
	long int a_id;		/*account id for user*/
	char pass[25];
	char name[25];
	char email[100];
	int credits;	
	long long int p_no;		//phone no.
}user;
void home(){		/*home page*/
	printf("\n\t\t\t\t\tWELCOME!!!\n\n\nChoose an option from the menu:\n\n1.Administrative Login\n2.User Login\n3.Create an Account\n4.Exit\n\nEnter your choice:");
}
int elogin()
{
char g[25];
long int m;
int ch;
int flag;
int x;
	printf("\n\nenter your account_Id:");
	scanf("%ld", &m);
	printf("\nenter your password:");
	scanf("%s", g);
	if(strcmp(g, "admin") == 0)
	      return 1;
	return 0;	
		
}
int ulogin()		//user login
{
	char p[25];
	long int e;
	int ch;
	int flag;
	int x;
	int i = 0;
	t();
	printf("\n\nenter your account_Id:");
	scanf("%ld",&e);
	printf("\nenter your password:");
	scanf("%s",p);
	fpq = fopen("user123.txt","r+");
	if(fpq == NULL) 
		{
	printf("an error occured!\ttry again.");}
	else
	{
		rewind(fpq);
		user u;
		int flag;
		long int a;
	flag = 0;
	while(!feof(fpq))
	{
		fread(&u,sizeof(user),1,fpq);
 		if((u.a_id == e)&&(strcmp(u.pass, p)==0)&&(u.a_id != 0)){
			system("clear");
			printf("\n\n\t\tWelcome %s\nchoose an option from list:\n1.Edit profile\n2.Delete account\n3.View profile\n4.Acess Library\n5.Logout\n",u.name);
			flag = 1;
			x = 1;
			a = ftell(fpq);
			break;
		}
	}
	if(flag == 0){
		x = 0; 
		printf("account not found");
	}
	else
	{
	char another = 'c';
	int ch;
	scanf("%d", &ch);
	switch(ch){	
		case 1:
			printf("\nenter your name:");
			scanf("%s",u.name);
			printf("\nenter your e-mail Id:");
			scanf("%s",u.email);
			printf("\nenter your Phone no:");
			scanf("%lld",&(u.p_no));
			printf("\nenter a password for your account(max 25 characters):");
			scanf("%s",u.pass);
			fseek(fpq,(a+((-1)*sizeof(user))),0);
			fwrite(&u, sizeof(user), 1, fpq);
			printf("\n\n your account has been modified");
			fclose(fpq); 
			break;
		case 2: 
			u.a_id = 0;
			strcpy(u.pass,"");
			fseek(fpq,(a+((-1)*sizeof(user))),0); 
			fwrite(&u,sizeof(user),1,fpq);
			fclose(fpq);
			printf("\n\n your account has been deleted"); 
			break;
		case 3:
			printf("\n\nAccount Id:%ld\nName:%s\nemail:%s\nphone no:%lld\n",u.a_id,u.name,u.email, u.p_no);
			fclose(fpq);
			break;
		case 4:
			maintry();
			break;
		case 5:
			fclose(fpq);
			printf("\nyou have logged out succesfully");
			break;		
		default:
 			printf("\nwrong choice!! enter again");
	}
	if((ch==6)||(ch==3));
		}
		
	}
	if(!flag)
		return x;
		
}
void create()		//creating account
{
	user u;
	int i, x, s;
	int sum = 0;
	char c,p;
	printf("\033[2J\033[1;1H");
	gotoxy(20, 2);
	printf("Enter the information below");
	gotoxy(10, 3);
	printf("\nenter your name:");
	scanf("%s",u.name);
	gotoxy(10, 5);
	printf("\nenter your e-mail Id:");
	scanf("%s",u.email);
	gotoxy(10, 7);
	printf("\nenter your Phone no:");
	scanf("%lld",&(u.p_no));
	gotoxy(10, 9);
	printf("\nenter a password for your account(max 25 characters):");
	scanf("%s",u.pass);
	u.credits = 0;
	u.a_id=(rand()/1000);	
	fpq = fopen("user123.txt","a");
	if(fpq == NULL)
		 {
		printf("\nan error occured while creating account.\tplease try again");}
	else
	{
		fseek(fpq,0,2);
		fwrite(&u,sizeof(user),1,fpq);
		fclose(fpq);
		printf("\nyour account_id is:%ld\n\tACCOUNT CREATED SUCCESSFULLY",u.a_id);
	}
	scanf("%c",&c);
	scanf("%c",&p);
}
void norecur(tree t, int i)
{	
	stack s;
	nodestore *p;
	p = t;
	qinit(&s);
	while(1)
	{
		if(p){	
	 		 fwrite(p, sizeof(nodestore), 1, datafile[i]);
			 if(p->right)
				 push(&s , p->right);
		 	 p = p->left;
		}
		else if(!empty(&s)) {
			p = pop(&s);
		}
		else
			break;
	}		
}
void norecurissue(tree1 t, int i)
{
	issuestack m;
	issuestore *p;
	p = t;
	issueinit(&m);
	while(1)
	{
		if(p){		
	 		 fprintf(fl, "%s %s %s %d\n", p->name, p->sname, p->time, p->MIS);
			 if(p->right)
				 issuepush(&m , p->right);
		 	 p = p->left;
		}
		else if(!issueempty(&m)) {
			p = issuepop(&m);
		}
		else
			break;
	}		
}
void printsection(int i)
{
	if(i == 1)
		printf("****************WELCOME TO  THE COMPUTER SECTION*************************\n");
	else if(i == 2)
		printf("****************WELCOME TO  THE MECHANICAL SECTION***********************\n");
	else if(i == 3)
		printf("****************WELCOME TO  THE ENTC SECTION*************************\n");
	else if(i == 4)
		printf("****************WELCOME TO  THE ELECTRICAL SECTION*************************\n");
	else if(i == 5)
		printf("****************WELCOME TO  THE PRODUCTION SECTION*************************\n");
	else if(i == 6)
		printf("****************WELCOME TO  THE INSTRUMENTATION SECTION*************************\n");
	else if(i == 7)
		printf("****************WELCOME TO  THE METALLURGY SECTION*************************\n");
}
int main() {		//main function
	int ch, b, x;
	char c;
	while(1){
		system("clear");
		home();
		scanf("%d",&ch);
			if(ch == 4)
				break;
		switch(ch)
		{
			case 1:
				x = elogin();
				if(x == 0){
					printf("\tWarning!! Incorrect Password\n\n");
					printf("press c to continue ");
					getchar();
					scanf("%c", &c);
					break;	
				}
				b = 1;
				maintry(b);	
				break;
			case 2:
				ulogin();		
				break;
			case 3:
				create();
				break;
 			case 4:
				exit(0);					;
				break;
 			default:
				printf("\nwrong choice");
				break;
		}
	}			

}		

