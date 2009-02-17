#pragma once

#include <string>
using namespace std;

class user
{
public:
	user(void);
	user(string nm, string tg, string note = "");
	~user(void);
	string getname();
	string gettag();
	string getnote();
	void setname(string n);
	void settag(string t);
	void setnote(string nt);
private:
	string name;
	string tag;
	string notes;
};
