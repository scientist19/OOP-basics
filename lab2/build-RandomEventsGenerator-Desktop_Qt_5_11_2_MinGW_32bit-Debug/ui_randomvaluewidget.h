/********************************************************************************
** Form generated from reading UI file 'randomvaluewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANDOMVALUEWIDGET_H
#define UI_RANDOMVALUEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RandomValueWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *labelValue;
    QSpinBox *value;
    QSpacerItem *horizontalSpacer;
    QLabel *labelProbability;
    QDoubleSpinBox *probability;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *RandomValueWidget)
    {
        if (RandomValueWidget->objectName().isEmpty())
            RandomValueWidget->setObjectName(QStringLiteral("RandomValueWidget"));
        RandomValueWidget->resize(392, 52);
        RandomValueWidget->setMinimumSize(QSize(392, 52));
        QFont font;
        font.setPointSize(12);
        RandomValueWidget->setFont(font);
        horizontalLayout = new QHBoxLayout(RandomValueWidget);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelValue = new QLabel(RandomValueWidget);
        labelValue->setObjectName(QStringLiteral("labelValue"));

        horizontalLayout->addWidget(labelValue);

        value = new QSpinBox(RandomValueWidget);
        value->setObjectName(QStringLiteral("value"));
        value->setMinimum(-100);
        value->setMaximum(100);

        horizontalLayout->addWidget(value);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        labelProbability = new QLabel(RandomValueWidget);
        labelProbability->setObjectName(QStringLiteral("labelProbability"));

        horizontalLayout->addWidget(labelProbability);

        probability = new QDoubleSpinBox(RandomValueWidget);
        probability->setObjectName(QStringLiteral("probability"));
        probability->setMaximum(1);
        probability->setSingleStep(0.05);

        horizontalLayout->addWidget(probability);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(RandomValueWidget);

        QMetaObject::connectSlotsByName(RandomValueWidget);
    } // setupUi

    void retranslateUi(QWidget *RandomValueWidget)
    {
        RandomValueWidget->setWindowTitle(QApplication::translate("RandomValueWidget", "Form", nullptr));
        labelValue->setText(QApplication::translate("RandomValueWidget", "Value", nullptr));
        labelProbability->setText(QApplication::translate("RandomValueWidget", "Probability", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RandomValueWidget: public Ui_RandomValueWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANDOMVALUEWIDGET_H
