#pragma once
#include <string>
#include <vector>
#include "user.h"

using namespace std;

class usertags
{
public:
	usertags(void);
	~usertags(void);
	void adduser(string user, string tag, string note = "");
	void importfile(char* filename);
	void exportfile();
	string gettag(string user);
	string gettag(int user);
	string getuser(string tag);
	string getuser(int tag);
	string getnote(string user);
	void setnote(string user, string note);
	user getwholeuser(string name);
	user getwholeuserfromtag(string tag);
	user getwholeuser(int user);
	void modifyuser(string user, string newtag);
	bool removeuser(string user);
	bool removeuser(int user);
	void listall();
	int size();
	string notes;
private:
	vector<user> users;
	char* file;
	bool importing;
};
