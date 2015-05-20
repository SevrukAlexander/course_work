//
//  errors.cpp
//  TrackGame
//
//  Created by Александр Севрук on 29.04.15.
//  Copyright (c) 2015 Александр Севрук. All rights reserved.
//

#include "errors.h"

errors::errors()
{}

errors::~errors()
{}

int errors::not_end(struct_way& wayy)
{
    if (wayy.track[wayy.position] != '+' && wayy.position + 1 < wayy.q)
    {
        cout << "\nВы не дошли до конца.\n";
        wayy.lose++;
    }
    return wayy.lose;
}

int errors::not_map(struct_way& wayy)
{
    if (wayy.track[wayy.position] != '+' && wayy.position + 1 > wayy.q)
    {
        cout << "\nВы вышли за игровое поле.\n";
        wayy.lose++;
    }
    return wayy.lose;
}
