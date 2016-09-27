#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<iostream>
#include<QDebug>
#include<QFileDialog>
#include"myqlistwidgetitem.h"
#include<QDir>
#include<QString>
#include<QStringList>
#include<QDebug>
#include<QMessageBox>
#include<strstream>
#include<string>
#include<sstream>
#include<QTextCodec>
#include <stdlib.h>
#include <time.h>
#include<QWidgetAction>
#include<QHBoxLayout>
#include<QAction>
#include<QMenu>
#include<QGraphicsDropShadowEffect>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));


    ui->setupUi(this);//如果不先set一次，获取到的width和height是错误的640*480，只能这样解决了

    //设置白色背景
    QLabel *background = new QLabel(this);
    background->setStyleSheet("background-color:rgb(250,250,250)");
    background->setGeometry(0, 0, this->width(), this->height());
    //设置指定颜色的标题栏
    /*QLabel *title = new QLabel(this);
    title->setStyleSheet("QLabel{background-color:rgb(242,242,242)}");
    title->setGeometry(0, 0, this->width(), TITLE_HEIGHT);*/
    //设置下方控件区域的蓝色背景
    QLabel *bottom = new QLabel(this);
    bottom->setStyleSheet("background-color: rgb(13,127,217)");
    bottom->setGeometry(0,this->height()-BOTTOM_HEIGHT , this->width(), BOTTOM_HEIGHT);









    ui->setupUi(this);//再设置一次UI








    //设置窗体标题栏隐藏并设置位于顶层
    setWindowFlags(Qt::FramelessWindowHint);
    //可获取鼠标跟踪效果
    setMouseTracking(true);

     //构建最小化、关闭按钮
     QToolButton *minButton = new QToolButton(this);
     QToolButton *closeButton= new QToolButton(this);
     minButton->setStyleSheet("QToolButton{border-image: url(:/images/min.png) } QToolButton:hover{border-image: url(:/images/min_hover.png)} ");
     closeButton->setStyleSheet("QToolButton{border-image: url(:/images/close.png) } QToolButton:hover{border-image: url(:/images/close_hover.png)} ");
     minButton->setGeometry(this->width()-TITLE_HEIGHT*2,  0,  TITLE_HEIGHT,  TITLE_HEIGHT);
     closeButton->setGeometry(this->width()-TITLE_HEIGHT,  0,  TITLE_HEIGHT,  TITLE_HEIGHT);


     //设置最小化、关闭按钮的信号和槽函数
     connect(minButton, SIGNAL(clicked()), this, SLOT(minButtonClicked()));
     connect(closeButton, SIGNAL(clicked()), this, SLOT(closeButtonClicked()));
     //设置导入文件按钮的信号和槽函数
     connect(ui->loadFileButton, SIGNAL(clicked()), this, SLOT(on_loadFileButton_clicked()));
     //设置播放暂停按钮的信号和槽函数
     connect(ui->playButton, SIGNAL(clicked()), this, SLOT(on_playButton_clicked()));
     //设置上一曲按钮的信号和槽函数
     connect(ui->preButton, SIGNAL(clicked()), this, SLOT(on_preButton_clicked()));
     //设置下一曲按钮的信号和槽函数
     connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(on_nextButton_clicked()));
     //设置列表中项目双击的信号和槽函数
     connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(on_listWidget_itemDoubleClicked(QListWidgetItem *)));
     //设置播放进度条释放的信号和槽函数
     connect(ui->progresslSlider, SIGNAL(sliderReleased()), this, SLOT(on_progresslSlider_sliderReleased()));
     //设置模式选择按钮的信号和槽函数
     connect(ui->modeBotton, SIGNAL(clicked()), this, SLOT(on_modeBotton_clicked()));
     //设置音量 按钮的信号和槽函数
     connect(ui->volumnButton, SIGNAL(clicked()), this, SLOT(on_volumnButton_clicked()));

     connect(ui->removeFileButton, SIGNAL(clicked()), this, SLOT(on_removeFileButton_clicked()));
connect(ui->progresslSlider, SIGNAL(sliderPressed()), this, SLOT(on_progresslSlider_sliderPressed()));

connect(ui->upButton, SIGNAL(clicked()), this, SLOT(on_upButton_clicked()));
connect(ui->downButton, SIGNAL(clicked()), this, SLOT(on_downButton_clicked()));

connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(on_stopButton_clicked()));




    ui->listWidget->setFocusPolicy(Qt::NoFocus);//去除项目被选中时的虚线边框
    ui->listWidget->setAlternatingRowColors(true);//设置列表中想邻条目背景色
    ui->listWidget->setStyleSheet(" QListWidget::item{color:black; background:white; } QListWidget::item:alternate{background:rgb(242,242,242);}  QListWidget::item:selected:enabled{ color:white;  background:rgb(0,120,215)} QListWidget::item:hover{background:rgb(233,244,255)}");

    ui->playButton->setStyleSheet("QToolButton{border-image: url(:/images/play.png) } QToolButton:hover{border-image: url(:/images/play_clicked.png)} QToolButton:pressed{border-image: url(:/images/play_hover.png)}");
    ui->nextButton->setStyleSheet("QToolButton{border-image: url(:/images/next.png) } QToolButton:hover{border-image: url(:/images/next_hover.png)} QToolButton:pressed{border-image: url(:/images/next_clicked.png)}");

    ui->preButton->setStyleSheet("QToolButton{border-image: url(:/images/pre.png) } QToolButton:hover{border-image: url(:/images/pre_hover.png)} QToolButton:pressed{border-image: url(:/images/pre_clicked.png)}");
    ui->progresslSlider->setStyleSheet("QSlider::groove:horizontal{ border:0px; height:4px; } QSlider::sub-page:horizontal{ background:white; } QSlider::add-page:horizontal{ background:lightgray; } QSlider::handle:horizontal{ background:white; width:10px; border-radius:5px; margin:-3px 0px -3px 0px; }");

    //计时器
    timer=new QTimer();
    //设置计时器超时的信号和槽函数
    connect(timer, SIGNAL(timeout()), this, SLOT(myTimeout()));

    //音乐播放模式的菜单
    modeMenu=new QMenu();
    modeMenu->setStyleSheet("QMenu{ padding:5px; background:white; border:1px solid gray; } QMenu::item{ padding:0px 30px 0px 20px; height:25px; } QMenu::item:selected:enabled{ background:lightgray; color:white; } QMenu::item:selected:!enabled{ background:transparent; } QMenu::separator{ height:1px; background:lightgray; margin:5px 0px 5px 0px; }");
    //定义一个action组
    QActionGroup *group = new QActionGroup(this);
    group->setExclusive(true);
    group->setEnabled(true);
    // 增加Action
    QAction *action1 = new QAction(tr("单曲循环"), group);
    action1->setCheckable(true);
    modeMenu->addAction(action1);
    QAction *action2 = new QAction(tr("顺序播放"), group);
    action2->setCheckable(true);
    action2->setChecked(true);
    modeMenu->addAction(action2);
    QAction *action3 = new QAction(tr("随机播放"), group);
    action3->setCheckable(true);
    modeMenu->addAction(action3);
    // 设置播放模式菜单的信号和槽函数
    connect(group, SIGNAL(triggered(QAction*)), SLOT(updateItem(QAction*)));

    //初始模式为顺序播放(自动循环)
    modeType=ORDER;
    ui->modeBotton->setStyleSheet("QToolButton{border-image: url(:/images/order.png) } QToolButton:hover{border-image: url(:/images/order_hover.png)} ");

    ui->volumnButton->setStyleSheet("QToolButton{border-image: url(:/images/volumn.png) } QToolButton:hover{border-image: url(:/images/volumn_hover.png)}");

    //音量调节滑动条
    volumnSlider=new QSlider();
    connect(volumnSlider, SIGNAL(valueChanged(int)), SLOT(on_volumnSlider_volumnChanged(int)));
    volumnSlider->setMinimum(0);
    volumnSlider->setMaximum(1000);
    volumnSlider->setValue(this->volumn);
    volumnSlider->setStyleSheet("QSlider::groove{ border:0px; width:4px; } QSlider::add-page{ background:gray; } QSlider::sub-page{ background:lightgray; } QSlider::handle{ background:rgb(13,127,217); height:10px; border-radius:5px; margin:0px -3px 0px -3px; }");


    ui->upButton->setStyleSheet("QToolButton{border-image: url(:/images/up.png) } QToolButton:hover{border-image: url(:/images/up_hover.png)}");
    ui->downButton->setStyleSheet("QToolButton{border-image: url(:/images/down.png) } QToolButton:hover{border-image: url(:/images/down_hover.png)}");
    ui->stopButton->setStyleSheet("QToolButton{border-image: url(:/images/stop.png) } QToolButton:hover{border-image: url(:/images/stop_hover.png)}");

    //出现的渐变动画
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
     animation->setDuration(400);
     animation->setStartValue(0);
     animation->setEndValue(1);
     animation->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::minButtonClicked()
{
    showMinimized();
}

