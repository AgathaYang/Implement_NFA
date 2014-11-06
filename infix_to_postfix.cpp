#include"stack1.h"
#include"infix_to_postfix1.h"
#include<string.h>
#include<iostream>
using namespace std;
void InToPost::setInfix(char infix[30])
{
	strcpy(in,infix); 
}

int InToPost::priority(char operation)		//�N�C��operaton���u���v�]�w�X��
{
	int pri=0;
	switch(operation){
		case'*':
			pri=3;
			break;
		case'.':
			pri=2;
			break;
		case'|':
			pri=1;
			break;
		case'(':
			pri=0;
		

	}
	return pri;
}
char* InToPost::in_to_post()	//��������
{
	int i=0,j=0;	//i:����in[]��index  j:����post[]��index
	int lengh_in=strlen(in);	//in[]���r�����
	Stack s1;	//stack����;
	op=in[i];
	while(i<lengh_in)
	{
		
		if(op>='a'&&op<='z')
		{
			post[j++]=op;
			if((in[i+1]>='a'&&in[i+1]<='z') || (in[i+1]=='('))//������'.'
			{
				op='.';	//create�@��op��'.'
			}
			else //���U�@��in
			{
				i++;
				op=in[i];
			}
		}
		else if(op=='.')
		{
			//cout<<s1.getTopElement();
			//cout<<priority(op)<<priority(s1.getTopElement());
			if(priority(op)>priority(s1.getTopElement())||s1.getTop()==0)
			{//�p�G�{�b��op���u���v�O�j��stack���ݪ��u���v�άOstack�O�Ū��Npush
				s1.push('.');
			}
			else
			{
				post[j++]=s1.pop();
				s1.push('.');
			}
			i++;
			op=in[i];
			
		}
		else if(op=='|')
		{
			//cout<<priority(op)<<priority(s1.getTopElement());
			if(priority(op)>priority(s1.getTopElement())||s1.getTop()==0)
			{//�p�G�{�b��op���u���v�O�j��stack���ݪ��u���v�άOstack�O�Ū��Npush
				s1.push('|');
			}
			else
			{
				post[j++]=s1.pop();
				s1.push('|');
			}
			
			i++;
			op=in[i];

		}
		else if(op=='(')
		{
			s1.push('(');
			i++;
			op=in[i];
		}
		else if(op==')')
		{
			while(s1.getTopElement()!='(')	//�N������operation pop�X�ӡA����̳��ݬO'('
			{
				post[j++] = s1.pop();
			}
			s1.pop();	//�N'('pop�X��
			i++;	//�U�@��in[]
			op=in[i];
		}
		else if(op=='*')
		{
			post[j++]=op;
			if(in[i+1]>='a'&&in[i+1]<='z')
			{	//*�p�G�᭱���r��������'.'
				op='.';	//create�@��op��'.'
			}
			else
			{
				
				i++;	//�U�@��in[]
				op=in[i];
			}
			
		}
	}

	while(s1.getTop()!=0)//�Ystack�S�����M�ŭn�N���e��pop�X��
	{
		post[j++] = s1.pop();
	}
	post[j]='\0';	//�n�[\0���M�L�k��{�r�굲��
	return post;	//return �৹�����G
}

char* InToPost::getPost()
{
	return post;
}
	