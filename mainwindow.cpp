#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qrencode.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    display(""),
    opEvent(0),
    val1(0),
    val2(0)
{
    ui->setupUi(this);
    connect(ui->btn_1, &QPushButton::clicked, this, &MainWindow::handleNumKey);
    connect(ui->btn_2, &QPushButton::clicked, this, &MainWindow::handleNumKey);
    connect(ui->btn_3, &QPushButton::clicked, this, &MainWindow::handleNumKey);
    connect(ui->btn_add, &QPushButton::clicked, this, &MainWindow::handlePlusKey);
    connect(ui->btn_eql, &QPushButton::clicked, this, &MainWindow::handleEqualKey);
}

QImage MainWindow::createQRCode(const QString &data, int size = 300) {
    QRcode *qr = QRcode_encodeString(data.toUtf8().constData(), 0, QR_ECLEVEL_Q, QR_MODE_8, 1);
    if (!qr) return QImage();

    QImage image(qr->width, qr->width, QImage::Format_RGB32);
    image.fill(Qt::white);

    for (int y = 0; y < qr->width; y++) {
        for (int x = 0; x < qr->width; x++) {
            QColor color = (qr->data[y * qr->width + x] & 0x01) ? Qt::black : Qt::white;
            image.setPixelColor(x, y, color);
        }
    }

    QRcode_free(qr);
    return image.scaled(size, size, Qt::KeepAspectRatio);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleNumKey() {
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    QString str = btn->text();
    if(opEvent == 0) {
        display += str;
        ui->label->setText(display);
    } else {

    }
}

void MainWindow::handlePlusKey() {
    opEvent = 1;
    ui->op_sign->setText(QString("+"));
    val1 = val1 + display.toInt();
    ui->label->setText(QString::number(val1));
}

void MainWindow::handleEqualKey() {
    opEvent = 0;
    val2 = display.toInt();
    val1 =val1 + val2;
    ui->label->setText(QString::number(val1));
    ui->op_sign->setText("=");
}
