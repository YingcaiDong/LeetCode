#include <iostream>
#include <cmath>
#include <string>
using namespace std;
long int string2num(string s);
long int numbermix(string a, string b);
int main(int argc, char *argv[]) {
	string a = "98417";
	string b = "679";
	long int result = numbermix(a, b);
	printf("%ld", result);
}
long int string2num(string s) {
	long int number = 0;
	for (int i = 0; i < s.size(); i++) {
		number += (int(s[i]) - 48) * pow(10.0, double(s.size() - i - 1));
	}
	return number;
}
long int numbermix(string a, string b) {
	int total_size = a.size() + b.size();
	string str_result = "";
	int a_cnt = 0;
	int b_cnt = 0;
	bool a_used_out = false;
	bool b_used_out = false;
	for (int i = 1; i < total_size+1; i++) {
		bool odd = (i%2 == 1);
		if (odd || b_used_out) {
			if (a_cnt < a.size()) {
				str_result += a[a_cnt];
				a_cnt += 1;
				if (a_cnt == a.size()) {
					a_used_out = true;
				}
			}
		}
		if (!odd || a_used_out) {
			if (b_cnt < b.size()) {
				str_result += b[b_cnt];
				b_cnt += 1;
				if (b_cnt == b.size()) {
					b_used_out = true;
				}
			}
		}
	}
	
	long int result = string2num(str_result);
	if (result > 10000000) {
		return -1;
	} else {
		return result;
	}
}
/*
假设 A B 两个数, A 在前 B 在后, 按位从各自 MSB 交叉填充, 生成一个新的数.
当其中一个数的全部数字全部用完, 另外一个数的剩余未交差数字补充在末尾.
例如 A: 1432 B: 321 则生成 1342312.
输入为两个 string A '1232' B '32'.
A,B 均小于 1*10^7.
结果大于 1*10^7 return -1.
用 c/c++ 编写.
*/
