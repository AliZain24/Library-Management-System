// Insert your code here by editing it online
//It will be more easy

#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<map>
static int count=1;
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

void book::setterid(string id)
{
	features['i']=id;
}

string book::getterid()
{
	return features['i'];
}

class library
{
	private:
		
	public:
		void setterbook(book obj);
		book getterbook(string id);
		void removebook(string id);
		void writetofile(book obj);
};

void library::removebook(string id)
{
	ifstream myInput("Librarybooks.txt",ios::in);
	
}

void library::setterbook(book obj)
{
	if(count==1)
	{
		ofstream outputfile("Librarybooks.txt");
		outputfile<<count<<endl;
		outputfile<<obj.gettername()<<endl;
		outputfile<<obj.getterid()<<endl<<endl;
	}
	
	else
	{
		ofstream outputfile("Librarybooks.txt",ios::app);
		outputfile<<count<<endl;
		outputfile<<obj.gettername()<<endl;
		outputfile<<obj.getterid()<<endl<<endl;
	}
	
	count++;
	
}

book library::getterbook(string id)
{
	ifstream myInput("Librarybooks.txt",ios::in);
	string compare;
	book obj,obj2;
	obj2.setterid("null");
	obj2.settername("0");
	while(1)
	{
		if(compare==id)
		{
			return obj;
		}
		else
		{
			return obj2;
		}
	}
}

int main(void)
{
	book obj,obj1;
	string name,id;
	int found=0;
	while(count!=3)
	{
	cout<<"Please enter the name of the book:";
	cin>>name;
	obj.settername(name);
	cout<<"Please enter the id of the book:";
	cin>>id;
	obj.setterid(id);
	
	library obj2;
	obj2.setterbook(obj);
	}
	book compare,compare2;
	ifstream myinput("Librarybooks.txt",ios::in);
	while(getline(myinput,id))
	{
		string input;
		cout<<"Please enter the name of book to be found:";
		cin>>input;
		if(input.compare(id)==0)
		{
			cout<<"Success"<<endl;
			myinput>>id;
			myinput>>id;
			cout<<id;
			found=1;
		}
	}
	if(found==0)
		{
			cout<<"Book not found"<<endl;
		}
}
