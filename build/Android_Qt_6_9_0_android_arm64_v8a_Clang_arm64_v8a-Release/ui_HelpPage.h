/********************************************************************************
** Form generated from reading UI file 'HelpPage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPPAGE_H
#define UI_HELPPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpPage
{
public:
    QLabel *label;
    QPushButton *btnGoToMain;
    QLabel *label_2;

    void setupUi(QWidget *HelpPage)
    {
        if (HelpPage->objectName().isEmpty())
            HelpPage->setObjectName("HelpPage");
        HelpPage->resize(480, 720);
        label = new QLabel(HelpPage);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 10, 201, 41));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        btnGoToMain = new QPushButton(HelpPage);
        btnGoToMain->setObjectName("btnGoToMain");
        btnGoToMain->setGeometry(QRect(130, 270, 231, 51));
        label_2 = new QLabel(HelpPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 461, 161));

        retranslateUi(HelpPage);

        QMetaObject::connectSlotsByName(HelpPage);
    } // setupUi

    void retranslateUi(QWidget *HelpPage)
    {
        label->setText(QCoreApplication::translate("HelpPage", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        btnGoToMain->setText(QCoreApplication::translate("HelpPage", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label_2->setText(QCoreApplication::translate("HelpPage", "<html><head/><body><p>1. \320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\321\203\320\271\321\202\320\265 \321\202\320\265\321\201\321\202\320\270\321\200\321\203\320\265\320\274\320\276\320\263\320\276 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\320\265, \320\275\320\260\320\266\320\260\320\262 \320\275\320\260 \320\272\320\275\320\276\320\277\320\272\321\203 &quot;\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214&quot;</p><p>2. \320\235\320\260\320\266\320\274\320\270\321\202\320\265 \320\275\320\260 \320\272\320\275\320\276\320\277\320\272\321\203 &quot;\320\237\321\200\320\276\320\271\321\202\320\270 \321\202\320\265\321\201\321\202&quot;</p><p>3. \320\237\320\276 \320\274\320\265\321\200\320\265 \320\277\321\200\320\276\321\205\320\276\320\266\320\264\320\265\320\275\320\270\321\217 \321\202\320\265\321\201\321\202\320\260 \320\262\321\213\320\261\320\270\321\200\320\260\320"
                        "\271\321\202\320\265 \321\201\320\276\320\276\321\202\320\262\320\265\321\202\321\201\321\202\320\262\321\203\321\216\321\211\320\270\320\265 \320\262\320\260\321\200\320\270\320\260\320\275\321\202\321\213 \320\276\321\202\320\262\320\265\321\202\320\276\320\262</p><p>4. \320\224\320\273\321\217 \320\277\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\260 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\276\320\262 \320\262\321\201\320\265\321\205 \321\202\320\265\321\201\321\202\320\270\321\200\321\203\320\265\320\274\321\213\321\205, \320\275\320\260\320\266\320\274\320\270\321\202\320\265 \320\275\320\260 \320\272\320\275\320\276\320\277\320\272\321\203 &quot;\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213&quot;</p></body></html>", nullptr));
        (void)HelpPage;
    } // retranslateUi

};

namespace Ui {
    class HelpPage: public Ui_HelpPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPPAGE_H
