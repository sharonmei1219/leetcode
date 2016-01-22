#include "gtest/gtest.h"

#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastOccurrence[256];
        for(int i = 0; i < 256; i++) lastOccurrence[i] = -1;
        int subStringStart = 0, maxLength = 0, length = 0;

        for(string::size_type i = 0; i < s.size(); i++){
            int lastOcc = lastOccurrence[(int)s[i]];
            if(lastOcc < subStringStart){
                length ++;
            }else{
                if(length > maxLength){
                    maxLength = length;
                }
                length = i - lastOcc;
                subStringStart = lastOcc + 1;
            }
            lastOccurrence[(int)s[i]] = i;
        }
        
        if(length > maxLength) return length;
        return maxLength;
    }
};

class TestLengthOfLongestSubString : public ::testing::Test{
};

TEST_F(TestLengthOfLongestSubString, testArrayInit){
	Solution *solution = new Solution();
    EXPECT_EQ(1, solution->lengthOfLongestSubstring("c"));
}
