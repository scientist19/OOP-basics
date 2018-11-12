#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "randomvaluewidget.h"

#include <QMainWindow>
#include <QVector>
#include <QLabel>

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


private:
    Ui::MainWindow *ui;
    QWidget* ScrollWidget;
    QWidget* ScrollWidget2;

    int randomValuesNumber = 0;
    QVector <RandomValueWidget*> RandomValuesList;
    QVector <QLabel*> resultsList;
};

#endif // MAINWINDOW_H
