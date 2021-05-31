//Q)) Check Permutation: Given two strings, write a method to decide if one is a permutation of the other. 

//logic => 
//Corner case -> strings must be of same length
//permutations are just same characters arranged in different locations.So, sort the strings.
//sort the string in O(n^2) time bcoz i have used bubble sort over here. OPTIMIZE it using merge sort later
//traverse both the strings once and check if corresponding characters are same, which they must be. It takes O(n) time
// TC after using merge sort => O(nlogn)+O(n)=O(nlogn)

#include<iostream>
#include<string.h>

using namespace std;

//function to swap
void swap(char *a,char *b)  
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

//Function to sort the string
void sort_string(char str[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{	
		for(j=0;j<n-i-1;j++)
		{
			if(str[j]>str[j+1])	
			{
				swap(&str[j],&str[j+1]);
			}
		}
	}
}

int main()
{
	char str1[100],str2[100];
	int i,n1,n2;
	
	cout<<"what length do you want for your string no 1 ";
	cin>>n1;
	cout<<"what length do you want for your string no 2 ";
	cin>>n2;
	
	cout<<"Enter your string 1 here => ";
	for(i=0;i<n1;i++)
	{
	    cout<<"\ncharacter no "<<i+1<<" is: "<<" ";
	    cin>>str1[i];
	}
	
	cout<<"Enter your string 2 here => ";
	for(i=0;i<n2;i++)
	{
	    cout<<"\ncharacter no "<<i+1<<" is: "<<" ";
	    cin>>str2[i];
	}
	
	//corner case
	if(n1==n2)
	{
		//sorting the string 1
		sort_string(str1,n1);
		//sorting the string 2
		sort_string(str2,n2);
	
		int count=0;
		//traverse the sorted string once to get the duplicates. n1 is used bcoz lengths are same
		for(i=0;i<n1;i++)
		{
			if(str1[i]==str2[i])  //if adjacent characters are equal
			{
	        	count++;
			}
		}
		if(count==n1)
		{
			cout<<"\nThe input Strings are pemutations of each other";
		}
		else
		{
			cout<<"\nThe input Strings are not the pemutations of each other bcoz every character isnt the same!";	
		}
	}
	else
	{
		cout<<"\nNot a permutation bcoz lengths are different";
	}
	
	return 0;
}

