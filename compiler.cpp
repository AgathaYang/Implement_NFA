#include "stack1.h"
#include "nfa.h"
#include"infix_to_postfix1.h"
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<iostream>
using namespace std;
void main()
{
	InToPost s1;
	NFA_Node a1;
	char a[30];
	char first;
	FILE *fptr;
	cout<<"File loading...\n"<<endl;
	if ((fptr = fopen("input.txt", "r")) == NULL)
	{
        puts("failed!");
        puts("input.txt not found!");
        return ;
    }
	while(fscanf(fptr, "%c", &first) != EOF)
	{
		if(first==':')
		{
			fscanf(fptr," %s", a);
			
			s1.setInfix(a);
			cout<<"# REG: "<<a<<"; "<<"POST-ORDER: "<<s1.in_to_post()<<endl;
			
			cout<<"# NFA created sucessful ";
			a1.To_NFA(s1.in_to_post());
			cout<<endl;
		}
		
	}
	puts("OK!");
	fclose(fptr);
	
	return ;
};