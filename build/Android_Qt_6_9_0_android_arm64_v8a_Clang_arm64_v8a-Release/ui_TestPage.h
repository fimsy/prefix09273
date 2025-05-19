/********************************************************************************
** Form generated from reading UI file 'TestPage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTPAGE_H
#define UI_TESTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestPage
{
public:
    QLabel *label;
    QPushButton *btnVerno;
    QPushButton *btnNeverno;
    QLabel *labelZadanie;
    QPushButton *recordButton;

    void setupUi(QWidget *TestPage)
    {
        if (TestPage->objectName().isEmpty())
            TestPage->setObjectName("TestPage");
        TestPage->resize(480, 720);
        label = new QLabel(TestPage);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 10, 201, 41));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        btnVerno = new QPushButton(TestPage);
        btnVerno->setObjectName("btnVerno");
        btnVerno->setGeometry(QRect(-50, 650, 191, 51));
        btnNeverno = new QPushButton(TestPage);
        btnNeverno->setObjectName("btnNeverno");
        btnNeverno->setGeometry(QRect(180, 650, 191, 51));
        labelZadanie = new QLabel(TestPage);
        labelZadanie->setObjectName("labelZadanie");
        labelZadanie->setGeometry(QRect(0, 80, 481, 201));
        labelZadanie->setFont(font);
        recordButton = new QPushButton(TestPage);
        recordButton->setObjectName("recordButton");
        recordButton->setGeometry(QRect(100, 570, 131, 51));

        retranslateUi(TestPage);

        QMetaObject::connectSlotsByName(TestPage);
    } // setupUi

    void retranslateUi(QWidget *TestPage)
    {
        label->setText(QCoreApplication::translate("TestPage", "\320\242\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        btnVerno->setText(QCoreApplication::translate("TestPage", "\320\222\320\265\321\200\320\275\320\276", nullptr));
        btnNeverno->setText(QCoreApplication::translate("TestPage", "\320\235\320\265\320\262\320\265\321\200\320\275\320\276", nullptr));
        labelZadanie->setText(QCoreApplication::translate("TestPage", "<html><head/><body><p align=\"center\">TextLabel</p></body></html>", nullptr));
        recordButton->setText(QCoreApplication::translate("TestPage", "PushButton", nullptr));
        (void)TestPage;
    } // retranslateUi

};

namespace Ui {
    class TestPage: public Ui_TestPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTPAGE_H
