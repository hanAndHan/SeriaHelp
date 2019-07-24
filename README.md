# SeriaHelp
开发环境：vs2010 opencv3.0 qt5.5.0
## 1.总体框架
![](https://github.com/hanAndHan/SeriaHelp/blob/master/img/%E6%A1%86%E6%9E%B6.png)
## 2.界面
![](https://github.com/hanAndHan/SeriaHelp/blob/master/img/%E7%95%8C%E9%9D%A2.png)
## 3.代码构成
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

Public Functions</br>
virtual void timerEvent(QTimerEvent *event);//定时器</br>

Private Functions</br>
void getSerialInfos();//获取可用串口</br>
QByteArray QString2Hex(const QString& str);//字符串转为16进制编码</br>
char ConvertHexChar(const char& ch);//字符转为16进制</br>
QString &addPlainForH(QString &str);//给十六进制(收/发)数据每个字节间添加空白</br>
QString &addPlainForA(QString &str);//给ASCII(收/发)数据每个字节间添加空白</br>
void showSendForA();//显示以ASCII码发送的数据</br>
void showSendForH();//显示以十六进制发送的数据</br>
void showRecieveForA();//以ASCII码显示收到的数据</br>
void showRecieveForH();//以十六进制显示收到的数据</br>
void showTimeForSend();//显示发送时间</br>
void showTimeForRecieve();//显示接收时间</br>
void showSendBytes(const qint64& m_sendBytes);//显示发送字节数</br>
void showRecieveBytesForA(const QByteArray& r_date);//显示接收字节数</br>
void showRecieveBytesForH(const QByteArray& r_date);//显示接收字节数</br>
void showSendCount();//显示发送次数</br>
void showRecieveCount();//显示接收次数</br>

Private Slots</br>
void setSerialParameter(bool checked);//设置串口参数</br>
void refreshSerialInfos();//刷新可用串口</br>
void readSerial();//从缓存区读取数据</br>
void writeSerial();//把数据发送到缓存区</br>
void enterFormatSet(bool checked);//限制输入文本框格式</br>
void startOrEndReplySend(bool checked);//启动或终止重复发送</br>
void getCurrentDelay(int value);//获取当前接收延迟时间大小</br>
void resetCurrentDelay(bool checked);//重置当前接收延迟时间大小</br>
void clean();//清除数据</br>
void chooseShowSendCount(bool checked);//不显示or显示发送次数</br>
void chooseShowRecieveCount(bool checked);//不显示or显示接收次数</br>
void onSave();//保存文件</br>
void onOpen();//打开文件</br>
