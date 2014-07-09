#ifndef MONTHLYRESIDESTATISTICS_H
#define MONTHLYRESIDESTATISTICS_H

#include <QWidget>

namespace Ui {
class MonthlyResideStatistics;
}

class MonthlyResideStatistics : public QWidget
{
    Q_OBJECT
    
public:
    explicit MonthlyResideStatistics(QWidget *parent = 0);
    ~MonthlyResideStatistics();
signals:
    void closeMonthlyAResideStatisticsPage();
    
private slots:
    void on_btn_search_clicked();
    void on_btn_print_clicked();
    void on_btn_close_clicked();

private:
    void initView();
    void initHtml();
    Ui::MonthlyResideStatistics *ui;
    QString html;
};

#endif // MONTHLYRESIDESTATISTICS_H
