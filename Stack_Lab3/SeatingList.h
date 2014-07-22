//
//  SeatingList.h
//  Stack_Lab3
//
//  Created by Devon Smith on 7/21/14.
//  Copyright (c) 2014 Devon Smith. All rights reserved.
//

#ifndef __Stack_Lab3__SeatingList__
#define __Stack_Lab3__SeatingList__

#include "GuestList.h"
#include <iostream>
#include <vector>
#include <Stack>

class SeatingList
{
public:
    void guestListGenerator(std::vector<GuestList>& initialList);
    void stackBuilder(std::vector<GuestList>& initialList, std::stack<GuestList, std::vector<GuestList>>& leftSideOfTable, std::stack<GuestList, std::vector<GuestList>>& rightSideOfTable);
    void rightSideOfTableSorter(std::stack<GuestList, std::vector<GuestList>>& rightSideOfTable, std::stack<GuestList, std::vector<GuestList>>& rightSideOfTableSorted);
};



#endif /* defined(__Stack_Lab3__SeatingList__) */
