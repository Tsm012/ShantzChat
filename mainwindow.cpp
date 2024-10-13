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


    // Initialize HttpClient
    httpClient = new HttpClient(this);
    connect(httpClient, &HttpClient::requestFinished, this, &MainWindow::handleRequestResult);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QUrl url("http://www.google.com");
    httpClient->sendGetRequest(url);
}


void MainWindow::handleRequestResult(const QString& result)
{
    // Display the result of the HTTP request in the textEdit
    data.append(result);
    model->setStringList(data);
}
