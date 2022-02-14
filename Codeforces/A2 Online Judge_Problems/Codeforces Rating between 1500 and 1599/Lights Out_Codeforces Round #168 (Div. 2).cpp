#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int num;
            cin >> num;
            if (num % 2 != 0)
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
    }
    int arr1[3][3] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == 1)
            {
                arr1[i][j] = ((arr1[i][j] == 0) ? 1 : 0);
                if (i > 0)
                    arr1[i - 1][j] = ((arr1[i - 1][j] == 0) ? 1 : 0);
                if (j > 0)
                    arr1[i][j - 1] = ((arr1[i][j - 1] == 0) ? 1 : 0);
                if (i < 2)
                    arr1[i + 1][j] = ((arr1[i + 1][j] == 0) ? 1 : 0);
                if (j < 2)
                    arr1[i][j + 1] = ((arr1[i][j + 1] == 0) ? 1 : 0);
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr1[i][j];
        }
        cout << endl;
    }
 
    return 0;
}