#ifndef nfa_H  // �קK���Х]�t���Y��
#define nfa_H
class NFA_Node
{
	public:
		

		int state;	//�`�I��state
		int state_type;	//state��type 1:start 2:normal 3:final
		char char_to_next;	//���Y���r��
		NFA_Node *next_state1;	//���Ы��V�U�@��node
		NFA_Node *next_state2;
		NFA_Node* To_NFA(char []);	//return start

		void Union();
		void concatenation();
		void kleene();
		void letter(char);
		
};
#endif