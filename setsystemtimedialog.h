#ifndef SETSYSTEMTIMEDIALOG_H
#define SETSYSTEMTIMEDIALOG_H

#include <QDialog>

namespace Ui {
class SetSystemTimeDialog;
}

class SetSystemTimeDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SetSystemTimeDialog(QWidget *parent = 0);
    void setCurrentTime();
    ~SetSystemTimeDialog();
public slots:
    void onSetSystemTime();
private:
    Ui::SetSystemTimeDialog *ui;
};

#endif // SETSYSTEMTIMEDIALOG_H
