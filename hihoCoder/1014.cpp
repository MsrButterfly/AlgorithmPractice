// http://hihocoder.com/problemset/problem/1014

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

template <class C>
struct node {
public:
    node(): value_(NULL) {}
    node(const C &v): value_(v) {}
    node(const node &another) {
        *this = another;
    }
    node(node &&another) {
        *this = another;
    }
public:
    void insert(const C *s) {
        ++size_;
        if (*s == '\0') {
            return;
        }
        auto result = find(*s);
        auto found = result.first;
        auto index = result.second;
        if (!found) {
            children_.insert(children_.begin() + index, *s);
        }
        children_[index].insert(s + 1);
    }
    const size_t &size() const {
        return size_;
    }
    node *children(const C *s) {
        auto i = s;
        node *n = this;
        while (*s != '\0' && n != nullptr) {
            n = n->children(*s);
            ++s;
        }
        return n;
    }
    node *children(const C &c) {
        auto result = find(c);
        if (result.first) {
            return &children_[find(c).second];
        } else {
            return nullptr;
        }
    }
#if MSR_DEBUG
    void dump(size_t level = 0) {
        cout << string(level * 2, ' ') << "- " << value_ << '\n';
        for (auto &&c : children_) {
            c.dump(level + 1);
        }
    }
#endif
private:
    pair<bool, size_t> find(const C &c) const {
        return find(c, 0, children_.size());
    }
    pair<bool, size_t> find(const C &c, const size_t &left, const size_t &right) const {
        if (left == right) {
            return make_pair(false, left);
        }
        auto i = (left + right) / 2;
        auto value = children_[i].value_;
        if (c < value) {
            return find(c, left, i);
        } else if (c > value) {
            return find(c, i + 1, right);
        } else {
            return make_pair(true, i);
        }
    }
public:
    node &operator=(const node &another) {
        value_ = another.value_;
        size_ = another.size_;
        children_ = another.children_;
        return *this;
    }
    node &operator=(node &&another) {
        value_ = move(another.value_);
        size_ = move(another.size_);
        children_ = move(another.children_);
        return *this;
    }
private:
    C value_;
    size_t size_ = 0;
    vector<node> children_;
};

int main(int argc, const char *argv[]) {
    node<char> root;
    size_t n, m;
#if MSR_DEBUG
    ifstream fin("1014.in");
    cin.rdbuf(fin.rdbuf());
#endif
    cin >> n;
    cin.get();
    for (size_t i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        root.insert(s.c_str());
    }
    cin >> m;
    cin.get();
    for (size_t i = 0; i < m; ++i) {
        string s;
        getline(cin, s);
        auto n = root.children(s.c_str());
        cout << (n ? n->size() : 0) << endl;
    }
    return EXIT_SUCCESS;
}