void MainWindow::closeButtonClicked()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
       animation->setDuration(300);
       animation->setStartValue(1);
       animation->setEndValue(0);
       animation->start();
       connect(animation, SIGNAL(finished()), this, SLOT(close()));
       //close();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
 if(event->button() == Qt::LeftButton)
 {
     if(event->pos().y()>TITLE_HEIGHT)//设置只能拖动“标题栏”来拖动窗口
         return;
      mouse_press = true;
      //鼠标相对于窗体的位置（或者使用event->globalPos() - this->pos()）
      move_point = event->pos();
 }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_press)
    {
        QPoint move_pos = event->globalPos();
       this->move(move_pos - move_point);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_press = false;
}

void MainWindow::on_loadFileButton_clicked()
{
    const QStringList filelist =
        QFileDialog::getOpenFileNames(this, tr("打开文件"),
                                      0,
                                     tr("音乐文件(*.mp3 *.wav *.wma *.aac *.au *.aif);;All files (*.*)"));
    if(!filelist.empty())
    {
        for(int i=0;i<filelist.length();++i)
        {
            QString file=filelist[i];
            MYQListWidgetItem * item=new  MYQListWidgetItem(file);
            ui->listWidget->addItem(item);
        }
    }
    else
    {
        QMessageBox message(QMessageBox::Warning, "No music", "Please select a music file.", QMessageBox::Yes);
        message.exec();
    }
}

void MainWindow::on_playButton_clicked()
{
    int index=ui->listWidget->currentIndex().row();
    if(index==-1&&playing==false)
    {
        QMessageBox message(QMessageBox::Warning, "No music selected", "Please select a music in the list.", QMessageBox::Yes);
        message.exec();
        return;
    }
    if(playing==false)//并且播放条是出于0，说明是新的歌曲开始播放，若不是，则可能是暂停之后恢复播放
    {
        if((ui->progresslSlider->value())!=0)
        {
            currentPlayingItem->removePlayingMark();
            currentPlayingItem->addPlayingMark();
            player.Resume();
            //还应该更改图片
            ui->playButton->setStyleSheet("QToolButton{border-image: url(:/images/pause.png) } QToolButton:hover{border-image: url(:/images/pause_clicked.png)} QToolButton:pressed{border-image: url(:/images/pause_hover.png)}");
            //标记播放状态
            playing=true;
            timer->setInterval(1000);
            timer->start();
        }
        else//播放新歌曲
        {

        //还应该更改图片
        ui->playButton->setStyleSheet("QToolButton{border-image: url(:/images/pause.png) } QToolButton:hover{border-image: url(:/images/pause_clicked.png)} QToolButton:pressed{border-image: url(:/images/pause_hover.png)}");
        //标记播放状态
        playing=true;
        //播放选中的文件
        MYQListWidgetItem* item=dynamic_cast<MYQListWidgetItem*>(ui->listWidget->currentItem());
        currentPlayingItem=item;
        for(int i=0;i<(ui->listWidget->count());++i)
        {
            MYQListWidgetItem * temp=dynamic_cast<MYQListWidgetItem *>(ui->listWidget->item(i));//row=index+1???????
            temp->removePlayingMark();
        }
        item->addPlayingMark();
        player.Stop();
        player.Open(item->filepath.toStdString());
        player.Play();
        player.SetVolume(volumn);
        timer->setInterval(1000);
        timer->start();
        ui->progresslSlider->setValue(0);
        }
    }
    else//说明是从播放状态变为暂停状态
    {
        playing=false;
        player.Pause();
        timer->stop();
        currentPlayingItem->addPauseMark();
        //设置播放样式的表示以供播放
        ui->playButton->setStyleSheet("QToolButton{border-image: url(:/images/play.png) } QToolButton:hover{border-image: url(:/images/play_clicked.png)} QToolButton:pressed{border-image: url(:/images/play_hover.png)}");
    }
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *importeditem)
{
    //还应该更改图片
    //ui->playButton->setStyleSheet("QToolButton{border-image: url(:/images/pause.png) } QToolButton:hover{border-image: url(:/images/pause_clicked.png)} QToolButton:pressed{border-image: url(:/images/pause_hover.png)}");
    //标记播放状态
    //playing=true;
    //播放选中的文件
    //MYQListWidgetItem* item=dynamic_cast<MYQListWidgetItem*>(ui->listWidget->currentItem());
    //player.Stop();
    //player.Open(item->filepath.toStdString());
    //player.Play();
    //timer->setInterval(1000);
    //timer->start();
   // ui->progresslSlider->setValue(0);
    playing=false;
    int row=ui->listWidget->currentRow();
    ui->listWidget->setCurrentRow(row);
    ui->progresslSlider->setValue(0);
    on_playButton_clicked();
}

