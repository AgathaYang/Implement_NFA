#include"stack1.h"
#include"infix_to_postfix1.h"
#include<string.h>
#include<iostream>
using namespace std;
void InToPost::setInfix(char infix[30])
{
	strcpy(in,infix); 
}

int InToPost::priority(char operation)		//將每個operaton的優先權設定出來
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
char* InToPost::in_to_post()	//中序轉後序
{
	int i=0,j=0;	//i:控制in[]的index  j:控制post[]的index
	int lengh_in=strlen(in);	//in[]的字串長度
	Stack s1;	//stack物件;
	op=in[i];
	while(i<lengh_in)
	{
		
		if(op>='a'&&op<='z')
		{
			post[j++]=op;
			if((in[i+1]>='a'&&in[i+1]<='z') || (in[i+1]=='('))//中間有'.'
			{
				op='.';	//create一個op為'.'
			}
			else //換下一個in
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
			{//如果現在的op的優先權是大於stack頂端的優先權或是stack是空的就push
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
			{//如果現在的op的優先權是大於stack頂端的優先權或是stack是空的就push
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
			while(s1.getTopElement()!='(')	//將全部的operation pop出來，直到最頂端是'('
			{
				post[j++] = s1.pop();
			}
			s1.pop();	//將'('pop出來
			i++;	//下一個in[]
			op=in[i];
		}
		else if(op=='*')
		{
			post[j++]=op;
			if(in[i+1]>='a'&&in[i+1]<='z')
			{	//*如果後面接字母中間有'.'
				op='.';	//create一個op為'.'
			}
			else
			{
				
				i++;	//下一個in[]
				op=in[i];
			}
			
		}
	}

	while(s1.getTop()!=0)//若stack沒完全清空要將內容都pop出來
	{
		post[j++] = s1.pop();
	}
	post[j]='\0';	//要加\0不然無法辨認字串結束
	return post;	//return 轉完的結果
}

char* InToPost::getPost()
{
	return post;
}
	