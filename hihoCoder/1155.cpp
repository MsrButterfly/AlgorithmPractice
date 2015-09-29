// http://hihocoder.com/problemset/problem/1155
// http://hihocoder.com/contest/mstest2015april2/problem/3

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

using int_t = long long;
using bool_t = bool;

enum class val_t {
    int_,
    bool_
};

enum class opt_t {
    plu = '+',
    sub = '-',
    mul = '*',
    div = '/',
    grt = '>',
    equ = '=',
    les = '<'
};

struct value {
    value(const int_t &v): int_value_(v), type_(val_t::int_) {}
    value(const bool_t &v): bool_value_(v), type_(val_t::bool_) {}
    union {
        int_t int_value_;
        bool_t bool_value_;
    };
    val_t type_;
};

struct node {
public:
    using pointer = shared_ptr<node>;
    using vars_t = deque<pair<string, ::value>>;
public:
    static pointer construct(istream &in);
    virtual ::value value(vars_t &vars) = 0;
public:
    virtual ~node() {};
};

struct atom_node: node {
public:
    ::value value(vars_t &vars) {
        return value_;
    }
public:
    ::value value_ = {true};
};

struct calc_node: node {
public:
    ::value value(vars_t &vars) {
        auto l = left_->value(vars);
        auto r = right_->value(vars);
        if (l.type_ != val_t::int_ || r.type_ != val_t::int_) {
            throw "Type Mismatch";
        }
        switch (operator_) {
            case opt_t::plu:
                return ::value(l.int_value_ + r.int_value_);
            case opt_t::sub:
                return ::value(l.int_value_ - r.int_value_);
            case opt_t::mul:
                return ::value(l.int_value_ * r.int_value_);
            case opt_t::div:
                if (r.int_value_ == 0) {
                    throw "Division By Zero";
                }
                return ::value(l.int_value_ / r.int_value_);
            case opt_t::les:
                return ::value(l.int_value_ < r.int_value_);
            case opt_t::equ:
                return ::value(l.int_value_ == r.int_value_);
            case opt_t::grt:
                return ::value(l.int_value_ > r.int_value_);
            default:
                throw "Unknown Error";
        }
    }
public:
    pointer left_ = nullptr;
    pointer right_ = nullptr;
    opt_t operator_ = opt_t::plu;
};

struct if_node: node {
public:
    ::value value(vars_t &vars) {
        auto c = condition_->value(vars);
        if (c.type_ != val_t::bool_) {
            throw "Type Mismatch";
        }
        return c.bool_value_ ? true_->value(vars) : false_->value(vars);
    }
public:
    pointer condition_ = nullptr;
    pointer true_ = nullptr;
    pointer false_ = nullptr;
};

struct let_node: node {
public:
    ::value value(vars_t &vars) {
        vars.push_back(make_pair(var_, let_->value(vars)));
        auto v = next_->value(vars);
        vars.pop_back();
        return v;
    }
public:
    string var_ = "";
    pointer let_ = nullptr;
    pointer next_ = nullptr;
};

struct var_node: node {
public:
    ::value value(vars_t &vars) {
        auto p = find_if(vars.rbegin(), vars.rend(), [this](const pair<string, ::value> &pair_) {
            return var_ == pair_.first;
        });
        if (p == vars.rend()) {
            throw "Unbound Identifier";
        } else {
            return p->second;
        }
    }
public:
    string var_ = "";
};

node::pointer node::construct(istream &in) {
    string s;
    in >> s;
    if (s != "(") {
        if (s == "true") {
            auto n = make_shared<atom_node>();
            n->value_ = ::value(true);
            return n;
        } else if (s == "false") {
            auto n = make_shared<atom_node>();
            n->value_ = ::value(false);
            return n;
        } else {
            if (s[0] >= 'a' && s[0] <= 'z') {
                auto n = make_shared<var_node>();
                n->var_ = s;
                return n;
            } else {
                auto n = make_shared<atom_node>();
                stringstream ss;
                ss << s;
                int_t v;
                ss >> v;
                n->value_ = ::value(v);
                return n;
            }
        }
    } else {
        in >> s;
        if (s == "if") {
            auto n = make_shared<if_node>();
            n->condition_ = construct(in);
            n->true_ = construct(in);
            n->false_ = construct(in);
            in >> s;
            return n;
        } else if (s == "let") {
            in >> s;
            auto n = make_shared<let_node>();
            in >> s;
            n->var_ = s;
            n->let_ = construct(in);
            in >> s;
            n->next_ = construct(in);
            in >> s;
            return n;
        } else {
            auto n = make_shared<calc_node>();
            n->operator_ = static_cast<opt_t>(s[0]);
            n->left_ = construct(in);
            n->right_ = construct(in);
            in >> s;
            return n;
        }
    }
}

int main(int argc, const char *argv[]) {
#if MSR_DEBUG
    ifstream fin("1155.in");
    cin.rdbuf(fin.rdbuf());
#endif
    size_t t;
    cin >> t;
    while (t--) {
        auto n = node::construct(cin);
        try {
            auto s = node::vars_t();
            auto v = n->value(s);
            if (v.type_ == val_t::bool_) {
                cout << boolalpha << v.bool_value_;
            } else {
                cout << v.int_value_;
            }
            cout << endl;
        } catch (const char *error) {
            cout << error << endl;
        }
    }
    return EXIT_SUCCESS;
}
