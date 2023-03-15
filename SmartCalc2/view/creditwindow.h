#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

#include <QWidget>

namespace Ui {
class CreditWindow;
}

class CreditWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CreditWindow(QWidget *parent = nullptr);
    ~CreditWindow();

private slots:
    void on_pushButton_Calculate_clicked();

    void on_comboBox_Term_currentIndexChanged(int index);

private:
    Ui::CreditWindow *ui;
};

#endif // CREDITWINDOW_H
