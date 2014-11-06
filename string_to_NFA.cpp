#include"infix_to_postfix1.h"
#include"nfa.h"
#include"stack1.h"
#include<iostream>
#include<string.h>
using namespace std;
NFA_Node *start[30]={NULL};
NFA_Node *ptr1,*ptr2;
int count=0;
int index=0;
int st=0;


void NFA_Node::letter(char lett) //³y¥X st->O->O 
{
	ptr1 = new NFA_Node;
	ptr2 = new NFA_Node;
	ptr1->state = st++;
	ptr1->state_type = 1;
	ptr1->next_state1 = ptr2;
	ptr1->next_state2 = NULL;
	ptr1->char_to_next = lett;
	ptr2->state = st++;
	ptr2->state_type = 3;
	ptr2->next_state1 = NULL;
	ptr2->next_state2 = NULL;
	ptr2->char_to_next = NULL;
	count+=2;

}
void NFA_Node::concatenation()
{
	NFA_Node *temp=NULL;
	temp = start[index-2];
	while(temp->next_state1!=NULL)
	{
		temp = temp->next_state1;
	}
	temp->next_state2 = NULL;
	temp->char_to_next = start[index-1]->char_to_next;
	temp->next_state1 = start[index-1]->next_state1;
	temp->state_type = 2;
	temp->state = st++;
	delete start[index-1];
	start[index-1]=NULL;
	//count--;
	 
}

void NFA_Node::kleene()
{
	NFA_Node *temp=NULL;
	temp=start[index-1];
	ptr1 = new NFA_Node;
	ptr2 = new NFA_Node;

	ptr1->char_to_next=NULL;
	ptr1->state_type=1;
	ptr1->next_state1=start[index-1];
	ptr1->next_state2=ptr2;
	ptr1->state = st++;
	while(temp->next_state1!=NULL)
	{
		temp = temp->next_state1;
	}
	temp->char_to_next=NULL;
	temp->next_state1=ptr2;
	temp->next_state2=start[index-1];
	temp->state_type=2;
	temp->state=st++;

	ptr2->char_to_next=NULL;
	ptr2->next_state1=NULL;
	ptr2->next_state2=NULL;
	ptr2->state_type=3;
	ptr2->state=st++;

	start[index-1]=ptr1;
	count+=2;
	
}

void NFA_Node::Union()
{
	NFA_Node *temp1,*temp2;
	ptr1 = new NFA_Node;
	ptr2 = new NFA_Node;
	temp1=start[index-2];
	temp2=start[index-1];

	ptr1->next_state1=start[index-2];
	ptr1->next_state2=start[index-1];
	ptr1->char_to_next=NULL;
	ptr1->state_type=1;
	ptr1->state=st++;

	start[index-1]->state_type=2;
	start[index-2]->state_type=2;
	while(temp1->next_state1!=NULL)
	{
		temp1=temp1->next_state1;
	}
	temp1->next_state1=ptr2;
	temp1->char_to_next=NULL;
	temp1->state_type=2;
	temp1->next_state2=NULL;
	temp1->state=st++;
	while(temp2->next_state1!=NULL)
	{
		temp2=temp2->next_state1;
	}
	temp2->next_state1=ptr2;
	temp2->char_to_next=NULL;
	temp2->state_type=2;
	temp2->next_state2=NULL;
	temp2->state=st++;

	ptr2->state_type = 3;
	ptr2->char_to_next=NULL;
	ptr2->next_state1=NULL;
	ptr2->next_state2=NULL;
	ptr2->state=st++;
	start[index-2]=ptr1;
	start[index-1]=NULL;
	count+=2;


}

NFA_Node* NFA_Node::To_NFA(char postfix[30])
{
	int post_lengh=strlen(postfix);
	int i=0;
	
	while(i<post_lengh)
	{
		if(postfix[i]>='a'&&postfix[i]<='z')
		{
			letter(postfix[i]);
			start[index]=ptr1;
			index++;
		}
		else if(postfix[i]=='.')
		{
			concatenation();
			index--;
		}
		else if(postfix[i]=='|')
		{
			Union();
			index--;
		}
		else if(postfix[i]=='*')
		{
			kleene();
		}

		i++;
	}
	
	cout<<"("<<count<<" nodes)"<<endl;
	
	count=0;
	st=0;
	index=0;

	return start[0];
	
}

