#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QStringList data;
    data << "Item 1" << "Item 2" << "Item 3" << "Item 4" << "Item 5";
    auto model = new QStringListModel(this);
    model->setStringList(data);
    ui->listView->setModel(model);
}

