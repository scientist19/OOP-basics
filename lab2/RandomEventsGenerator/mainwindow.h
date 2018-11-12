#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "randomvaluewidget.h"

#include <QMainWindow>
#include <QVector>

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

public slots:
    void addRandomValues();
    void onProbabilityChange();


private:
    Ui::MainWindow *ui;
    QWidget* ScrollWidget;
    QWidget* ScrollWidget2;

    int randomValuesNumber = 0;
    QVector <RandomValueWidget*> RandomValuesList;
};

#endif // MAINWINDOW_H
