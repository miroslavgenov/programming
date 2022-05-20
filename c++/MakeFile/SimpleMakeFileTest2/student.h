#pragma once
#include <cstring>
#include <iostream>

class Student{
  private:
    
  public:
    char student_first_name[20];
    Student(){
      strcpy(student_first_name,"Ivan");
    }
    void show();
};















