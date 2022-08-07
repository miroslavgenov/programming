package com.miroslav.simpleGymMemberManage.dateBase;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;


public class GymDbHelper extends SQLiteOpenHelper {
    public static final int DATABASE_VERSION =1;
    public static final String DATABASE_NAME ="gymMemberManage.db";
    public Integer defaultCardPrice;


    public GymDbHelper(Context appContext) {
        super(appContext, DATABASE_NAME, null, DATABASE_VERSION);
    }

    public GymDbHelper(Context appContext,Integer defaultCardPrice) {
        super(appContext, DATABASE_NAME, null, DATABASE_VERSION);
        this.defaultCardPrice=defaultCardPrice;
    }

    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        sqLiteDatabase.execSQL(GymContract.ClientEntry.SQL_CREATE_ENTRIES);
        sqLiteDatabase.execSQL(GymContract.CardEntry.getSqlCreateEntries(defaultCardPrice));
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
        sqLiteDatabase.execSQL(GymContract.ClientEntry.SQL_DELETE_ENTRIES);
        sqLiteDatabase.execSQL(GymContract.CardEntry.SQL_DELETE_ENTRIES);

        this.onCreate(sqLiteDatabase);
    }

    @Override
    public void onDowngrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        this.onUpgrade(db, oldVersion, newVersion);
    }
}






















