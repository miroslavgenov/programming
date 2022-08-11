package com.miroslav.simpleGymMemberManage.dateBase;


import android.content.Context;



/**
 * this class is used to open or create gymMemberDataBase.db
 * end execute queries
 */

public class GymSqlQuery {

    GymDbHelper gymDbHelper;
    Context appContext;
    String userPassword;





    public Context getAppContext() {
        return appContext;
    }

    public void setAppContext(Context appContext) {
        this.appContext = appContext;
    }

    public String getUserPassword() {
        return userPassword;
    }

    public void setUserPassword(String userPassword) {
        this.userPassword = userPassword;
    }

    public void setGymDbHelper(Context appContext){}
    public GymDbHelper getGymDbHelper(){return this.gymDbHelper;}


    public GymSqlQuery(){}

    public  GymSqlQuery(Context appContext,String userPassword){
        this.setAppContext(appContext);
        this.setUserPassword(userPassword);
    }


    /**
     *
     * @param appContext
     * @param userPassword default card price from setDefaultActivity
     */
    public void createDataBaseWithDefaultUserPassword(Context appContext, String userPassword){
        //read from database and create
        gymDbHelper = new GymDbHelper(appContext,userPassword);
    }

    public void openDataBaseWithPassword(){
            gymDbHelper = new GymDbHelper(getAppContext(),getUserPassword());
    }


    public void closeGymDbHelper(){
        if(gymDbHelper!=null){
            this.gymDbHelper.close();
        }
    }



}


























