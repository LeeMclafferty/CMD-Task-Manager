/*
*** Task Manager Project ***

A command-line task manager built to strengthen my C++ fundamentals. This project 
focuses on core concepts like file I/O, STL containers, and exception handling. It 
allows users to add, complete, delete, and save tasks, combining practical features with 
clean, efficient code.
*/

#include <iostream>
#include "Source/TaskManagerUI.h"

int main()
{
    task_manager_UI ui;

    while (true)
    {
        ui.render();
    }
}
