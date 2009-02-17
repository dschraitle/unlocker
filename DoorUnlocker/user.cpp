#include "StdAfx.h"
#include "user.h"
#include <string>

using namespace std;

user::user(void)
{
}

user::user(string nm, string tg, string note)
{
	name = nm;
	tag = tg;
	notes = note;
}

user::~user(void)
{
}

string user::getname()
{
	return name;
}

string user::gettag()
{
	return tag;
}

string user::getnote()
{
	return notes;
}

void user::setname(string n)
{
	name = n;
}

void user::settag(string t)
{
	tag = t;
}

void user::setnote(string nt)
{
	notes = nt;
}