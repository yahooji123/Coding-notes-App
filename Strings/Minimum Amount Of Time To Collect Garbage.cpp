#include <iostream>
#include <vector>
#include <string>
using namespace std;

// leetcode->2391 -> https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/

/*

Example 1:

Input: garbage = ["G","P","GP","GG"], travel = [2,4,3]
Output: 21
Explanation:
The paper garbage truck:
1. Travels from house 0 to house 1
2. Collects the paper garbage at house 1
3. Travels from house 1 to house 2
4. Collects the paper garbage at house 2
Altogether, it takes 8 minutes to pick up all the paper garbage.
The glass garbage truck:
1. Collects the glass garbage at house 0
2. Travels from house 0 to house 1
3. Travels from house 1 to house 2
4. Collects the glass garbage at house 2
5. Travels from house 2 to house 3
6. Collects the glass garbage at house 3
Altogether, it takes 13 minutes to pick up all the glass garbage.
Since there is no metal garbage, we do not need to consider the metal garbage truck.
Therefore, it takes a total of 8 + 13 = 21 minutes to collect all the garbage.
Example 2:

Input: garbage = ["MMM","PGM","GP"], travel = [3,10]
Output: 37
Explanation:
The metal garbage truck takes 7 minutes to pick up all the metal garbage.
The paper garbage truck takes 15 minutes to pick up all the paper garbage.
The glass garbage truck takes 15 minutes to pick up all the glass garbage.
It takes a total of 7 + 15 + 15 = 37 minutes to collect all the garbage.


*/

class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {

        // p truck
        int pickP = 0;
        int lastHouseP = 0;

        // g truck
        int pickG = 0;
        int lastHouseG = 0;

        // m truck
        int pickM = 0;
        int lastHouseM = 0;

        // travel krna start krte hain road par
        for (int i = 0; i < garbage.size(); i++)
        {

            // main kisi ghar par truck leker pahunch gaya
            string currentHouseGarbage = garbage[i];

            for (int j = 0; j < currentHouseGarbage.length(); j++)
            {

                char GarbageType = currentHouseGarbage[j];

                if (GarbageType == 'P')
                {
                    pickP++;
                    lastHouseP = i;
                }
                else if (GarbageType == 'M')
                {
                    pickM++;
                    lastHouseM = i;
                }
                else if (GarbageType == 'G')
                {
                    pickG++;
                    lastHouseG = i;
                }
            }
        }

        // ab mere pass har truck ka pick and lastHouse ka Data Present h
        // ab mujhe har truck k travel time ka data nikalna hai
        // travel time ka data nikalne ke liye house index ka data use hoga

        int travelP = 0;
        int travelG = 0;
        int travelM = 0;

        // lets find out the travel time for truck P
        for (int i = 0; i < lastHouseP; i++)
        {
            travelP = travelP + travel[i];
        }

        for (int i = 0; i < lastHouseM; i++)
        {
            travelM = travelM + travel[i];
        }

        for (int i = 0; i < lastHouseG; i++)
        {
            travelG = travelG + travel[i];
        }

        int totalTime = (pickP + pickM + pickG) + (travelP + travelM + travelG);
        return totalTime;
    }
};
