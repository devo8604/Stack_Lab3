//
//  GuestList.h
//  Stack_Lab3
//
//  Created by Devon Smith on 7/21/14.
//  Copyright (c) 2014 Devon Smith. All rights reserved.
//

#ifndef __Stack_Lab3__GuestList__
#define __Stack_Lab3__GuestList__

#include <iostream>

class GuestList
{
public:
    GuestList(std::string name, std::string sex, int salesAmount);
    std::string getName();
    std::string getSex();
    int getSalesAmount();
    
private:
    //Variables
    std::string name;
    std::string sex;
    int salesAmount;
    
    void setName(std::string input);
    void setSex(std::string input);
    void setSalesAmount(int input);
};
    


#endif /* defined(__Stack_Lab3__GuestList__) */
