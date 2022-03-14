#pragma once
#include "Player.h"
class Rookie :
    public Player
{
public:
    Rookie();
    Rookie(string);
    ~Rookie();

    virtual void View_Level();
    virtual void View_Name();
};

