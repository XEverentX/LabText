#include "tree.h"
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

node::node(QListWidgetItem* nitem) {
    left = right = parent = nullptr;
    item = nitem;
    pr = 0;
}
node::node(QListWidgetItem* nitem, int npr) {
    left = right = parent = nullptr;
    item = nitem;
    pr = npr;
}
node::node(node* t) {
    left = t->left;
    right = t->right;
    item = t->item;
    pr = t->pr;
}
node::~node() {
    delete left;
    delete right;
    delete parent;
    delete item;
}

tree::tree() {
    QListWidgetItem* nitem = new QListWidgetItem ("");
    root = new node(nitem);
    t = root;
}

QListWidgetItem* tree::get_last (node* nt) {
    while (nt->left != nullptr) nt = nt->left;
    if (nt->right == nullptr) return nt->item;
    nt = nt->right;
    return get_last (nt);
}

QListWidgetItem* tree::add (QListWidgetItem* nitem) {
    node* n = new node(nitem, t->pr);
    while (t->left != nullptr) {
        t = t->left;
    }
    QListWidgetItem* ans = get_last(t);
    t->left = n;
    t->left->parent = t;
    t = t->left;
    return ans;
}
 QListWidgetItem* tree::insert (QListWidgetItem* nitem) {
    node* n = new node(nitem, t->pr + 1);
    if (t->right == nullptr) {
        t->right = n;
        t->right->parent = t;
        t = t->right;
        return t->parent->item;
    }
    else {
        QListWidgetItem* ans = get_last(t->right);
        t = t->right;
        while (t->left != nullptr) t = t->left;
        t->left = n;
        t->left->parent = t;
        t = t->left;
        return ans;
    }
}
void tree::up() {
    if (t->parent != nullptr && t->parent->pr == t->pr) t = t->parent;
}

void tree::down() {
    if (t->left != nullptr) t = t->left;
}

void tree::up_level() {
    if (t->pr == 0) return;
    node* mem = t;
    while (t->parent != nullptr && t->parent->pr == t->pr) t = t->parent;
    if (t->parent == nullptr) t = mem;
    else t = t->parent;
}

void tree::down_level() {
    if (t->right != nullptr) t = t->right;
}
