//
//  commands.h
//  TrackGame
//
//  Created by Александр Севрук on 29.03.15.
//  Copyright (c) 2015 Александр Севрук. All rights reserved.
//

#ifndef TrackGame_commands_h
#define TrackGame_commands_h

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

struct struct_way
{
    string track;
    string command[40];
    int i;
    int repeat_num;
    int position = 0;
    int lose;
    unsigned long q;
    int count;
};

class commands
{
private:
    
public:
    
    commands();
    ~commands();
    
    struct_way walk_func(struct_way& way);
    struct_way jump_func(struct_way& way);
    struct_way fly_func(struct_way& way);
    struct_way do_func(struct_way& way);
    struct_way repeat_func (struct_way& way);
    struct_way while_func (struct_way& way);
    
};

#endif

