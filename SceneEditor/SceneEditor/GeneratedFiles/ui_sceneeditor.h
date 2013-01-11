/********************************************************************************
** Form generated from reading UI file 'sceneeditor.ui'
**
** Created: Fri Jan 11 10:04:24 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCENEEDITOR_H
#define UI_SCENEEDITOR_H

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

class Ui_SceneEditorClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SceneEditorClass)
    {
        if (SceneEditorClass->objectName().isEmpty())
            SceneEditorClass->setObjectName(QString::fromUtf8("SceneEditorClass"));
        SceneEditorClass->resize(600, 400);
        menuBar = new QMenuBar(SceneEditorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        SceneEditorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SceneEditorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SceneEditorClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SceneEditorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        SceneEditorClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SceneEditorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SceneEditorClass->setStatusBar(statusBar);

        retranslateUi(SceneEditorClass);

        QMetaObject::connectSlotsByName(SceneEditorClass);
    } // setupUi

    void retranslateUi(QMainWindow *SceneEditorClass)
    {
        SceneEditorClass->setWindowTitle(QApplication::translate("SceneEditorClass", "SceneEditor", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SceneEditorClass: public Ui_SceneEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENEEDITOR_H
