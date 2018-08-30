/*******************************************************************************
* Filename  	: mytask.cpp
* 
* Details   	: Implementation of Execute() of MyTask class
*
* Author        : Sergey Kolody
*******************************************************************************/
#include "mytask.hpp"
#include "../Rtos/wrapper/thread.hpp"
#include "../CMSIS/stm32f411xe.h"
#include "../Rtos/wrapper/mailbox.hpp"
#include "../Rtos/wrapper/event.hpp"
#include "../Application/leds.hpp"

extern OsWrapper::MailBox<int, 10> queue;
extern OsWrapper::Event event;

void MyTask::Execute()
{ 
  while(true) 
  {
    using OsWrapper::operator""ms ;
    if (event.Wait() != 0)
    {
      Led2::GetInstance().Toggle();
    }
  }
} ;