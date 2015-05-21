//
//  commands.cpp
//  TrackGame
//
//  Created by Александр Севрук on 29.04.15.
//  Copyright (c) 2015 Александр Севрук. All rights reserved.
//

#include "commands.h"

commands::commands()
{}

commands::~commands()
{}

struct_way commands::walk_func(struct_way& way)
{
    way.position++;
    if (way.track[way.position] == '|' )
    {
        cout << "\nВы не перепрыгнули стенку.\n";
        way.lose++;
    }
    return way;
}

struct_way commands::jump_func(struct_way& way)
{
    way.position += 2;
    if (way.track[way.position] == '|' )
    {
        cout << "\nВы не перепрыгнули стенку.\n";
        way.lose++;
    }
    return way;
}

struct_way commands::fly_func(struct_way &way)
{
    way.position += 4;
    way.count++;
    if (way.track[way.position] == '|' )
    {
        cout << "\nВы не перепрыгнули стенку.\n";
        way.lose++;
    }
    if (way.count > 1)
    {
        cout << "\nКоманду fly можно использовать только один раз.\n";
        way.lose++;
    }
    return way;
}

struct_way commands::while_func(struct_way &way) // Вариант 1
{
    way.i++;
    try
    {
        if (way.command[way.i] == "-")
        {
            way.i++;
            if (way.command[way.i] == "walk")
            {
                while (way.track[way.position + 1] == '-')
                    way = walk_func(way);
            }
            else if (way.command[way.i] == "jump")
            {
                while (way.track[way.position + 1] == '-')
                    way = jump_func(way);
            }
            else throw 3;
        }
        else if (way.command[way.i] == "--")
        {
            way.i++;
            if (way.command[way.i] == "walk")
            {
                while (way.track[way.position + 2] == '-')
                    way = walk_func(way);
            }
            else if (way.command[way.i] == "jump")
            {
                while (way.track[way.position + 2] == '-')
                    way = jump_func(way);
            }
            else throw 3;
        }
        else throw 3;
    }
    catch (int c)
    {
        cout << "\nВы ввели неверную команду.\n";
        way.lose++;
    }
    
    return way;
}

/*struct_way commands::do_func (struct_way& way) // Вариант 1
{
    way.i++;
    if (way.command[way.i] == "walk")
    {
        way.i++;
        if (way.command[way.i] == "while")
        {
            way.i++;
            if (way.command[way.i] == "not")
            {
                way.i++;
                if (way.command[way.i] == "+")
                {
                    do
                    {
                        way = walk_func(way);
                    }
                    while (way.track[way.position] != '+');
                }
                else if (way.command[way.i] == "|")
                {
                    do
                    {
                        way = walk_func(way);
                    }
                    while (way.track[way.position + 1] != '|');
                }
                else
                    throw 1;
            }
            else
                throw 1;
        }
        else
            throw 1;
    }
    else if (way.command[way.i] == "jump")
    {
        way.i++;
        if (way.command[way.i] == "while")
        {
            way.i++;
            if (way.command[way.i] == "not")
            {
                way.i++;
                if (way.command[way.i] == "+")
                {
                    do
                    {
                        way = jump_func(way);
                    }
                    while (way.track[way.position] != '+');
                }
                else if (way.command[way.i] == "|")
                {
                    do
                    {
                        way = jump_func(way);
                    }
                    while (way.track[way.position + 1] != '|');
                }
                else
                    throw 1;
            }
            else
                throw 1;
        }
        else
            throw 1;
    }
    else
        throw 1;
    
    return way;
}*/

