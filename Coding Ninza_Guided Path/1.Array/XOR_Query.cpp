#include<iostream>
using namespace std;
#include<vector>

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
    #endif
    
	int n;
	int **array=new int* [n];
	for(int i=0;i<n;i++)
	{
		array[i]=new int[2];
		for(int j=0;j<2;j++)
		{
			cin>>array[i][j];
		}
	}
    
	vector<int> output;
    for(int i=0;i<n;i++)
    {
	    if(array[i][0]==1)
	    {
	    	output.push_back(array[i][1]);
	    }
	    if(array[i][0]==2)
	    {
	    	output.push_back(output[i]^array[i][1]);
	    }
	}

    for(int i=0;i<output.size();i++)
    {
    	cout<<output[i]<<" ";
    }

    // for(int i=0;i<n;i++)
    // {
    // 	delete[] array[i];
    // }

    return 0;
}