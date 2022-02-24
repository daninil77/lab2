#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <occupation.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void findOccupation();

private:
    Ui::MainWindow *ui;

 std::vector<Occupation> zanytiya;

};
#endif // MAINWINDOW_H
