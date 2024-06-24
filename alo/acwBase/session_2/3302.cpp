#include <bits/stdc++.h>

using namespace std;

stack<int> num;
stack<char> op;

void eval() {
	int b = num.top();
	num.pop();
	int a = num.top();
	num.pop();

	char c = op.top();
	op.pop();

	int ans = 0;
	if (c == '+') {
		ans = a + b;
	} else if (c == '-') {
		ans = a - b;
	} else if (c == '*') {
		ans = a * b;
	} else if (c == '/') {
		ans = a / b;
	}
	num.push(ans);
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

    string tt;
    cin >> tt;

   	unordered_map<char, int> pri = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    for (int i = 0; i < tt.size(); i ++) {
    	auto c = tt[i];
    	if (isdigit(c)) {
    		int ans = 0;
    		int j = i;
    		while (j < tt.size() && isdigit(tt[j])) {
    			ans = ans * 10 + tt[j ++] - '0';
    		}
    		num.push(ans);
    		i = j - 1;
    	} else if (c == '(') {
    		op.push(c);
    	} else if (c == ')') {
    		while (op.top() != '(') eval();
    		op.pop();
    	} else {
    		while (op.size() && pri[op.top()] >= pri[c]) eval();
    		op.push(c);
    	}
    }


   	while (op.size()) eval();

   	cout << num.top() << endl;
    

	return 0;
}