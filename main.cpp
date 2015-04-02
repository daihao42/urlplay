#include <QtGui>
#include <QString>
#include <QTextCodec>
#include "logindlg.h"
int main(int argc,char * argv[])
{	QApplication app(argc,argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));//设置汉字编码
    CLogindlg dlg;
    return dlg.exec();
    return app.exec();//循环等待事件结束
}
