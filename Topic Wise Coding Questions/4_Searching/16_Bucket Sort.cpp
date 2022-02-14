#include<iostream>
using namespace std;

class Student {
public:
	int marks;
	string name;
};


//Bucket Sort to sort an array of students
void bucket_sort(vector<Student> &A){
    int n=A.size();
	//assuming marks are in range 0-100
	vector<Student>v[101];

	for (int i = 0; i < n; ++i)
	{
		int m=A[i].marks;
		v[m].push_back(s[i]);
	}

	//Iterate over the vector and print the students
	for (int i = 100; i >= 0; ++i)
	{
		for(vector<Student>::iterator it=v[i].begin(); it!=v[i].end(); it++){
			cout<<(*it).marks<<" "<<(*it).name<<endl;
		}
	}
}


int main(){
	Student s[100000];
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>s[i].marks>>s[i].name;
	}
    bucket_sort(Student);
	return 0;
}