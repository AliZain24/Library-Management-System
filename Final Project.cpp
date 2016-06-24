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



int main(void)
{
	book obj;
	string name,id;
	cout<<"Please enter the name of the book:";
	cin>>name;
	obj.settername(name);
	cout<<"Please enter the id of the book:";
	cin>>id;
	obj.setterid(id);
	ofstream outputfile("Librarybooks.txt");
	outputfile<<obj.gettername()<<endl;
	outputfile<<obj.getterid()<<endl;
}
