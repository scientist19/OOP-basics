#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "randomvaluewidget.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ScrollWidget = new QWidget;
    ScrollWidget->setLayout(new QVBoxLayout());
//    ScrollWidget->setMaximumWidth(400);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    ui->scrollArea->setWidget(ScrollWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addRandomValues(){

    RandomValueWidget* randomValue = new RandomValueWidget();
    ScrollWidget->layout()->addWidget(randomValue);
}
