#include "KMainWindow.h"
#include "KConfigFileManager.h"
#include "KListWidget.h"
#include "KPrintPreview.h"


KMainWindow::KMainWindow(QWidget *parent)
: QDialog(parent)
{
    setWindowFlags(windowFlags() &~Qt::WindowContextHelpButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
  
    mpOpenFileBtn = new QPushButton(tr("open..."), this);
    mpListWidget = new KListWidget(this);
    mpPrintPreview = new KPrintPreview(this);
    mpPrintBtn = new QPushButton(tr("print"), this);
    QVBoxLayout* leftLy = new QVBoxLayout;
    QHBoxLayout* ltLy = new QHBoxLayout;
    ltLy->addWidget(mpOpenFileBtn);
    ltLy->addWidget(mpPrintBtn);
    ltLy->addStretch();
    leftLy->addLayout(ltLy);
    leftLy->addWidget(mpListWidget);

    QVBoxLayout* rightLy = new QVBoxLayout;

    QHBoxLayout* rtLy = new QHBoxLayout;
    rightLy->addLayout(rtLy);
    rightLy->addStretch();
    rightLy->addWidget(mpPrintPreview);
    rightLy->addStretch();

    QHBoxLayout* mainLy = new QHBoxLayout(this);
    mainLy->addLayout(leftLy);
    mainLy->addLayout(rightLy);

    InitConnection();

    mpPrinter = new QPrinter();
}

KMainWindow::~KMainWindow()
{
    delete mpPrinter;
}

void KMainWindow::InitConnection()
{
    connect(mpOpenFileBtn, SIGNAL(clicked()), this, SLOT(OnOpenFile()));
    connect(mpListWidget, SIGNAL(TextChanged(const QString&)), this, SLOT(OnTextChanged(const QString&)));
    connect(mpPrintBtn, SIGNAL(clicked()), this, SLOT(OnPrint()));
}

void KMainWindow::OnOpenFile()
{
    QString dir = qApp->applicationDirPath();
    QString  path = QFileDialog::getOpenFileName(this, "", dir);

    if (!path.isEmpty()) {
        mpListWidget->LoadFile(path);
    }
}

void KMainWindow::OnTextChanged(const QString& text)
{
    mpPrintPreview->SetText(text);
}

void KMainWindow::OnPrint()
{
    QPrintDialog dlg(mpPrinter, this);
    if (dlg.exec() == QDialog::Accepted) {
        mpPrintPreview->Print(mpPrinter);
    }
}







