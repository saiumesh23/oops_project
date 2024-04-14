#ifndef agent_h
#define agent_h
#include <iostream>
#include <string>
using std::string;
class Agent
{
	
	
	private :
		string id;
		int contact;
		
	public:
		void setid(string x){this->id=x;}
		void setcontact(int x){this->contact=x;}
		int getcontact()const{return this->contact;}
		string getid()const{return this->id;}
		void operator=(Agent &a);//operator is an overload assignment operator
		// In general, when you don't define your own overloaded assignment operator, the compiler generates one for you,
		//  which performs a shallow copy of each member variable. However, if your class contains dynamically allocated memory or resources that need proper management, 
		// you should typically define your own overloaded assignment operator to ensure correct behavior.
};
void Agent::operator=(Agent &a)
{
	setid(a.getid());
	setcontact(a.getcontact());
}
#endif
