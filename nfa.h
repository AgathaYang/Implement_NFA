#ifndef nfa_H  // 避免重覆包含標頭檔
#define nfa_H
class NFA_Node
{
	public:
		

		int state;	//節點的state
		int state_type;	//state的type 1:start 2:normal 3:final
		char char_to_next;	//鍵頭的字串
		NFA_Node *next_state1;	//指標指向下一個node
		NFA_Node *next_state2;
		NFA_Node* To_NFA(char []);	//return start

		void Union();
		void concatenation();
		void kleene();
		void letter(char);
		
};
#endif