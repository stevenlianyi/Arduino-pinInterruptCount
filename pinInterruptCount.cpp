#include "pinInterruptCount.h"

/*
  modified on 2018/07/18 by Steven Lian steven.lian@gmail.com
  用于检测某个pin的电位变化，并计数。
  利用中断记录，中断方式可以是：上升沿，下降沿，变化和 低电平等
  
*/

static uint8_t _local_pin_number;
static uint8_t _local_pin_stat;
static uint8_t _local_pin_count;

static void interrupt_process()
{
  _local_pin_stat = digitalRead(_local_pin_number);
  _local_pin_count ++;
}

pinInterruptCount::pinInterruptCount()
{
}


bool pinInterruptCount::begin(uint8_t pin)
{
  return begin(pin,CHANGE);
  
}


bool pinInterruptCount::begin(uint8_t pin,short mode)
{
  _local_pin_number = pin;
  if ((mode != LOW ) && (mode != CHANGE) && (mode != RISING ) && (mode != FALLING ) )
    _mode = CHANGE;
  else
    _mode = mode;
  
  pinMode(_local_pin_number,INPUT);

  //Enable中断管脚, 中断服务程序为onChange(), 监视引脚变化
  attachInterrupt(digitalPinToInterrupt(_local_pin_number), interrupt_process, mode);
  return true;
}


uint8_t pinInterruptCount::readStat()
{
  currStat = _local_pin_stat;
  return currStat;
}


short pinInterruptCount::readCount()
{
  statChangeCount = _local_pin_count;
  _local_pin_count = 0;
  return statChangeCount;
}


short pinInterruptCount::clean()
{
  _local_pin_stat = 0;
  statChangeCount = 0;  
}

