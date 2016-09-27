#include "player.h"
#include <mmstream.h>
#include <stdlib.h>
#include <Digitalv.h>
#include <QMessageBox>
#include<QString>

Player::Player()
{

}

Player::~Player()
{

}

DWORD64 Player::info(DWORD64 item)
{
    MCI_STATUS_PARMS mcistatusparms;
    mcistatusparms.dwItem=item;
    mcistatusparms.dwReturn=0;
    mciSendCommand(Device,MCI_STATUS,MCI_STATUS_ITEM,(DWORD64)&mcistatusparms);
    return mcistatusparms.dwReturn;
}

void Player::Open(std::string Strfilepath)
{
    mciSendCommand(Device,MCI_CLOSE,0,0);


     //convert std::string to LPWSTR refering to a c++ programing website
     int len;
     int slength = (int)Strfilepath.length() + 1;
     len = MultiByteToWideChar(CP_ACP, 0, Strfilepath.c_str(), slength, 0, 0);
     wchar_t* buf = new wchar_t[len];
     MultiByteToWideChar(CP_ACP, 0, Strfilepath.c_str(), slength, buf, len);
     std::wstring r(buf);
     delete[] buf;
    // // //  /////////////////////////////////////////
    #ifdef UNICODE
    std::wstring stemp =r; // Temporary buffer is required
    mciopenparms.lpstrElementName = stemp.c_str();
    #else
    mciopenparms.lpstrElementName = Strfilepath.c_str();
    #endif
    //end convertion




    //mciopenparms.lpstrElementName=(LPCWSTR)Strfilepath;//Can't convert.
    DWORD64 dwReturn;
    if (dwReturn=mciSendCommand(NULL,MCI_OPEN,MCI_OPEN_ELEMENT|MCI_WAIT,(DWORD64)&mciopenparms))
    {
        QMessageBox message(QMessageBox::Warning, "ERROR", "Can't open this file.", QMessageBox::Yes);
        message.exec();
    }
    Device=mciopenparms.wDeviceID;
}

void Player::Play()
{
    MCI_PLAY_PARMS mciplayparms;
    mciplayparms.dwFrom=0;
    mciSendCommand(Device,MCI_PLAY,MCI_NOTIFY,(DWORD64)&mciplayparms);
}

void Player::Pause()
{
    mciSendCommand(Device,MCI_PAUSE,0,0);
}

void Player::Resume()
{
    mciSendCommand(Device,MCI_RESUME,0,0);
}

void Player::Stop()
{
    mciSendCommand(Device,MCI_STOP,0,0);
    mciSendCommand(Device,MCI_CLOSE,0,0);
}

void Player::SetVolume(DWORD64 vol)
{
    MCI_DGV_SETAUDIO_PARMS mcisetvolumn;
    mcisetvolumn.dwItem=MCI_DGV_SETAUDIO_VOLUME;
    mcisetvolumn.dwValue=vol;
    mciSendCommand(Device,MCI_SETAUDIO,MCI_DGV_SETAUDIO_VALUE|MCI_DGV_SETAUDIO_ITEM,(DWORD64)&mcisetvolumn);
}

void Player::SeekTo(DWORD64 to)
{
    MCI_SEEK_PARMS mciseek;
    mciseek.dwTo=to;
    mciSendCommand(Device,MCI_SEEK,MCI_TO,(DWORD64)&mciseek);
}
