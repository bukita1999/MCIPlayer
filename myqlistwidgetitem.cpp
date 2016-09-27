#include "myqlistwidgetitem.h"
#include <QFileInfo>
#include<QtGui>
#include<QDebug>

MYQListWidgetItem::MYQListWidgetItem()
{

}
MYQListWidgetItem::MYQListWidgetItem(QString file)
{
   //获取file的文件名
   filepath=file;
   QFileInfo fileinfo;
   fileinfo = QFileInfo(file);
   QString file_name = fileinfo.fileName();
   //设置text
   this->setText(file_name);
   //设置大小
   this->setSizeHint(QSize(0,ITEM_HEIGHT));
}
void MYQListWidgetItem::addPlayingMark()
{
    playingMark=true;
    QString filename=this->text();
    filename="正在播放   "+filename;
    this->setText(filename);
}
void MYQListWidgetItem::addPauseMark()
{
    playingMark=false;
    QFileInfo fileinfo;
    fileinfo = QFileInfo(filepath);
   QString filename=fileinfo.fileName();
   filename="暂停   "+filename;
   this->removePlayingMark();
   this->setText(filename);
}

void MYQListWidgetItem::removePlayingMark()
{
    playingMark=false;
    QFileInfo fileinfo;
    fileinfo = QFileInfo(filepath);
    QString file_name = fileinfo.fileName();
    //设置text
    this->setText(file_name);
}
