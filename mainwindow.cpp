#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tree.h"
#include <iostream>
#include "stack.h"

using namespace std;

node* t = new node(1);

int n = 0;
int row = 0;

Stack l, r;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_button_clicked()
{
    QString s = ui->textEdit->text();
    ui->textEdit->clear();
    add (t, s, (t == nullptr ? 1 : t->get_pr()));
    QString wsp;
    for (int i = 0; i < t->get_pr(); i++) wsp += ' ';
    ui->listWidget->insertItem(row, wsp + s);
    ui->listWidget->setCurrentRow(row);
    n++;
    r.add (t);
    ui->textEdit->setFocus();
}

void MainWindow::on_ins_button_clicked()
{
    //if (!n) throw 4;
    QString s = ui->textEdit->text();
    ui->textEdit->setFocus();
    ui->textEdit->clear();
    insert (t, s, t->get_pr());
    t = t->right;
    QString wsp;
    for (int i = 0; i < t->get_pr(); i++) wsp += ' ';
    ui->listWidget->insertItem(++row, wsp + s);
    ui->listWidget->setCurrentRow(row);
    n++;
    l.add (r.pop());
    r.add (t);
    ui->textEdit->setFocus();
}

void MainWindow::on_up_button_clicked()
{
    if (row > 0) {
        ui->listWidget->setCurrentRow(--row);
        t = l.pop();
        r.add (t);
    }
    ui->textEdit->setFocus();
}

void MainWindow::on_down_button_clicked()
{
    if (row < n - 1) {
        ui->listWidget->setCurrentRow(++row);
        l.add (r.pop());
        t = r.front();
    }
    ui->textEdit->setFocus();
}

void add_from_str (int pr, QString& s) {
    node* tmp = t;

    int k = 0;
    while (tmp->get_pr() > pr) {
        tmp = l.pop();
        r.add(tmp);
        k++;
    }
    node* nt = new node (s, pr);
    if (tmp->get_pr() == pr) tmp->left = nt;
    else {
        tmp->right = nt;
    }
    for (int i = 0; i < k; i++) {
        l.add (r.pop());
    }
    l.add(nt);

}

void MainWindow::on_pushButton_clicked()
{
    QString qs = ui->file_name->text();
    freopen (qs.toUtf8().constData(),"r", stdin);
    string s;

    int old = 1;
    while (getline(cin, s)) {
        QString res;
        int k = 1;
        bool flag = true;
        for (int i = 0; i < int(s.size()); i++) {
            if (flag && s[i] == ' ') k++;
            else {
                flag = false;
                res += s[i];
            }
        }
        int step;
        if (k > old) old++, step = 1;
        else
            if (k < old) old--, step = -1;
            else
                step = 0;
        QString wsp;
        for (int i = 0; i < old; i++) wsp += ' ';
        QString ans = wsp + res;
        add_from_str(old, res);
        ui->listWidget->insertItem(row++, ans);
        ui->listWidget->setCurrentRow(row);
        n++;
    }
}
