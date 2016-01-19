#include <vector>
using namespace std;
#include "gtest/gtest.h"


class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int l = (nums1.size() + nums2.size() -1)/2;
        int r = (nums1.size() + nums2.size())/2;
        return (find(nums1, 0, nums2, 0, l) + find(nums1, 0, nums2, 0, r))/2;
    }

    double find(vector<int>& nums1, int start_1, vector<int>& nums2, int start_2, int kth){
        if(start_1 >= nums1.size()) return nums2[start_2 + kth];
        if(start_2 >= nums2.size()) return nums1[start_1 + kth];
        if(kth == 0) return min(nums1[start_1], nums2[start_2]);

        int mid1 = 0xEFFFFFF, mid2 = 0xEFFFFFF;
        if(kth/2 + start_1 < nums1.size()) mid1 = nums1[kth/2 + start_1];
        if(kth/2 + start_2 < nums2.size()) mid2 = nums2[kth/2 + start_2];
        if(mid1 < mid2) return find(nums1, (kth+1)/2 + start_1, nums2, start_2, kth/2);
        else return find(nums1, start_1, nums2, (kth+1)/2 + start_2, kth/2);
    }
};




//------ revised time O(m+n), space O(1)
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


//------- time: O(m+n) space: O(m+n) -----

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

	Solution2 * solution = new Solution2();
	vector<int> result = solution->merge(nums1, nums2);
	EXPECT_EQ(1, result[0]);
	EXPECT_EQ(2, result[1]);
	EXPECT_EQ(3, result[2]);
	EXPECT_EQ(4, result[3]);
};

TEST_F(Test004, solutionOfDivide){
    vector<int> nums1;
    vector<int> nums2;

    nums1.push_back(1);

    nums2.push_back(1);

    Solution * solution = new Solution();
    EXPECT_EQ(1, solution->find(nums1, 0, nums2, 0, 0));
    EXPECT_EQ(1, solution->find(nums1, 0, nums2, 0, 1));
    EXPECT_EQ(1, solution->findMedianSortedArrays(nums1, nums2));
};

TEST_F(Test004, solutionOfDivide11And12){
    vector<int> nums1;
    vector<int> nums2;

    nums1.push_back(1);
    nums1.push_back(1);

    nums2.push_back(1);
    nums2.push_back(2);

    Solution * solution = new Solution();
    EXPECT_EQ(1, (nums1.size() + nums2.size() -1)/2);
    EXPECT_EQ(2, (nums1.size() + nums2.size())/2);

    EXPECT_EQ(1, solution->find(nums1, 0, nums2, 0, 1));
    EXPECT_EQ(1, solution->find(nums1, 0, nums2, 0, 2));
    EXPECT_EQ(1, solution->findMedianSortedArrays(nums1, nums2));
};

TEST_F(Test004, solutionOfDivide12And12){
    vector<int> nums1;
    vector<int> nums2;

    nums1.push_back(1);
    nums1.push_back(2);

    nums2.push_back(1);
    nums2.push_back(2);

    Solution * solution = new Solution();
    EXPECT_EQ(1, (nums1.size() + nums2.size() -1)/2);
    EXPECT_EQ(2, (nums1.size() + nums2.size())/2);

    EXPECT_EQ(1, solution->find(nums1, 0, nums2, 0, 1));
    EXPECT_EQ(2, solution->find(nums1, 0, nums2, 0, 2));
    EXPECT_EQ(1.5, solution->findMedianSortedArrays(nums1, nums2));
};
