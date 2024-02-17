#ifndef UI_H
#define UI_H

#include "fogeheader.h"
#include "map.h"


void printgame(Map *map);

char gd[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char wd[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char hd[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char bd[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char ed[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

#endif