// https://leetcode.com/problems/add-two-numbers/
// runtime: O(n), space: O(1)

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
#include <utility>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ret = nullptr;
        ListNode *c = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int sum = a + b + carry;
            carry = sum / 10;
            sum %= 10;
            if (!ret) {
                ret = new ListNode(sum);
                c = ret;
            } else {
                c->next = new ListNode(sum);
                c = c->next;
            }
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        if (carry) {
            c->next = new ListNode(1);
        }
        return ret;
    }
};

ListNode *input() {
    size_t n;
    ListNode *ret = nullptr;
    ListNode *c = nullptr;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        int v;
        cin >> v;
        auto n = new ListNode(v);
        if (!ret) {
            ret = n;
            c = n;
        } else {
            c->next = n;
            c = n;
        }
    }
    return ret;
}

void output(ListNode *n) {
    while (n) {
        cout << n->val << ' ';
        n = n->next;
    }
    cout << endl;
}

void dealloc(ListNode *n) {
    while (n) {
        auto c = n;
        n = n->next;
        delete c;
    }
}

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("2.in");
    cin.rdbuf(fin.rdbuf());
#endif
    auto l1 = input();
    auto l2 = input();
    auto result = Solution().addTwoNumbers(l1, l2);
    output(result);
    dealloc(l1);
    dealloc(l2);
    dealloc(result);
    return EXIT_SUCCESS;
}
