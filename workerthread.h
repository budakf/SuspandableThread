#ifndef CUSTOMTHREAD_H
#define CUSTOMTHREAD_H

#include <QThread>
#include "suspandableworker.h"

class WorkerThread : public QThread{
    Q_OBJECT
public:
    WorkerThread(SuspandableWorker* pWorker, QObject* parent = nullptr);
    ~WorkerThread();
    void pause();
    void stop();
    void resume();

protected:
    void run() override;

private:
    SuspandableWorker* mWorker;
    void connection();

signals:
    void play();

};

#endif // CUSTOMTHREAD_H

