#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStringListModel(this);
    data.append("Weclome To Shantz Chat");
    model->setStringList(data);
    ui->listView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    data.append(ui->textEdit->toPlainText());
    model->setStringList(data);
}
