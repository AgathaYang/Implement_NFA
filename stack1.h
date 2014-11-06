#ifndef stack1_H  // 避免重覆包含標頭檔
#define stack1_H

class Stack{
	public:
		//void readFile();	//讀出regular expression
		void push(char);	//push element ok
		char pop();		//pop element ok
		bool isEmpty();		//判斷stack是否空 ok
		bool isFull();		//判斷stack是否滿 ok
		char* getStack();		//將結果的stack拿出 ok
		int getTop();	//拿出top的值
		char getTopElement();	//拿出stack最頂端的值
		Stack();//constructor ok
	private:
		char stack[30];		//stack陣列
		int top; //stack top
};
#endif