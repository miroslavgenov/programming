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



//    void insertData() {
        // inserting data in dataBase
        //get the data repository in write mode
//        SQLiteDatabase db = gymDbHelper.getWritableDatabase();
//
//        // create a new map of values , where column names are the keys
//        ContentValues values = new ContentValues();
//        values.put(GymContract.ClientEntry.COLUMN_NAME_CLIENT_NAME,clientName);
//
//
//        long newRowId = db.insert(GymContract.ClientEntry.TABLE_NAME,null,values);
//        if(newRowId!=-1){
//            Log.d("DataBase","inserted rowId= "+ newRowId);
//        }else {
//            Log.d("DataBase","insertion error = " +newRowId);
//        }
//        db.close();
//    }


}





























































