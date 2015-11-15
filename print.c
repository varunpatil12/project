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
#include"111.h"
#include<time.h>
extern FILE *fd;
void gotoxy(int x, int y)
{
	printf("\033[%d;%df", y, x);
	fflush(stdout);	
}  	
void printissue(issuestore *m)
{
 	gotoxy(13, 17);
	printf("Name %s ",m->name);
	gotoxy(13, 18);
	printf("Student %s ",m->sname);
	gotoxy(13, 19);
	printf("MIS %d ",m->MIS);
	gotoxy(13, 20);
	printf("Time %s ", m->time);
} 
void printsearch(tree searchnode){
	gotoxy(7, 15);
	printf("-----------------BOOK INFORMATION-----------------\n\n");
	printf("\tName    : %s\n", searchnode->name);
	printf("\tBook Id : %d\n", searchnode->Id);
	printf("\tAuthor  : %s\n", searchnode->Author);
	printf("\tRackno  : %d\n", searchnode->rackno);
	printf("\tQuantity: %d\n", searchnode->quantity);
	printf("\tPrice 	: %f\n", searchnode->price);
}			       													
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
int t(void) // checks for time 
{
time_t t;
time(&t);
printf("\nlogin time: \nDate and time:%s\n",ctime(&t));
return 0 ;
}
/*prints the bramch menu*/
void printmenu()
{
system("clear");
printf("\nSelect Your Category\n\n");
gotoxy(10, 5);
printf("1. COMPUTER\n");
gotoxy(10,7);
printf("2. MECHANICAL\n");
gotoxy(10,9);
printf("3. ENTC\n");
gotoxy(10,11);
printf("4. ELECTRICAL\n");
gotoxy(10,13);
printf("5. PRODUCTION\n");
gotoxy(10,15);
printf("6. INSTRUMENTATION\n");
gotoxy(10,17);
printf("7. METALLURGY\n");
gotoxy(10, 19);
printf("8. RETURN TO MAIN MENU");
gotoxy(10, 21);
}
