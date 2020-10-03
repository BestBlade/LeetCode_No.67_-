/* ------------------------------------------------------------------|
给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。

 

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
 

提示：

每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-binary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
------------------------------------------------------------------*/

/*	reverse反转
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了77.75%的用户
*	内存消耗：6.2 MB;, 在所有 C++ 提交中击败了98.85%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

string addBinary(string a, string b) {
	if (a.size() < b.size()) {
		return addBinary(b, a);
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int flag = 0;
	char c;

	for (int i = 0; i < a.size(); i++) {
		if (i >= b.size()) {
			c = a[i] + flag - '0';
		}
		else {
			c = a[i] + b[i] - '0' + flag;
		}
		flag = 0;


		if (c >= '2') {
			c -= 2;
			flag = 1;
		}
		a[i] = c;
	}
	if (flag) {
		a.push_back('1');
	}

	reverse(a.begin(), a.end());

	return a;

}

int main() {
	string a = "1010";
	string b = "1011";
	
	string ans = addBinary(a, b);
}