#ifndef stack1_H  // �קK���Х]�t���Y��
#define stack1_H

class Stack{
	public:
		//void readFile();	//Ū�Xregular expression
		void push(char);	//push element ok
		char pop();		//pop element ok
		bool isEmpty();		//�P�_stack�O�_�� ok
		bool isFull();		//�P�_stack�O�_�� ok
		char* getStack();		//�N���G��stack���X ok
		int getTop();	//���Xtop����
		char getTopElement();	//���Xstack�̳��ݪ���
		Stack();//constructor ok
	private:
		char stack[30];		//stack�}�C
		int top; //stack top
};
#endif