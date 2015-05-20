//
//  rules.h
//  TrackGame
//
//  Created by Александр Севрук on 03.05.15.
//  Copyright (c) 2015 Александр Севрук. All rights reserved.
//

#ifndef TrackGame_rules_h
#define TrackGame_rules_h

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void rules()
{
    ifstream ifs("rules.txt");
    if(ifs.is_open())
    {
        string s;
        s.assign((std::istreambuf_iterator<char>(ifs.rdbuf())), istreambuf_iterator<char>());
        cout << s;
        ifs.close();
    }
    else
        cerr << "Не удалось открыть файл." << endl;
}

#endif
