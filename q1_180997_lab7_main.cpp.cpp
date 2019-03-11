// Q NO.1.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "bankAccount.h"
#include <fstream>
#include <string>
using namespace std;

bankAccount** fileinput(string filename)
{
	int size;
	ifstream in;
	int ID=0;
	int limit=0;
	int nooftrans=0;
	int balance=0;
	in.open(filename);
	while(!in.eof())
	{
		in>>size;
		cout<<"number of bank accounts are : "<<size<<endl;
		bankAccount** arr1=new bankAccount*[size];
		for(int i=0;i<size;i++)
		{
			in>>ID>>balance>>limit>>nooftrans;
			float* transactions=new float(nooftrans);
			for(int i=0;i<nooftrans;i++)
			{
				in>>transactions[i];
			}
			arr1[i]=new bankAccount(ID,balance,transactions,nooftrans,limit);
			arr1[i]->print();
		}
			return arr1;

	}

}

void printaccount(bankAccount** array,int s)
{
	for(int i=0;i<s;i++)
	{
		array[i]->print();
		cout<<endl;
		cout<<endl;
	}


}

bool transactionsuccessful(bankAccount** b2,int id, int transaction,string size)
{
	for(int i=0;i<4;i++)
	{
		if(id==b2[i]->getID())
		{
			if(size=="withdraw")
			{
				if(b2[i]->withdraw(transaction)==true)
				return true;
			}
			else if(size=="deposit")
			{
				if(b2[i]->deposit(transaction)==true)
				return true;
			}
		}
		else if(id!=b2[i]->getID())
			{cout<<"no id"<<endl;
		return false;}
	}
	}

int main()
{
	ifstream in;
	bankAccount* ptrIdentifier;
	ptrIdentifier= new bankAccount(10 , 13000,100000);
	bankAccount* b1=new bankAccount(10,13000,15000);
	b1->print();
	b1->deposit(1000);
	b1->deposit(3000);
	b1->withdraw(10000);
	b1->withdraw(6000);
	b1->print();

	bankAccount *arrayIdentifier[2];
	float transactions[3]={3000,5000,60000};
	arrayIdentifier[0]=new bankAccount(30,2000,transactions,3,15000);
	arrayIdentifier[1]=new bankAccount(40,255000,400000);
	arrayIdentifier[0]->print();
	arrayIdentifier[1]->print();

	bankAccount **dyarrayIdentifier= new bankAccount*[2];
	float trans[2]={-5000,5000};
	dyarrayIdentifier[0]=new bankAccount(50,2000,trans,2,15000);
	dyarrayIdentifier[0]->withdraw(1000);
	dyarrayIdentifier[1]=new bankAccount(60,6000,400000);
	dyarrayIdentifier[0]->print();
	dyarrayIdentifier[1]->print();

	delete ptrIdentifier;
	ptrIdentifier=nullptr;
	delete b1;
	b1=nullptr;
	delete arrayIdentifier[0];
	arrayIdentifier[0]=nullptr;
	delete arrayIdentifier[1];
	arrayIdentifier[1]=nullptr;
	//delete []arrayIdentifier;
	delete dyarrayIdentifier[0];
	dyarrayIdentifier[0]=nullptr;
	delete dyarrayIdentifier[1];
	dyarrayIdentifier[1]=nullptr;
	delete []dyarrayIdentifier;

	//fileinput("data.txt");
	bankAccount** b2;
	b2=fileinput("data.txt");
	printaccount(b2,4);
	int id=0;
	int transaction=0;
	string type;
	cout<<"enter id you want to search :"<<endl;
	cin>>id;
	cout<<"enter the transaction amount you want:"<<endl;
	cin>>transaction;
	cout<<"enter the transaction type ypu want : withdraw or deposit :"<<endl;
	cin>>type;
	transactionsuccessful(b2,id,transaction,type);


	return 0;
}

