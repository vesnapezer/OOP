#include "Volume.h"
#include <cassert>

int Volume::clamp(int v) {
    if (v < 0) return 0;
    if (v > 100) return 100;
    return v;
}

bool Volume::valid() const {
    return level >= 0 && level <= 100;
}

Volume::Volume(int l) : level{ clamp(l) }, before_mute{ level } {
    assert(valid());
}

// Delegirajući konstruktor
Volume::Volume() : Volume(50) {}

void Volume::up(int step) {
    level = clamp(level + step);
    assert(valid());
}

void Volume::down(int step) {
    level = clamp(level - step);
    assert(valid());
}

void Volume::mute() {
    if (level > 0) {
        before_mute = level;
    }
    level = 0;
    assert(valid());
}

void Volume::unmute() {
    level = before_mute;
    assert(valid());
}

int Volume::get() const {
    return level;
}