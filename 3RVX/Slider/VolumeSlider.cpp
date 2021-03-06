#include "VolumeSlider.h"

#include "..\Controllers\Volume\CoreAudio.h"
#include "..\Error.h"
#include "..\Settings.h"
#include "..\Skin.h"
#include "SliderKnob.h"

VolumeSlider::VolumeSlider(CoreAudio &volumeCtrl) :
SliderWnd(L"3RVX-VolumeSlider", L"3RVX Volume Slider"),
_settings(*Settings::Instance()),
_volumeCtrl(volumeCtrl) {

    Skin *skin = _settings.CurrentSkin();

    Gdiplus::Bitmap *bg = skin->SliderBgImg("volume");
    BackgroundImage(bg);

    _knob = skin->Knob("volume");
    _vertical = _knob->Vertical();

    std::list<Meter*> meters = skin->VolumeSliderMeters();
    for (Meter *m : meters) {
        AddMeter(m);
    }

    Knob(_knob);
}

void VolumeSlider::SliderChanged() {
    _volumeCtrl.Volume(_knob->Value());
}

void VolumeSlider::MeterLevels(float level) {
    if (Visible() && _dragging == false) {
        MeterWnd::MeterLevels(level);
        Update();
    }
    _level = level;
}

void VolumeSlider::Show() {
    MeterWnd::MeterLevels(_level);
    Update();
    SliderWnd::Show();
    SetActiveWindow(_hWnd);
    SetForegroundWindow(_hWnd);
}

bool VolumeSlider::Visible() {
    return _visible;
}