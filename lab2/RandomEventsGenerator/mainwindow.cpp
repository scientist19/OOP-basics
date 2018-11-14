#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "randomvaluewidget.h"

#include <QVBoxLayout>
#include <QtGui>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ScrollWidget = new QWidget();
    ScrollWidget->setLayout(new QVBoxLayout());
//    ScrollWidget->setMaximumWidth(400);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    ui->scrollArea->setWidget(ScrollWidget);

    ScrollWidget2 = new QWidget();
    ScrollWidget2->setLayout(new QVBoxLayout());
    ScrollWidget2->layout()->setSpacing(12);
    ui->scrollArea_2->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    ui->scrollArea_2->setWidget(ScrollWidget2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addRandomValues(){

    static int ind = -1;
    if (randomValuesNumber < ui->randomValuesNumber->value()){

        for (int i = randomValuesNumber; i < ui->randomValuesNumber->value(); i++){

            RandomValueWidget* randomValue = new RandomValueWidget();

            randomValue->setLabelValue("Value #" + QString::number(i+1));
            randomValue->setLabelProbability("Probaility " + QString::number(i+1));
            randomValue->setValue(i+1);
            connect(randomValue->probabilityWidget(), SIGNAL(valueChanged(double)),this, SLOT(onProbabilityChange()));
            connect(randomValue->probabilityWidget(), SIGNAL(valueChanged(double)),this, SLOT(onNumberChange()));

            ScrollWidget->layout()->addWidget(randomValue);
            RandomValuesList.push_back(randomValue);
            qDebug() << "push_back ind = " << ++ind;
        }
    }
    else {

        for (int i = randomValuesNumber-1; i >= ui->randomValuesNumber->value(); i--){

            RandomValuesList[i]->~RandomValueWidget();
    //        ScrollWidget->layout()->removeWidget(RandomValuesList[i]);
            RandomValuesList.erase(RandomValuesList.end() - 1);
        }
    }
    randomValuesNumber = ui->randomValuesNumber->value();
}

bool MainWindow::checkP(){

    double sp = 0;
    for (int i = 0; i < randomValuesNumber; i++)
        sp += RandomValuesList[i]->getProbability();

 //   qDebug() << "CHECK sp = " << sp << "   " << absolute(sp-1) << " " << (absolute(sp-1) < std::numeric_limits<double>::epsilon()) <<
 //               " ----- " << (sp == 1);
    return (fabs(sp-1) < 1e-15);
}

bool MainWindow::checkRepeat(){

    int posRandomValuesNumber = 0;
    for (int i = 0; i < RandomValuesList.size(); i++)
        if (RandomValuesList[i]->getProbability() > 0) posRandomValuesNumber++;

    return (ui->experimentsNumber->value() <= posRandomValuesNumber);
}

void MainWindow::onProbabilityChange(){

    if (checkP()) ui->generateButton->setEnabled(true);
    else ui->generateButton->setEnabled(false);
}

void MainWindow::onNumberChange(){

    if (checkRepeat()) ui->checkBox->setEnabled(true);
    else {
        ui->checkBox->setEnabled(false);
        ui->checkBox->setChecked(true);
    }
}

void MainWindow::generateRandomValues(){

    for (int i = 0; i < resultsList.size(); i++)
        resultsList[i]->~QLabel();
    resultsList.clear();

    if (ui->checkBox->isChecked()){

        for (int i = 0; i < ui->experimentsNumber->value(); i++){

            double x = (rand() % 100) / (double)100;
            double sp = 0;
            int j = 0;

            while (sp <= x){
                sp += RandomValuesList[j]->getProbability();
                j++;
            }
            qDebug() << x << " " << sp << " " << j;
            QLabel* result = new QLabel(
                                         QString::number(i+1) + ".)   " +
                                         QString::number(RandomValuesList[j-1]->getValue()) +
                                         "  (value #" + QString::number(j) + ", p = " +
                                         QString::number(RandomValuesList[j-1]->getProbability()) + ")"
                                        );
            QFont font = QFont();
            font.setPointSize(12);
            result->setFont(font);
            qDebug() << result->text();
            resultsList.push_back(result);
            ScrollWidget2->layout()->addWidget(result);
        }
    }
    else{

        QVector <RandomValueWidget*> list;
        for (int i = 0; i < randomValuesNumber; i++)
            list.push_back(RandomValuesList[i]);

        int pr = 100;
        for (int i = 0; i < ui->experimentsNumber->value(); i++){

            qDebug() << i;
            double x = (rand() % pr)/ (double)100;
            double sp = 0;
            int j = 0;

            while (sp <= x){
                sp += list[j]->getProbability();
                j++;
            }
            qDebug() << x << " " << sp << " " << j;
            QLabel* result = new QLabel(
                                         QString::number(i+1) + ".)   " +
                                         QString::number(list[j-1]->getValue()) +
                                         // "  (value #" + QString::number(j) +
                                         "  (p = " +
                                         QString::number(list[j-1]->getProbability()) + ")"
                                        );
            QFont font = QFont();
            font.setPointSize(12);
            result->setFont(font);
            qDebug() << result->text();
            resultsList.push_back(result);
            ScrollWidget2->layout()->addWidget(result);

            int cur_pr = list[j-1]->getProbability()*100;
            if (list[j-1]->getProbability() >= 0.3) cur_pr++;

            pr -= cur_pr;
            qDebug() << "PR === " << pr;
            list.erase(list.begin() + j-1);
        }
    }
}

