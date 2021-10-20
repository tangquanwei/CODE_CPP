#include <bits/stdc++.h>

using namespace std;
/**
 * 
 */
class Solution {
public:
	static string minWindow(string s, string t) {
		int start = 0, minLen = INT_MAX;
		// 定义左右指针
		int left = 0, right = 0;
		// 先定义两个计数器
		unordered_map<char, int> window;
		unordered_map<char, int> needs;
		// 将待匹配字符串添加到needs
		for (char c : t)
			needs[c]++;
		// 完全匹配的字符数
		int match = 0;
		// 扩大右边
		while (right < s.size()) {
			char c1 = s[right];
			if (needs.count(c1)) {			 // needs中存在c1
				window[c1]++;				 //加入window
				if (window[c1] == needs[c1]) // 字符的个数也满足
					match++;
			}
			right++; // 指针后移
			// 收缩左边
			while (match == needs.size()) {
				if (right - left < minLen) { //更新minLen
					start = left;
					minLen = right - left;
				}
				char c2 = s[left];
				if (needs.count(c2)) {
					window[c2]--;
					if (window[c2] < needs[c2]) // 字符的个数不满足
						match--;
				}
				left++;
			}
		}
		return minLen == INT_MAX ? "" : s.substr(start, minLen);
	}
};


int main() {

	string s = "asdfgbhsaasaajkl";
	string t = "aaabs";
	cout << Solution::minWindow(s, t);
	// cout << s.substr(1, 5);

	return 0;
}