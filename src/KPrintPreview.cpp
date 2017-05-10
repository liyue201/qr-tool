#include "KPrintPreview.h"
#include "KConfigFileManager.h"


KPrintPreview::KPrintPreview(QWidget* parent)
: QWidget(parent)
{
    mLevel = LEVEL_L;
    mPercent = 0.2;
    mMode = MODE_8;
    mMargin = 20;
    setFixedSize(240 , 240);
}

KPrintPreview::~KPrintPreview()
{

}

void KPrintPreview::SetText(const QString& text)
{
    mText = text;
    update();
}

void KPrintPreview::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    DrawRQ(painter);
}

void KPrintPreview::Print(QPrinter* printer)
{
    QPainter painter(printer);
    DrawRQ(painter);
}

void KPrintPreview::DrawRQ(QPainter& painter)
{
    QColor background(255, 255, 255);
    QColor foreground(0, 0, 0);
    painter.fillRect(rect(), background);

    QRcode *qrcode = QRcode_encodeString(mText.toLatin1().data(), 7, (QRecLevel)mLevel, (QRencodeMode)mMode, 1);
    if (0 != qrcode)
    {
        unsigned char *point = qrcode->data;
        painter.setPen(Qt::NoPen);
        painter.setBrush(background);
        painter.drawRect(0, 0, this->width(), this->height());
        double scale = (this->width() - 2 * mMargin) / qrcode->width;
        painter.setBrush(foreground);
        for (int y = 0; y < qrcode->width; y++)
        {
            for (int x = 0; x < qrcode->width; x++) {
                if (*point & 1) {
                    QRectF r(mMargin + x * scale, mMargin + y * scale, scale, scale);
                    painter.drawRects(&r, 1);
                }
                point++;
            }
        }
        QRcode_free(qrcode);

        painter.setBrush(background);
        double icon_width = (this->width() - 2 * mMargin) * mPercent;
        double icon_height = icon_width;
        double wrap_x = (this->width() - icon_width) / 2.0;
        double wrap_y = (this->width() - icon_height) / 2.0;
        QRectF wrap(wrap_x - 5, wrap_y - 5, icon_width + 10, icon_height + 10);
        painter.drawRoundRect(wrap, 50, 50);
       
        QPixmap image(":/logo.png");
        QRectF target(wrap_x, wrap_y, icon_width, icon_height);
        QRectF source(0, 0, image.width(), image.height());

        painter.drawPixmap(target, image, source);
    }
}


