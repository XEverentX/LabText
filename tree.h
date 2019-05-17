#pragma once
#ifndef TREE_H
#define TREE_H
#include <string>
#include <QMainWindow>

using namespace std;

class node {
    int pr;
    QString val;
public:
    node* left;
    node* right;
    node* parent;
    node(int n_pr);
    node(const QString& s, int n_pr);
    void set_val (const QString& s);
    void set_pr (int n_pr);
    void set_parent (node* t);
    int get_pr ();
    QString get_val();

};

void del_node (node* t);

node* add (node* t, const QString& s, int n_pr);

void insert (node* t, const QString& s, int n_pr);


#endif // TREE_H