void MainWindow::myTimeout()
{
    int totaltime=player.info(MCI_STATUS_LENGTH);
    int currenttime=player.info(MCI_STATUS_POSITION);
    if(currenttime>=totaltime)//进行模式选择
    {
        int index;
        int count;
        switch(modeType)
        {
                    case SINGLEREPEAT:
                        player.SeekTo(0);
                        //OnBnClickedPlay();
                        player.Play();
                        break;
                    case ORDER:
                        playing=false;
                        index=ui->listWidget->currentRow();
                        count=ui->listWidget->count();
                        index=(index+1)%count;
                        ui->listWidget->setCurrentRow(index);
                        ui->progresslSlider->setValue(0);
                        on_playButton_clicked();
                        break;
                    case SHUFFLE:
                        playing=false;
                        srand((unsigned)time(NULL));
                        count=ui->listWidget->count();
                         index=rand()%count;
                         ui->listWidget->setCurrentRow(index);
                         ui->progresslSlider->setValue(0);
                         on_playButton_clicked();
                         break;
          }
          return;
    }

    totaltime=totaltime/1000;
    int minute=(totaltime/60)%60;
    int second=totaltime%60;

    currenttime=currenttime/1000;
    ui->progresslSlider->setValue((currenttime*100)/totaltime);
    int currentMinute=(currenttime/60)%60;
    int currentSecond=currenttime%60;
    //设置当前时间
    std::strstream ss,aa;
    std::string m;
    ss<<currentMinute;
    ss>>m;
    aa<<currentSecond;
    std::string s;
    aa>>s;
    if(currentMinute<10)
        m="0"+m;
    if(currentSecond<10)
        s="0"+s;
    std::string text=m+":"+s;
    QString qtext=QString::fromStdString(text);
    ui->currentTimeLabel->setText(qtext);
    //设置音乐总时间
    std::strstream sss,aaa;
    std::string mm;
    sss<<minute;
    sss>>mm;
    aaa<<second;
    std::string ssss;
    aaa>>ssss;
    if(minute<10)
        mm="0"+mm;
    if(second<10)
        ssss="0"+ssss;
    std::string texttt=mm+":"+ssss;
    QString qtexttt=QString::fromStdString(texttt);
    ui->totalTImeLabel->setText(qtexttt);
}

void MainWindow::on_progresslSlider_sliderReleased()
{
    timer->start();
    DWORD64 time=player.info(MCI_STATUS_LENGTH);
    DWORD64 currenttime;
    currenttime=time*(ui->progresslSlider->value())/100;
    player.SeekTo(currenttime);
    player.Play();
    player.Pause();
    playing=false;
    on_playButton_clicked();
}

void MainWindow::on_modeBotton_clicked()
{
    QPoint position;
    position.setX(531-30);
    position.setY(425-92);
    modeMenu->exec(mapToGlobal(position));
}

void MainWindow::updateItem(QAction *action)
{
    if (action->text() == tr("单曲循环")) {
        modeType=SINGLEREPEAT;
        ui->modeBotton->setStyleSheet("QToolButton{border-image: url(:/images/singlerepeat.png) } QToolButton:hover{border-image: url(:/images/singlerepeat_hover.png)} ");
    }
    else if (action->text() == tr("顺序播放")) {
        modeType=ORDER;
        ui->modeBotton->setStyleSheet("QToolButton{border-image: url(:/images/order.png) } QToolButton:hover{border-image: url(:/images/order_hover.png)} ");
    }
    else if (action->text() == tr("随机播放")) {
        modeType=SHUFFLE;
        ui->modeBotton->setStyleSheet("QToolButton{border-image: url(:/images/shuffle.png) } QToolButton:hover{border-image: url(:/images/shuffle_hover.png)} ");
    }
}

void MainWindow::on_volumnButton_clicked()
{
    QMenu * vol=new QMenu(this);
    vol->setStyleSheet("QMenu{ padding:5px; background:white; border:1px solid gray; } QMenu::item{ padding:0px 30px 0px 20px; height:25px; } QMenu::item:selected:enabled{ background:lightgray; color:white; } QMenu::item:selected:!enabled{ background:transparent; } QMenu::separator{ height:1px; background:lightgray; margin:5px 0px 5px 0px; }");
    QWidgetAction * waction=new QWidgetAction(this);
     waction->setDefaultWidget(volumnSlider);
     vol->addAction(waction);
     QPoint position;
     position.setX(531-43);
     position.setY(425-92-10);
     vol->exec(mapToGlobal(position));
}
void MainWindow::on_volumnSlider_volumnChanged(int)
{
    volumn=volumnSlider->value();
    player.SetVolume(volumn);
}


void MainWindow::on_preButton_clicked()
{
    int index=ui->listWidget->currentRow();
    int count=ui->listWidget->count();
    if(index==0)
        index=count-1;
    else
         index=index-1;
    ui->listWidget->setCurrentRow(index);
    ui->progresslSlider->setValue(0);
    playing=false;
    on_playButton_clicked();
}

void MainWindow::on_nextButton_clicked()
{
    int index=ui->listWidget->currentRow();
    int count=ui->listWidget->count();
    index=(index+1)%count;
    ui->listWidget->setCurrentRow(index);
    ui->progresslSlider->setValue(0);
    playing=false;
    on_playButton_clicked();
}

void MainWindow::on_removeFileButton_clicked()
{
    if(ui->listWidget->count()==0)
    {
        QMessageBox message(QMessageBox::Warning, "Can't remove", "Unable to remove the playing song.", QMessageBox::Yes);
        message.exec();
        return;
    }
    MYQListWidgetItem * item=dynamic_cast< MYQListWidgetItem *>(ui->listWidget->currentItem());
    if(currentPlayingItem==item)
    {
        QMessageBox message(QMessageBox::Warning, "Can't remove", "Unable to remove the playing song.", QMessageBox::Yes);
        message.exec();
        return;
    }
    ui->listWidget->removeItemWidget(item);
    delete item;
}

void MainWindow::on_progresslSlider_sliderPressed()
{
    timer->stop();//在用户拖动的时候停止计时器以免自动更新滑块位置
}

void MainWindow::on_upButton_clicked()
{
    if(ui->listWidget->count()==0)
        return;
    MYQListWidgetItem* item=dynamic_cast<MYQListWidgetItem*>(ui->listWidget->currentItem());
    QString path=item->filepath;
    MYQListWidgetItem* itemNew=new MYQListWidgetItem(path);
    int index=ui->listWidget->currentRow();
    if(index==0)
     {
        index=ui->listWidget->count();
        ui->listWidget->insertItem(index,itemNew);
    }
    else
    {
        ui->listWidget->insertItem(index-1,itemNew);
    }
    if(item->playingMark==true)
        itemNew->addPlayingMark();
    ui->listWidget->setCurrentItem(itemNew);
    delete item;
}

void MainWindow::on_downButton_clicked()
{
    if(ui->listWidget->count()==0)
        return;
    MYQListWidgetItem* item=dynamic_cast<MYQListWidgetItem*>(ui->listWidget->currentItem());
    QString path=item->filepath;
    MYQListWidgetItem* itemNew=new MYQListWidgetItem(path);
    int index=ui->listWidget->currentRow();
    index=(index+2)%(ui->listWidget->count()+1);
    ui->listWidget->insertItem(index,itemNew);
    if(item->playingMark==true)
        itemNew->addPlayingMark();
    ui->listWidget->setCurrentItem(itemNew);
    delete item;
}


void MainWindow::on_stopButton_clicked()
{
    timer->stop();
    playing=false;
    player.Stop();
    ui->playButton->setStyleSheet("QToolButton{border-image: url(:/images/play.png) } QToolButton:hover{border-image: url(:/images/play_clicked.png)} QToolButton:pressed{border-image: url(:/images/play_hover.png)}");
    ui->progresslSlider->setValue(0);
    ui->currentTimeLabel->setText("00:00");
    ui->totalTImeLabel->setText("00:00");
    for(int i=0;i<(ui->listWidget->count());++i)
    {
        MYQListWidgetItem * temp=dynamic_cast<MYQListWidgetItem *>(ui->listWidget->item(i));//row=index+1???????
        temp->removePlayingMark();
    }
}
