#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tree.h"
#include <iostream>
#include "stack.h"

using namespace std;

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
    QString text;
    for (int i = 0; i < t.t->pr; i++) text += " ";
    text += ui->textEdit->text();
    ui->textEdit->clear();
    ui->textEdit->setFocus();
    QListWidgetItem* nitem = new QListWidgetItem (text);
    int pos = ui->listWidget->row(t.add(nitem));
    ui->listWidget->insertItem(pos + 1, t.t->item);
    ui->listWidget->setCurrentItem(t.t->item);
}

void MainWindow::on_ins_button_clicked()
{
    QString text;
    for (int i = 0; i <= t.t->pr; i++) text += " ";
    text += ui->textEdit->text();
    ui->textEdit->clear();
    ui->textEdit->setFocus();
    QListWidgetItem* nitem = new QListWidgetItem (text);
    int pos = ui->listWidget->row(t.insert(nitem));
    ui->listWidget->insertItem(pos + 1, t.t->item);
    ui->listWidget->setCurrentItem(t.t->item);
}

void MainWindow::on_up_button_clicked()
{
    t.up();
    ui->listWidget->setCurrentItem(t.t->item);
    ui->textEdit->setFocus();
}

void MainWindow::on_down_button_clicked()
{
    t.down();
    ui->listWidget->setCurrentItem(t.t->item);
    ui->textEdit->setFocus();
}

void MainWindow::on_pushButton_clicked()
{
    t.up_level ();
    ui->listWidget->setCurrentItem(t.t->item);
    ui->textEdit->setFocus();
}

void MainWindow::on_pushButton_2_clicked()
{
    t.down_level();
    ui->listWidget->setCurrentItem(t.t->item);
    ui->textEdit->setFocus();
}

void MainWindow::on_ch_button_clicked()
{
    QString text;
    for (int i = 0; i < t.t->pr; i++) text += " ";
    text += ui->textEdit->text();
    ui->textEdit->clear();
    ui->textEdit->setFocus();
    t.change(text);
}

void MainWindow::on_del_button_clicked()
{
    t.del();
    ui->listWidget->setCurrentItem(t.t->item);
    ui->textEdit->setFocus();
}
