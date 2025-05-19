/********************************************************************************
** Form generated from reading UI file 'MainPage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPage
{
public:
    QLabel *label;
    QPushButton *btnregister;
    QPushButton *btntest;
    QPushButton *btndatabase;
    QPushButton *btnhelp;
    QPushButton *btnabout;

    void setupUi(QWidget *MainPage)
    {
        if (MainPage->objectName().isEmpty())
            MainPage->setObjectName("MainPage");
        MainPage->resize(480, 720);
        label = new QLabel(MainPage);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 281, 31));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        btnregister = new QPushButton(MainPage);
        btnregister->setObjectName("btnregister");
        btnregister->setGeometry(QRect(-10, 60, 341, 71));
        QFont font1;
        font1.setPointSize(17);
        btnregister->setFont(font1);
        btntest = new QPushButton(MainPage);
        btntest->setObjectName("btntest");
        btntest->setGeometry(QRect(-10, 140, 341, 71));
        btntest->setFont(font1);
        btndatabase = new QPushButton(MainPage);
        btndatabase->setObjectName("btndatabase");
        btndatabase->setGeometry(QRect(-10, 220, 341, 71));
        btndatabase->setFont(font1);
        btnhelp = new QPushButton(MainPage);
        btnhelp->setObjectName("btnhelp");
        btnhelp->setGeometry(QRect(-10, 300, 341, 71));
        btnhelp->setFont(font1);
        btnabout = new QPushButton(MainPage);
        btnabout->setObjectName("btnabout");
        btnabout->setGeometry(QRect(-10, 380, 341, 71));
        btnabout->setFont(font1);

        retranslateUi(MainPage);

        QMetaObject::connectSlotsByName(MainPage);
    } // setupUi

    void retranslateUi(QWidget *MainPage)
    {
        label->setText(QCoreApplication::translate("MainPage", "\320\232\320\276\320\275\321\202\321\200\320\276\320\273\321\214\320\275\320\260\321\217 \320\264\320\270\320\260\320\263\320\275\320\276\321\201\321\202\320\270\320\272\320\260", nullptr));
        btnregister->setText(QCoreApplication::translate("MainPage", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        btntest->setText(QCoreApplication::translate("MainPage", "\320\237\321\200\320\276\320\271\321\202\320\270 \321\202\320\265\321\201\321\202", nullptr));
        btndatabase->setText(QCoreApplication::translate("MainPage", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213", nullptr));
        btnhelp->setText(QCoreApplication::translate("MainPage", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        btnabout->setText(QCoreApplication::translate("MainPage", "\320\236 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\270", nullptr));
        (void)MainPage;
    } // retranslateUi

};

namespace Ui {
    class MainPage: public Ui_MainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
