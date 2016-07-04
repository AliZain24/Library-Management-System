#include<iostream>
#include<cstdio>
#include<fstream>
#include<windows.h>
#include<string>
#include<map>

using namespace std;
static int count=1,found=0,usercount=0,attempts=0;

class person
{
	private:
		map<char,string>info;
	
	public:
		void settername(string u_name);
		string gettername();
		void setterid(string u_id);
		string getterid();
		void setpassword(string password);
		string getpassword(void);
};

void person::setpassword(string password)
{
	info['p']=password;
}

string person::getpassword(void)
{
	return info['p'];
}

string person::gettername()
{
	return info['n'];
}

void person::settername(string u_name)
{
	info['n']=u_name;
}

void person::setterid(string u_id)
{
	info['i']=u_id;
}



string person::getterid()
{
	return info['i'];
}


class user:public person
{
	
};

class librarian:public person
{
	
};



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
		void removeuser(string name);
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


int check_librarian(string username,string password)
{
	string match1,match2;
	ifstream output("Librarian.txt",ios::in);
	while(getline(output,match1))
	{
		if(match1==username)
		{
			getline(output,match2);
			if(match2==password)
			{
				cout<<"***************     Welcome to the library     ******************"<<endl;
				return 1;
			}
			else
			{
				cout<<"Invalid username or password"<<endl;
				Sleep(2000);
				system("cls");
				return 0;
			}
		}
	}
	return 0;
}


int check_user(string username,string password)
{
	string match1,match2,input;
	input=username.append(".txt");
	ifstream file(input.c_str(),ios::in);
	while(getline(file,match1))
	{
		if(match1==username)
		{
			getline(file,match2);
			if(match2==password)
			{
				cout<<"***************     Welcome to the library     ******************"<<endl;
				return 1;
			}
			else
			{
				cout<<"Invalid username or password"<<endl;
				Sleep(2000);
				system("cls");
				return 0;
			}
		}
	}
	return 0;
}


int main(void)
{
	while(attempts!=4)
	{
		book obj;
	string name,id,author,choice;
	int choose;
	static library obj2;
	system("Color 1B");//syntax => system("Color ab");  description => a=background color, b=text color, 0 black, 1 blue, 2 green, 3 aqua, 4 red, 5 purple, 6 yellow, 7 white, 8 gray, 9 light blue, A light green, B light aqua, C light red, D light purple, E light yellow, F bright white
	string username,password;
	cout<<"Enter username (without spaces):";
	getline(cin,username);
	cout<<"Enter password (without spaces):";
	getline(cin,password);
	int check=check_librarian(username,password);
	int checkuser=check_user(username,password);
	if(check==1)
	{
		
		while(1)
		{
			cout<<"***************Library Management System*******************"<<endl<<endl;
			cout<<"What do you want to do?"<<endl;
			cout<<"To add a user, enter 1"<<endl;
			cout<<"To remove a user,enter 2"<<endl;
			cout<<"To view all users, enter 3"<<endl;
			cout<<"To add a book, enter 4"<<endl;
			cout<<"To find a book, enter 5"<<endl;
			cout<<"To edit a book, enter 6"<<endl;
			cout<<"To view all books, enter 7"<<endl;
			cout<<"To remove a book, enter 8"<<endl;
			cout<<"To exit, enter 0"<<endl;
			cout<<"Your choice:";
			cin>>choose;
			attempts=4;
		
			if(choose==1)
			{
				user person1;
				string filename;
				cout<<"Please enter the name of the user (username):";
				getline(cin,username);
				getline(cin,username);
				person1.settername(username);
				cout<<"Please enter the password:";
				getline(cin,password);
				person1.setpassword(password);
				filename=person1.gettername().append(".txt");
				ofstream open(filename.c_str(),ios::out);
				open<<username<<endl;
				open<<password<<endl;
			}
			
			if(choose==2)
			{
				string filename;
				cout<<"Enter the name of the user to be removed:";
				getline(cin,username);
				getline(cin,username);
				filename=username.append(".txt");
				ifstream file(filename.c_str(),ios::in);
				if(file!=NULL)
				{
					file.close();
					remove(filename.c_str());
					cout<<"Removed"<<endl;
				}
				else
				{
					cout<<"User not found"<<endl;
				}
			}
			
			if(choose==3)
			{
				
			}
			
			if(choose==0)
			{	
				break;
			}
			
			
			if(choose==4)
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
		
		if(choose==8)
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
		
		if(choose==7)
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
		
		
		if(choose==5)
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
		
		if(choose==6)
		{
			system("cls");
			string id;
			getline(cin,id);
			cout<<"Please enter the id of the book to be edited:";
			getline(cin,id);
			obj2.editbook(id);
		}
			//if()
	}
	
	/*book obj;
	string name,id,author,choice;
	int choose;
	static library obj2;
	
	while(1)
	{
		cout<<"***************Library Management System*******************"<<endl<<endl;
		cout<<"What do you want to do?"<<endl;
		cout<<"To add a user, enter 1"<<endl;
		cout<<"To remove a user,enter 2"<<endl;
		cout<<"To view all users, enter 3"<<endl;
		cout<<"To find a book, enter 4"<<endl;
		cout<<"To edit a book, enter 5"<<endl;
		cout<<"To exit, enter 0"<<endl;
		cout<<"Your choice:";
		cin>>choose;
		
		if(choose==1)
		{
			
		}
	/*string name,filename;
	librarian sarfraz;
	user qadoos;
	getline(cin,name);
	qadoos.settername(name);
	//sarfraz.settername("Sarfraz shafi");
	filename=qadoos.gettername().append(".txt");
	ofstream open(filename.c_str(),ios::out);}*/
}

if(checkuser==1)
{
	while(1)
	{
		cout<<"***************Welcome to the library*******************"<<endl<<endl;
			cout<<"What do you want to do?"<<endl;
			cout<<"To issue a book, enter 1"<<endl;
			cout<<"To return a book, enter 2"<<endl;
			cout<<"To find a book, enter 3"<<endl;
			cout<<"To view all books, enter 4"<<endl;
			cout<<"To exit, enter 0"<<endl;
			cout<<"Your choice:";
			cin>>choose;
			attempts=4;
			
		if(choose==4)
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
		
		if(choose==3)
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
	}
}
}
}
