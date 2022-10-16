#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ciphers[0].setText("Шамир");
    ciphers[0].setChecked(true);
    ciphers[1].setText("Эль-Гамаль");
    ciphers[2].setText("Вернам");
    ciphers[3].setText("RSA");
    for(int i = 0; i < 4; i++){
        ui->verticalLayout_ciphers->addWidget(&ciphers[i]);
    }
    connect(ui->pushButton_code, SIGNAL(clicked()), SLOT(coding_slot()));
    connect(ui->pushButton_decode, SIGNAL(clicked()), SLOT(decoding_slot()));
    connect(ui->pushButton_get_path, SIGNAL(clicked()), SLOT(get_path_slot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::get_cipher()
{
    for(int i = 0; i < 4; i++){
        if(ciphers[i].isChecked()){
            return i;
        }
    }
    return -1;
}

void MainWindow::shamir_cipher()
{

}

void MainWindow::vernam_cipher()
{

}

void MainWindow::eg_cipher()
{

}

void MainWindow::rsa_cipher()
{

}

void MainWindow::decoding_slot()
{
    qDebug() << get_cipher();


}

void MainWindow::coding_slot()
{
    qDebug() << get_cipher();
    path_to_file = ui->lineEdit->text();
    qDebug() << path_to_file;
    switch(get_cipher()){
    case 0:
        shamir_cipher();
        break;
    case 1:
        eg_cipher();
        break;
    case 2:
        vernam_cipher();
        break;
    case 3:
        rsa_cipher();
        break;
    }
}

void MainWindow::get_path_slot()
{
    QString path_to_file_loc = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "/home", "*.*");
    qDebug() << path_to_file_loc;
    if(!path_to_file_loc.isEmpty()){
        ui->lineEdit->setText(path_to_file_loc);
    }
}

