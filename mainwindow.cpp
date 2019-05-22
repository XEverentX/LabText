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

