#include "StdAfx.h"
#include "usertags.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "user.h"

using namespace std;

usertags::usertags(void)
{
	importing = false;
}

usertags::~usertags(void)
{
}
void usertags::adduser(string newuser, string tag)
{
	users.push_back(user(newuser,tag));
	if(!importing)
		exportfile();
}
void usertags::adduser(string newuser, string tag, string note)
{
	users.push_back(user(newuser,tag,note));
	if(!importing)
		exportfile();
}
void usertags::importfile(char* filename)
{
	importing = true;
	file = filename;
	string name, tag, note;
	ifstream infile;
	if(ifstream(filename))
	{
		infile.open(filename);
		while(!infile.eof())
		{
			getline(infile,name);
			getline(infile,tag);
			getline(infile,note);
			adduser(name,tag,note);
		}
		infile.close();
		importing = false;
	}
	else
	{
		cout << "File " << (string)filename << " not found, creating\n";
		ofstream ofile;
		ofile.open(filename);
		ofile.close();
	}
}

void usertags::exportfile()
{
	ofstream ofile(file);
	for (int i = 0; i < (int)users.size(); i++)
	{
		ofile << users[i].getname() << "\n";
		ofile << users[i].gettag() << "\n";
		ofile << users[i].getnote();
		if(i < (int)users.size()-1)
			ofile << "\n";
	}
	ofile.close();
}

string usertags::gettag(string user)
{
	for(int i = 0; i < (int)users.size(); i++)
		if(users[i].getname() == user)
			return users[i].gettag();
	return user;
}
string usertags::getuser(string tag)
{
	for(int i = 0; i < (int)users.size(); i++)
		if(users[i].gettag() == tag)
			return users[i].getname();
	return tag;
}
string usertags::getuser(int user)
{
	if(user < (int)users.size() && user > -1)
		return users[user].getname();
	return "";
}

string usertags::gettag(int tag)
{
	if(tag < (int)users.size() && tag > -1)
		return users[tag].gettag();
	return "";
}

string usertags::getnote(string user)
{
	for(int i = 0; i < (int)users.size(); i++)
		if(users[i].getname() == user)
			return users[i].getnote();
	return user;
}

user usertags::getwholeuser(string name)
{
	for(int i = 0; i < (int)users.size(); i++)
		if(users[i].getname() == name)
			return users[i];
	return user();
}

user usertags::getwholeuserfromtag(string tag)
{
	for(int i = 0; i < (int)users.size(); i++)
		if(users[i].gettag() == tag)
			return users[i];
	return user();
}

user usertags::getwholeuser(int userid)
{
	if(userid < (int)users.size() && userid > -1)
		return users[userid];
	return user();
}
void usertags::modifyuser(string user, string newtag)
{
	for(int i = 0; i < (int)users.size(); i++)
		if(users[i].getname() == user)
			users.erase(users.begin()+i);
	adduser(user,newtag);
}
bool usertags::removeuser(string user)
{
	bool success = false;
	for(int i = 0; i < (int)users.size(); i++)
		if(users[i].getname() == user)
		{
			users.erase(users.begin()+i);
			success = true;
		}
	if(success)
		exportfile();
	else
		cout << "User could not be found\n";
	return success;
}

bool usertags::removeuser(int user)
{
	bool success = false;
	if(user < (int)users.size() && user > -1)
	{
		users.erase(users.begin()+user);
		exportfile();
		return true;
	}
	else
	{
		cout << "User could not be found\n";
		return false;
	}
}

void usertags::listall()
{
	for(int i = 0; i < (int)users.size(); i++)
	{
		cout << users[i].getname() << ":" << users[i].gettag() << endl;
	}
}

int usertags::size()
{
	return (int)users.size();
}