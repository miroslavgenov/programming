package com.miroslav.simpleGymMemberManage.dateBase;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;

import com.miroslav.simpleGymMemberManage.actors.Client;

import java.util.ArrayList;

public interface GymSqlQueryInterface {
    <T> ArrayList<T> readAllData();
    <T>void insertData(T value);
    Integer getCountOfAllElements();
}





























































