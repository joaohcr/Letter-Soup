#pragma once
#include "Player.h"
class Master :
    public Player
{
public:
    Master();
    Master(string);
    ~Master();

    virtual void View_Level();
    virtual void View_Name();
};

