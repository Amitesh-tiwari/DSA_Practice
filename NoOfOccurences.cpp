#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



    bool uniqueOccurrences(vector<int> & arr)
    {
        sort(begin(arr), end(arr));
        vector ans(1001, 0);
        int i = 0;
        while (i < arr.size())
        {
            int count = 1;
            int j = i + 1;
            while (j < arr.size() and arr[i] == arr[j])
                count++, j++;
            if (ans[count])
                return 0;
            ans[count] = 1;
            i = j;
        }
        return 1;
    }


    int main()
    {
        int arr[] = {1, 2, 2, 1, 1, 3};
        bool andsd = ans.uniqueOccurrences(arr);
        return 0;
    }