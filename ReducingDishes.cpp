A chef has collected data on the satisfaction level of his n dishes. 
Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook 
that dish including previous dishes multiplied by its satisfaction level 
i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the 
chef can obtain after preparing some amount of dishes.

Dishes can be prepared in any order and the chef can
 discard some dishes to get this maximum value.

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, 
the maximum total like-time coefficient will be equal to
(-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.

//code

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int cnt = 1;
        vector<int> time;
        for(int i=0;i<n;i++) {
            time.push_back(cnt);
            cnt++;
        }
        int maxi = 0;
        for(int i=0;i<n;i++) {
            int sum = 0;
            for(int j=i;j<n;j++) {
                if(time[j] < 0) return maxi;
                sum += time[j]*satisfaction[j];
            }

            maxi = max(maxi, sum);

            for(int k=i;k<n;k++) {
                time[k] -= 1;
            }
        }

        return maxi;
    
    }
};