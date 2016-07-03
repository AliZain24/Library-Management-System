#include<iostream>
#include<cstdio>
#include<fstream>
#include<windows.h>
#include<string>
#include<map>

static int count=1,found=0;

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
		void setterauthor(string author);
		string getterauthor();
};

void book::setterauthor(string author)
{
	features['a']=author;
}

string book::getterauthor()
{
	return features['a'];
}

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
		void editbook(string id);
};

void library::editbook(string id)
{
	ifstream input("Librarybooks.txt",ios::in);
	string filedata,updatedname,updatedauthor;
	ofstream output("Updatedbooks.txt",ios::out);
	while(getline(input,filedata)!=NULL)
	{
		if(id==filedata)
		{
			output<<id<<endl;
			cout<<"Please enter the updated name of the book:";
			getline(input,filedata);
			getline(cin,updatedname);
			output<<updatedname<<endl;
			cout<<"Please enter the updated book author's name:";
			getline(input,filedata);
			getline(cin,updatedauthor);
			output<<updatedauthor<<endl;
			system("cls");
			cout<<"The book number "<<id<<" has been updated"<<endl;
			Sleep(2000);
			system("cls");
			filedata.clear();
		}
		else
		{
			output<<filedata<<endl;
			filedata.clear();
		}
	}
	string removefile="Librarybooks.txt";
	string renamefile="Updatedbooks.txt";
	input.close();
	output.close();
	remove(removefile.c_str());
	rename(renamefile.c_str(),removefile.c_str());
}

void library::removebook(string id)
{
	ifstream myinput("Librarybooks.txt",ios::in);
	string outputoffile;
	ofstream outputfile("Temp.txt",ios::app);
	while(getline(myinput,outputoffile))
	{
		if(id==outputoffile)
		{
			getline(myinput,outputoffile);
			getline(myinput,outputoffile);
		}
		else
		{
			outputfile<<outputoffile<<endl;
		}
	}
	string removefile="Librarybooks.txt";
	string renamefile="Temp.txt";
	myinput.close();
	outputfile.close();
	remove(removefile.c_str());
	rename(renamefile.c_str(),removefile.c_str());
}

void library::setterbook(book obj)
{
	if(count==1)
	{
		ofstream outputfile("Librarybooks.txt",ios::out);
		//outputfile<<count<<endl;
		outputfile<<obj.getterid()<<endl;
		outputfile<<obj.gettername()<<endl;
		outputfile<<obj.getterauthor()<<endl;
		outputfile.close();
	}
	
	else
	{
		ofstream outputfile("Librarybooks.txt",ios::app);
		//outputfile<<count<<endl;
		outputfile<<obj.getterid()<<endl;
		outputfile<<obj.gettername()<<endl;
		outputfile<<obj.getterauthor()<<endl;
		outputfile.close();
	}
	
	count++;
	
}

book library::getterbook(string id)
{
	ifstream myInput("Librarybooks.txt",ios::in);
	string compare;
	book obj;
	while(getline(myInput,compare))
	{
		if(compare==id)
		{
			system("cls");
			obj.setterid(compare);
			getline(myInput,compare);
			obj.settername(compare);
			getline(myInput,compare);
			obj.setterauthor(compare);
			found=1;
		}
	}
	if(found==0)
	{
		cout<<"Book not found"<<endl;
		Sleep(2000);
		system("cls");
	}
	return obj;
	myInput.close();
}

