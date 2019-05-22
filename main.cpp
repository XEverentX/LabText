#include "mainwindow.h"
#include <QApplication>
#include <iostream>

using namespace std;

void pus (node* t) {
    if (t == nullptr) return;
    cout << string(t->s.toUtf8()) << endl;
    pus (t->left);
    pus (t->right);
}

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/
    tree tr;
    tr.add ("F1");
    tr.insert("FG2");
    tr.add ("F3");
    tr.t = tr.root;
    tr.add ("G@#");
    tr.t = tr.root;
    cout << "fsdf" << endl;
    pus (tr.t);

}
