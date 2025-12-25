#include <vector>
using namespace std;

/*

Example 1:
Input:

array1 = [1, 5, 10, 20, 40, 80]
array2 = [6, 7, 20, 80, 100]
array3 = [3, 4, 15, 20, 30, 70, 80, 120]
Output:

[20, 80]
Explaination:
The number 20 is present in all three arrays. The number 80 is also present in all three arrays. No other number is common to all three.

Example 2:
Input:

array1 = [1, 2, 3, 4, 5]
array2 = [1, 2, 3, 4, 5]
array3 = [1, 2, 3, 4, 5]
Output:

[1, 2, 3, 4, 5]
Explaination:
All elements from 1 to 5 are common to all three arrays.

Follow-up: Could you solve this problem with a time complexity of O(n1 + n2 + n3) where n1, n2, and n3 are the lengths of arrays array1, array2, and array3 respectively, and with minimal additional space?

Example 1:

Input:

array1=[1,5,10,20,40,80] array2=[6,7,20,80,100] array3=[3,4,15,20,30,70,80,120]

Output:

20 80
Explanation:Only 20 and 80 appear in all three arrays; duplicates are removed.

Example 2:

Input:

array1=[1,2,3] array2=[1,2,3] array3=[1,2,3]

Output:

1 2 3
Explanation:Every element is common, output keeps sorted order without duplicates.

Example 3:

Input:

array1=[1,2,3] array2=[4,5,6] array3=[7,8,9]

Explanation:The three arrays share no values; result list is empty.

*/

// first best way to sovle it

class Solution
{
public:
    vector<int> removeDup(vector<int> &arr)
    {

        vector<int> temp;
        if (arr.size() == 0)
            return temp;

        temp.push_back(arr[0]);

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] != arr[i - 1])
                temp.push_back(arr[i]);
        }
        return temp;
    }

    vector<int> commonElements(vector<int> &array1, vector<int> &array2,
                               vector<int> &array3)
    {

        vector<int> a = removeDup(array1);
        vector<int> b = removeDup(array2);
        vector<int> c = removeDup(array3);

        vector<int> ans;
        int i = 0, j = 0, k = 0;

        while (i < a.size() && j < b.size() && k < c.size())
        {

            if (a[i] == b[j] && b[j] == c[k])
            {
                ans.push_back(a[i]);
                i++;
                j++;
                k++;
            }
            else if (a[i] < b[j])
                i++;
            else if (b[j] < c[k])
                j++;
            else
                k++;
        }
        return ans;
    }
};

// second best way to solve it

class Solution
{
public:
    vector<int> commonElements(vector<int> &array1, vector<int> &array2,
                               vector<int> &array3)
    {

        vector<int> ans;
        int i = 0, j = 0, k = 0;

        while (i < array1.size() && j < array2.size() && k < array3.size())
        {

            if (array1[i] == array2[j] && array2[j] == array3[k])
            {

                if (ans.size() == 0 || ans.back() != array1[i])
                    ans.push_back(array1[i]);

                i++;
                j++;
                k++;
            }
            else if (array1[i] < array2[j])
                i++;
            else if (array2[j] < array3[k])
                j++;
            else
                k++;
        }
        return ans;
    }
};

// third best way to solve it
#include <set>
class Solution
{
public:
    vector<int> commonElements(vector<int> &array1, vector<int> &array2,
                               vector<int> &array3)
    {

        vector<int> ans;
        int i, j, k;
        i = j = k = 0;
        set<int> s;

        while (i < array1.size() && j < array2.size() && k < array3.size())
        {
            if (array1[i] == array2[j] && array2[j] == array3[k])
            {
                s.insert(array1[i]);
                i++, j++, k++;
            }
            else if (array1[i] < array2[j])
                i++;
            else if (array2[j] < array3[k])
                j++;
            else
                k++;
        }
        for (auto x : s)
        {
            ans.push_back(x);
        }
        return ans;
    }
};