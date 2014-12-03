#pragma once

#include <vector>

#include "Controllers\Volume\CoreAudio.h"
#include "Controllers\Volume\VolumeController.h"
#include "MeterWnd\Animations\FadeOut.h"
#include "MeterWnd\MeterWnd.h"
#include "NotifyIcon.h"
#include "Settings.h"

class Skin;

class VolumeOSD {
public:
    VolumeOSD(HINSTANCE hInstance, Settings &settings);
    void HideIcon();

private:
    Settings &_settings;
    HWND _hWnd;
    MeterWnd _mWnd;
    HWND _masterWnd;
    NotifyIcon *_icon;
    HMENU _menu;
    HMENU _deviceMenu;
    UINT _menuFlags;
    CoreAudio *_volumeCtrl;
    std::vector<VolumeController::DeviceInfo> _deviceList;
    std::wstring _selectedDevice;
    std::wstring _selectedDesc;
    MeterWnd _muteWnd;
    Gdiplus::Bitmap *_muteBg;

    void Hide();
    void LoadSkin(std::wstring skinXML);
    void MeterLevels(float value);
    void UpdateIconTip();
    void UpdateDeviceMenu();

    static LRESULT CALLBACK StaticWndProc(HWND hWnd, UINT message,
        WPARAM wParam, LPARAM lParam);
    LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};