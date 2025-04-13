#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <bitset>

using namespace std;

//출력용 함수들

template<class T>
void print(T& v)
{
    for (auto& c : v)
    {
        cout << c << " ";
    }
}

template<class T>
void print_doubled(T& v)
{
    for (auto& a : v)
    {
        print(a);
        cout << endl;
    }
}

template<class T>
void print_map(T& l)
{
    for (auto& x : l)
    {
        cout << x.first << " " << x.second << endl;
    }
    cout << endl;
}