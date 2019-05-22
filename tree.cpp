#include "tree.h"
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

node::node() {
    left = right = nullptr;
    s = "";
    pr = 0;
}
node::node(QString ns, int npr) {
    left = right = nullptr;
    s = ns;
    pr = npr;
}
node::node(node* t) {
    left = t->left;
    right = t->right;
    s = t->s;
    pr = t->pr;
}
node::~node() {
    delete left;
    delete right;
}

tree::tree() {
    root = new node();
    t = root;
}

void tree::add (QString ns) {
    node* n = new node(ns, t->pr);
    while (t->left != nullptr) {
        t = t->left;
    }
    t->left = n;
    t = t->left;
}
void tree::insert (QString ns) {
    node* n = new node(ns, t->pr + 1);
    if (t->right == nullptr) { t->right = n; t = t->right; }
    else {
        t = t->right;
        while (t->left != nullptr) t = t->left;
        t->left = n;
        t = t->left;
    }
}
