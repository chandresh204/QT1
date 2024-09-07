#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui -> pushButton, &QPushButton::clicked, this, &MainWindow::play);
}

void MainWindow::play()
{
    cout << "button clicked";
}

MainWindow::~MainWindow()
{
    delete ui;
}
