// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// runtime: O(list.size), space: O(1)

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head->next) {
            delete head;
            return nullptr;
        }
        size_t size = 0;
        ListNode *node = nullptr, *prev = nullptr;
        for (ListNode *p = head; p; p = p->next, ++size) {
            if (size == n - 1) {
                node = head;
            }
            if (size == n) {
                prev = head;
            }
            if (size > n - 1) {
                node = node->next;
            }
            if (size > n) {
                prev = prev->next;
            }
        }
        if (prev) {
            prev->next = node->next;
        }
        if (node == head) {
            head = head->next;
        }
        delete node;
        return head;
    }
};

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("19.in");
    cin.rdbuf(fin.rdbuf());
#endif
    size_t m, n;
    cin >> m >> n;
    auto start = new ListNode(0);
    auto current = start;
    int num;
    for (size_t i = 0; i < m; ++i) {
        cin >> num;
        current->next = new ListNode(num);
        current = current->next;
    }
    auto head = start->next;
    delete start;
    Solution().removeNthFromEnd(head, n);
    for (auto node = head; node; node = node->next) {
        cout << node->val << ' ';
    }
    cout << endl;
    while (head) {
        auto node = head;
        head = head->next;
        delete node;
    }
    return EXIT_SUCCESS;
}
