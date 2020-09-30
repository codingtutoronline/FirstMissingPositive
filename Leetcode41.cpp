Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]>0 && nums[i]<=nums.size() && nums[nums[i]-1]!=nums[i])
                 swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=i+1) return i+1;
         return nums.size()+1;
    }
};

// I am adding another solution which is more optimised
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st;
        int target = 1;
        
        for(int item:nums){ 
            st.insert(item);
        }
        
        for(auto it = st.begin();it!=st.end();it++){
            int currentItem = *it;
            
            if(target < currentItem){
                return target;
            }
            if(target == currentItem){
                target++;
            }
        }
        
        return target;
    }
};


// Python Solution
# T: O(n^2) 
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        size = len(nums)
        
        for i in range(1, size+1):
            if i not in nums:
                return i
        return size + 1

#T: O(nlogn)
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.sort()
        counter = 1
        for i in nums:
            if i == counter:
                counter += 1
        return counter

#T: O(n) S: O(n)
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        dic = {}
        size = len(nums)
        
        for i in nums:
            dic[i] = i
        
        for i in range(1, size+1):
            if i not in dic:
                return i
        return size + 1

 #T: O(n) S: O(1)
 class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        size = len(nums)
        
        for i in range(size):
            if nums[i] <= 0 or nums[i] > size:
                nums[i] = size + 1
        
        for number in nums:
            number = abs(number)
            if number <= len(nums) and nums[number-1] >= 0:
                nums[number-1] *= -1
                
        for i in range(size):
            if nums[i] > 0:
                return i + 1
        return size + 1