int main(void)
{
	system("Color 1B");//syntax => system("Color ab");  description => a=background color, b=text color, 0 black, 1 blue, 2 green, 3 aqua, 4 red, 5 purple, 6 yellow, 7 white, 8 gray, 9 light blue, A light green, B light aqua, C light red, D light purple, E light yellow, F bright white
	book obj;
	string name,id,author,choice;
	int choose;
	static library obj2;
	
	while(1)
	{
		cout<<"***************Library Management System*******************"<<endl<<endl;
		cout<<"What do you want to do?"<<endl;
		cout<<"To add a book, enter 1"<<endl;
		cout<<"To remove a book,enter 2"<<endl;
		cout<<"To view all books, enter 3"<<endl;
		cout<<"To find a book, enter 4"<<endl;
		cout<<"To edit a book, enter 5"<<endl;
		cout<<"To exit, enter 0"<<endl;
		cout<<"Your choice:";
		cin>>choose;
		
		if(choose==0)
		{
			break;
		}
		if(choose==1)
		{
			label:
			{
				system("cls");
				getline(cin,name);
				cout<<"Please enter the name of the book:";
				getline(cin,name);
				cout<<"Please enter the id of the book:";
				getline(cin,id);
				cout<<"Please enter the author of the book:";
				getline(cin,author);
				
				obj.setterid(id);
				obj.settername(name);
				obj.setterauthor(author);
				obj2.setterbook(obj);
				cout<<"The book has been added to library"<<endl;
			}
				cout<<"Do you want to add another book?(Yes/No)"<<endl;
				cout<<"Your choice:";
				
				cin>>choice;
				
				if(choice=="Yes"||choice=="yes"||choice=="y"||choice=="YES")
				{
					system("cls");
					goto label;
				}
				
				else
				{
					system("cls");
					continue;
				}
		}
		
		if(choose==2)
		{
			int found=0;
			string input,choice;
			
			label2:
			{
				system("cls");
				getline(cin,input);
				cout<<"Enter the book's id to be removed:";
				getline(cin,id);
				obj2.removebook(id);
				ifstream myinput("Librarybooks.txt",ios::in);
				while(getline(myinput,input))
				{
					if(id.compare(input)==0)
					{
						cout<<"No success"<<endl<<endl;
						cout<<"ID:"<<input<<endl;
						cout<<"Name:";
						getline(myinput,input);
						cout<<input<<endl;
						getline(myinput,input);
						cout<<"Author:";
						cout<<input<<endl;
						found=1;
					}
				}
			}
			
			if(found==0)
			{
				system("cls");
				cout<<"Book is deleted"<<endl;
			}
			cout<<"Do you want to delete another book?(Yes/No)";
			cout<<"Your choice:";
			getline(cin,choice);
			
			if(choice=="Yes"||choice=="yes"||choice=="YES"||choice=="y")
			{
				system("cls");
				goto label2;
			}
			else
			{
				system("cls");
				continue;
			}
		}
		
		if(choose==3)
		{
			system("cls");
			cout<<endl;
			string input;
			ifstream myinput("Librarybooks.txt",ios::in);
			while(getline(myinput,input))
			{
				if(myinput.eof())
				{
					break;
				}
				cout<<"ID: "<<input<<endl;
				getline(myinput,input);
				cout<<"Name of book: "<<input<<endl;
				getline(myinput,input);
				cout<<"Author: "<<input<<endl<<endl;
			}
			cout<<endl;
			cout<<"Do you want to go to main menu?"<<endl;
			cout<<"Just press enter";
			getline(cin,input);
			getline(cin,input);
			system("cls");
		}
		if(choose==4)
		{
			system("cls");
			string find;
			cout<<"Please enter the ID of the book:";
			getline(cin,find);
			getline(cin,find);
			book found;
			found=obj2.getterbook(find);
			cout<<"ID: "<<found.getterid()<<endl;
			cout<<"Name: "<<found.gettername()<<endl;
			cout<<"Author: "<<found.getterauthor()<<endl<<endl;
			cout<<"Do you want to go to main menu?"<<endl;
			cout<<"Just press enter";
			getline(cin,find);
			system("cls");
		}
		
		if(choose==5)
		{
			system("cls");
			string id;
			getline(cin,id);
			cout<<"Please enter the id of the book to be edited:";
			getline(cin,id);
			obj2.editbook(id);
		}
	}
}
