#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    qDebug()<<QThread::currentThread() << "Main Thread";

    ui->mPause->setDisabled(true);
    ui->mResume->setDisabled(true);
    ui->mStop->setDisabled(true);

}

MainWindow::~MainWindow(){
    delete ui;
//    delete mWorkerThread;
}

void MainWindow::on_mPlay_clicked(){
    mWorker = new SuspandableWorker();
    mWorkerThread = new WorkerThread(mWorker);
    emit mWorkerThread->play();

    ui->mPlay->setDisabled(true);
    ui->mPause->setDisabled(false);
    ui->mStop->setDisabled(false);
}

void MainWindow::on_mPause_clicked(){
    mWorkerThread->pause();

    ui->mPause->setDisabled(true);
    ui->mResume->setEnabled(true);
}

void MainWindow::on_mResume_clicked(){
    mWorkerThread->resume();

    ui->mResume->setDisabled(true);
    ui->mPause->setEnabled(true);
}

void MainWindow::on_mStop_clicked(){
    mWorkerThread->stop();

    ui->mPlay->setDisabled(false);
    ui->mPause->setDisabled(true);
    ui->mResume->setDisabled(true);
    ui->mStop->setDisabled(true);
}

