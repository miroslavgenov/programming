package com.miroslav.simpleGymMemberManage.dateBase;

import java.util.ArrayList;



public interface GymSqlQueryImp {
    <T> ArrayList<T> readAllData();
    <T>void insertData(T value);
    Integer getCountOfAllElements();

}





























































