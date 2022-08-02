package com.miroslav.simpleGymMemberManage.dateBase;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;

import com.miroslav.simpleGymMemberManage.actors.Client;
import com.miroslav.simpleGymMemberManage.fragments.ClientsFragment;

import java.util.ArrayList;
import java.util.List;

/**
 * this class is used to open or create gymMemberDataBase.db
 * end execute queries
 */

public class GymSqlQuery {

    GymDbHelper gymDbHelper;

    public void setGymDbHelper(Context appContext){}
    public GymDbHelper getGymDbHelper(){return this.gymDbHelper;}


    public GymSqlQuery(){}

    public void createDataBase(Context appContext, Integer defaultCardPrice){
        //read from database and create
        gymDbHelper = new GymDbHelper(appContext,defaultCardPrice);
    }

    public void openDataBase(Context appContext){
            gymDbHelper = new GymDbHelper(appContext);
    }
    public void closeGymDbHelper(){
        this.gymDbHelper.close();
    }



}


























