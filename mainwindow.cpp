#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <csvreader.h>
#include<occupation.h>

#include <QString>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   //Открытие файла
    CSVReader csv("F:\\qt\\lab_2\\lab2\\database.csv");
   if (csv.is_open())
   {

   //Чтение из файла в вектор
   zanytiya = csv.readAll();


   //Сортировка

   std::sort(zanytiya.begin(), zanytiya.end(),[](const  Occupation &c1, const  Occupation &c2){
    return c1.aud < c2.aud;
});
 ui->setupUi(this);
   }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::findOccupation()
{
    for (const auto &e: zanytiya)
    if(ui->editsearch->text().isEmpty())
       ui->textBrowser->append(QString::fromStdString(std::to_string(e.n))+ ", "+e.predmet+", "+ QString::fromStdString(std::to_string(e.tipe))+","+QString::fromStdString(std::to_string(e.aud)));
    else if(e.predmet==ui->editsearch->text())
           ui->textBrowser->append(QString::fromStdString(std::to_string(e.n))+ ", "+e.predmet+", "+ QString::fromStdString(std::to_string(e.tipe))+","+QString::fromStdString(std::to_string(e.aud)));
        }
