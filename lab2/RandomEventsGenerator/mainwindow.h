#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "randomvaluewidget.h"

#include <QMainWindow>
#include <QVector>
#include <QLabel>
#include <QFile>
#include <QSpacerItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool checkP();
    bool checkRepeat();

public slots:
    void addRandomValues();
    void onProbabilityChange();
    void onNumberChange();
    void generateRandomValues();
    void balanceRandomValues();

private slots:
    void on_actionSave_triggered();
    void saveData(QString fileName);
    void openData(QString fileName);

    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
    QWidget* ScrollWidget;
    QWidget* ScrollWidget2;
    QSpacerItem* Spacer = new QSpacerItem(0,10, QSizePolicy::Expanding, QSizePolicy::Expanding);

    int randomValuesNumber = 0;
    int randSeed = time(0);
    int oldRandSeed = randSeed;
    QVector <RandomValueWidget*> RandomValuesList;
    QVector <QLabel*> resultsList;

    void addRandomValue(int value, double p, int number);
};

#endif // MAINWINDOW_H
