//
//  main.cpp
//  TrackGame
//
//  Created by Александр Севрук on 14.05.15.
//  Copyright (c) 2015 Александр Севрук. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

#include "commands.h"
#include "errors.h"
#include "menu.h"
#include "rules.h"

using namespace std;

ifstream ifs("levels.txt");

int j = 0;
long long length;
int number = 0;
int position;

void restart(int number, int position)
{
    ifs.seekg(length);
    cout << "\nПопробуйте снова.\n";
}

int main ()
{
    setlocale(LC_ALL, "rus");
    
    enum
    {
        Walk   = 10,
        Jump   = 11,
        Repeat = 12,
        Do     = 13,
        If     = 14,
        While  = 15,
        Fly    = 16
    };
    
    int e;
    
    struct_way ways;
    errors err;
    commands com;
    std::unordered_map<string, int> hashmap;
    hashmap["walk"] = Walk;
    hashmap["jump"] = Jump;
    hashmap["repeat"] = Repeat;
    hashmap["do"] = Do;
    hashmap["if"] = If;
    hashmap["if"] = While;
    hashmap["fly"] = Fly;
    hashmap["end"] = 0;
    
    int item = menu();
    
    switch (item)
    {
        case 1:
            if (!ifs.is_open())
            {
                cout << "Не удалось открыть файл.";
                return -1;
            }
            
            while (!ifs.eof())
            {
                
                length = ifs.tellg();
                getline(ifs, ways.track);
                ways.q = ways.track.length();
                
                number++;
                j = 0;
                ways.lose = 0;
                ways.count = 0;
                ways.position = 0;
                
                cout << "Уровень: " << number << "\n"
                << "Длина пути: " << ways.q << "\n\n"
                << ways.track << "\n\n"
                << "Введите команды: ";
                
                while (ways.command[j - 1] != "end")
                {
                    cin >> ways.command[j];
                    
                    if (ways.command[j] == "exit")
                    {
                        number = 0;
                        ifs.seekg(0);
                        cout << "\n";
                        exit(main());
                    }
                    
                    j++;
                }
                
                for (ways.i = 0; ways.i < j; ways.i++)
                {
                    if (hashmap.count(ways.command[ways.i]))
                    {
                        switch (hashmap[ways.command[ways.i]])
                        {
                            case Walk:
                                ways = com.walk_func(ways);
                                break;
                                
                            case Jump:
                                ways = com.jump_func(ways);
                                break;
                                
                            case Fly:
                                ways = com.fly_func(ways);
                                break;
                                
                            case Repeat:
                                ways = com.repeat_func(ways);
                                break;
                                
                            case Do:
                                ways = com.do_func(ways);
                                break;
                                
                            case While:
                                ways = com.while_func(ways);
                                break;
                        }
                    }
                    else
                    {
                        cout << "\nВы ввели неверную команду.\n";
                        ways.lose++;
                        
                    }
                }
                
                err.not_map(ways);
                err.not_end(ways);
                
                if (ways.lose != 0)
                {
                    number--;
                    restart(number, position);
                }
                else if (number != 7)
                {
                    cout << "\nОтлично, продолжайте в том же духе!\n";
                }
                cout << "\n";
            }
            ifs.close();
            
            cout << "Поздравляем, вы прошли все уровни!\n";
            break;
            
        case 2:
            rules();
            cin >> e;
            if (e == 0)
            {
                cout << "\n";
                exit(main());
            }
            break;
            
        case 3:
            exit(0);
            break;
            
        default:
            cout<<"Такого пункта не существует, попробуйте снова.\n\n";
            exit(main());
            break;
            
    }
    
    
    return 0;
}