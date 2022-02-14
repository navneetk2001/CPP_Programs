// Given a collection of intervals, merge all overlapping intervals.
// For example:
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].
// Make sure the returned intervals are sorted.




//First Method :-
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool mycomp(Interval a,Interval b){
     return a.start<b.start;
 }

vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(),A.end(),mycomp);
    vector<Interval> res;
    int n=A.size();
    res.push_back(A[0]);
    for(int i=1;i<n;i++){
        if(A[i].start<=res[res.size()-1].end)
         res[res.size()-1].end=max(res[res.size()-1].end,A[i].end);
        else
         res.push_back(A[i]);
    }
    return res;
}




//Second Method :-
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
void swap(int* a, int* b);
void swap1(Interval* a, Interval* b);
int partition (vector<Interval> &A, int low, int high);
void quicksort(vector<Interval> &A, int p, int r);    

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void swap1(Interval* a, Interval* b)
{
    Interval t = *a;
    *a = *b;
    *b = t;
}
int partition (vector<Interval> &A, int low, int high)
{
    int pivot = A[high].start;  // selecting last element as pivot
    int i = (low - 1);  // index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If the current element is smaller than or equal to pivot
        if (A[j].start <= pivot)
        {
            i++;    // increment index of smaller element
            swap1(&A[i], &A[j]);
        }
    }
    swap1(&A[i + 1], &A[high]);
    return (i + 1);
}
void quicksort(vector<Interval> &A, int p, int r)    
{
    if(p < r)
    {
        int q;
        q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}


vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    Interval temp = Interval();
    vector<bool>B (A.size(), false);
    vector<Interval>C;
    for(int i = 0; i<A.size();i++){
        if(A[i].start>A[i].end){
            swap(A[i].start,A[i].end );
        }
    }
    // int first = 0;
    // int secont = 0;
    for(int first = 0; first<A.size();first++){
        if(B[first]==true) continue;
        for(int second = 0; second<A.size();second++){
            if(B[second]==true) continue;
            if(first==second) continue;
            // cout<<"{"<<A[first].start<<" "<<A[first].end<<"}";
            if(max(A[first].start,A[second].start)<=min(A[first].end,A[second].end)){
                // cout<<"r"<<endl;
                temp.start = min(A[first].start,A[second].start);
                temp.end = max(A[first].end,A[second].end);
                B[second] = true;
                A[first] = temp;
            }
            // cout<<"{"<<A[second].start<<" "<<A[second].end<<"}"<<"{"<<temp.start<<" "<<temp.end<<"}"<<B[second]<<endl;
        }    
    }
    for(int iter = 0; iter<B.size();iter++){
        if(B[iter]==false){
            C.push_back(A[iter]);
        } 
        
    }
    quicksort(C, 0, C.size()-1);

    // cout<<C.size()<<endl;
    // for(int iter = 0; iter<C.size();iter++){
    //     cout<<"{"<<C[iter].start<<" "<<C[iter].end<<"}";
    // }
    return C;

}/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
void swap(int* a, int* b);
void swap1(Interval* a, Interval* b);
int partition (vector<Interval> &A, int low, int high);
void quicksort(vector<Interval> &A, int p, int r);    

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void swap1(Interval* a, Interval* b)
{
    Interval t = *a;
    *a = *b;
    *b = t;
}
int partition (vector<Interval> &A, int low, int high)
{
    int pivot = A[high].start;  // selecting last element as pivot
    int i = (low - 1);  // index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If the current element is smaller than or equal to pivot
        if (A[j].start <= pivot)
        {
            i++;    // increment index of smaller element
            swap1(&A[i], &A[j]);
        }
    }
    swap1(&A[i + 1], &A[high]);
    return (i + 1);
}
void quicksort(vector<Interval> &A, int p, int r)    
{
    if(p < r)
    {
        int q;
        q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}


vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    Interval temp = Interval();
    vector<bool>B (A.size(), false);
    vector<Interval>C;
    for(int i = 0; i<A.size();i++){
        if(A[i].start>A[i].end){
            swap(A[i].start,A[i].end );
        }
    }
    // int first = 0;
    // int secont = 0;
    for(int first = 0; first<A.size();first++){
        if(B[first]==true) continue;
        for(int second = 0; second<A.size();second++){
            if(B[second]==true) continue;
            if(first==second) continue;
            // cout<<"{"<<A[first].start<<" "<<A[first].end<<"}";
            if(max(A[first].start,A[second].start)<=min(A[first].end,A[second].end)){
                // cout<<"r"<<endl;
                temp.start = min(A[first].start,A[second].start);
                temp.end = max(A[first].end,A[second].end);
                B[second] = true;
                A[first] = temp;
            }
            // cout<<"{"<<A[second].start<<" "<<A[second].end<<"}"<<"{"<<temp.start<<" "<<temp.end<<"}"<<B[second]<<endl;
        }    
    }
    for(int iter = 0; iter<B.size();iter++){
        if(B[iter]==false){
            C.push_back(A[iter]);
        } 
        
    }
    quicksort(C, 0, C.size()-1);

    // cout<<C.size()<<endl;
    // for(int iter = 0; iter<C.size();iter++){
    //     cout<<"{"<<C[iter].start<<" "<<C[iter].end<<"}";
    // }
    return C;

}



