#include <QtGui>
#include <QMessageBox>
#include "logindlg.h"
CLogindlg::CLogindlg(QWidget* parent)
    : QDialog(parent)
{
    QLabel* urlLabel = new QLabel(tr("url："));

    urlLineEdit = new QLineEdit;


    QGridLayout* gridLayout = new QGridLayout;
    gridLayout->addWidget(urlLabel,0,0,1,1);
    gridLayout->addWidget(urlLineEdit,0,1,1,3);

    QPushButton* playBtn = new QPushButton(tr("播放"));
    QPushButton* downBtn = new QPushButton(tr("下载"));
    QPushButton* cancelBtn = new QPushButton(tr("退出"));
    QHBoxLayout* btnLayout  = new QHBoxLayout;
    btnLayout->setSpacing(40);
    btnLayout->addWidget(playBtn);
   btnLayout->addWidget(downBtn);
    btnLayout->addWidget(cancelBtn);

    QVBoxLayout* dlgLayout = new QVBoxLayout;
    dlgLayout->setMargin(20);
    dlgLayout->addLayout(gridLayout);
    dlgLayout->addStretch(20);
    dlgLayout->addLayout(btnLayout);
    setLayout(dlgLayout);
    connect(playBtn,SIGNAL(clicked()),this,SLOT(play()));
  connect(downBtn,SIGNAL(clicked()),this,SLOT(down()));
    connect(cancelBtn,SIGNAL(clicked()),this,SLOT(reject()));
    setWindowTitle(tr("url播放"));
    resize(300,200);
}
void CLogindlg::play()
{	QString shpa="~/exam/urlplay1/vsp play ";
    if(urlLineEdit->text() != NULL )
        {	QString url=urlLineEdit->text();
            shpa+=url;
    shpa+=" &";//加&保证shell在后台执行，此时可关掉UI
            QByteArray ba = shpa.toLatin1();
            char *com = ba.data();
            system(com);
        urlLineEdit->clear();
    }
    else
    {	QMessageBox::warning(this,tr("警告"),tr("未输入地址"),QMessageBox::Yes);
        urlLineEdit->setFocus();
    }
}
void CLogindlg::down()
{	QString shpa="~/exam/urlplay1/vsp dump ";
    if(urlLineEdit->text() != NULL )
        {	QString url=urlLineEdit->text();
            shpa+=url;
        shpa+=" &";
            QByteArray ba = shpa.toLatin1();
            char *com = ba.data();
            system(com);
        urlLineEdit->clear();
    }
    else
    {	QMessageBox::warning(this,tr("警告"),tr("未输入地址"),QMessageBox::Yes);
        urlLineEdit->setFocus();
    }
}
