#pragma once
#ifndef TREE_H
#define TREE_H
#include <string>
#include <QMainWindow>
#include <QString>

using namespace std;

struct node {
    int pr;
    QString s;
    node* left;
    node* right;
    node();
    node(QString ns, int npr);
    node(node* t);
    ~node();
};

struct tree {
    node* root;
    node* t;
    tree();
    void add (QString ns);
    void insert (QString ns);
};




#endif // TREE_H
