#include"seriahelp.h"
#include<QMessageBox>
#include <QString>
#include <QDebug>
SeriaHelp::SeriaHelp(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	serial=new QSerialPort;
    sendCount=0;
	recieveCount=0;
    sendBytes=0;
	recieveBytes=0;
	delay=0;
	getSerialInfos();
	m_timerId_S=startTimer(1000);//获取系统当前时间
	ui.sendTextEdit->setAttribute(Qt::WA_InputMethodEnabled, false);//屏蔽中文输入法
	ui.statusBar->insertWidget(0,ui.m_lableName);
	connect(ui.Button_openSerialPort,SIGNAL(toggled(bool)),this,SLOT(setSerialParameter(bool)));
	connect(ui.Button_refresh,SIGNAL(clicked()),this,SLOT(refreshSerialInfos()));
	connect(ui.Button_SendDate,SIGNAL(clicked()),this,SLOT(writeSerial()));
	connect(ui.radioButton_S_A,SIGNAL(toggled(bool)),this,SLOT(enterFormatSet(bool)));
	connect(ui.checkBox_reply,SIGNAL(toggled(bool)),this,SLOT(startOrEndReplySend(bool)));
	connect(ui.spinBox_recieveDelay,SIGNAL(valueChanged(int)),this,SLOT(getCurrentDelay(int)));
	connect(ui.checkBox_recieveDelay,SIGNAL(toggled(bool)),this,SLOT(resetCurrentDelay(bool)));
	connect(ui.Button_clear,SIGNAL(clicked()),this,SLOT(clean()));
	connect(ui.checkBox_S_Count,SIGNAL(toggled(bool)),this,SLOT(chooseShowSendCount(bool)));
	connect(ui.checkBox_R_Count,SIGNAL(toggled(bool)),this,SLOT(chooseShowRecieveCount(bool)));
	connect(ui.actionSave,SIGNAL(triggered()),this,SLOT(onSave()));
	connect(ui.actionOpen,SIGNAL(triggered()),this,SLOT(onOpen()));	
	
}

