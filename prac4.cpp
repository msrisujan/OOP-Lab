#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    int a,b;
	    cin>>a>>b;
	    int j=0,k=0,c=0;
	    for( j=2;j<11;j++)
	    {
	        for(k=1;k<7;k++)
	        {
	            if(pow(j,k)==min(a,b))
	            {
	               c++;
	            }
	        }
	        if(c==1)
	            break;
	    }
	    if(c==0)
	    {
	        cout<<"NO"<<endl;
	    }
	    else
	    {
    	    while(pow(j,k)<max(a,b))
    	    {
    	        k++;
    	    }
    	    if(pow(j,k)==max(a,b))
    	        cout<<"YES"<<endl;
    	    else
    	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}