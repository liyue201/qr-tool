#ifndef __KPRINTPREVIEWT_H_
#define __KPRINTPREVIEWT_H_

#include "stdafx.h"
#include "qrencode.h"

class KPrintPreview : public QWidget
{
    Q_OBJECT
public:
    KPrintPreview(QWidget* parent);
    ~KPrintPreview();

    enum QR_MODE {
        MODE_NUL = QR_MODE_NUL,
        MODE_NUM = QR_MODE_NUM,
        MODE_AN = QR_MODE_AN,
        MODE_8 = QR_MODE_8,
        MODE_KANJI = QR_MODE_KANJI,
        MODE_STRUCTURE = QR_MODE_STRUCTURE,
        MODE_ECI = QR_MODE_ECI,
        MODE_FNC1FIRST = QR_MODE_FNC1FIRST,
        MODE_FNC1SECOND = QR_MODE_FNC1SECOND
    };

    enum QR_LEVEL {
        LEVEL_L = QR_ECLEVEL_L,
        LEVEL_M = QR_ECLEVEL_M,
        LEVEL_Q = QR_ECLEVEL_Q,
        LEVEL_H = QR_ECLEVEL_H
    };
    void SetText(const QString& str);
    void Print(QPrinter* printer);

private:
    void paintEvent(QPaintEvent *);
    void DrawRQ(QPainter& painter);

private:
    QString     mText;
    qreal       mPercent;
    QR_MODE     mMode;
    QR_LEVEL    mLevel;
    float       mMargin;
};

#endif