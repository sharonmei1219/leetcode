#include <string>
#include "gtest/gtest.h"
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
    	int maxLength = 0, maxStart = 0;
    	for(string::size_type i = 0; i < s.size(); i++){
    		for(int start = i; start <= i+1; start++){
	    		int l = longestPalindromeFrom(start, i, s);
	    		if(l > maxLength){
	    			maxLength = l;
	    			maxStart = start - maxLength/2;
	    		}
    		}
    	}
    	return s.substr(maxStart,maxLength);
    }

    int longestPalindromeFrom(string::size_type start, string::size_type end, string s){
    	while(start >= 0 && end < s.size() && s[start] == s[end]){
    		end++;
    		start--;
    	}
    	return end - start - 1;
    }
};

class Test005 : public ::testing::Test{
};

TEST_F(Test005, testLongestPalindromeFrom){
	Solution *sl = new Solution();
	EXPECT_EQ (1, sl->longestPalindromeFrom(0, 0, "abc"));
	EXPECT_EQ (5, sl->longestPalindromeFrom(2, 2, "abcba"));
	EXPECT_EQ (6, sl->longestPalindromeFrom(3, 2, "abccba"));
	EXPECT_EQ (1, sl->longestPalindromeFrom(4, 4, "abccba"));
}

TEST_F(Test005, testSubStr){
	EXPECT_EQ ("a", string("abc").substr(0, 1));
	EXPECT_EQ ("ab", string("abc").substr(0, 2));
	EXPECT_EQ ("abc", string("abc").substr(0, 3));
}

TEST_F(Test005, testLongestFunction){
	Solution *sl = new Solution();
	EXPECT_EQ ("bcb", sl->longestPalindrome("abcbe"));
	EXPECT_EQ ("bb", sl->longestPalindrome("bb"));
}
