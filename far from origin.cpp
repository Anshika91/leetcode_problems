#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int anshii;
	cin>>anshii;
	while(anshii--)
	{
	    int a1,a2,b1,b2;
	    cin>>a1>>b1>>a2>>b2;
	    int a = ((a1*a1) + (b1*b1));
	    int b = ((a2*a2) + (b2*b2));
	    
	    if(a>b)
	    {
	        cout<<"ALEX"<<endl;
	    }
	    else if(a<b)
	    {
	        cout<<"BOB"<<endl;
	    }
	    else
	    {
	        cout<<"EQUAL"<<endl;
	    }
	}
	return 0;
}
