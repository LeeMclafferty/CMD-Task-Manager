/*
*** Task Manager Project ***

A command-line task manager built to strengthen my C++ fundamentals. This project 
focuses on core concepts like file I/O, STL containers, and exception handling. It 
allows users to add, complete, delete, and save tasks, combining practical features with 
clean, efficient code.
*/

#include <iostream>
#include<memory>
#include "Source/TaskManagerUI.h"

int main()
{
    std::shared_ptr<task_manager_UI> ui = std::make_shared<task_manager_UI>();
    ui->post_construct();

    while (true)
    {
        ui->render();
    }
}
