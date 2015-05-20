//
//  errors.h
//  TrackGame
//
//  Created by Александр Севрук on 16.04.15.
//  Copyright (c) 2015 Александр Севрук. All rights reserved.
//

#pragma once
#include "commands.h"

class errors
{
private:
    
public:
    errors();
    ~errors();
    
    int not_end(struct_way &wayy);
    int not_map(struct_way &wayy);
    
};

