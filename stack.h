#pragma once
#include "tree.h"

#ifndef STACK_H
#define STACK_H

class Stack {
    node** a;
    int size;
    int head;
public:
    Stack(int nsize = 1000) {
        size = nsize;
        a = new node* [nsize];
        head = 0;
    }
    void add (node* x) {
        if (head == size) throw 3;
        a[head++] = x;
    }
    node* pop () {
        if (head < 1) throw 3;
        return a[--head];
    }
    node* front (){
        if (head < 1) throw 3;
        return a[head - 1];
    }
    int get_head () {
        return head;
    }
};

#endif // STACK_H
