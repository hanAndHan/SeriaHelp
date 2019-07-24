# SeriaHelp
开发环境：vs2010 opencv3.0 qt5.5.0
## 1.总体框架
![](https://github.com/hanAndHan/SeriaHelp/blob/master/img/%E6%A1%86%E6%9E%B6.png)
## 2.界面
![](https://github.com/hanAndHan/SeriaHelp/blob/master/img/%E7%95%8C%E9%9D%A2.png)
## 3.函数说明
Header:	#include "seriahelp.h"</br>
Inherits:	QMainWindow</br>
Properties</br>
QSerialPort *serial;//串口对象</br>
QList<QSerialPortInfo> infos;//保存串口信息</br>
QByteArray r_date;//接收缓存</br>
QByteArray s_date;//发送缓存</br>
int m_timerId;//延长串口读取缓存的时间</br>
int m_timerId_S;//显示发送时间</br>
int m_timerId_R;//显示接收时间</br>
int m_timerId_Reply;//重复发送</br>
int delay;//延迟接收</br>
unsigned int sendCount;//发送数据次数</br>
unsigned int recieveCount;//收到数据次数</br>
qint64 sendBytes;//发送字节数</br>
qint64 recieveBytes;//收到字节数</br>
QString timeText;//保存系统时间</br>

Public Functions
virtual void timerEvent(QTimerEvent *event);//定时器


Private Functions
void getSerialInfos();//获取可用串口
QByteArray QString2Hex(const QString& str);//字符串转为16进制编码
char ConvertHexChar(const char& ch);//字符转为16进制
QString &addPlainForH(QString &str);//给十六进制(收/发)数据每个字节间添加空白
QString &addPlainForA(QString &str);//给ASCII(收/发)数据每个字节间添加空白
void showSendForA();//显示以ASCII码发送的数据
void showSendForH();//显示以十六进制发送的数据
void showRecieveForA();//以ASCII码显示收到的数据
void showRecieveForH();//以十六进制显示收到的数据
void showTimeForSend();//显示发送时间
void showTimeForRecieve();//显示接收时间
void showSendBytes(const qint64& m_sendBytes);//显示发送字节数
void showRecieveBytesForA(const QByteArray& r_date);//显示接收字节数
void showRecieveBytesForH(const QByteArray& r_date);//显示接收字节数
void showSendCount();//显示发送次数
void showRecieveCount();//显示接收次数

Private Slots
void setSerialParameter(bool checked);//设置串口参数
void refreshSerialInfos();//刷新可用串口
void readSerial();//从缓存区读取数据
void writeSerial();//把数据发送到缓存区
void enterFormatSet(bool checked);//限制输入文本框格式
void startOrEndReplySend(bool checked);//启动或终止重复发送
void getCurrentDelay(int value);//获取当前接收延迟时间大小
void resetCurrentDelay(bool checked);//重置当前接收延迟时间大小
void clean();//清除数据
void chooseShowSendCount(bool checked);//不显示or显示发送次数
void chooseShowRecieveCount(bool checked);//不显示or显示接收次数
void onSave();//保存文件
void onOpen();//打开文件
