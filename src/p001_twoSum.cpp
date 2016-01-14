#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include "gtest/gtest.h"
using namespace std;

//--- revised ---
class RevisedSolution{
public: 
    vector<int> twoSum(vector<int>& nums, int target){
        map<int, int> indexLookUp;
        int index = 0;
        while (index != nums.size()){
            map<int, int>::iterator it = indexLookUp.find(target - nums[index]);
            if(it != indexLookUp.end()){
                vector<int> result;
                result.push_back(it->second);
                result.push_back(index);
                return result;
            }
            indexLookUp[nums[index]] = index;
            index++;
        }
    }
};

// --- origin ---

class IndexCompare{
public:
    IndexCompare(vector<int> & array):array(array){}
    const vector<int>  & array;
    bool operator()(int a, int b) const {return array[a] < array[b];}
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index;
        for(size_t i = 0; i < nums.size(); i++)
            index.push_back(i);
        sort(index.begin(), index.end(), IndexCompare(nums));


        int front = 0, back = index.size() - 1;
        int sum = nums[index[front]] + nums[index[back]];
        while (front != back && sum != target){
            if (sum > target){
                back = back - 1;
                sum = nums[index[front]] + nums[index[back]];
            }
            else if(sum < target){
                front = front + 1;
                sum = nums[index[front]] + nums[index[back]];
            }
        }

        vector<int> result;
        if(index[front] > index[back]){
            result.push_back(index[back] + 1);
            result.push_back(index[front] + 1);
        }else{
            result.push_back(index[front] + 1);
            result.push_back(index[back] + 1);
        }
        return result;
    }
};

class TestTwoSum : public ::testing::Test{
};

TEST_F(TestTwoSum, sortedIndex){
	vector<int> nums;
	vector<int> index;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);


	for(size_t i = 0; i < nums.size(); i++)
		index.push_back(i);
	sort(index.begin(), index.end(), IndexCompare(nums));

	EXPECT_EQ(0, index[0]);
	EXPECT_EQ(1, index[1]);
	EXPECT_EQ(2, index[2]);
};
