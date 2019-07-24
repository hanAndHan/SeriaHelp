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
	m_timerId_S=startTimer(1000);//��ȡϵͳ��ǰʱ��
	ui.sendTextEdit->setAttribute(Qt::WA_InputMethodEnabled, false);//�����������뷨
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
//��ȡ���ô���
void SeriaHelp::getSerialInfos()
{
	
	ui.comboBox_serialPort->clear();//�������Item
	infos=QSerialPortInfo::availablePorts();
    if(infos.empty())
		ui.comboBox_serialPort->addItem("none");
	else
	{
		foreach(QSerialPortInfo info,infos)//����ȡ�õ����ϵĴ�����Ϣ
		{

			serial->setPortName(info.portName());//ͨ��infoȡ��һ����������������Ϊ��ǰ����
			if(serial->open(QIODevice::ReadWrite))//�����Զ�д��ʽ�򿪸ô��ڣ���ô��ڿ���ʹ��
			{
				QString str=QString::fromLocal8Bit("����");
				ui.comboBox_serialPort->addItem(info.portName()+str);
				serial->close();//�رոô��ڣ���֮��ѡ��
			}
			else
			{
				QString str=QString::fromLocal8Bit("ռ��");
				ui.comboBox_serialPort->addItem(info.portName()+str);
			}
		}
	}
}
//���ô�����ز���
void SeriaHelp::setSerialParameter(bool checked)
{
	if(checked)
	{
		QString str=ui.comboBox_serialPort->currentText();
		QString str1=str.left(4);//��ȡǰ4���ַ�CMOX
		serial->setPortName(str1);
		if(serial->open(QIODevice::ReadWrite))
		{
			switch(ui.comboBox_baud->currentIndex())//������
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
			switch(ui.comboBox_dataWidth->currentIndex())//����λ
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
			switch(ui.comboBox_parityWidth->currentIndex())//У��λ
			{
			case 0:serial->setParity(QSerialPort::NoParity);
				break;
			case 1:serial->setParity(QSerialPort::OddParity);
				break;
			case 2:serial->setParity(QSerialPort::EvenParity);
				break;

			}
			switch(ui.comboBox_stopWidth->currentIndex())//ֹͣλ
			{
			case 0:serial->setStopBits(QSerialPort::OneStop);
				break;
			case 1:serial->setStopBits(QSerialPort::OneAndHalfStop);
				break;
			case 2:serial->setStopBits(QSerialPort::TwoStop);
				break;

			}
			switch(ui.comboBox_flowControl->currentIndex())//����
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
			ui.Button_SendDate->setEnabled(true);//���Կ�ʼ��������
			ui.checkBox_reply->setEnabled(true);//���Կ�ʼ�ظ���������
		
			ui.Button_openSerialPort->setText(QString::fromLocal8Bit("�رմ���"));
			connect(serial, SIGNAL(readyRead()), this, SLOT(readSerial()));//��ȡ����
		}
		else
		{
			QMessageBox::warning
				(
				this,
				QString::fromLocal8Bit("���ڴ�ʧ��"),
				QString::fromLocal8Bit("�������Ѿ���ռ�ã��򿪴���ǰ��ˢ�¿��ð�ť��"),
				QMessageBox::Cancel
				);
			ui.Button_openSerialPort->setChecked(false);
			return;
		}
	}
	else
	{
		serial->clear();//��ջ�����
		serial->close();//�رմ���
		ui.comboBox_baud->setEnabled(true);
		ui.comboBox_dataWidth->setEnabled(true);
		ui.comboBox_flowControl->setEnabled(true);
		ui.comboBox_parityWidth->setEnabled(true);
		ui.comboBox_serialPort->setEnabled(true);
		ui.comboBox_stopWidth->setEnabled(true);
		ui.Button_SendDate->setEnabled(false);//��ֹ��������
		ui.checkBox_reply->setEnabled(false);//��ֹ�ظ���������
        ui.Button_openSerialPort->setText(QString::fromLocal8Bit("�򿪴���"));

	}
}
//��ʱ��������
void SeriaHelp::timerEvent(QTimerEvent *event)
{
	if(event->timerId()==m_timerId)//��ʾ��ȡ����
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
		r_date.clear();//��ս��ջ���

		/*����*/
		QByteArray a="0x41";
		qDebug()<<a.toHex();//30 78 34 31��0��ASCII���������ʽ00110000��תΪʮ�����ƾ���30
	}
	if(event->timerId()==m_timerId_S)//��ʾ����ʱ��
	{
			QTime time=QTime::currentTime();
			timeText=time.toString("HH:mm:ss");
	}
	 if(event->timerId()==m_timerId_Reply)
	 {
		 writeSerial();
	 }
}
//ˢ�¿��ô���
void SeriaHelp::refreshSerialInfos()
{
	getSerialInfos();
}
//��ȡ����
void SeriaHelp::readSerial()
{
	m_timerId=startTimer(delay);//��100msʱ�����뼸������ۺ�������ÿ�ζ��������ݵ��ӣ�Ŀ����Ϊ�˵õ�����һ֡����ȥ��ʾ
	r_date.append(serial->readAll());//�ӻ���ȡ�� ����òۺ�����һ�̻����е��������� �����ջ���
	/*��ʾ��ȡ���ݵĴ������붨ʱ����������*/
}
//��������+��ʾ��������
void SeriaHelp::writeSerial()
{
	if(ui.radioButton_S_A->isChecked())
	{
		showSendForA();
		s_date=ui.sendTextEdit->text().toLatin1();//��������Latin1������ʽ���뷢�ͻ���
		showSendBytes(serial->write(s_date));//�ѷ��ͻ�������ݷ��뻺�棬�Զ����Ʊ�������ʽ����,����ʾ���͵��ֽ�
	}
	else if(ui.radioButton_S_H->isChecked())
	{
		
		if(ui.sendTextEdit->text().remove(QRegExp("\\s")).size()%2!=0)
		{
			qDebug()<<ui.sendTextEdit->text().size();
			QMessageBox::warning
				(
				this,
				QString::fromLocal8Bit("����ʧ��"),
				QString::fromLocal8Bit("��ǰѡ��16���Ʒ��ͣ�������ż�������ȵ�ʮ�������ַ���"),
				QMessageBox::Cancel
				);
			if(ui.checkBox_reply->isChecked())
				ui.checkBox_reply->setChecked(false);
			return ;
		}
		else
		{
			showSendForH();
			s_date=QString2Hex(ui.sendTextEdit->text().remove(QRegExp("\\s")));//ȥ���ո��������ʮ�����Ʊ�����ʽ���뷢�ͻ���
			showSendBytes(serial->write(s_date));//�ѷ��ͻ�������ݷ��뻺�棬�Զ����Ʊ�������ʽ����,����ʾ���͵��ֽ�
		}
	}
	s_date.clear();//��շ��ͻ���
}
//�ַ�תΪ16����
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
//�ַ���תΪ16���Ʊ���
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
		hstr=str[i].toLatin1();   //�ַ���
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
//��ʮ������(��/��)����ÿ���ֽڼ���ӿհ�
QString &SeriaHelp::addPlainForH(QString &str)
{
	int m=str.size();
	for(int i=0;i<m/2-1;i++)
		str.insert(i*3+2," ");
	return str;
}
//��ASCII(��/��)����ÿ���ֽڼ���ӿհ�
QString &SeriaHelp::addPlainForA(QString &str)
{
	int m=str.size();
	m--;
	for(int i=0;i<=m;i++)
		str.insert(i*2+1," ");  
	//01234567891011 
	//0 1 2 3       4�� 1,3,5 ,       i 0,1,2 
	//0 1 2 3 4     5�� 1,3,5,7,      i,0,1,2,3
	//0 1 2 3 4 5   6�� 1,3,5,7,9     i,0,1,2,3,4
	//0 1 2 3 4 5 6 7�� 1,3,5,7,9,11  i,0,1,2,3,4,5
	return str;
}
//��ʾ��ASCII�뷢�͵�����
void SeriaHelp::showSendForA()
{
	if(ui.checkBox_S->isChecked())
	{
		if(ui.checkBox_S_T->isChecked()&&!ui.sendTextEdit->text().isEmpty())
		{
			 showTimeForSend();
			 QString str=addPlainForA(ui.sendTextEdit->text());//���ֽڼ���ӿհ�
			 ui.recieveTextEdit->append(str);//��plaintext�Ի�����ʾ��ӿհ׺�ķ��͵�����
		}
		else if(!ui.sendTextEdit->text().isEmpty())
		{
			QString str=addPlainForA(ui.sendTextEdit->text());//�ֽڼ���ӿհ�
			QString str1=QString::fromLocal8Bit("���ͣ�");
			ui.recieveTextEdit->append(str1+str);//��plaintext�Ի�����ʾ��ӿհ׺�ķ��͵�����
		}
		else
			ui.recieveTextEdit->append(QString::fromLocal8Bit("�����ݣ����������ݣ�"));
	}
}
//��ʾ��ʮ�����Ʒ��͵�����
void SeriaHelp::showSendForH()
{
	if(ui.checkBox_S->isChecked())
	{
		if(ui.checkBox_S_T->isChecked()&&!ui.sendTextEdit->text().isEmpty())
		{
		    showTimeForSend();
			QString str=addPlainForH(ui.sendTextEdit->text().remove(QRegExp("\\s")).toUpper());//��ɾ������հ������ֽڼ���ӿհ�
			ui.recieveTextEdit->append(str);//��plaintext�Ի�����ʾ��ӿհ׺�ķ��͵�����
		}
		else if(!ui.sendTextEdit->text().isEmpty())
		{
			QString str=addPlainForH(ui.sendTextEdit->text().remove(QRegExp("\\s")).toUpper());//��ɾ������հ������ֽڼ���ӿհ�
			QString str1=QString::fromLocal8Bit("���ͣ�");
			ui.recieveTextEdit->append(str1+str);//��plaintext�Ի�����ʾ��ӿհ׺�ķ��͵�����
		}
		else
			ui.recieveTextEdit->append(QString::fromLocal8Bit("�����ݣ����������ݣ�"));
	}
}
//��ASCII����ʾ�յ�������
void SeriaHelp::showRecieveForA()
{
	if(ui.checkBox_R_T->isChecked())
	{
		showTimeForRecieve();
		showRecieveBytesForA(r_date);
		ui.recieveTextEdit->append(addPlainForA(QString(r_date)));//��ʾ���ջ����е����ݣ�Ĭ�Ͻ��ַ���Ӧ�Ķ����Ʊ�����תΪASCII���ַ�
	}
	else
	{
		QString str1=QString::fromLocal8Bit("���գ�");
		showRecieveBytesForA(r_date);
		ui.recieveTextEdit->append(str1+addPlainForA(QString(r_date)));//��ʾ���ջ����е����ݣ�Ĭ�Ͻ��ַ���Ӧ�Ķ����Ʊ�����תΪASCII���ַ�
	}
}
//��ʮ��������ʾ�յ�������
void SeriaHelp::showRecieveForH()
{
	if(ui.checkBox_R_T->isChecked())
	{
		showTimeForRecieve();
		QByteArray str=r_date.toHex();//toHex()���ַ���Ӧ�Ķ����Ʊ�����תΪ16���ƣ�ֻ��QByteArray����toHex()
		showRecieveBytesForH(str);
		ui.recieveTextEdit->append(addPlainForH(QString(str.toUpper())));//��plaintext�Ի�����ʾ���ջ����е�����
    }
	else
	{
		QByteArray str=r_date.toHex();//toHex()���ַ���Ӧ�Ķ����Ʊ�����תΪ16���ƣ�ֻ��QByteArray����toHex()
		showRecieveBytesForH(str);
		QString str1=QString::fromLocal8Bit("���գ�");
		ui.recieveTextEdit->append(str1+addPlainForH(QString(str.toUpper())));//��plaintext�Ի�����ʾ���ջ����е�����
	}
}
//��ʾ����ʱ��
void SeriaHelp::showTimeForSend()
{
	QString str1=QString::fromLocal8Bit("����(");
	QString str2=timeText;
	str2.append(")");
	ui.recieveTextEdit->append(str1+str2);
}
//��ʾ����ʱ��
void SeriaHelp::showTimeForRecieve()
{
	QString str1=QString::fromLocal8Bit("����(");
	QString str2=timeText;
	str2.append(")");
	ui.recieveTextEdit->append(str1+str2);
}
//���������ı����ʽ
void SeriaHelp::enterFormatSet(bool checked)
{
	if(checked)
	{
		ui.sendTextEdit->clear();
		ui.sendTextEdit->setValidator(0);
		ui.sendTextEdit->setPlaceholderText(QString::fromLocal8Bit("ASCII�ַ�"));
	}
   else
   {
	   ui.sendTextEdit->clear();
	   ui.sendTextEdit->setPlaceholderText(QString::fromLocal8Bit("ʮ�������ַ���������ż��������"));
	   QRegExp reg("[a-fA-F0-9]+$"); 
	   QRegExpValidator *pValidator = new QRegExpValidator(this); 
	   pValidator->setRegExp(reg); 
	   ui.sendTextEdit->setValidator(pValidator);
   }
}
//��ʾ�����ֽ���
void SeriaHelp::showSendBytes(const qint64& m_sendBytes)
{
	if(m_sendBytes>0)
		showSendCount();//�ڲ��������ݵ�����µ�����ͣ�m_sendBytes=0����ȻҲ�ܷ��Ͷ�����ȥ������û�����壬����m_sendBytes>0ʱ�ټ���
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
			QString::fromLocal8Bit("����ʧ��"),
			QString::fromLocal8Bit("δ֪�����볢�����·���"),
			QMessageBox::Cancel
			);
	}
}
//��ʾ�����ֽ���
void SeriaHelp::showRecieveBytesForA(const QByteArray& r_date)
{
	recieveBytes+=r_date.size();
	ui.lcdNumber_receive->display(QString::number(recieveBytes));
}
//��ʾ�����ֽ���
void SeriaHelp::showRecieveBytesForH(const QByteArray& r_date)
{
	recieveBytes+=r_date.size()/2;
	ui.lcdNumber_receive->display(QString::number(recieveBytes));
}
//��ʾ���ʹ���
void SeriaHelp::showSendCount()
{
	sendCount++;
	if(ui.checkBox_S_Count->isChecked())
		ui.label_sendCount->setText(QString::number(sendCount));
}
//��ʾ���մ���
void SeriaHelp::showRecieveCount()
{
	recieveCount++;
	if(ui.checkBox_R_Count->isChecked())
		ui.label_recieveCount->setText(QString::number(recieveCount));
}
//��������ֹ�ظ�����
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
//��ȡ��ǰ�����ӳ�ʱ���С
void SeriaHelp::getCurrentDelay(int value)
{
	if(ui.checkBox_recieveDelay->isChecked())
	    delay=value;
	else
		delay=0;
}
//���õ�ǰ�����ӳ�ʱ���С
void SeriaHelp::resetCurrentDelay(bool checked)//���õ�ǰ�����ӳ�ʱ���С
{
	if(checked)
		delay=ui.spinBox_recieveDelay->text().toInt();
	else
		delay=0;
}
//�������
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
//����ʾor��ʾ���ʹ���
void SeriaHelp::chooseShowSendCount(bool checked)
{
	if(!checked)
		ui.label_sendCount->clear();
	else
		ui.label_sendCount->setText(QString::number(sendCount));
}
//����ʾor��ʾ���մ���
void SeriaHelp::chooseShowRecieveCount(bool checked)
{
	if(!checked)
		ui.label_recieveCount->clear();
	else
		ui.label_recieveCount->setText(QString::number(recieveCount));
}
//�����ļ�
void SeriaHelp::onSave()
{
	QString filepath=QFileDialog::getSaveFileName(this,QString::fromLocal8Bit("�����ļ�"),"xxx.txt",QString::fromLocal8Bit("�ı��ļ�(*txt)"));
	if(filepath.length()==0)
		return;
	//����ļ�����
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
    //״̬����ʾ
	ui.statusBar->showMessage(QString::fromLocal8Bit("�ѱ���"),3*1000);//�ڶ�����������ʾ�೤ʱ�䣬������3��
	ui.m_lableName->setText(filepath);
}
//���ļ�
void SeriaHelp::onOpen()
{
	QString filepath=QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("���ļ�"),".",QString::fromLocal8Bit("�ı��ļ�(*txt)"));
	if(filepath.length()==0)
		return;
	string filename=filepath.toLocal8Bit();
	//��ȡ�ļ�����
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
	//���ļ�������ʾ������
	ui.sendTextEdit->setText(QString::fromLocal8Bit(buf1.c_str()));
	//״̬����ʾ
	ui.statusBar->showMessage(QString::fromLocal8Bit("�Ѵ�"),3*1000);//�ڶ�����������ʾ�೤ʱ�䣬������3��
	ui.m_lableName->setText( filepath);
}