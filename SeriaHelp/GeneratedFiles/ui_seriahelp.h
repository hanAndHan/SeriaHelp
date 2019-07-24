/********************************************************************************
** Form generated from reading UI file 'seriahelp.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIAHELP_H
#define UI_SERIAHELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SeriaHelpClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_serialPort;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_baud;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox_dataWidth;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *comboBox_parityWidth;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *comboBox_stopWidth;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QComboBox *comboBox_flowControl;
    QTextBrowser *recieveTextEdit;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_12;
    QRadioButton *radioButton_S_A;
    QRadioButton *radioButton_S_H;
    QHBoxLayout *horizontalLayout_20;
    QCheckBox *checkBox_S_T;
    QCheckBox *checkBox_S;
    QHBoxLayout *horizontalLayout_16;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *checkBox_S_Count;
    QLabel *label_sendCount;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_14;
    QCheckBox *checkBox_reply;
    QSpinBox *spinBox_Reply;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *radioButton_R_A;
    QRadioButton *radioButton_R_H;
    QCheckBox *checkBox_R_T;
    QHBoxLayout *horizontalLayout_19;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *checkBox_R_Count;
    QLabel *label_recieveCount;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_17;
    QCheckBox *checkBox_recieveDelay;
    QSpinBox *spinBox_recieveDelay;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_13;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_11;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *sendTextEdit;
    QPushButton *Button_SendDate;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QToolButton *Button_openSerialPort;
    QPushButton *Button_refresh;
    QPushButton *Button_clear;
    QPushButton *Button_exit;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_18;
    QGroupBox *groupBox_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_9;
    QLCDNumber *lcdNumber_receive;
    QLabel *label_10;
    QGroupBox *groupBox_6;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_11;
    QLCDNumber *lcdNumber_send;
    QLabel *label_12;
    QLabel *m_lableName;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SeriaHelpClass)
    {
        if (SeriaHelpClass->objectName().isEmpty())
            SeriaHelpClass->setObjectName(QStringLiteral("SeriaHelpClass"));
        SeriaHelpClass->setEnabled(true);
        SeriaHelpClass->resize(740, 399);
        SeriaHelpClass->setStyleSheet(QStringLiteral(""));
        actionOpen = new QAction(SeriaHelpClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(SeriaHelpClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralWidget = new QWidget(SeriaHelpClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 141, 191));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox_serialPort = new QComboBox(groupBox);
        comboBox_serialPort->setObjectName(QStringLiteral("comboBox_serialPort"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_serialPort->sizePolicy().hasHeightForWidth());
        comboBox_serialPort->setSizePolicy(sizePolicy);
        comboBox_serialPort->setMinimumSize(QSize(72, 0));
        comboBox_serialPort->setMaximumSize(QSize(72, 16777215));

        horizontalLayout->addWidget(comboBox_serialPort);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBox_baud = new QComboBox(groupBox);
        comboBox_baud->setObjectName(QStringLiteral("comboBox_baud"));
        sizePolicy.setHeightForWidth(comboBox_baud->sizePolicy().hasHeightForWidth());
        comboBox_baud->setSizePolicy(sizePolicy);
        comboBox_baud->setMinimumSize(QSize(72, 0));
        comboBox_baud->setMaximumSize(QSize(72, 16777215));

        horizontalLayout_2->addWidget(comboBox_baud);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        comboBox_dataWidth = new QComboBox(groupBox);
        comboBox_dataWidth->setObjectName(QStringLiteral("comboBox_dataWidth"));
        comboBox_dataWidth->setMinimumSize(QSize(72, 0));
        comboBox_dataWidth->setMaximumSize(QSize(72, 16777215));
        comboBox_dataWidth->setLayoutDirection(Qt::LeftToRight);
        comboBox_dataWidth->setInsertPolicy(QComboBox::InsertAtBottom);

        horizontalLayout_3->addWidget(comboBox_dataWidth);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        comboBox_parityWidth = new QComboBox(groupBox);
        comboBox_parityWidth->setObjectName(QStringLiteral("comboBox_parityWidth"));
        comboBox_parityWidth->setMinimumSize(QSize(72, 0));
        comboBox_parityWidth->setMaximumSize(QSize(72, 16777215));

        horizontalLayout_4->addWidget(comboBox_parityWidth);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        comboBox_stopWidth = new QComboBox(groupBox);
        comboBox_stopWidth->setObjectName(QStringLiteral("comboBox_stopWidth"));
        comboBox_stopWidth->setMinimumSize(QSize(72, 0));
        comboBox_stopWidth->setMaximumSize(QSize(72, 16777215));

        horizontalLayout_5->addWidget(comboBox_stopWidth);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(36, 20));

        horizontalLayout_6->addWidget(label_6);

        comboBox_flowControl = new QComboBox(groupBox);
        comboBox_flowControl->setObjectName(QStringLiteral("comboBox_flowControl"));
        comboBox_flowControl->setMinimumSize(QSize(72, 0));
        comboBox_flowControl->setMaximumSize(QSize(72, 16777215));

        horizontalLayout_6->addWidget(comboBox_flowControl);


        verticalLayout->addLayout(horizontalLayout_6);

        recieveTextEdit = new QTextBrowser(centralWidget);
        recieveTextEdit->setObjectName(QStringLiteral("recieveTextEdit"));
        recieveTextEdit->setGeometry(QRect(160, 10, 381, 291));
        recieveTextEdit->setStyleSheet(QStringLiteral(""));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(550, 10, 181, 130));
        groupBox_2->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        radioButton_S_A = new QRadioButton(groupBox_2);
        radioButton_S_A->setObjectName(QStringLiteral("radioButton_S_A"));
        radioButton_S_A->setChecked(true);

        horizontalLayout_12->addWidget(radioButton_S_A);

        radioButton_S_H = new QRadioButton(groupBox_2);
        radioButton_S_H->setObjectName(QStringLiteral("radioButton_S_H"));

        horizontalLayout_12->addWidget(radioButton_S_H);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        checkBox_S_T = new QCheckBox(groupBox_2);
        checkBox_S_T->setObjectName(QStringLiteral("checkBox_S_T"));

        horizontalLayout_20->addWidget(checkBox_S_T);

        checkBox_S = new QCheckBox(groupBox_2);
        checkBox_S->setObjectName(QStringLiteral("checkBox_S"));
        checkBox_S->setEnabled(true);
        checkBox_S->setCheckable(true);
        checkBox_S->setChecked(true);

        horizontalLayout_20->addWidget(checkBox_S);


        verticalLayout_2->addLayout(horizontalLayout_20);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        checkBox_S_Count = new QCheckBox(groupBox_2);
        checkBox_S_Count->setObjectName(QStringLiteral("checkBox_S_Count"));
        checkBox_S_Count->setCheckable(true);
        checkBox_S_Count->setChecked(true);

        horizontalLayout_7->addWidget(checkBox_S_Count);

        label_sendCount = new QLabel(groupBox_2);
        label_sendCount->setObjectName(QStringLiteral("label_sendCount"));
        sizePolicy.setHeightForWidth(label_sendCount->sizePolicy().hasHeightForWidth());
        label_sendCount->setSizePolicy(sizePolicy);
        label_sendCount->setMinimumSize(QSize(61, 16));
        label_sendCount->setMaximumSize(QSize(61, 16));
        label_sendCount->setFrameShape(QFrame::StyledPanel);
        label_sendCount->setFrameShadow(QFrame::Plain);

        horizontalLayout_7->addWidget(label_sendCount);


        horizontalLayout_16->addLayout(horizontalLayout_7);

        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_16);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        checkBox_reply = new QCheckBox(groupBox_2);
        checkBox_reply->setObjectName(QStringLiteral("checkBox_reply"));
        checkBox_reply->setEnabled(false);
        checkBox_reply->setCheckable(true);
        checkBox_reply->setChecked(false);

        horizontalLayout_14->addWidget(checkBox_reply);

        spinBox_Reply = new QSpinBox(groupBox_2);
        spinBox_Reply->setObjectName(QStringLiteral("spinBox_Reply"));
        sizePolicy.setHeightForWidth(spinBox_Reply->sizePolicy().hasHeightForWidth());
        spinBox_Reply->setSizePolicy(sizePolicy);
        spinBox_Reply->setMinimumSize(QSize(50, 18));
        spinBox_Reply->setMaximumSize(QSize(0, 18));
        spinBox_Reply->setMaximum(10000);
        spinBox_Reply->setValue(1000);

        horizontalLayout_14->addWidget(spinBox_Reply);


        horizontalLayout_15->addLayout(horizontalLayout_14);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(12, 0));
        label_7->setMaximumSize(QSize(10, 16777215));

        horizontalLayout_15->addWidget(label_7);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_15);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(550, 180, 181, 132));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        radioButton_R_A = new QRadioButton(groupBox_3);
        radioButton_R_A->setObjectName(QStringLiteral("radioButton_R_A"));
        radioButton_R_A->setChecked(true);

        horizontalLayout_8->addWidget(radioButton_R_A);

        radioButton_R_H = new QRadioButton(groupBox_3);
        radioButton_R_H->setObjectName(QStringLiteral("radioButton_R_H"));

        horizontalLayout_8->addWidget(radioButton_R_H);


        verticalLayout_3->addLayout(horizontalLayout_8);

        checkBox_R_T = new QCheckBox(groupBox_3);
        checkBox_R_T->setObjectName(QStringLiteral("checkBox_R_T"));

        verticalLayout_3->addWidget(checkBox_R_T);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        checkBox_R_Count = new QCheckBox(groupBox_3);
        checkBox_R_Count->setObjectName(QStringLiteral("checkBox_R_Count"));
        checkBox_R_Count->setChecked(true);

        horizontalLayout_9->addWidget(checkBox_R_Count);

        label_recieveCount = new QLabel(groupBox_3);
        label_recieveCount->setObjectName(QStringLiteral("label_recieveCount"));
        sizePolicy.setHeightForWidth(label_recieveCount->sizePolicy().hasHeightForWidth());
        label_recieveCount->setSizePolicy(sizePolicy);
        label_recieveCount->setMinimumSize(QSize(61, 16));
        label_recieveCount->setMaximumSize(QSize(61, 16));
        label_recieveCount->setFrameShape(QFrame::StyledPanel);
        label_recieveCount->setFrameShadow(QFrame::Plain);

        horizontalLayout_9->addWidget(label_recieveCount);


        horizontalLayout_19->addLayout(horizontalLayout_9);

        horizontalSpacer_4 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_19);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        checkBox_recieveDelay = new QCheckBox(groupBox_3);
        checkBox_recieveDelay->setObjectName(QStringLiteral("checkBox_recieveDelay"));
        checkBox_recieveDelay->setChecked(false);

        horizontalLayout_17->addWidget(checkBox_recieveDelay);

        spinBox_recieveDelay = new QSpinBox(groupBox_3);
        spinBox_recieveDelay->setObjectName(QStringLiteral("spinBox_recieveDelay"));
        sizePolicy.setHeightForWidth(spinBox_recieveDelay->sizePolicy().hasHeightForWidth());
        spinBox_recieveDelay->setSizePolicy(sizePolicy);
        spinBox_recieveDelay->setMinimumSize(QSize(50, 18));
        spinBox_recieveDelay->setMaximumSize(QSize(0, 18));
        spinBox_recieveDelay->setMaximum(200);
        spinBox_recieveDelay->setValue(100);

        horizontalLayout_17->addWidget(spinBox_recieveDelay);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_17->addWidget(label_8);

        horizontalSpacer_3 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_17);

        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 0, 2, 2));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 0, 2, 2));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(160, 310, 381, 31));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        sendTextEdit = new QLineEdit(layoutWidget2);
        sendTextEdit->setObjectName(QStringLiteral("sendTextEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sendTextEdit->sizePolicy().hasHeightForWidth());
        sendTextEdit->setSizePolicy(sizePolicy1);
        sendTextEdit->setStyleSheet(QStringLiteral(""));

        horizontalLayout_10->addWidget(sendTextEdit);

        Button_SendDate = new QPushButton(layoutWidget2);
        Button_SendDate->setObjectName(QStringLiteral("Button_SendDate"));
        Button_SendDate->setEnabled(false);
        Button_SendDate->setMaximumSize(QSize(16777215, 29));
        Button_SendDate->setCheckable(false);

        horizontalLayout_10->addWidget(Button_SendDate);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 200, 141, 141));
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        Button_openSerialPort = new QToolButton(groupBox_4);
        Button_openSerialPort->setObjectName(QStringLiteral("Button_openSerialPort"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Button_openSerialPort->sizePolicy().hasHeightForWidth());
        Button_openSerialPort->setSizePolicy(sizePolicy2);
        Button_openSerialPort->setMinimumSize(QSize(0, 23));
        Button_openSerialPort->setCheckable(true);
        Button_openSerialPort->setAutoRaise(false);

        verticalLayout_4->addWidget(Button_openSerialPort);

        Button_refresh = new QPushButton(groupBox_4);
        Button_refresh->setObjectName(QStringLiteral("Button_refresh"));

        verticalLayout_4->addWidget(Button_refresh);

        Button_clear = new QPushButton(groupBox_4);
        Button_clear->setObjectName(QStringLiteral("Button_clear"));

        verticalLayout_4->addWidget(Button_clear);

        Button_exit = new QPushButton(groupBox_4);
        Button_exit->setObjectName(QStringLiteral("Button_exit"));
        Button_exit->setCheckable(false);

        verticalLayout_4->addWidget(Button_exit);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 0, 2, 2));
        horizontalLayout_18 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(550, 310, 181, 31));
        widget = new QWidget(groupBox_5);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 10, 134, 18));
        horizontalLayout_22 = new QHBoxLayout(widget);
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(26, 0));
        label_9->setMaximumSize(QSize(26, 16777215));

        horizontalLayout_22->addWidget(label_9);

        lcdNumber_receive = new QLCDNumber(widget);
        lcdNumber_receive->setObjectName(QStringLiteral("lcdNumber_receive"));
        sizePolicy.setHeightForWidth(lcdNumber_receive->sizePolicy().hasHeightForWidth());
        lcdNumber_receive->setSizePolicy(sizePolicy);
        lcdNumber_receive->setMinimumSize(QSize(64, 16));
        lcdNumber_receive->setMaximumSize(QSize(64, 16));
        lcdNumber_receive->setFrameShape(QFrame::Box);
        lcdNumber_receive->setFrameShadow(QFrame::Plain);
        lcdNumber_receive->setLineWidth(1);
        lcdNumber_receive->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_22->addWidget(lcdNumber_receive);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_22->addWidget(label_10);

        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(550, 140, 181, 31));
        widget1 = new QWidget(groupBox_6);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(30, 11, 132, 18));
        horizontalLayout_21 = new QHBoxLayout(widget1);
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        horizontalLayout_21->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(widget1);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_21->addWidget(label_11);

        lcdNumber_send = new QLCDNumber(widget1);
        lcdNumber_send->setObjectName(QStringLiteral("lcdNumber_send"));
        sizePolicy.setHeightForWidth(lcdNumber_send->sizePolicy().hasHeightForWidth());
        lcdNumber_send->setSizePolicy(sizePolicy);
        lcdNumber_send->setMinimumSize(QSize(64, 16));
        lcdNumber_send->setMaximumSize(QSize(64, 16));
        lcdNumber_send->setStyleSheet(QStringLiteral(""));
        lcdNumber_send->setFrameShadow(QFrame::Plain);
        lcdNumber_send->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_21->addWidget(lcdNumber_send);

        label_12 = new QLabel(widget1);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_21->addWidget(label_12);

        m_lableName = new QLabel(centralWidget);
        m_lableName->setObjectName(QStringLiteral("m_lableName"));
        m_lableName->setGeometry(QRect(50, 360, 54, 12));
        SeriaHelpClass->setCentralWidget(centralWidget);
        layoutWidget->raise();
        groupBox->raise();
        recieveTextEdit->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        groupBox_4->raise();
        groupBox_5->raise();
        groupBox_6->raise();
        m_lableName->raise();
        menuBar = new QMenuBar(SeriaHelpClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 740, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        SeriaHelpClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(SeriaHelpClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SeriaHelpClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionOpen);
        menu->addAction(actionSave);

        retranslateUi(SeriaHelpClass);
        QObject::connect(Button_exit, SIGNAL(clicked()), SeriaHelpClass, SLOT(close()));

        QMetaObject::connectSlotsByName(SeriaHelpClass);
    } // setupUi

    void retranslateUi(QMainWindow *SeriaHelpClass)
    {
        SeriaHelpClass->setWindowTitle(QApplication::translate("SeriaHelpClass", "SeriaHelp", 0));
        actionOpen->setText(QApplication::translate("SeriaHelpClass", "\346\211\223\345\274\200", 0));
        actionSave->setText(QApplication::translate("SeriaHelpClass", "\344\277\235\345\255\230", 0));
        groupBox->setTitle(QString());
#ifndef QT_NO_WHATSTHIS
        label->setWhatsThis(QApplication::translate("SeriaHelpClass", "set", 0));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("SeriaHelpClass", "\347\253\257\345\217\243\345\217\267", 0));
#ifndef QT_NO_WHATSTHIS
        label_2->setWhatsThis(QApplication::translate("SeriaHelpClass", "set", 0));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("SeriaHelpClass", "\346\263\242\347\211\271\347\216\207", 0));
        comboBox_baud->clear();
        comboBox_baud->insertItems(0, QStringList()
         << QApplication::translate("SeriaHelpClass", "115200", 0)
         << QApplication::translate("SeriaHelpClass", "57600", 0)
         << QApplication::translate("SeriaHelpClass", "38400", 0)
         << QApplication::translate("SeriaHelpClass", "19200", 0)
         << QApplication::translate("SeriaHelpClass", "9600", 0)
         << QApplication::translate("SeriaHelpClass", "4800", 0)
         << QApplication::translate("SeriaHelpClass", "2400", 0)
         << QApplication::translate("SeriaHelpClass", "1200", 0)
        );
#ifndef QT_NO_WHATSTHIS
        label_3->setWhatsThis(QApplication::translate("SeriaHelpClass", "set", 0));
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("SeriaHelpClass", "\346\225\260\346\215\256\344\275\215", 0));
        comboBox_dataWidth->clear();
        comboBox_dataWidth->insertItems(0, QStringList()
         << QApplication::translate("SeriaHelpClass", "8", 0)
         << QApplication::translate("SeriaHelpClass", "7", 0)
         << QApplication::translate("SeriaHelpClass", "6", 0)
         << QApplication::translate("SeriaHelpClass", "5", 0)
        );
#ifndef QT_NO_WHATSTHIS
        label_4->setWhatsThis(QApplication::translate("SeriaHelpClass", "set", 0));
#endif // QT_NO_WHATSTHIS
        label_4->setText(QApplication::translate("SeriaHelpClass", "\346\240\241\351\252\214\344\275\215", 0));
        comboBox_parityWidth->clear();
        comboBox_parityWidth->insertItems(0, QStringList()
         << QApplication::translate("SeriaHelpClass", "\346\227\240", 0)
         << QApplication::translate("SeriaHelpClass", "\345\245\207\346\240\241\351\252\214", 0)
         << QApplication::translate("SeriaHelpClass", "\345\201\266\346\240\241\351\252\214", 0)
        );
#ifndef QT_NO_WHATSTHIS
        label_5->setWhatsThis(QApplication::translate("SeriaHelpClass", "set", 0));
#endif // QT_NO_WHATSTHIS
        label_5->setText(QApplication::translate("SeriaHelpClass", "\345\201\234\346\255\242\344\275\215", 0));
        comboBox_stopWidth->clear();
        comboBox_stopWidth->insertItems(0, QStringList()
         << QApplication::translate("SeriaHelpClass", "1", 0)
         << QApplication::translate("SeriaHelpClass", "1.5", 0)
         << QApplication::translate("SeriaHelpClass", "2", 0)
        );
#ifndef QT_NO_WHATSTHIS
        label_6->setWhatsThis(QApplication::translate("SeriaHelpClass", "set", 0));
#endif // QT_NO_WHATSTHIS
        label_6->setText(QApplication::translate("SeriaHelpClass", "\346\265\201\346\216\247\345\210\266", 0));
        comboBox_flowControl->clear();
        comboBox_flowControl->insertItems(0, QStringList()
         << QApplication::translate("SeriaHelpClass", "OFF", 0)
         << QApplication::translate("SeriaHelpClass", "RTS/CTS", 0)
         << QApplication::translate("SeriaHelpClass", "XON/XOFF", 0)
        );
        groupBox_2->setTitle(QApplication::translate("SeriaHelpClass", "\345\217\221\351\200\201\350\256\276\347\275\256", 0));
        radioButton_S_A->setText(QApplication::translate("SeriaHelpClass", "ACSII", 0));
        radioButton_S_H->setText(QApplication::translate("SeriaHelpClass", "Hex", 0));
        checkBox_S_T->setText(QApplication::translate("SeriaHelpClass", "\346\230\276\347\244\272\346\227\266\351\227\264", 0));
        checkBox_S->setText(QApplication::translate("SeriaHelpClass", "\346\230\276\347\244\272\345\217\221\351\200\201", 0));
        checkBox_S_Count->setText(QApplication::translate("SeriaHelpClass", "\345\217\221\351\200\201\346\254\241\346\225\260", 0));
#ifndef QT_NO_WHATSTHIS
        label_sendCount->setWhatsThis(QApplication::translate("SeriaHelpClass", "count", 0));
#endif // QT_NO_WHATSTHIS
        label_sendCount->setText(QApplication::translate("SeriaHelpClass", "0", 0));
        checkBox_reply->setText(QApplication::translate("SeriaHelpClass", "\350\207\252\345\212\250\345\217\221\351\200\201", 0));
        spinBox_Reply->setSuffix(QString());
        spinBox_Reply->setPrefix(QString());
#ifndef QT_NO_WHATSTHIS
        label_7->setWhatsThis(QApplication::translate("SeriaHelpClass", "ms", 0));
#endif // QT_NO_WHATSTHIS
        label_7->setText(QApplication::translate("SeriaHelpClass", "ms", 0));
        groupBox_3->setTitle(QApplication::translate("SeriaHelpClass", "\346\216\245\346\224\266\350\256\276\347\275\256", 0));
        radioButton_R_A->setText(QApplication::translate("SeriaHelpClass", "ACSII", 0));
        radioButton_R_H->setText(QApplication::translate("SeriaHelpClass", "Hex", 0));
        checkBox_R_T->setText(QApplication::translate("SeriaHelpClass", "\346\230\276\347\244\272\346\227\266\351\227\264", 0));
        checkBox_R_Count->setText(QApplication::translate("SeriaHelpClass", "\346\216\245\346\224\266\346\254\241\346\225\260", 0));
#ifndef QT_NO_WHATSTHIS
        label_recieveCount->setWhatsThis(QApplication::translate("SeriaHelpClass", "count", 0));
#endif // QT_NO_WHATSTHIS
        label_recieveCount->setText(QApplication::translate("SeriaHelpClass", "0", 0));
        checkBox_recieveDelay->setText(QApplication::translate("SeriaHelpClass", "\346\216\245\346\224\266\345\273\266\350\277\237", 0));
        spinBox_recieveDelay->setSuffix(QString());
        spinBox_recieveDelay->setPrefix(QString());
#ifndef QT_NO_WHATSTHIS
        label_8->setWhatsThis(QApplication::translate("SeriaHelpClass", "ms", 0));
#endif // QT_NO_WHATSTHIS
        label_8->setText(QApplication::translate("SeriaHelpClass", "ms", 0));
        sendTextEdit->setPlaceholderText(QApplication::translate("SeriaHelpClass", "ASCII\345\255\227\347\254\246", 0));
        Button_SendDate->setText(QApplication::translate("SeriaHelpClass", "\345\217\221\351\200\201\346\225\260\346\215\256", 0));
        groupBox_4->setTitle(QString());
        Button_openSerialPort->setText(QApplication::translate("SeriaHelpClass", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
        Button_refresh->setText(QApplication::translate("SeriaHelpClass", "\345\210\267\346\226\260\344\270\262\345\217\243", 0));
        Button_clear->setText(QApplication::translate("SeriaHelpClass", "\346\270\205\351\231\244\346\225\260\346\215\256", 0));
        Button_exit->setText(QApplication::translate("SeriaHelpClass", "\351\200\200\345\207\272\347\250\213\345\272\217", 0));
        groupBox_5->setTitle(QString());
#ifndef QT_NO_WHATSTHIS
        label_9->setWhatsThis(QApplication::translate("SeriaHelpClass", "count1", 0));
#endif // QT_NO_WHATSTHIS
        label_9->setText(QApplication::translate("SeriaHelpClass", "Rx\357\274\232 ", 0));
#ifndef QT_NO_WHATSTHIS
        label_10->setWhatsThis(QApplication::translate("SeriaHelpClass", "count1", 0));
#endif // QT_NO_WHATSTHIS
        label_10->setText(QApplication::translate("SeriaHelpClass", "Bytes", 0));
        groupBox_6->setTitle(QString());
#ifndef QT_NO_WHATSTHIS
        label_11->setWhatsThis(QApplication::translate("SeriaHelpClass", "count1", 0));
#endif // QT_NO_WHATSTHIS
        label_11->setText(QApplication::translate("SeriaHelpClass", "Tx\357\274\232", 0));
#ifndef QT_NO_WHATSTHIS
        label_12->setWhatsThis(QApplication::translate("SeriaHelpClass", "count1", 0));
#endif // QT_NO_WHATSTHIS
        label_12->setText(QApplication::translate("SeriaHelpClass", "Bytes", 0));
        m_lableName->setText(QString());
        menu->setTitle(QApplication::translate("SeriaHelpClass", "\346\226\207\344\273\266", 0));
    } // retranslateUi

};

namespace Ui {
    class SeriaHelpClass: public Ui_SeriaHelpClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIAHELP_H
