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
	cin>>n;
   
    vector<int>array;
    for(int j=0;j<n;j++)
    {
    	int value;
    	cin>>value;
    	array.push_back(value);
    }

	int L,R;
	cin>>L>>R;

    int sum=0;
	for(int x=L; x<=R; x++)
	{
		int index = (int) (x % n);
		sum=sum+array[index];
	}
	cout<<sum<<endl;

	return 0;
}








// To repeat elements like infinite times.........

// String arr[] = {"a", "b", "c", "d", "e", "f"};
// int repeat = 10000;
// String result[] = new String[repeat];
// for(int i=0, j=0; i<repeat && j<arr.length; i++, j++)
// {
//    result[i] = arr[j];
//    if(j == arr.length -1)
//          j = -1;
//    System.out.println("array["+i+"] : "+result[i]);
// }