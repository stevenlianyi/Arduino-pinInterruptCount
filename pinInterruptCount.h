/*
  pinInterruptCount.h

  modified on 2018/07/18 by Steven Lian steven.lian@gmail.com
  用于检测某个pin的电位变化，并计数。
  利用中断记录，中断方式可以是：上升沿，下降沿，变化和 低电平等
  ---
  Copyright (C) 2018  Steven Lian (steven.lian@gmail.com)    

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
 
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.
 
  You should have received a copy of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.

  */

#pragma once
#ifndef _pinInterruptCount_H
#define _pinInterruptCount_H


#include <Arduino.h>

//ClASS BEGIN

class pinInterruptCount
{
  public:
    //data

    short statChangeCount; //状态变换指示器,这个是说本机状态改变
    uint8_t currStat; //当前pin状态

    //device current status

    //function
    pinInterruptCount();
    bool begin(uint8_t pin);
    bool begin(uint8_t pin,short mode);
    short readCount();
    uint8_t readStat();
    short clean();

    //功能调用

    //test only

  private:
    //data
    //uint8_t _pin;
    short _mode;
};

//class end


#endif // _pinInterruptCount_H