struct_way commands::do_func (struct_way& way) // Вариант 2
{
    way.i++;
    try
    {
        if (way.command[way.i] == "walk")
        {
            way.i++;
            if (way.command[way.i] == "while")
            {
                way.i++;
                if (way.command[way.i] == "not")
                {
                    way.i++;
                    if (way.command[way.i] == "+")
                    {
                        while (way.track[way.position] != '+')
                            way = walk_func(way);
                    }
                    else if (way.command[way.i] == "|")
                    {
                        while (way.track[way.position + 1] != '|')
                        way = walk_func(way);
                    }
                    else throw 2;
                }
                else throw 2;
            }
            else throw 2;
        }
        else if (way.command[way.i] == "jump")
        {
            way.i++;
            if (way.command[way.i] == "while")
            {
                way.i++;
                if (way.command[way.i] == "not")
                {
                    way.i++;
                    if (way.command[way.i] == "+")
                    {
                        while (way.track[way.position] != '+')
                            way = jump_func(way);
                    }
                    else if (way.command[way.i] == "|")
                    {
                        while (way.track[way.position + 1] != '|')
                            way = jump_func(way);
                    }
                    else throw 2;
                }
                else throw 2;
            }
            else throw 2;
        }
        else throw 2;
    }
    catch(int b)
    {
        cout << "\nВы ввели неверную команду.\n";
        way.lose++;
    }
    
    return way;
}

/*struct_way commands::repeat_func (struct_way& way) // Вариант 1
{
    way.i++;
    if (way.command[way.i] == "until")
    {
        way.i++;
        
        if(way.command[way.i] == "+")
        {
            way.i++;
            
            if (way.command[way.i] == "walk")
            {
                while (way.track[way.position] != '+')
                    way = walk_func(way);
                
            }
            
            if (way.command[way.i] == "jump")
            {
                while (way.track[way.position] != '+')
                    way = jump_func(way);
            }
        }
        else if(way.command[way.i] == "|")
        {
            way.i++;
            
            if (way.command[way.i] == "walk")
            {
                while (way.track[way.position + 1] != '|')
                    way = walk_func(way);
                
            }
            
            if (way.command[way.i] =="jump")
            {
                while (way.track[way.position + 1] != '|')
                    way = jump_func(way);
            }
        }
        else
            throw 1;
    }
    else
        throw 1;
    return way;
}*/

/*struct_way commands::repeat_func (struct_way& way) // Вариант 2
{
    way.i++;
    if (way.command[way.i] == "walk")
    {
        way.i++;
        if (way.command[way.i] == "until")
        {
            way.i++;
            if (way.command[way.i++] == "+")
            {
                while (way.track[way.position] != '+')
                    way = walk_func(way);
            }
            else if (way.command[way.i++] == "|")
            {
                while (way.track[way.position + 1] != '|')
                    way = walk_func(way);
            }
        }
    }
    else if (way.command[way.i] == "jump")
    {
        way.i++;
        if (way.command[way.i] == "until")
        {
            way.i++;
            if (way.command[way.i++] == "+")
            {
                while (way.track[way.position] != '+')
                    way = jump_func(way);
            }
            else if (way.command[way.i++] == "|")
            {
                while (way.track[way.position + 1] != '|')
                    way = jump_func(way);
            }
        }
    }
    
    return way;
}*/

struct_way commands::repeat_func (struct_way& way) // Вариант 3
{
    way.i++;
    try
    {
        if (way.command[way.i] == "walk")
        {
            way.i++;
            if (way.command[way.i] == "until")
            {
                way.i++;
                if (way.command[way.i] == "+")
                {
                    while (way.track[way.position] != '+')
                        way = walk_func(way);
                }
                else if (way.command[way.i] == "|")
                {
                    while (way.track[way.position + 1] != '|')
                        way = walk_func(way);
                }
                else throw 1;
            }
            else throw 1;
        }
        else if (way.command[way.i] == "jump")
        {
            way.i++;
            if (way.command[way.i] == "until")
            {
                way.i++;
                if (way.command[way.i] == "+")
                {
                    while (way.track[way.position] != '+')
                        way = jump_func(way);
                }
                else if (way.command[way.i] == "|")
                {
                    while (way.track[way.position + 1] != '|')
                        way = jump_func(way);
                }
                else throw 1;
            }
            else throw 1;
        }
        else throw 1;
    }
    catch(int i)
    {
        cout << "\nВы ввели неверную команду.\n";
        way.lose++;
    }
    
    return way;
}