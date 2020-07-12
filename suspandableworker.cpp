#include "suspandableworker.h"

SuspandableWorker::SuspandableWorker(){
    mIsPaused = false;
    mWillStop = false;
}

SuspandableWorker::~SuspandableWorker(){}

void SuspandableWorker::play(){
    qDebug()<<QThread::currentThread() << "Play";

    while(true){
        qDebug()<<QThread::currentThread() << "Do Work";
        mMutex.lock();
        if(mIsPaused){
            qDebug()<<QThread::currentThread() << "Thread Waiting";
            mWaitCondition.wait(&mMutex);
        }
        if(mWillStop){
            qDebug()<<QThread::currentThread() << "Thread Stopping";
            mMutex.unlock();
            break;
        }
        mMutex.unlock();
    }
}

void SuspandableWorker::pause(){
    mMutex.lock();
    mIsPaused = true;
    qDebug()<<QThread::currentThread() << "Pause";
    mMutex.unlock();
}

void SuspandableWorker::resume(){
    mMutex.lock();
    mIsPaused = false;
    mMutex.unlock();
    mWaitCondition.wakeAll();
    qDebug()<<QThread::currentThread() << "Resume";
}

void SuspandableWorker::stop(){

    mMutex.lock();
    if(mIsPaused)
        resume();

    mWillStop = true;
    qDebug()<<QThread::currentThread() << "Stop";
    emit finished();
    mMutex.unlock();
}

