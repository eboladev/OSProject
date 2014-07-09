/********************************************************************************
** Form generated from reading UI file 'roomstatesearchdialog.ui'
**
** Created: Sat May 17 16:16:39 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMSTATESEARCHDIALOG_H
#define UI_ROOMSTATESEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoomStateSearchDialog
{
public:
    QGroupBox *simplesearch_groupbox;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *or_radiobutton;
    QRadioButton *and_radiobutton;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QCheckBox *temperatureup_checkbox;
    QCheckBox *humidityup_checkbox;
    QCheckBox *oxygenup_checkbox;
    QCheckBox *carbodioxideup_checkbox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QCheckBox *temperaturedown_checkbox;
    QCheckBox *humiditydown_checkbox;
    QCheckBox *oxygendown_checkbox;
    QCheckBox *carbodioxidedown_checkbox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *smoke_checkbox;
    QCheckBox *comindex_checkbox;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *pm25_checkbox;
    QCheckBox *mat_checkbox;
    QGroupBox *advancedsearch_groupbox;
    QFrame *frame;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *smoke_toolbutton;
    QToolButton *comindex_toolbutton;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *pm25_toolbutton;
    QToolButton *mat_toolbutton;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_14;
    QVBoxLayout *verticalLayout_9;
    QToolButton *leftbracket_toolbutton;
    QToolButton *rightbracket_toolbutton;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_8;
    QToolButton *or_toolbutton;
    QToolButton *and_toolbutton;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_15;
    QVBoxLayout *verticalLayout_10;
    QToolButton *clear_toolbutton;
    QToolButton *backdel_toolbutton;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QToolButton *temperatureup_toolbutton;
    QToolButton *humidityup_toolbutton;
    QToolButton *oxygenup_toolbutton;
    QToolButton *carbodioxideup_toolbutton;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_5;
    QToolButton *temperaturedown_toolbutton;
    QToolButton *humiditydown_toolbutton;
    QToolButton *oxygendown_toolbutton;
    QToolButton *carbodioxidedown_toolbutton;
    QTextEdit *exp_textedit;
    QLabel *label_3;
    QToolButton *demonstration_toolbutton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_5;
    QPushButton *search_pushbutton;
    QPushButton *simpleandadvanced_pushbutton;
    QToolButton *waterlevel_toolbutton;
    QCheckBox *water_checkbox;
    QCheckBox *mainvoltageup_checkbox;
    QCheckBox *mainvoltagedown_checkbox;
    QCheckBox *zerovoltageup_checkbox;
    QCheckBox *zerovoltagedown_checkbox;
    QToolButton *mainvoltageup_toolbutton;
    QToolButton *mainvoltagedown_toolbutton;
    QToolButton *zerovoltageup_toolbutton;
    QToolButton *zerovoltagedown_toolbutton;

    void setupUi(QDialog *RoomStateSearchDialog)
    {
        if (RoomStateSearchDialog->objectName().isEmpty())
            RoomStateSearchDialog->setObjectName(QString::fromUtf8("RoomStateSearchDialog"));
        RoomStateSearchDialog->resize(520, 375);
        RoomStateSearchDialog->setSizeGripEnabled(false);
        simplesearch_groupbox = new QGroupBox(RoomStateSearchDialog);
        simplesearch_groupbox->setObjectName(QString::fromUtf8("simplesearch_groupbox"));
        simplesearch_groupbox->setGeometry(QRect(10, 10, 501, 111));
        simplesearch_groupbox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        simplesearch_groupbox->setFlat(false);
        simplesearch_groupbox->setCheckable(true);
        horizontalLayout_7 = new QHBoxLayout(simplesearch_groupbox);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        groupBox_3 = new QGroupBox(simplesearch_groupbox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setAlignment(Qt::AlignCenter);
        horizontalLayout_6 = new QHBoxLayout(groupBox_3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        or_radiobutton = new QRadioButton(groupBox_3);
        or_radiobutton->setObjectName(QString::fromUtf8("or_radiobutton"));

        verticalLayout_3->addWidget(or_radiobutton);

        and_radiobutton = new QRadioButton(groupBox_3);
        and_radiobutton->setObjectName(QString::fromUtf8("and_radiobutton"));

        verticalLayout_3->addWidget(and_radiobutton);


        horizontalLayout_6->addLayout(verticalLayout_3);


        horizontalLayout_7->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(simplesearch_groupbox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setAlignment(Qt::AlignCenter);
        groupBox_2->setCheckable(false);
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(140, 20, 261, 51));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        temperatureup_checkbox = new QCheckBox(layoutWidget);
        temperatureup_checkbox->setObjectName(QString::fromUtf8("temperatureup_checkbox"));

        horizontalLayout->addWidget(temperatureup_checkbox);

        humidityup_checkbox = new QCheckBox(layoutWidget);
        humidityup_checkbox->setObjectName(QString::fromUtf8("humidityup_checkbox"));

        horizontalLayout->addWidget(humidityup_checkbox);

        oxygenup_checkbox = new QCheckBox(layoutWidget);
        oxygenup_checkbox->setObjectName(QString::fromUtf8("oxygenup_checkbox"));

        horizontalLayout->addWidget(oxygenup_checkbox);

        carbodioxideup_checkbox = new QCheckBox(layoutWidget);
        carbodioxideup_checkbox->setObjectName(QString::fromUtf8("carbodioxideup_checkbox"));

        horizontalLayout->addWidget(carbodioxideup_checkbox);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        temperaturedown_checkbox = new QCheckBox(layoutWidget);
        temperaturedown_checkbox->setObjectName(QString::fromUtf8("temperaturedown_checkbox"));

        horizontalLayout_2->addWidget(temperaturedown_checkbox);

        humiditydown_checkbox = new QCheckBox(layoutWidget);
        humiditydown_checkbox->setObjectName(QString::fromUtf8("humiditydown_checkbox"));

        horizontalLayout_2->addWidget(humiditydown_checkbox);

        oxygendown_checkbox = new QCheckBox(layoutWidget);
        oxygendown_checkbox->setObjectName(QString::fromUtf8("oxygendown_checkbox"));

        horizontalLayout_2->addWidget(oxygendown_checkbox);

        carbodioxidedown_checkbox = new QCheckBox(layoutWidget);
        carbodioxidedown_checkbox->setObjectName(QString::fromUtf8("carbodioxidedown_checkbox"));

        horizontalLayout_2->addWidget(carbodioxidedown_checkbox);


        verticalLayout_2->addLayout(horizontalLayout_2);

        widget = new QWidget(groupBox_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 22, 128, 44));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        smoke_checkbox = new QCheckBox(widget);
        smoke_checkbox->setObjectName(QString::fromUtf8("smoke_checkbox"));

        horizontalLayout_3->addWidget(smoke_checkbox);

        comindex_checkbox = new QCheckBox(widget);
        comindex_checkbox->setObjectName(QString::fromUtf8("comindex_checkbox"));

        horizontalLayout_3->addWidget(comindex_checkbox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pm25_checkbox = new QCheckBox(widget);
        pm25_checkbox->setObjectName(QString::fromUtf8("pm25_checkbox"));

        horizontalLayout_8->addWidget(pm25_checkbox);

        mat_checkbox = new QCheckBox(widget);
        mat_checkbox->setObjectName(QString::fromUtf8("mat_checkbox"));

        horizontalLayout_8->addWidget(mat_checkbox);


        verticalLayout->addLayout(horizontalLayout_8);

        layoutWidget->raise();
        layoutWidget->raise();
        pm25_checkbox->raise();

        horizontalLayout_7->addWidget(groupBox_2);

        advancedsearch_groupbox = new QGroupBox(RoomStateSearchDialog);
        advancedsearch_groupbox->setObjectName(QString::fromUtf8("advancedsearch_groupbox"));
        advancedsearch_groupbox->setGeometry(QRect(10, 140, 501, 191));
        advancedsearch_groupbox->setCheckable(true);
        advancedsearch_groupbox->setChecked(false);
        frame = new QFrame(advancedsearch_groupbox);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 30, 481, 71));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(1);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 10, 111, 51));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Sunken);
        frame_2->setLineWidth(1);
        verticalLayout_11 = new QVBoxLayout(frame_2);
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        smoke_toolbutton = new QToolButton(frame_2);
        smoke_toolbutton->setObjectName(QString::fromUtf8("smoke_toolbutton"));
        smoke_toolbutton->setPopupMode(QToolButton::InstantPopup);
        smoke_toolbutton->setAutoRaise(true);

        horizontalLayout_4->addWidget(smoke_toolbutton);

        comindex_toolbutton = new QToolButton(frame_2);
        comindex_toolbutton->setObjectName(QString::fromUtf8("comindex_toolbutton"));
        comindex_toolbutton->setAutoRaise(true);

        horizontalLayout_4->addWidget(comindex_toolbutton);


        verticalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pm25_toolbutton = new QToolButton(frame_2);
        pm25_toolbutton->setObjectName(QString::fromUtf8("pm25_toolbutton"));
        pm25_toolbutton->setAutoRaise(true);

        horizontalLayout_5->addWidget(pm25_toolbutton);

        mat_toolbutton = new QToolButton(frame_2);
        mat_toolbutton->setObjectName(QString::fromUtf8("mat_toolbutton"));
        mat_toolbutton->setAutoRaise(true);

        horizontalLayout_5->addWidget(mat_toolbutton);


        verticalLayout_7->addLayout(horizontalLayout_5);


        verticalLayout_11->addLayout(verticalLayout_7);

        frame_5 = new QFrame(frame);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(359, 10, 28, 51));
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Sunken);
        frame_5->setLineWidth(1);
        verticalLayout_14 = new QVBoxLayout(frame_5);
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        leftbracket_toolbutton = new QToolButton(frame_5);
        leftbracket_toolbutton->setObjectName(QString::fromUtf8("leftbracket_toolbutton"));
        leftbracket_toolbutton->setPopupMode(QToolButton::InstantPopup);
        leftbracket_toolbutton->setAutoRaise(true);

        verticalLayout_9->addWidget(leftbracket_toolbutton);

        rightbracket_toolbutton = new QToolButton(frame_5);
        rightbracket_toolbutton->setObjectName(QString::fromUtf8("rightbracket_toolbutton"));
        rightbracket_toolbutton->setPopupMode(QToolButton::InstantPopup);
        rightbracket_toolbutton->setAutoRaise(true);

        verticalLayout_9->addWidget(rightbracket_toolbutton);


        verticalLayout_14->addLayout(verticalLayout_9);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(391, 10, 40, 50));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Sunken);
        frame_4->setLineWidth(1);
        verticalLayout_12 = new QVBoxLayout(frame_4);
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        or_toolbutton = new QToolButton(frame_4);
        or_toolbutton->setObjectName(QString::fromUtf8("or_toolbutton"));
        or_toolbutton->setPopupMode(QToolButton::InstantPopup);
        or_toolbutton->setAutoRaise(true);

        verticalLayout_8->addWidget(or_toolbutton);

        and_toolbutton = new QToolButton(frame_4);
        and_toolbutton->setObjectName(QString::fromUtf8("and_toolbutton"));
        and_toolbutton->setPopupMode(QToolButton::InstantPopup);
        and_toolbutton->setAutoRaise(true);

        verticalLayout_8->addWidget(and_toolbutton);


        verticalLayout_12->addLayout(verticalLayout_8);

        frame_6 = new QFrame(frame);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(434, 10, 40, 51));
        frame_6->setFrameShape(QFrame::Box);
        frame_6->setFrameShadow(QFrame::Sunken);
        frame_6->setLineWidth(1);
        verticalLayout_15 = new QVBoxLayout(frame_6);
        verticalLayout_15->setSpacing(0);
        verticalLayout_15->setContentsMargins(0, 0, 0, 0);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        clear_toolbutton = new QToolButton(frame_6);
        clear_toolbutton->setObjectName(QString::fromUtf8("clear_toolbutton"));
        clear_toolbutton->setPopupMode(QToolButton::InstantPopup);
        clear_toolbutton->setAutoRaise(true);

        verticalLayout_10->addWidget(clear_toolbutton);

        backdel_toolbutton = new QToolButton(frame_6);
        backdel_toolbutton->setObjectName(QString::fromUtf8("backdel_toolbutton"));
        backdel_toolbutton->setPopupMode(QToolButton::InstantPopup);
        backdel_toolbutton->setAutoRaise(true);

        verticalLayout_10->addWidget(backdel_toolbutton);


        verticalLayout_15->addLayout(verticalLayout_10);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(124, 10, 231, 51));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Sunken);
        frame_3->setLineWidth(1);
        verticalLayout_6 = new QVBoxLayout(frame_3);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_9->addWidget(label_4);

        temperatureup_toolbutton = new QToolButton(frame_3);
        temperatureup_toolbutton->setObjectName(QString::fromUtf8("temperatureup_toolbutton"));
        temperatureup_toolbutton->setPopupMode(QToolButton::InstantPopup);
        temperatureup_toolbutton->setAutoRaise(true);

        horizontalLayout_9->addWidget(temperatureup_toolbutton);

        humidityup_toolbutton = new QToolButton(frame_3);
        humidityup_toolbutton->setObjectName(QString::fromUtf8("humidityup_toolbutton"));
        humidityup_toolbutton->setPopupMode(QToolButton::InstantPopup);
        humidityup_toolbutton->setAutoRaise(true);

        horizontalLayout_9->addWidget(humidityup_toolbutton);

        oxygenup_toolbutton = new QToolButton(frame_3);
        oxygenup_toolbutton->setObjectName(QString::fromUtf8("oxygenup_toolbutton"));
        oxygenup_toolbutton->setPopupMode(QToolButton::InstantPopup);
        oxygenup_toolbutton->setAutoRaise(true);

        horizontalLayout_9->addWidget(oxygenup_toolbutton);

        carbodioxideup_toolbutton = new QToolButton(frame_3);
        carbodioxideup_toolbutton->setObjectName(QString::fromUtf8("carbodioxideup_toolbutton"));
        carbodioxideup_toolbutton->setPopupMode(QToolButton::InstantPopup);
        carbodioxideup_toolbutton->setAutoRaise(true);

        horizontalLayout_9->addWidget(carbodioxideup_toolbutton);


        verticalLayout_6->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_10->addWidget(label_5);

        temperaturedown_toolbutton = new QToolButton(frame_3);
        temperaturedown_toolbutton->setObjectName(QString::fromUtf8("temperaturedown_toolbutton"));
        temperaturedown_toolbutton->setPopupMode(QToolButton::InstantPopup);
        temperaturedown_toolbutton->setAutoRaise(true);

        horizontalLayout_10->addWidget(temperaturedown_toolbutton);

        humiditydown_toolbutton = new QToolButton(frame_3);
        humiditydown_toolbutton->setObjectName(QString::fromUtf8("humiditydown_toolbutton"));
        humiditydown_toolbutton->setPopupMode(QToolButton::InstantPopup);
        humiditydown_toolbutton->setAutoRaise(true);

        horizontalLayout_10->addWidget(humiditydown_toolbutton);

        oxygendown_toolbutton = new QToolButton(frame_3);
        oxygendown_toolbutton->setObjectName(QString::fromUtf8("oxygendown_toolbutton"));
        oxygendown_toolbutton->setPopupMode(QToolButton::InstantPopup);
        oxygendown_toolbutton->setAutoRaise(true);

        horizontalLayout_10->addWidget(oxygendown_toolbutton);

        carbodioxidedown_toolbutton = new QToolButton(frame_3);
        carbodioxidedown_toolbutton->setObjectName(QString::fromUtf8("carbodioxidedown_toolbutton"));
        carbodioxidedown_toolbutton->setPopupMode(QToolButton::InstantPopup);
        carbodioxidedown_toolbutton->setAutoRaise(true);

        horizontalLayout_10->addWidget(carbodioxidedown_toolbutton);


        verticalLayout_6->addLayout(horizontalLayout_10);

        frame_5->raise();
        frame_4->raise();
        frame_6->raise();
        frame_2->raise();
        frame_3->raise();
        exp_textedit = new QTextEdit(advancedsearch_groupbox);
        exp_textedit->setObjectName(QString::fromUtf8("exp_textedit"));
        exp_textedit->setGeometry(QRect(10, 130, 481, 45));
        exp_textedit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        exp_textedit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        exp_textedit->setReadOnly(true);
        exp_textedit->setAcceptRichText(false);
        label_3 = new QLabel(advancedsearch_groupbox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 107, 111, 16));
        demonstration_toolbutton = new QToolButton(advancedsearch_groupbox);
        demonstration_toolbutton->setObjectName(QString::fromUtf8("demonstration_toolbutton"));
        demonstration_toolbutton->setGeometry(QRect(450, 107, 37, 18));
        layoutWidget1 = new QWidget(RoomStateSearchDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        layoutWidget2 = new QWidget(RoomStateSearchDialog);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_5 = new QVBoxLayout(layoutWidget2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        search_pushbutton = new QPushButton(RoomStateSearchDialog);
        search_pushbutton->setObjectName(QString::fromUtf8("search_pushbutton"));
        search_pushbutton->setGeometry(QRect(445, 340, 55, 25));
        simpleandadvanced_pushbutton = new QPushButton(RoomStateSearchDialog);
        simpleandadvanced_pushbutton->setObjectName(QString::fromUtf8("simpleandadvanced_pushbutton"));
        simpleandadvanced_pushbutton->setGeometry(QRect(385, 340, 55, 25));
        waterlevel_toolbutton = new QToolButton(RoomStateSearchDialog);
        waterlevel_toolbutton->setObjectName(QString::fromUtf8("waterlevel_toolbutton"));
        waterlevel_toolbutton->setGeometry(QRect(20, 340, 35, 18));
        waterlevel_toolbutton->setPopupMode(QToolButton::InstantPopup);
        waterlevel_toolbutton->setAutoRaise(true);
        water_checkbox = new QCheckBox(RoomStateSearchDialog);
        water_checkbox->setObjectName(QString::fromUtf8("water_checkbox"));
        water_checkbox->setGeometry(QRect(20, 340, 35, 16));
        mainvoltageup_checkbox = new QCheckBox(RoomStateSearchDialog);
        mainvoltageup_checkbox->setObjectName(QString::fromUtf8("mainvoltageup_checkbox"));
        mainvoltageup_checkbox->setGeometry(QRect(20, 340, 57, 16));
        mainvoltagedown_checkbox = new QCheckBox(RoomStateSearchDialog);
        mainvoltagedown_checkbox->setObjectName(QString::fromUtf8("mainvoltagedown_checkbox"));
        mainvoltagedown_checkbox->setGeometry(QRect(20, 340, 71, 16));
        zerovoltageup_checkbox = new QCheckBox(RoomStateSearchDialog);
        zerovoltageup_checkbox->setObjectName(QString::fromUtf8("zerovoltageup_checkbox"));
        zerovoltageup_checkbox->setGeometry(QRect(20, 340, 71, 16));
        zerovoltagedown_checkbox = new QCheckBox(RoomStateSearchDialog);
        zerovoltagedown_checkbox->setObjectName(QString::fromUtf8("zerovoltagedown_checkbox"));
        zerovoltagedown_checkbox->setGeometry(QRect(20, 340, 71, 16));
        mainvoltageup_toolbutton = new QToolButton(RoomStateSearchDialog);
        mainvoltageup_toolbutton->setObjectName(QString::fromUtf8("mainvoltageup_toolbutton"));
        mainvoltageup_toolbutton->setGeometry(QRect(30, 340, 64, 18));
        mainvoltageup_toolbutton->setPopupMode(QToolButton::InstantPopup);
        mainvoltageup_toolbutton->setAutoRaise(true);
        mainvoltagedown_toolbutton = new QToolButton(RoomStateSearchDialog);
        mainvoltagedown_toolbutton->setObjectName(QString::fromUtf8("mainvoltagedown_toolbutton"));
        mainvoltagedown_toolbutton->setGeometry(QRect(20, 340, 64, 18));
        mainvoltagedown_toolbutton->setPopupMode(QToolButton::InstantPopup);
        mainvoltagedown_toolbutton->setAutoRaise(true);
        zerovoltageup_toolbutton = new QToolButton(RoomStateSearchDialog);
        zerovoltageup_toolbutton->setObjectName(QString::fromUtf8("zerovoltageup_toolbutton"));
        zerovoltageup_toolbutton->setGeometry(QRect(20, 340, 67, 18));
        zerovoltageup_toolbutton->setPopupMode(QToolButton::InstantPopup);
        zerovoltageup_toolbutton->setAutoRaise(true);
        zerovoltagedown_toolbutton = new QToolButton(RoomStateSearchDialog);
        zerovoltagedown_toolbutton->setObjectName(QString::fromUtf8("zerovoltagedown_toolbutton"));
        zerovoltagedown_toolbutton->setGeometry(QRect(30, 340, 67, 18));
        zerovoltagedown_toolbutton->setPopupMode(QToolButton::InstantPopup);
        zerovoltagedown_toolbutton->setAutoRaise(true);
        simpleandadvanced_pushbutton->raise();
        simplesearch_groupbox->raise();
        advancedsearch_groupbox->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        search_pushbutton->raise();
        waterlevel_toolbutton->raise();
        water_checkbox->raise();
        mainvoltageup_checkbox->raise();
        mainvoltagedown_checkbox->raise();
        zerovoltageup_checkbox->raise();
        zerovoltagedown_checkbox->raise();
        mainvoltageup_toolbutton->raise();
        mainvoltagedown_toolbutton->raise();
        zerovoltageup_toolbutton->raise();
        zerovoltagedown_toolbutton->raise();

        retranslateUi(RoomStateSearchDialog);

        QMetaObject::connectSlotsByName(RoomStateSearchDialog);
    } // setupUi

    void retranslateUi(QDialog *RoomStateSearchDialog)
    {
        RoomStateSearchDialog->setWindowTitle(QApplication::translate("RoomStateSearchDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        simplesearch_groupbox->setTitle(QApplication::translate("RoomStateSearchDialog", "\347\256\200\345\215\225\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("RoomStateSearchDialog", "\345\205\263\347\263\273", 0, QApplication::UnicodeUTF8));
        or_radiobutton->setText(QApplication::translate("RoomStateSearchDialog", "\346\210\226\350\200\205", 0, QApplication::UnicodeUTF8));
        and_radiobutton->setText(QApplication::translate("RoomStateSearchDialog", "\345\271\266\344\270\224", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("RoomStateSearchDialog", "\346\212\245\350\255\246\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RoomStateSearchDialog", "\344\270\212\351\231\220\357\274\232", 0, QApplication::UnicodeUTF8));
        temperatureup_checkbox->setText(QApplication::translate("RoomStateSearchDialog", "\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8));
        humidityup_checkbox->setText(QApplication::translate("RoomStateSearchDialog", "\346\271\277\345\272\246", 0, QApplication::UnicodeUTF8));
        oxygenup_checkbox->setText(QApplication::translate("RoomStateSearchDialog", "\346\260\247\346\260\224", 0, QApplication::UnicodeUTF8));
        carbodioxideup_checkbox->setText(QApplication::translate("RoomStateSearchDialog", "\344\272\214\346\260\247\345\214\226\347\242\263", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RoomStateSearchDialog", "\344\270\213\351\231\220\357\274\232", 0, QApplication::UnicodeUTF8));
        temperaturedown_checkbox->setText(QApplication::translate("RoomStateSearchDialog", "\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8));
        humiditydown_checkbox->setText(QApplication::translate("RoomStateSearchDialog", "\346\271\277\345\272\246", 0, QApplication::UnicodeUTF8));
        oxygendown_checkbox->setText(QApplication::translate("RoomStateSearchDialog", "\346\260\247\346\260\224", 0, QApplication::UnicodeUTF8));
        carbodioxidedown_checkbox->setText(QApplication::translate("RoomStateSearchDialog", "\344\272\214\346\260\247\345\214\226\347\242\263", 0, QApplication::UnicodeUTF8));
        smoke_checkbox->setText(QApplication::translate("RoomStateSearchDialog", "\347\203\237\351\233\276", 0, QApplication::UnicodeUTF8));
        comindex_checkbox->setText(QApplication::translate("RoomStateSearchDialog", "\347\251\272\346\260\224\345\223\201\350\264\250", 0, QApplication::UnicodeUTF8));
        pm25_checkbox->setText(QApplication::translate("RoomStateSearchDialog", "PM2.5", 0, QApplication::UnicodeUTF8));
        mat_checkbox->setText(QApplication::translate("RoomStateSearchDialog", "\345\272\212\345\236\253", 0, QApplication::UnicodeUTF8));
        advancedsearch_groupbox->setTitle(QApplication::translate("RoomStateSearchDialog", "\351\253\230\347\272\247\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        smoke_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\347\203\237\351\233\276", 0, QApplication::UnicodeUTF8));
        comindex_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\347\251\272\346\260\224\345\223\201\350\264\250", 0, QApplication::UnicodeUTF8));
        pm25_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "PM2.5", 0, QApplication::UnicodeUTF8));
        mat_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\345\272\212\345\236\253", 0, QApplication::UnicodeUTF8));
        leftbracket_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "(", 0, QApplication::UnicodeUTF8));
        rightbracket_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", ")", 0, QApplication::UnicodeUTF8));
        or_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\346\210\226\350\200\205", 0, QApplication::UnicodeUTF8));
        and_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\345\271\266\344\270\224", 0, QApplication::UnicodeUTF8));
        clear_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        backdel_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\345\233\236\345\210\240", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("RoomStateSearchDialog", "\344\270\212\351\231\220\357\274\232", 0, QApplication::UnicodeUTF8));
        temperatureup_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8));
        humidityup_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\346\271\277\345\272\246", 0, QApplication::UnicodeUTF8));
        oxygenup_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\346\260\247\346\260\224", 0, QApplication::UnicodeUTF8));
        carbodioxideup_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\344\272\214\346\260\247\345\214\226\347\242\263", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("RoomStateSearchDialog", "\344\270\213\351\231\220\357\274\232", 0, QApplication::UnicodeUTF8));
        temperaturedown_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\346\270\251\345\272\246", 0, QApplication::UnicodeUTF8));
        humiditydown_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\346\271\277\345\272\246", 0, QApplication::UnicodeUTF8));
        oxygendown_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\346\260\247\346\260\224", 0, QApplication::UnicodeUTF8));
        carbodioxidedown_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\344\272\214\346\260\247\345\214\226\347\242\263", 0, QApplication::UnicodeUTF8));
        exp_textedit->setHtml(QApplication::translate("RoomStateSearchDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("RoomStateSearchDialog", "\350\241\250\350\276\276\345\274\217\347\274\226\350\276\221\357\274\232", 0, QApplication::UnicodeUTF8));
        demonstration_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\347\244\272\344\276\213", 0, QApplication::UnicodeUTF8));
        search_pushbutton->setText(QApplication::translate("RoomStateSearchDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        simpleandadvanced_pushbutton->setText(QApplication::translate("RoomStateSearchDialog", "\351\253\230\347\272\247>>", 0, QApplication::UnicodeUTF8));
        waterlevel_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\346\274\217\346\260\264", 0, QApplication::UnicodeUTF8));
        water_checkbox->setText(QApplication::translate("RoomStateSearchDialog", "\346\274\217\346\260\264", 0, QApplication::UnicodeUTF8));
        mainvoltageup_checkbox->setText(QApplication::translate("RoomStateSearchDialog", "\345\270\202\347\224\265\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        mainvoltagedown_checkbox->setText(QApplication::translate("RoomStateSearchDialog", "\345\270\202\347\224\265\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        zerovoltageup_checkbox->setText(QApplication::translate("RoomStateSearchDialog", "\351\233\266\347\224\265\345\216\213\345\267\256", 0, QApplication::UnicodeUTF8));
        zerovoltagedown_checkbox->setText(QApplication::translate("RoomStateSearchDialog", "\351\233\266\347\224\265\345\216\213\345\267\256", 0, QApplication::UnicodeUTF8));
        mainvoltageup_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\345\270\202\347\224\265\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        mainvoltagedown_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\345\270\202\347\224\265\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        zerovoltageup_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\351\233\266\345\234\260\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
        zerovoltagedown_toolbutton->setText(QApplication::translate("RoomStateSearchDialog", "\351\233\266\345\234\260\347\224\265\345\216\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RoomStateSearchDialog: public Ui_RoomStateSearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMSTATESEARCHDIALOG_H
