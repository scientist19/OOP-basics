#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "randomvaluewidget.h"

#include <QVBoxLayout>
#include <QtGui>
#include <cmath>
#include <fstream>
#include <QFileDialog>

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

void MainWindow::addRandomValue(int value, double p, int number){

    RandomValueWidget* randomValue = new RandomValueWidget();

    randomValue->setLabelValue("Value #" + QString::number(number));
    randomValue->setLabelProbability("Probability " + QString::number(number));
    randomValue->setValue(value);
    randomValue->setProbability(p);
    connect(randomValue->probabilityWidget(), SIGNAL(valueChanged(double)),this, SLOT(onProbabilityChange()));
    connect(randomValue->probabilityWidget(), SIGNAL(valueChanged(double)),this, SLOT(onNumberChange()));

    ScrollWidget->layout()->removeItem(Spacer);

    ScrollWidget->layout()->addWidget(randomValue);

    ScrollWidget->layout()->addItem(Spacer);
    RandomValuesList.push_back(randomValue);
}

void MainWindow::addRandomValues(){

    static int ind = -1;
    if (randomValuesNumber < ui->randomValuesNumber->value()){

        for (int i = randomValuesNumber; i < ui->randomValuesNumber->value(); i++){

            addRandomValue(i+1, 0, i+1);
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

    double sum = 0;
    for (int i = 0; i < randomValuesNumber; i++)
        sum += RandomValuesList[i]->getProbability();
    ui->sumP->setText(QString::number(sum));

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

void MainWindow::balanceRandomValues(){

    if (randomValuesNumber == 0) return;
    double sum;
    for (int i = 0; i < randomValuesNumber; i++)
        sum += RandomValuesList[i]->getProbability();

    if (sum == 1) return;

    if (sum < 1){

        RandomValuesList[0]->setProbability(RandomValuesList[0]->getProbability() + 1 - sum);
        return;
    }

    int i = randomValuesNumber-1;
    while (sum > 1){

        double d = std::min(sum-1, RandomValuesList[i]->getProbability());
        RandomValuesList[i]->setProbability(RandomValuesList[i]->getProbability() - d);
        sum -= d;
        i--;
    }
}

void MainWindow::generateRandomValues(){

    srand(randSeed);
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

            ScrollWidget2->layout()->removeItem(Spacer);
            ScrollWidget2->layout()->addWidget(result);
            ScrollWidget2->layout()->addItem(Spacer);
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

            ScrollWidget2->layout()->removeItem(Spacer);
            ScrollWidget2->layout()->addWidget(result);
            ScrollWidget2->layout()->addItem(Spacer);

            int cur_pr = list[j-1]->getProbability()*100;
            qDebug() << "PPP " << list[j-1]->getProbability() << "   " << cur_pr;
            if (list[j-1]->getProbability() >= 0.3) cur_pr++;

            pr -= cur_pr;
            qDebug() << "PR === " << pr;
            list.erase(list.begin() + j-1);
        }
    }

    oldRandSeed = randSeed;
    randSeed = time(0);
}


void MainWindow::saveData(QString fileName){

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);

    QTextStream out(&file);
    out << randomValuesNumber << " ";

    for (int i = 0; i < randomValuesNumber; i++)
        out << RandomValuesList[i]->getValue() << " "
            << RandomValuesList[i]->getProbability() << " ";

    out << ui->experimentsNumber->value() << " "
        << ui->checkBox->isChecked() << " "
        << oldRandSeed;

    file.close();
}

void MainWindow::openData(QString fileName){

    for (int i = 0; i < randomValuesNumber; i++)
        RandomValuesList[i]->~RandomValueWidget();
    RandomValuesList.clear();

    QFile file(fileName);
    file.open(QIODevice::ReadOnly);

    QTextStream in(&file);
    in >> randomValuesNumber;

    int v;
    double p;
    for (int i = 0; i < randomValuesNumber; i++){
        in >> v >> p;
        addRandomValue(v, p, i+1);
    }

    int expNumber, withRepeat;
    in >> expNumber >> withRepeat >> randSeed;
    file.close();

    ui->randomValuesNumber->setValue(randomValuesNumber);
    ui->experimentsNumber->setValue(expNumber);
    ui->checkBox->setChecked(withRepeat);
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save file as..."), "../RandomEventsGenerator/saves/untitled.dat",
                                                    tr("Files (*.dat)"));
    saveData(fileName);
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file..."), "../RandomEventsGenerator/saves",
                                                    tr("Files (*.dat)"));
    openData(fileName);
}
