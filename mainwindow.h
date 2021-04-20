#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include <memory>

#include <workerthread.h>
#include "suspandableworker.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow{

    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui{nullptr};
    WorkerThread* mWorkerThread{nullptr};
    SuspandableWorker* mWorker{nullptr};


private slots:
    void on_mPlay_clicked();
    void on_mPause_clicked();
    void on_mResume_clicked();
    void on_mStop_clicked();


};
#endif // MAINWINDOW_H

