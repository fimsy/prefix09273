/********************************************************************************
** Form generated from reading UI file 'DatabasePage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEPAGE_H
#define UI_DATABASEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabasePage
{
public:
    QLabel *label;
    QPushButton *btnGoToMain;
    QListWidget *listWidget;

    void setupUi(QWidget *DatabasePage)
    {
        if (DatabasePage->objectName().isEmpty())
            DatabasePage->setObjectName("DatabasePage");
        DatabasePage->resize(480, 720);
        label = new QLabel(DatabasePage);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 10, 201, 41));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        btnGoToMain = new QPushButton(DatabasePage);
        btnGoToMain->setObjectName("btnGoToMain");
        btnGoToMain->setGeometry(QRect(130, 530, 231, 51));
        listWidget = new QListWidget(DatabasePage);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(30, 60, 421, 451));
        QFont font1;
        font1.setPointSize(12);
        listWidget->setFont(font1);

        retranslateUi(DatabasePage);

        QMetaObject::connectSlotsByName(DatabasePage);
    } // setupUi

    void retranslateUi(QWidget *DatabasePage)
    {
        label->setText(QCoreApplication::translate("DatabasePage", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213", nullptr));
        btnGoToMain->setText(QCoreApplication::translate("DatabasePage", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        (void)DatabasePage;
    } // retranslateUi

};

namespace Ui {
    class DatabasePage: public Ui_DatabasePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEPAGE_H
