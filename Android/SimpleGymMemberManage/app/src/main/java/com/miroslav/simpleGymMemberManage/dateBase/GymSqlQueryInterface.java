package com.miroslav.simpleGymMemberManage.dateBase;

import java.util.ArrayList;

//change GymSqlQueryInterface to GymSqlQueryImp

public interface GymSqlQueryInterface {
    <T> ArrayList<T> readAllData();
    <T>void insertData(T value);
    Integer getCountOfAllElements();

}





























































