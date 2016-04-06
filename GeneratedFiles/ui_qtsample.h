/********************************************************************************
** Form generated from reading UI file 'qtsample.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSAMPLE_H
#define UI_QTSAMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qtsampleClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qtsampleClass)
    {
        if (qtsampleClass->objectName().isEmpty())
            qtsampleClass->setObjectName(QStringLiteral("qtsampleClass"));
        qtsampleClass->resize(600, 400);
        centralWidget = new QWidget(qtsampleClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout_2->addWidget(textEdit);


        verticalLayout->addWidget(groupBox);

        qtsampleClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(qtsampleClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        qtsampleClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qtsampleClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        qtsampleClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(qtsampleClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        qtsampleClass->setStatusBar(statusBar);

        retranslateUi(qtsampleClass);

        QMetaObject::connectSlotsByName(qtsampleClass);
    } // setupUi

    void retranslateUi(QMainWindow *qtsampleClass)
    {
        qtsampleClass->setWindowTitle(QApplication::translate("qtsampleClass", "qtsample", 0));
        groupBox->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class qtsampleClass: public Ui_qtsampleClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSAMPLE_H
