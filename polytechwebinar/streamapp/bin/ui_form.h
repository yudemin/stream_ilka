/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_form
{
public:
    QPushButton *bstart;
    QPushButton *bstop;

    void setupUi(QDialog *form)
    {
        if (form->objectName().isEmpty())
            form->setObjectName(QStringLiteral("form"));
        form->resize(494, 366);
        bstart = new QPushButton(form);
        bstart->setObjectName(QStringLiteral("bstart"));
        bstart->setGeometry(QRect(20, 200, 81, 31));
        bstop = new QPushButton(form);
        bstop->setObjectName(QStringLiteral("bstop"));
        bstop->setGeometry(QRect(20, 250, 81, 31));

        retranslateUi(form);

        QMetaObject::connectSlotsByName(form);
    } // setupUi

    void retranslateUi(QDialog *form)
    {
        form->setWindowTitle(QApplication::translate("form", "Dialog", nullptr));
        bstart->setText(QApplication::translate("form", "START", nullptr));
        bstop->setText(QApplication::translate("form", "STOP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class form: public Ui_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
