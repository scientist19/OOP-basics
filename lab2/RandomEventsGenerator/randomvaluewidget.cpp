#include "randomvaluewidget.h"
#include "ui_randomvaluewidget.h"

RandomValueWidget::RandomValueWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RandomValueWidget)
{
    ui->setupUi(this);
}

RandomValueWidget::~RandomValueWidget()
{
    delete ui;
}

void RandomValueWidget::setLabelValue(QString labelValue){

    ui->labelValue->setText(labelValue);
}

void RandomValueWidget::setLabelProbability(QString labelProbability){

    ui->labelProbability->setText(labelProbability);
}

void RandomValueWidget::setValue(int value){

    ui->value->setValue(value);
}

void RandomValueWidget::setProbability(double probability){

    ui->probability->setValue(probability);
}

int RandomValueWidget::getValue(){
    return ui->value->value();
}

double RandomValueWidget::getProbability(){
    return ui->probability->value();
}

QDoubleSpinBox* RandomValueWidget::probabilityWidget(){

    return ui->probability;
}
