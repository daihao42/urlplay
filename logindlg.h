#ifndef _LOGINDLG_H
#define _LOGINDLG_H
#include <QDialog>
class QLineEdit;
class CLogindlg : public QDialog
{	Q_OBJECT
    public :
         CLogindlg(QWidget* = 0);
    public slots:
        virtual void play();
    virtual void down();
    private :
        QLineEdit* urlLineEdit;

};
#endif
