#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include "httpclient.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void handleRequestResult(const QString& result);


private:
    Ui::MainWindow *ui;
    QStringListModel *model;
    QStringList data;
    HttpClient* httpClient;  // New HttpClient member
};
#endif // MAINWINDOW_H
