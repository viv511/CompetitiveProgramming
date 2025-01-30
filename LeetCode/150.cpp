// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> s;
    string operators = "+-*/";
    int ans = 0;

    for(auto symbol : tokens) {
        if(operators.find(symbol) == std::string::npos) {
            s.push(stoi(symbol));
        }
        else {
            int second = s.top();
            s.pop();
            int first = s.top();
            s.pop();

            if(symbol == "+") {
                s.push(first+second);
            }
            else if(symbol == "-") {
                s.push(first-second);
            }
            else if(symbol == "*") {
                s.push(first*second);
            }
            else {
                s.push(first/second);
            }
        }
    }

    return s.top();
}