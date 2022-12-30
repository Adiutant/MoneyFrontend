#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    QFile file;
        globPath = QFileDialog::getOpenFileName(nullptr, "", "C:\\Users\Eduard\\Desktop\\QT","*.json");
        file.setFileName(globPath);
        if(file.open(QIODevice::ReadOnly|QFile::Text))
        {
            doc = QJsonDocument::fromJson(QByteArray(file.readAll()),&docError);
        }
file.close();
QStandardItemModel* model = new QStandardItemModel(nullptr);
model->setHorizontalHeaderLabels(QStringList()<<"name"<<"age"<<"telephone");

QStandardItem* item_col_1 = new QStandardItem(doc.object().value("name").toString());
QStandardItem* item_col_2 = new QStandardItem(QString::number(doc.object().value("age").toInt()));
QStandardItem* item_col_3 = new QStandardItem(doc.object().value("tel").toString());

model->appendRow(QList<QStandardItem*>()<<item_col_1<<item_col_2<<item_col_3);

ui->tableView->setModel(model);
}

