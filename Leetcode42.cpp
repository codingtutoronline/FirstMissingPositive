/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6




Intuition

Do as directed in question. For each element in the array, we find the maximum level of water it can trap after the rain, which is equal to the minimum of maximum height of bars on both the sides minus its own height.

Algorithm

Initialize ans=0ans=0
Iterate the array from left to right:
Initialize \text{left\_max}=0left_max=0 and \text{right\_max}=0right_max=0
Iterate from the current element to the beginning of array updating:
\text{left\_max}=\max(\text{left\_max},\text{height}[j])left_max=max(left_max,height[j])
Iterate from the current element to the end of array updating:
\text{right\_max}=\max(\text{right\_max},\text{height}[j])right_max=max(right_max,height[j])
Add \min(\text{left\_max},\text{right\_max}) - \text{height}[i]min(left_max,right_max)−height[i] to \text{ans}ans


class Solution {
    int max_from_left(vector<int> &v,int k){
        int n = v.size();
        int lmax = INT_MIN;
        for(int i = k; i>=0;i--){
            lmax = max(v[i],lmax);
        }
        return lmax;
    }
    int max_from_right(vector<int> &v,int k){
        
        int n = v.size();
        int rmax = INT_MIN;
        for(int i = k; i<v.size();i++){
            rmax = max(v[i],rmax);
        }
        return rmax;
    }
    
public:
    int trap(vector<int>& height) {
        
        int total_water = 0;
        int n = height.size();
        
        for(int i =0 ;i < n; ++i)
        {
            int curHeight = height[i];
            
            int lmax = max_from_left(height, i); //find the max from current index to it left in the vector height
            
            int rmax = max_from_right(height, i);//find the max from current index to it right in the vector height
            
            int water_that_can_be_stored = min(lmax,rmax); 
            
            int water_stored_above_building_currently =  water_that_can_be_stored - curHeight;
            
            total_water += water_stored_above_building_currently;
            
        }
        
        return total_water;
    }
};
*/
My short c++ solution, O(1) space, and O(n) time


Put each number in its right place.

For example:

When we find 5, then swap it with A[4].

At last, the first place where its number is not right, return the place + 1.

class Solution
{
public:
    int firstMissingPositive(int A[], int n)
    {
        for(int i = 0; i < n; ++ i)
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
                swap(A[i], A[A[i] - 1]);
        
        for(int i = 0; i < n; ++ i)
            if(A[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
};
