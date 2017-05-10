#ifndef __MAINWINDOW_H_
#define __MAINWINDOW_H_

#include "stdafx.h"
class KListWidget;
class KPrintPreview;

class KMainWindow : public QDialog
{
    Q_OBJECT
public:
    KMainWindow(QWidget *parent = 0);
    ~KMainWindow();

    void InitConnection();

private slots:
    void OnOpenFile();
    void OnTextChanged(const QString& text);

    void OnPrint();


private:
    QPushButton*    mpOpenFileBtn;
    KListWidget*    mpListWidget;
    KPrintPreview*  mpPrintPreview;
    QPushButton*    mpPrintBtn;
    QPrinter*       mpPrinter;
};

#endif