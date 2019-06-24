#include "mythread.h"
#include <QThread>
#include <QDebug>

MyThread::MyThread()
{

}

void MyThread::run()
{

}


void MyThread::setValue(int num)
{
 printNum = num;
}
//void My_Thread()
//{
// MyThread *thread01 = new MyThread() ;
//// thread01->setValue(10);  //线程标记值
//   thread01->setValue(10);

// MyThread *thread02 = new MyThread() ;
//// thread02->setValue(20);

// thread01->start();
// thread02->start();
//}
