#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
 Q_OBJECT
public:
 MyThread();

protected:
 void run();
public:
 //用来打印数据
 void setValue(int num);
private:
 int printNum;
};

#endif // MYTHREAD_H
