#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui -> pushButton, &QPushButton::clicked, this, &MainWindow::handleButton);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButton()
{
    ui->label->setText("this value will change");
}
