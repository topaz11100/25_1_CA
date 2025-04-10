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

template<class T>
void print(T& v)
{
    for (auto& c : v)
    {
        cout << c << " ";
    }
    cout << endl;
}

template<class T>
void print_doubled(T& v)
{
    for (auto& a : v)
    {
        print(a);
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