/********************************************************************************
** Form generated from reading UI file 'AboutPage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTPAGE_H
#define UI_ABOUTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutPage
{
public:
    QLabel *label;
    QPushButton *btnGoToMain;
    QLabel *label_2;

    void setupUi(QWidget *AboutPage)
    {
        if (AboutPage->objectName().isEmpty())
            AboutPage->setObjectName("AboutPage");
        AboutPage->resize(480, 720);
        label = new QLabel(AboutPage);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 10, 201, 41));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        btnGoToMain = new QPushButton(AboutPage);
        btnGoToMain->setObjectName("btnGoToMain");
        btnGoToMain->setGeometry(QRect(130, 270, 231, 51));
        label_2 = new QLabel(AboutPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 90, 261, 111));

        retranslateUi(AboutPage);

        QMetaObject::connectSlotsByName(AboutPage);
    } // setupUi

    void retranslateUi(QWidget *AboutPage)
    {
        label->setText(QCoreApplication::translate("AboutPage", "\320\236 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\270", nullptr));
        btnGoToMain->setText(QCoreApplication::translate("AboutPage", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label_2->setText(QCoreApplication::translate("AboutPage", "Made by Me in Qt6", nullptr));
        (void)AboutPage;
    } // retranslateUi

};

namespace Ui {
    class AboutPage: public Ui_AboutPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTPAGE_H
