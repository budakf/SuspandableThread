#include "workerthread.h"

WorkerThread::WorkerThread(SuspandableWorker *pWorker, QObject* parent) : QThread(parent), mWorker(pWorker){
    mWorker->moveToThread(this);
    this->start();
    connection();
}

WorkerThread::~WorkerThread(){
    qDebug()<<"Destructor";
}

void WorkerThread::run(){
    qDebug()<<QThread::currentThread() << "Custom Thread";
    QThread::run();
}

void WorkerThread::pause(){
    mWorker->pause();
}

void WorkerThread::resume(){
    mWorker->resume();
}

void WorkerThread::stop(){
    mWorker->stop();
}

void WorkerThread::connection(){
    connect(this, &WorkerThread::play, mWorker, &SuspandableWorker::play);
    connect(mWorker, &SuspandableWorker::finished, this, &WorkerThread::quit);
    connect(this, &WorkerThread::finished, [&](){
        qDebug()<<QThread::currentThread() << "Custom Thread Finished";
        mWorker->deleteLater();
        this->deleteLater();
    });

}

