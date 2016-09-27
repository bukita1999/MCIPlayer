#ifndef PLAYER_H
#define PLAYER_H

#include <mmstream.h>
#include <stdlib.h>
#include <Digitalv.h>
#include <string>

class Player
{
private:
    DWORD64 Device;
    MCI_OPEN_PARMS mciopenparms;
public:
    Player();
    ~Player();
    DWORD64 info(DWORD64 item);
    void Open(std::string Strfilepath);
    void Play();
    void Pause();
    void Resume();
    void Stop();
    void SetVolume(DWORD64 vol);
    void SeekTo(DWORD64 to);
    BOOL MByteToWChar(LPCSTR lpcszStr, LPWSTR lpwszStr, DWORD64 dwSize)
    {
        // Get the required size of the buffer that receives the Unicode
        // string.
        DWORD64 dwMinSize;
        dwMinSize = MultiByteToWideChar(CP_ACP, 0, lpcszStr, -1, NULL, 0);

        if(dwSize < dwMinSize)
        {
            return FALSE;
        }

        // Convert headers from ASCII to Unicode.
        MultiByteToWideChar(CP_ACP, 0, lpcszStr, -1, lpwszStr, dwMinSize);
        return TRUE;
    };

};

#endif // PLAYER_H
