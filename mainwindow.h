#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRadioButton>
#include <QDebug>
#include <QFileDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QRadioButton ciphers[4];
    Ui::MainWindow *ui;
    QString path_to_file;
private:
    int get_cipher();
    void shamir_cipher();
    void vernam_cipher();
    void eg_cipher();
    void rsa_cipher();
private slots:
    void decoding_slot();
    void coding_slot();
    void get_path_slot();
};
#endif // MAINWINDOW_H
