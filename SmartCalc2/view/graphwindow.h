#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include "../controller/controller.h"

#include <QWidget>
#include <QVector>

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GraphWindow(QWidget *parent = nullptr);
    ~GraphWindow();

private slots:
    void on_pushButton_Print_clicked();

private:
    Ui::GraphWindow *ui;
};

#endif // GRAPHWINDOW_H
