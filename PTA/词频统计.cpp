// 请编写程序，对一段英文文本，统计其中所有不同单词的个数，以及词频最大的前10%的单词。
// 所谓“单词”，是指由不超过80个单词字符组成的连续字符串，但长度超过15的单词将只截取保留前15个单词字符。而合法的“单词字符”为大小写字母、数字和下划线，其它字符均认为是单词分隔符。
// 输入格式:
// 输入给出一段非空文本，最后以符号#结尾。输入保证存在至少10个不同的单词。
// 输出格式:
// 在第一行中输出文本中所有不同单词的个数。注意“单词”不区分英文大小写，例如“PAT”和“pat”被认为是同一个单词。
// 随后按照词频递减的顺序，按照词频:单词的格式输出词频最大的前10%的单词。若有并列，则按递增字典序输出。
// Input:
// This is a test.
// 
// The word "this" is the word with the highest frequency.
// 
// Longlonglonglongword should be cut off, so is considered as the same as longlonglonglonee.  But this_8 is different than this, and this, and this...#
// this line should be ignored.
// Output:
// 23
// 5:this
// 4:is
/** 
 * 解法1:
 * 1.以单个字符的方式获取输入
 * 2.如果输入的字符可以组成单词, 则该字符放入chars数组中(先判断字符数是否满15(下标到14), 再转化成小写)
 * 3.如果输入的字符不能组成单词, 则以此处为分界, 前面储存的字符构成一个单词
 * 4.将字符们转化为字符串, 并检查map里是否存在该字符串, 若不存在, 则设值为1; 若存在, 则将值+1
 * 5.将map转化为vector, 并以值为key从大到小排序; 若值相同,以单词的字典顺序排序
 * 6.输出前10%的单词及其出现次数
 * 
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
	map<string, int> msi;
	char ch;
	char chars[80];
	int idx = 0;
	while (ch = getchar()) {
		if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9' || ch == '_') {
			if (idx < 15) {
				if (ch >= 'A' && ch <= 'Z')
					ch = ch - 'A' + 'a';
				chars[idx++] = ch; //保留前15个字符
			}
		}
		else if (idx > 0) {
			chars[idx] = 0;//截断
			idx = 0;
			string word = string(chars);
			auto mit = msi.find(word);
			if (mit == msi.end())
				msi.insert(make_pair(move(word), 1));
			else
				++(mit->second);
		}
		if (ch == '#')//先添加
			break;
	}
	multimap<int, string> mis;
	for_each(msi.begin(), msi.end(), [&mis](auto& it) {
		mis.insert(make_pair(it.second, it.first));
	});
	idx = 0;
	int sz = mis.size();
	cout << sz << "\n";
	for (auto it = mis.rbegin(); idx != sz / 10; ++it, ++idx) {
		if (idx == sz - 1)
			cout << it->first << ":" << it->second;
		else
			cout << it->first << ":" << it->second << "\n";
	}
	// vector<pair<string, int>> v;
	// for (auto it = msi.begin(); it != msi.end(); it++) {
	// 	v.push_back(make_pair(it->first, it->second));
	// }
	// sort(v.begin(), v.end(), [](auto a, auto b) {
	// 	if (a.second != b.second)
	// 		return a.second > b.second;
	// 	else
	// 		return a.first < b.first;
	// });
	// cout << v.size() << endl;
	// int ans = v.size() / 10;
	// for (auto itv = v.begin(); itv != v.begin() + ans; itv++) {
	// 	cout << itv->second << ":" << itv->first << endl;
	// }
	return 0;
}
