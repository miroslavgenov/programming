#pragma once
#include <cstring>
#include <iostream>

class Student{
  private:
    char student_first_name[20];
  public:
    Student(){
      strcpy(student_first_name,"Ivan");
    }
    void show();
};















