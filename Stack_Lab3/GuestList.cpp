//
//  GuestList.cpp
//  Stack_Lab3
//
//  Created by Devon Smith on 7/21/14.
//  Copyright (c) 2014 Devon Smith. All rights reserved.
//

#include "GuestList.h"

using namespace std;

string name;
string sex;
int salesAmount;

GuestList::GuestList(string name, string sex, int salesAmount)
{
    setName(name);
    setSex(sex);
    setSalesAmount(salesAmount);
}

string GuestList::getName()
{
    return name;
}

string GuestList::getSex()
{
    return sex;
}

int GuestList::getSalesAmount()
{
    return salesAmount;
}

void GuestList::setName(string input)
{
    name = input;
}

void GuestList::setSex(string input)
{
    sex = input;
}

void GuestList::setSalesAmount(int input)
{
    salesAmount = input;
}



