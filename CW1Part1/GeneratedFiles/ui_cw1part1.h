/********************************************************************************
** Form generated from reading ui file 'cw1part1.ui'
**
** Created: Mon 9. Nov 18:47:32 2009
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CW1PART1_H
#define UI_CW1PART1_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CW1Part1Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CW1Part1Class)
    {
        if (CW1Part1Class->objectName().isEmpty())
            CW1Part1Class->setObjectName(QString::fromUtf8("CW1Part1Class"));
        CW1Part1Class->resize(600, 400);
        menuBar = new QMenuBar(CW1Part1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        CW1Part1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CW1Part1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CW1Part1Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(CW1Part1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        CW1Part1Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CW1Part1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CW1Part1Class->setStatusBar(statusBar);

        retranslateUi(CW1Part1Class);

        QMetaObject::connectSlotsByName(CW1Part1Class);
    } // setupUi

    void retranslateUi(QMainWindow *CW1Part1Class)
    {
        CW1Part1Class->setWindowTitle(QApplication::translate("CW1Part1Class", "CW1Part1", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(CW1Part1Class);
    } // retranslateUi

};

namespace Ui {
    class CW1Part1Class: public Ui_CW1Part1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CW1PART1_H
