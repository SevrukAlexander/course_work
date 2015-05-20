//
//  menu.h
//  TrackGame
//
//  Created by Александр Севрук on 03.05.15.
//  Copyright (c) 2015 Александр Севрук. All rights reserved.
//

#ifndef TrackGame_menu_h
#define TrackGame_menu_h

#include <iostream>

int menu()
{
    cout << "Меню игры\n\n";
    cout << "1.Начать игру\n";
    cout << "2.Правила игры\n";
    cout << "3.Выход\n\n";
    
    int choice;
    cin >> choice;
    cout << "\n";
    
    return choice;
}

#endif
