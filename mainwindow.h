#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qrencode.h>

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
    QImage createQRCode(const QString &data, int size);
    ~MainWindow();

private slots:
    void handleNumKey();
    void handlePlusKey();
    void handleEqualKey();

private:
    Ui::MainWindow *ui;
    QString display;
    int opEvent; // 0=none, 1=add
    int val1;
    int val2;
};
#endif // MAINWINDOW_H
