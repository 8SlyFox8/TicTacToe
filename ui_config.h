/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_config
{
public:
    QGridLayout *gridLayout;
    QLabel *label_6;
    QPushButton *pushButton;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLabel *label;

    void setupUi(QDialog *config)
    {
        if (config->objectName().isEmpty())
            config->setObjectName(QString::fromUtf8("config"));
        config->resize(213, 215);
        gridLayout = new QGridLayout(config);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(config);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font;
        font.setPointSize(14);
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 6, 1, 1, 1);

        pushButton = new QPushButton(config);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 7, 2, 1, 1);

        lineEdit_4 = new QLineEdit(config);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 6, 2, 1, 2);

        lineEdit_3 = new QLineEdit(config);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 5, 2, 1, 2);

        pushButton_2 = new QPushButton(config);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 7, 3, 1, 1);

        lineEdit = new QLineEdit(config);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 2, 1, 2);

        label_5 = new QLabel(config);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 5, 1, 1, 1);

        label_2 = new QLabel(config);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        label_3 = new QLabel(config);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        lineEdit_2 = new QLineEdit(config);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 2, 2, 1, 2);

        label_4 = new QLabel(config);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 4, 1, 1, 3);

        label = new QLabel(config);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 1, 1, 3);


        retranslateUi(config);

        QMetaObject::connectSlotsByName(config);
    } // setupUi

    void retranslateUi(QDialog *config)
    {
        config->setWindowTitle(QCoreApplication::translate("config", "Dialog", nullptr));
        label_6->setText(QCoreApplication::translate("config", "Port", nullptr));
        pushButton->setText(QCoreApplication::translate("config", "Confirm", nullptr));
        pushButton_2->setText(QCoreApplication::translate("config", "Cancel", nullptr));
        label_5->setText(QCoreApplication::translate("config", "IP", nullptr));
        label_2->setText(QCoreApplication::translate("config", "IP", nullptr));
        label_3->setText(QCoreApplication::translate("config", "Port", nullptr));
        label_4->setText(QCoreApplication::translate("config", "from", nullptr));
        label->setText(QCoreApplication::translate("config", "Connect to", nullptr));
    } // retranslateUi

};

namespace Ui {
    class config: public Ui_config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
