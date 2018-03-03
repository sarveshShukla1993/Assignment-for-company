#include<iostream>
#include<string.h>
using namespace std;
#define max 1000
string words[max];
int instances[max];
int count = 0;


void insert(string input)
{
	for(int i =0 ; i<=count ; i++)
	{
		
		if(input == words[i])
		{
			instances[i]++;
			return;
		}
	}
		if(count<max)
		{
			words[count] = input;
			instances[count] = 1;
			count++;
		}
		else
		{
			cerr<<"count can't be more than max"<<endl;
		}
	return;
}


int findTop(string &word)
{
//	int topIndex = 0;
	int topCount = instances[0];
	//word = words[0];
	int topIndex = 0; 
	for(int i=1 ; i<count ; i++)
	{
		if(instances[i] > topCount)
		{
			topCount = instances[i];
			topIndex = i;
		}
	}
	instances[topIndex] = 0;
	word = words[topIndex];
	return topCount;
}
int main()
{
	string input[20];
	string word;
	int n;
	cout<<"enter the number of words you want to insert"<<endl;
	cin>>n;
	for(int i = 0 ; i<n; i++)
	{
		cin>>input[i];
	}
	for(int i = 0; i<n; i++)
	{
		word = input[i];
		insert(word);
	}
	
	for(int i=0; i<5; i++)
	{
		cout<<findTop(word)<<"->"<<word<<endl;
	}
    return 0;
}
