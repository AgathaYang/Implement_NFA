#include"stack1.h"
#include<string.h>
#include<iostream>
using namespace std;

Stack::Stack(){
	top=0;
}
char* Stack::getStack(){
	return stack;
}
int Stack::getTop(){
	return top;
}
void Stack::push(char c){
	stack[top]= c ;
	
	if(isFull()==true){
		cout<<"stack is full\n"<<endl;
	}
	top++;

}
char Stack::pop(){
	if(isEmpty()==true){
		cout<<"stack is empty\n";
	}
	top--;
	return stack[top];
}
bool Stack::isEmpty(){
	
	if(top==0)return true;
	else return false;
}
bool Stack::isFull(){
	if(top>30) return true;
	else return false;
}
char Stack::getTopElement(){
	return stack[top-1];
}


