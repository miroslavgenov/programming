package com.miroslav.simpleGymMemberManage.dateBase;


import android.content.Context;



/**
 * this class is used to open or create gymMemberDataBase.db
 * end execute queries
 */

public class GymSqlQuery {

    GymDbHelper gymDbHelper;

    public void setGymDbHelper(Context appContext){}
    public GymDbHelper getGymDbHelper(){return this.gymDbHelper;}


    public GymSqlQuery(){}


    //TODO change createDataBase and openDataBase to createOrOpenDataBase(Context appContext,Integer defaultCardPrice)
    // if default card price is not null then create the database else open the database
    // and place it in the constructor

    /**
     *
     * @param appContext
     * @param userPassword default card price from setDefaultActivity
     */
    public void createDataBaseWithDefaultUserPassword(Context appContext, String userPassword){
        //read from database and create
        gymDbHelper = new GymDbHelper(appContext,userPassword);
    }

    public void openDataBaseWithPassword(Context appContext, String password){
            gymDbHelper = new GymDbHelper(appContext,password);
    }


    public void closeGymDbHelper(){
        if(gymDbHelper!=null){
            this.gymDbHelper.close();
        }
    }



}


























