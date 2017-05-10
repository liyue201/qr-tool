#include "KListWidget.h"
#include "KConfigFileManager.h"


KListWidget::KListWidget(QWidget* parent)
: QWidget(parent)
{
    mpListWidget = new QListWidget(this);
    mpListWidget->setMinimumSize(200, 400);
    QVBoxLayout* mainLy = new QVBoxLayout(this);
    mainLy->addWidget(mpListWidget);

    connect(mpListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(OnItemClicked(QListWidgetItem *)));
}

KListWidget::~KListWidget()
{

}

void KListWidget::LoadFile(const QString& path)
{
    QFile file(path);

    if (file.open(QFile::ReadOnly)){
        mpListWidget->clear();
        while (!file.atEnd())
        {
            QString line = file.readLine();
            if (line.length() > 3) {
                mpListWidget->addItem(line);
            }
        }
    }
}

void KListWidget::OnItemClicked(QListWidgetItem *item)
{
    emit TextChanged(item->text());
}
