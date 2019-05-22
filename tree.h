#pragma once
#ifndef TREE_H
#define TREE_H
#include <string>
#include <QMainWindow>
#include <QString>
#include <QListWidgetItem>

using namespace std;

struct node {
    int pr;
    node* left;
    node* right;
    node* parent;
    QListWidgetItem* item;
    node(QListWidgetItem* nitem);
    node(QListWidgetItem* nitem, int npr);
    node(node* t);
    ~node();
};

struct tree {
    node* root;
    node* t;
    tree();
    QListWidgetItem* get_last (node* nt);
    QListWidgetItem* add (QListWidgetItem* nitem);
    QListWidgetItem* insert (QListWidgetItem* nitem);
    void up ();
    void down();
    void up_level ();
    void down_level();
};




#endif // TREE_H
