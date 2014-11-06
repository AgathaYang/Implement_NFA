#ifndef infix_to_postfix1_H  // 避免重覆包含標頭檔
#define infix_to_postfix1_H
#include<string.h>
class InToPost{
	public:
	char* in_to_post();
	void setInfix(char []);
	int priority(char);
	char* getPost();
	private:
		char op;
		char post[30];
		char in[30];
};
#endif