// Insert your code here by editing it online
//It will be more easy

#include<iostream>
#include<fstream>
#include<string>
#include<map>

using namespace std;

class book
{
	private:
		map<char,string>features;
	
	public:
		void settername(string name);
		string gettername();
		void setterid(string id);
		string getterid();
};

string book::gettername()
{
	return features['n'];
}

void book::settername(string name)
{
	features['n']=name;
}

class library
{
	private:
		map<char,book> collection;
		
	public:
		void setterbook(char index,book obj);
		book getterbook(string id);
		void removebook(string id);
};

void library::setterbook(char index,book obj)
{
		collection[index]=obj;
}

class person
{
	private:
		map<char,string> info;
	
	public:	
		void settername(string name);
		string gettername();
		void setterid(string id);
		string getterid();
		
	protected:
		
};

void person::settername(string name)
{
	info['n']=name;
}

string person::gettername()
{
	return info['n'];
}

string person::getterid()
{
	return info['i'];
}

void person::setterid(string id)
{
	info['i']=id;
}

class librarian:public person
{
	
};

class member:public person
{
	public:
		void leavemembership(string id, string name);
		void returnbook(book obj,int returndate);
		void issuebook(book obj,int issuedate);
};

int main(void)
{
	book obj;
	string name;
	cout<<"Please enter the name of the book:";
	cin>>name;
	obj.settername(name);
	cout<<endl<<obj.gettername()<<endl;
	librarian obj1;
	obj1.setterid("123456");
	obj1.settername("admin");
	cout<<"Librarian created..........."<<endl;
	cout<<"ID: "<<obj1.getterid()<<endl;
	cout<<"Name: "<<obj1.gettername()<<endl;
	ofstream outputfile("Library.txt");
	outputfile<<obj1.gettername()<<endl;
	outputfile<<"Alizain";
}
