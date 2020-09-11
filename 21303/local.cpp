// nowcoder_oi_advance/21303/local.cpp
// https://ac.nowcoder.com/acm/problem/21303
// Created by learntocode1024 on Sep 11 2020.
// 
#include <iostream>
#include <memory.h>
#include <string>
#define MX 55
#define new_node &pool[++iter]
using std::string;
using std::cin;
using std::cout;

int node_id;

struct node {
    // int id = node_id++;
    bool vis = false;
    node* father = nullptr;
    node* sibling = nullptr;
    node* child = nullptr;
    bool islast() {
        if (sibling == nullptr) return true;
        return false;
    }
    bool isleaf() {
        if (child == nullptr) return true;
        return false;
    }
    // bool const operator== (const node& a) {
    //     if (id == a.id) return true;
    //     return false;
    // }
};

node pool[MX];
int iter = 0;

void bracket_tree(node* const root, string s) {
    if (s[0] != '(') return;
    node* curr = root;
    for (char i : s) {
        if (i == '(') {
            if(curr->isleaf()) {
                // add to child
                curr->child = new_node;
                curr->child->father = curr;
                curr = curr->child;
            } else {
                // add to sibling
                curr = curr->child;
                while (!curr->islast()) curr = curr->sibling;
                curr->sibling = new_node;
                curr->sibling->father = curr->father;
                curr = curr->sibling;
            }
        }
        if (i == ')') curr = curr->father;
    }
    return;
}

int main() {
    // set iostream status
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    // input
    string s, t;
    getline(cin, s);
    getline(cin, t);
    node* root_s = new_node;
    bracket_tree(root_s, s);
    bool ans = true;
    node* walk = root_s;
    for (int i : t) {
        if (!ans) break;
        if (i == '(') {
            if (walk->isleaf()) ans = false;
            else {
                walk = walk->child;
                while (walk->vis == true) {
                    if (walk->islast()) {
                        ans = false;
                        break;
                    }
                    else walk = walk->sibling;
                }
                walk->vis = true;
            }
        }
        if (i == ')') walk = walk->father;
    }
    if (ans) cout << "Possible";
    else cout << "Impossible";
    return 0;
}
/*
*/