SeriaHelp::~SeriaHelp()
{
	delete serial;	
}
//获取可用串口
void SeriaHelp::getSerialInfos()
{
	
	ui.comboBox_serialPort->clear();//清空现有Item
	infos=QSerialPortInfo::availablePorts();
    if(infos.empty())
		ui.comboBox_serialPort->addItem("none");
	else
	{
		foreach(QSerialPortInfo info,infos)//依次取得电脑上的串口信息
		{

			serial->setPortName(info.portName());//通过info取得一个串口名，把它设为当前串口
			if(serial->open(QIODevice::ReadWrite))//若能以读写方式打开该串口，则该串口可以使用
			{
				QString str=QString::fromLocal8Bit("可用");
				ui.comboBox_serialPort->addItem(info.portName()+str);
				serial->close();//关闭该串口，待之后选用
			}
			else
			{
				QString str=QString::fromLocal8Bit("占用");
				ui.comboBox_serialPort->addItem(info.portName()+str);
			}
		}
	}
}
//设置串口相关参数
void SeriaHelp::setSerialParameter(bool checked)
{
	if(checked)
	{
		QString str=ui.comboBox_serialPort->currentText();
		QString str1=str.left(4);//截取前4个字符CMOX
		serial->setPortName(str1);
		if(serial->open(QIODevice::ReadWrite))
		{
			switch(ui.comboBox_baud->currentIndex())//波特率
			{
			case 0:serial->setBaudRate(QSerialPort::Baud115200);
				break;
			case 1:serial->setBaudRate(QSerialPort::Baud57600);
				break;
			case 2:serial->setBaudRate(QSerialPort::Baud38400);
				break;
			case 3:serial->setBaudRate(QSerialPort::Baud19200);
				break;
			case 4:serial->setBaudRate(QSerialPort::Baud9600);
				break;
			case 5:serial->setBaudRate(QSerialPort::Baud4800);
				break;
			case 6:serial->setBaudRate(QSerialPort::Baud2400);
				break;
			case 7:serial->setBaudRate(QSerialPort::Baud1200);
				break;
			}
			switch(ui.comboBox_dataWidth->currentIndex())//数据位
			{
			case 0:serial->setDataBits(QSerialPort::Data8);
				break;
			case 1:serial->setDataBits(QSerialPort::Data7);
				break;
			case 2:serial->setDataBits(QSerialPort::Data6);
				break;
			case 3:serial->setDataBits(QSerialPort::Data5);
				break;
			}
			switch(ui.comboBox_parityWidth->currentIndex())//校验位
			{
			case 0:serial->setParity(QSerialPort::NoParity);
				break;
			case 1:serial->setParity(QSerialPort::OddParity);
				break;
			case 2:serial->setParity(QSerialPort::EvenParity);
				break;

			}
			switch(ui.comboBox_stopWidth->currentIndex())//停止位
			{
			case 0:serial->setStopBits(QSerialPort::OneStop);
				break;
			case 1:serial->setStopBits(QSerialPort::OneAndHalfStop);
				break;
			case 2:serial->setStopBits(QSerialPort::TwoStop);
				break;

			}
			switch(ui.comboBox_flowControl->currentIndex())//流控
			{
			case 0:serial->setFlowControl(QSerialPort::NoFlowControl);
				break;
			case 1:serial->setFlowControl(QSerialPort::HardwareControl);
				break;
			case 2:serial->setFlowControl(QSerialPort::SoftwareControl);
				break;
			}
			ui.comboBox_baud->setEnabled(false);
			ui.comboBox_dataWidth->setEnabled(false);
			ui.comboBox_flowControl->setEnabled(false);
			ui.comboBox_parityWidth->setEnabled(false);
			ui.comboBox_serialPort->setEnabled(false);
			ui.comboBox_stopWidth->setEnabled(false);
			ui.Button_SendDate->setEnabled(true);//可以开始发送数据
			ui.checkBox_reply->setEnabled(true);//可以开始重复发送数据
		
			ui.Button_openSerialPort->setText(QString::fromLocal8Bit("关闭串口"));
			connect(serial, SIGNAL(readyRead()), this, SLOT(readSerial()));//读取数据
		}
		else
		{
			QMessageBox::warning
				(
				this,
				QString::fromLocal8Bit("串口打开失败"),
				QString::fromLocal8Bit("本串口已经被占用，打开串口前请刷新可用按钮！"),
				QMessageBox::Cancel
				);
			ui.Button_openSerialPort->setChecked(false);
			return;
		}
	}
	else
	{
		serial->clear();//清空缓冲区
		serial->close();//关闭串口
		ui.comboBox_baud->setEnabled(true);
		ui.comboBox_dataWidth->setEnabled(true);
		ui.comboBox_flowControl->setEnabled(true);
		ui.comboBox_parityWidth->setEnabled(true);
		ui.comboBox_serialPort->setEnabled(true);
		ui.comboBox_stopWidth->setEnabled(true);
		ui.Button_SendDate->setEnabled(false);//禁止发送数据
		ui.checkBox_reply->setEnabled(false);//禁止重复发送数据
        ui.Button_openSerialPort->setText(QString::fromLocal8Bit("打开串口"));

	}
}
//定时器处理函数
void SeriaHelp::timerEvent(QTimerEvent *event)
{
	if(event->timerId()==m_timerId)//显示读取数据
	{
		if(!r_date.isEmpty())
		{
			showRecieveCount();
			killTimer(m_timerId);
			if(ui.radioButton_R_H->isChecked())
			{
				showRecieveForH();
			}
			else if(ui.radioButton_R_A->isChecked())
			{
				showRecieveForA();
			}
		}
		r_date.clear();//清空接收缓存

		/*测试*/
		QByteArray a="0x41";
		qDebug()<<a.toHex();//30 78 34 31，0的ASCII码二进制形式00110000，转为十六进制就是30
	}
	if(event->timerId()==m_timerId_S)//显示发送时间
	{
			QTime time=QTime::currentTime();
			timeText=time.toString("HH:mm:ss");
	}
	 if(event->timerId()==m_timerId_Reply)
	 {
		 writeSerial();
	 }
}
//刷新可用串口
void SeriaHelp::refreshSerialInfos()
{
	getSerialInfos();
}
//读取数据
void SeriaHelp::readSerial()
{
	m_timerId=startTimer(delay);//给100ms时间多进入几次这个槽函数，把每次读到的数据叠加，目的是为了得到完整一帧数据去显示
	r_date.append(serial->readAll());//从缓存取出 进入该槽函数那一刻缓存中的所有数据 到接收缓存
	/*显示读取数据的代码移入定时器处理函数中*/
}
//发送数据+显示发送数据
void SeriaHelp::writeSerial()
{
	if(ui.radioButton_S_A->isChecked())
	{
		showSendForA();
		s_date=ui.sendTextEdit->text().toLatin1();//将数据以Latin1编码形式放入发送缓存
		showSendBytes(serial->write(s_date));//把发送缓存的数据放入缓存，以二进制比特流形式发送,并显示发送的字节
	}
	else if(ui.radioButton_S_H->isChecked())
	{
		
		if(ui.sendTextEdit->text().remove(QRegExp("\\s")).size()%2!=0)
		{
			qDebug()<<ui.sendTextEdit->text().size();
			QMessageBox::warning
				(
				this,
				QString::fromLocal8Bit("发送失败"),
				QString::fromLocal8Bit("当前选中16进制发送，请输入偶数倍长度的十六进制字符！"),
				QMessageBox::Cancel
				);
			if(ui.checkBox_reply->isChecked())
				ui.checkBox_reply->setChecked(false);
			return ;
		}
		else
		{
			showSendForH();
			s_date=QString2Hex(ui.sendTextEdit->text().remove(QRegExp("\\s")));//去掉空格后将数据以十六进制编码形式放入发送缓存
			showSendBytes(serial->write(s_date));//把发送缓存的数据放入缓存，以二进制比特流形式发送,并显示发送的字节
		}
	}
	s_date.clear();//清空发送缓存
}
//字符转为16进制
char SeriaHelp::ConvertHexChar(const char& ch)
{
	if((ch >= '0') && (ch <= '9'))
		return ch-0x30;
	else if((ch >= 'A') && (ch <= 'F'))
		return ch-'A'+10;
	else if((ch >= 'a') && (ch <= 'f'))
		return ch-'a'+10;
	else return (-1);
}
//字符串转为16进制编码
QByteArray SeriaHelp::QString2Hex(const QString& str)
{
	QByteArray senddata;
	int hexdata,lowhexdata;
	int hexdatalen = 0;
	int len = str.length();
	senddata.resize(len/2);
	char lstr,hstr;
	for(int i=0; i<len; )
	{
		hstr=str[i].toLatin1();   //字符型
		if(hstr == ' ')
		{
			i++;
			continue;
		}
		i++;
		if(i >= len)
			break;
		lstr = str[i].toLatin1();
		hexdata = ConvertHexChar(hstr);
		lowhexdata = ConvertHexChar(lstr);
		if((hexdata == 16) || (lowhexdata == 16))
			break;
		else
			hexdata = hexdata*16+lowhexdata;
		i++;
		senddata[hexdatalen] = (char)hexdata;
		hexdatalen++;
	}
	senddata.resize(hexdatalen);
	return senddata;
}
//给十六进制(收/发)数据每个字节间添加空白
QString &SeriaHelp::addPlainForH(QString &str)
{
	int m=str.size();
	for(int i=0;i<m/2-1;i++)
		str.insert(i*3+2," ");
	return str;
}
//给ASCII(收/发)数据每个字节间添加空白
QString &SeriaHelp::addPlainForA(QString &str)
{
	int m=str.size();
	m--;
	for(int i=0;i<=m;i++)
		str.insert(i*2+1," ");  
	//01234567891011 
	//0 1 2 3       4个 1,3,5 ,       i 0,1,2 
	//0 1 2 3 4     5个 1,3,5,7,      i,0,1,2,3
	//0 1 2 3 4 5   6个 1,3,5,7,9     i,0,1,2,3,4
	//0 1 2 3 4 5 6 7个 1,3,5,7,9,11  i,0,1,2,3,4,5
	return str;
}
//显示以ASCII码发送的数据
void SeriaHelp::showSendForA()
{
	if(ui.checkBox_S->isChecked())
	{
		if(ui.checkBox_S_T->isChecked()&&!ui.sendTextEdit->text().isEmpty())
		{
			 showTimeForSend();
			 QString str=addPlainForA(ui.sendTextEdit->text());//在字节间添加空白
			 ui.recieveTextEdit->append(str);//在plaintext对话框显示添加空白后的发送的数据
		}
		else if(!ui.sendTextEdit->text().isEmpty())
		{
			QString str=addPlainForA(ui.sendTextEdit->text());//字节间添加空白
			QString str1=QString::fromLocal8Bit("发送：");
			ui.recieveTextEdit->append(str1+str);//在plaintext对话框显示添加空白后的发送的数据
		}
		else
			ui.recieveTextEdit->append(QString::fromLocal8Bit("无数据！请输入数据！"));
	}
}
//显示以十六进制发送的数据
void SeriaHelp::showSendForH()
{
	if(ui.checkBox_S->isChecked())
	{
		if(ui.checkBox_S_T->isChecked()&&!ui.sendTextEdit->text().isEmpty())
		{
		    showTimeForSend();
			QString str=addPlainForH(ui.sendTextEdit->text().remove(QRegExp("\\s")).toUpper());//先删除多余空白再在字节间添加空白
			ui.recieveTextEdit->append(str);//在plaintext对话框显示添加空白后的发送的数据
		}
		else if(!ui.sendTextEdit->text().isEmpty())
		{
			QString str=addPlainForH(ui.sendTextEdit->text().remove(QRegExp("\\s")).toUpper());//先删除多余空白再在字节间添加空白
			QString str1=QString::fromLocal8Bit("发送：");
			ui.recieveTextEdit->append(str1+str);//在plaintext对话框显示添加空白后的发送的数据
		}
		else
			ui.recieveTextEdit->append(QString::fromLocal8Bit("无数据！请输入数据！"));
	}
}
//以ASCII码显示收到的数据
void SeriaHelp::showRecieveForA()
{
	if(ui.checkBox_R_T->isChecked())
	{
		showTimeForRecieve();
		showRecieveBytesForA(r_date);
		ui.recieveTextEdit->append(addPlainForA(QString(r_date)));//显示接收缓存中的数据，默认将字符对应的二进制比特流转为ASCII码字符
	}
	else
	{
		QString str1=QString::fromLocal8Bit("接收：");
		showRecieveBytesForA(r_date);
		ui.recieveTextEdit->append(str1+addPlainForA(QString(r_date)));//显示接收缓存中的数据，默认将字符对应的二进制比特流转为ASCII码字符
	}
}
//以十六进制显示收到的数据
void SeriaHelp::showRecieveForH()
{
	if(ui.checkBox_R_T->isChecked())
	{
		showTimeForRecieve();
		QByteArray str=r_date.toHex();//toHex()将字符对应的二进制比特流转为16进制，只有QByteArray才有toHex()
		showRecieveBytesForH(str);
		ui.recieveTextEdit->append(addPlainForH(QString(str.toUpper())));//在plaintext对话框显示接收缓存中的数据
    }
	else
	{
		QByteArray str=r_date.toHex();//toHex()将字符对应的二进制比特流转为16进制，只有QByteArray才有toHex()
		showRecieveBytesForH(str);
		QString str1=QString::fromLocal8Bit("接收：");
		ui.recieveTextEdit->append(str1+addPlainForH(QString(str.toUpper())));//在plaintext对话框显示接收缓存中的数据
	}
}
//显示发送时间
void SeriaHelp::showTimeForSend()
{
	QString str1=QString::fromLocal8Bit("发送(");
	QString str2=timeText;
	str2.append(")");
	ui.recieveTextEdit->append(str1+str2);
}
//显示接收时间
void SeriaHelp::showTimeForRecieve()
{
	QString str1=QString::fromLocal8Bit("接收(");
	QString str2=timeText;
	str2.append(")");
	ui.recieveTextEdit->append(str1+str2);
}
//限制输入文本框格式
void SeriaHelp::enterFormatSet(bool checked)
{
	if(checked)
	{
		ui.sendTextEdit->clear();
		ui.sendTextEdit->setValidator(0);
		ui.sendTextEdit->setPlaceholderText(QString::fromLocal8Bit("ASCII字符"));
	}
   else
   {
	   ui.sendTextEdit->clear();
	   ui.sendTextEdit->setPlaceholderText(QString::fromLocal8Bit("十六进制字符，请输入偶数倍长度"));
	   QRegExp reg("[a-fA-F0-9]+$"); 
	   QRegExpValidator *pValidator = new QRegExpValidator(this); 
	   pValidator->setRegExp(reg); 
	   ui.sendTextEdit->setValidator(pValidator);
   }
}
//显示发送字节数
void SeriaHelp::showSendBytes(const qint64& m_sendBytes)
{
	if(m_sendBytes>0)
		showSendCount();//在不输入数据的情况下点击发送，m_sendBytes=0，虽然也能发送东西出去，但是没有意义，所以m_sendBytes>0时再记数
	if(m_sendBytes!=-1)
	{
		qDebug()<<m_sendBytes;
		sendBytes+=m_sendBytes;
		ui.lcdNumber_send->display(QString::number(sendBytes));
	}
	else
	{
		QMessageBox::warning
			(
			this,
			QString::fromLocal8Bit("发送失败"),
			QString::fromLocal8Bit("未知错误，请尝试重新发送"),
			QMessageBox::Cancel
			);
	}
}
//显示接收字节数
void SeriaHelp::showRecieveBytesForA(const QByteArray& r_date)
{
	recieveBytes+=r_date.size();
	ui.lcdNumber_receive->display(QString::number(recieveBytes));
}
//显示接收字节数
void SeriaHelp::showRecieveBytesForH(const QByteArray& r_date)
{
	recieveBytes+=r_date.size()/2;
	ui.lcdNumber_receive->display(QString::number(recieveBytes));
}
//显示发送次数
void SeriaHelp::showSendCount()
{
	sendCount++;
	if(ui.checkBox_S_Count->isChecked())
		ui.label_sendCount->setText(QString::number(sendCount));
}
//显示接收次数
void SeriaHelp::showRecieveCount()
{
	recieveCount++;
	if(ui.checkBox_R_Count->isChecked())
		ui.label_recieveCount->setText(QString::number(recieveCount));
}
//启动或终止重复发送
void SeriaHelp::startOrEndReplySend(bool checked)
{
	if(checked)
	{
		m_timerId_Reply=startTimer(ui.spinBox_Reply->text().toInt());
		ui.Button_SendDate->setEnabled(false);
		ui.spinBox_Reply->setEnabled(false);
	}
	else if(!checked)
		{
			killTimer(m_timerId_Reply);
			ui.Button_SendDate->setEnabled(true);
			ui.spinBox_Reply->setEnabled(true);
	    }
}
//获取当前接收延迟时间大小
void SeriaHelp::getCurrentDelay(int value)
{
	if(ui.checkBox_recieveDelay->isChecked())
	    delay=value;
	else
		delay=0;
}
//重置当前接收延迟时间大小
void SeriaHelp::resetCurrentDelay(bool checked)//重置当前接收延迟时间大小
{
	if(checked)
		delay=ui.spinBox_recieveDelay->text().toInt();
	else
		delay=0;
}
//清除数据
void SeriaHelp::clean()
{
	sendCount=0;
	recieveCount=0;
	sendBytes=0;
	recieveBytes=0;
	if(ui.checkBox_S_Count->isChecked())
	ui.label_sendCount->setText(QString::number(0));
	if(ui.checkBox_R_Count->isChecked())
	ui.label_recieveCount->setText(QString::number(0));
	ui.lcdNumber_send->display(QString::number(0));
	ui.lcdNumber_receive->display(QString::number(0));
	ui.recieveTextEdit->clear();
	ui.sendTextEdit->clear();
}
//不显示or显示发送次数
void SeriaHelp::chooseShowSendCount(bool checked)
{
	if(!checked)
		ui.label_sendCount->clear();
	else
		ui.label_sendCount->setText(QString::number(sendCount));
}
//不显示or显示接收次数
void SeriaHelp::chooseShowRecieveCount(bool checked)
{
	if(!checked)
		ui.label_recieveCount->clear();
	else
		ui.label_recieveCount->setText(QString::number(recieveCount));
}
//保存文件
void SeriaHelp::onSave()
{
	QString filepath=QFileDialog::getSaveFileName(this,QString::fromLocal8Bit("保存文件"),"xxx.txt",QString::fromLocal8Bit("文本文件(*txt)"));
	if(filepath.length()==0)
		return;
	//输出文件内容
	string text=ui.recieveTextEdit->toPlainText().toLocal8Bit();
	string filename=filepath.toLocal8Bit();
	ofstream fout;
	fout.open(filename.c_str());
	if(fout.is_open())
	{
		fout<<text;
		fout.close();
		fout.clear();
	}
    //状态栏显示
	ui.statusBar->showMessage(QString::fromLocal8Bit("已保存"),3*1000);//第二个参数是显示多长时间，这里是3秒
	ui.m_lableName->setText(filepath);
}
//打开文件
void SeriaHelp::onOpen()
{
	QString filepath=QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("打开文件"),".",QString::fromLocal8Bit("文本文件(*txt)"));
	if(filepath.length()==0)
		return;
	string filename=filepath.toLocal8Bit();
	//读取文件内容
	ifstream fin;
	fin.open(filename.c_str());
	string buf;
	string buf1;
	if(fin.is_open())
	{
		while(getline(fin,buf))
			buf1=buf1+buf;
		fin.close();
		fin.clear();
	}
	//将文件内容显示到界面
	ui.sendTextEdit->setText(QString::fromLocal8Bit(buf1.c_str()));
	//状态栏显示
	ui.statusBar->showMessage(QString::fromLocal8Bit("已打开"),3*1000);//第二个参数是显示多长时间，这里是3秒
	ui.m_lableName->setText( filepath);
}