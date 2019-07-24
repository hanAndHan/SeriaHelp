#ifndef SERIAHELP_H
#define SERIAHELP_H
#include <QtWidgets/QMainWindow>
#include "ui_seriahelp.h"
#include<QSerialPortInfo>
#include <QFileDialog>
#include<QSerialPort>
#include<QByteArray>
#include<fstream>
#include<QString>
#include<string>
#include<QLabel>
#include<QList>
#include<QTime>
using namespace std;
class SeriaHelp : public QMainWindow
{
	Q_OBJECT

public:
	SeriaHelp(QWidget *parent = 0);
	~SeriaHelp();
	virtual void timerEvent(QTimerEvent *event);
	Ui::SeriaHelpClass ui;
private:
	
	QSerialPort *serial;//串口对象
	QList<QSerialPortInfo> infos;//保存串口信息
	QByteArray r_date;//接收缓存
	QByteArray s_date;//发送缓存
	int m_timerId;//延长串口读取缓存的时间
	int m_timerId_S;//显示发送时间
	int m_timerId_R;//显示接收时间
	int m_timerId_Reply;//重复发送
	int delay;//延迟接收
	unsigned int sendCount;//发送数据次数
	unsigned int recieveCount;//收到数据次数
	qint64 sendBytes;//发送字节数
	qint64 recieveBytes;//收到字节数
	QString timeText;//保存系统时间
	
	
private:
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

private slots:	
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
};

#endif // SERIAHELP_H
