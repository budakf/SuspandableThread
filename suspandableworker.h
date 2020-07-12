#ifndef SUSPANDABLEWORKER_H
#define SUSPANDABLEWORKER_H

#include<QMutex>
#include<QDebug>
#include<QThread>
#include<QObject>
#include<QWaitCondition>


class SuspandableWorker : public QObject{
    Q_OBJECT

public:
    SuspandableWorker();
    ~SuspandableWorker();

private:
    QMutex mMutex;
    QWaitCondition mWaitCondition;
    bool mIsPaused;
    bool mWillStop;

public slots:
    void play();
    void pause();
    void resume();
    void stop();

signals:
    void finished();

};

#endif // SUSPANDABLEWORKER_H

