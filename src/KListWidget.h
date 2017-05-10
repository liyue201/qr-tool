#ifndef __KLOCKWIDGET_H_
#define __KLISTWIDGET_H_

#include "stdafx.h"

class KListWidget : public QWidget
{
    Q_OBJECT
public:
    KListWidget(QWidget* parent = 0);
    ~KListWidget();

    void LoadFile(const QString& path);
signals:
    void TextChanged(const QString& text);

private slots:
    void OnItemClicked(QListWidgetItem *item);

private:

    QListWidget* mpListWidget;
};

#endif