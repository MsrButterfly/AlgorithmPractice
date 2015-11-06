// https://leetcode.com/problems/valid-parentheses/
// runtime: O(string.length), space: O(string.length)

#include <cassert>
#include <cstdint>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <complex>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <memory>
#include <numeric>
#include <random>
#include <regex>
#include <string>
#include <tuple>
#include <typeindex>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

class Solution {
public:
    bool isValid(const string &str) {
        stack<char> s;
        for (size_t i = 0; i < str.length(); ++i) {
            auto c = str[i];
            if (c == '(' || c == '[' || c == '{') {
                s.push(c);
            } else if (s.size() == 0) {
                return false;
            } else {
                if (c == ')' && s.top() == '(' ||
                    c == ']' && s.top() == '[' ||
                    c == '}' && s.top() == '{') {
                    s.pop();
                } else {
                    return false;
                }
            }
        }
        if (s.size() > 0) {
            return false;
        }
        return true;
    }
};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("20.in");
    cin.rdbuf(fin.rdbuf());
#endif
    string s;
    while (getline(cin, s)) {
        cout << boolalpha << Solution().isValid(s) << endl;
    }
    return EXIT_SUCCESS;
}
