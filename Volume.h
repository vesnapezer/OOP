#pragma once

class Volume {
private:
    int level;
    int before_mute;

    static int clamp(int v);
    bool valid() const;

public:
    Volume();
    Volume(int l);

    void up(int step = 10);
    void down(int step = 10);
    void mute();
    void unmute();
    int get() const;
};