#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots: void addRandomValues();

private:
    Ui::MainWindow *ui;
    QWidget* ScrollWidget;
};

#endif // MAINWINDOW_H
