#include<iostream>

using namespace std;
int main()
{
	int arrayA[100000], arrayB[100000], arrayC[200000];
	int m, n;
	
	cout<<"please enter the size of first array"<<endl;
	cin>>m;
	
	cout<<"please enter the size of second array"<<endl;
	cin>>n;
	
	
	//initializing value in first array.
	for(int i = 0 ; i<m ; i++)
	{
		arrayA[i] = i+i/2;
	}
	
	//Initializing value in second array.
	for(int j = 0 ; j<n ; j++)
	{
		arrayB[j] = j+2;
	}
	
	//Storing value in third array.
	int i, a=0, b=0;
	for(i = 0 ; i < (m+n) ; i++)
	{
		if(a < m && b < n)
			{
				if(arrayA[a] > arrayB[b])
					{
						arrayC[i] = arrayB[b++];
					}
				
				else
					{
						arrayC[i] = arrayA[a++];
					}		
			}
		
	    else if(a == m && b == n)
			{
				break;
			}
		
		else if(a == m)
			{
				arrayC[i] = arrayB[b++];
			}
		
		else
			{
				arrayC[i] = arrayA[a++];
			}
	}
	
	//Printing values of arrayC.
	for( i = 0 ; i<(m+n) ; i++)
	{
		cout<<arrayC[i]<<endl;
	}
	
	return 0;
}
