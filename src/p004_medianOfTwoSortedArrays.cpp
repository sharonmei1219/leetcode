#include <vector>
using namespace std;
#include "gtest/gtest.h"


class Solution1{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        vector<int>::iterator it1 = nums1.begin(), it2 = nums2.begin();
        int count = 0;
        const int mid = (nums1.size() + nums2.size())/2;

        while(it1 != nums1.end() && it2 != nums2.end() && count < mid){
            if(*it1 < *it2) it1 ++;
            else it2 ++;
            count ++;
        }

        if (count < mid && it1 != nums1.end()){
            it1 += mid - count;
            if(mid%2 == 1) return *it1;
            else return ((double)(*it1) + (*(it1+1)))/2;
        }

        if (count < mid && it2 != nums2.end()){
            it2 += mid - count;
            if(mid%2 == 1) return *it2;
            else return ((double)(*it2) + (*(it2+1)))/2;
        }

        if(*it1 < *it2){
            if(mid%2 == 1) return *it1;
            else return ((double)(*it1 + min(*(it1+1), *it2)))/2;
        }else{
            if(mid%2 == 1) return *it2;
            else return ((double)(*it2 + min(*(it2+1), *it1)))/2;
        }
    }

};




class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	vector<int> mergedArray = merge(nums1, nums2);
    	if(mergedArray.size()%2 == 1)
	    	return mergedArray[mergedArray.size()/2];
	    return ((double)(mergedArray[mergedArray.size()/2] + mergedArray[mergedArray.size()/2 - 1]))/2;
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
    	vector<int> result;
    	vector<int>::iterator iterNums1 = nums1.begin();
    	vector<int>::iterator iterNums2 = nums2.begin();
    	while(iterNums2 !=nums2.end() && iterNums1 != nums1.end()){
    		if(*iterNums2 < *iterNums1){
    			result.push_back(*iterNums2);
    			iterNums2 ++;
    		}else{
    			result.push_back(*iterNums1);
    			iterNums1 ++;
    		}
    	}
    	while(iterNums1 != nums1.end()){
    		result.push_back(*iterNums1);
    		iterNums1 ++;
    	}
    	while(iterNums2 != nums2.end()){
    		result.push_back(*iterNums2);
    		iterNums2 ++;
    	}
    	return result;
    }
};

class Test004 : public ::testing::Test{
};

TEST_F(Test004, merge2Vectors){
	vector<int> nums1;
	vector<int> nums2;

	nums1.push_back(1);
	nums1.push_back(3);

	nums2.push_back(2);
	nums2.push_back(4);

	Solution * solution = new Solution();
	vector<int> result = solution->merge(nums1, nums2);
	EXPECT_EQ(1, result[0]);
	EXPECT_EQ(2, result[1]);
	EXPECT_EQ(3, result[2]);
	EXPECT_EQ(4, result[3]);
};
