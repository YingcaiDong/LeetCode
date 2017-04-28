#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

int string2num(string s, int strlen);
int like_stack(string s);

int main(int argc, char *argv[]) {
	std::string input = "13 DUP 4 POP 5 + - DUP POP";
	
	int read = like_stack(input);
	printf("%d", read);
}

int string2num(string s) {
	int number = 0;
	for (int i = 0; i < s.size(); i++) {
		number += (int(s[i]) - 48) * pow(10.0, double(s.size() - i - 1));
	}
	return number;
}

int like_stack(string s) {
	string numberstr = "";
	std::stack<int> num_stack;
	int s_size = int(s.size());
	int prev_id = s[0];
	
	for(int i = 0; i < s_size; i++) {
		// char to int
		int char_id = s[i];
		
		bool numberStart = (char_id >= 48 && char_id <= 57);
		bool numberEnd1 = (prev_id >= 48 && prev_id <= 57 && char_id == 32);
		bool numberEnd2 = (s_size == i+1 && char_id >= 48 && char_id <= 57);
		int realnum = 0;
		// numbers start and continue
		if(numberStart) {
			numberstr += s[i];
		}
		// number end
		if(numberEnd1 || numberEnd2) {
			realnum = string2num(numberstr);
			num_stack.push(realnum);
			// empty var waite reload
			numberstr = "";
		}
		
		bool DUP_en = (char_id == 80 && prev_id == 85);
		bool POP_en = (char_id == 80 && prev_id == 79);
		// instructions
		if (DUP_en) {
			if (num_stack.empty()) {
				return -1;
			} else {
				int temp_top = num_stack.top();
				num_stack.push(temp_top);
			}
		}
		if (POP_en) {
			if (num_stack.empty()) {
				return -1;
			} else {
				num_stack.pop();
			}
		}
		
		bool add_en = (char_id == 43);
		bool sub_en = (char_id == 45);
		if (add_en) {
			if (num_stack.size() < 2) {
				return -1;
			} else {
				int tempA = num_stack.top();
				num_stack.pop();
				int tempB = num_stack.top();
				num_stack.pop();
				num_stack.push(tempA + tempB);
			}
		}
		if (sub_en) {
			if (num_stack.size() < 2) {
				return -1;
			} else {
				int tempA = num_stack.top();
				num_stack.pop();
				int tempB = num_stack.top();
				num_stack.pop();
				if (tempA - tempB < 0) {
					return -1;
				} else {
					num_stack.push(tempA - tempB);
				}
			}
		}
		prev_id = char_id;
	}
	return num_stack.top();
}

/*
实现 stack 的功能.
输入为 '13 DUP 4 POP 5 DUP 6 + POP - 8' 的字符串(string), 以空格隔开
数字代表 push, DUP 代表 push 一个等于 top 的数字, POP 代表 pop, + 代表 pop 出两个数相加后 push, - 代表 pop 出两个数 top1 - top2 后 push
特殊情况处理: stack.size()  <= 1 时无法 + 或 -, 因此 return -1. stack.size() == 0 时无法 POP 或 DUP 因此 return -1, 相减后小于0 return -1.
其余情况 return stack.top
用 c/c++ 编写
*/
