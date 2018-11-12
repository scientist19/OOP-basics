#ifndef RANDOMVALUEWIDGET_H
#define RANDOMVALUEWIDGET_H

#include <QWidget>
#include <QDoubleSpinBox>

namespace Ui {
class RandomValueWidget;
}

class RandomValueWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RandomValueWidget(QWidget *parent = nullptr);
    ~RandomValueWidget();

    void setLabelValue(QString labelValue);
    void setValue(int value);
    void setLabelProbability(QString labelProbability);
    void setProbability(int probability);
    int getValue();
    double getProbability();
    QDoubleSpinBox* probabilityWidget();

private:
    Ui::RandomValueWidget *ui;
};

#endif // RANDOMVALUEWIDGET_H
