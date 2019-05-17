#include "tree.h"
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

node::node(int n_pr) {
    left = right = nullptr;
    val = "";
    pr = n_pr;
}

node::node(const QString& s, int n_pr) {
    parent = left = right = nullptr;
    val = s;
    pr = n_pr;
}

void node::set_val (const QString& s) {
    val = s;
}

void node::set_pr (int n_pr) {
    pr = n_pr;
}

void node::set_parent (node* t) {
    parent = t;
}

int node::get_pr () {
    return pr;
}
QString node::get_val() {
    return val;
}

void del_node (node* t) {
    if (t == nullptr) throw 2;
    t = t->left;
}

node* add (node* t, const QString& s, int n_pr) {
    node* tmp = new node(s, n_pr);
    tmp->left = t;
    t = tmp;
    return t;
}

void insert (node* t, const QString& s, int n_pr) {
    if (t == nullptr) throw 1;
    t->right = add (t->right, s, n_pr + 1);
}
