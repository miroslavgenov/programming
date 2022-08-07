package com.miroslav.simpleGymMemberManage.dateBase;

import android.content.Context;

import net.zetetic.database.DatabaseErrorHandler;
import net.zetetic.database.sqlcipher.SQLiteDatabase;
import net.zetetic.database.sqlcipher.SQLiteOpenHelper;


public class GymDbHelper extends SQLiteOpenHelper {
    public static final int DATABASE_VERSION =1;
    public static final String DATABASE_NAME ="gymMemberManage.db";
    public String defaultUserPassword;

    public GymDbHelper(Context appContext) {
        super(appContext, DATABASE_NAME, null, DATABASE_VERSION);
    }

    public GymDbHelper(Context appContext,String defaultUserPassword) {
//        super(appContext, DATABASE_NAME, null, DATABASE_VERSION);
        super(appContext, DATABASE_NAME, defaultUserPassword, null,
                DATABASE_VERSION, 0,
                null, null,
                true);
        this.defaultUserPassword =defaultUserPassword;
    }

    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        sqLiteDatabase.execSQL(GymContract.ClientEntry.SQL_CREATE_ENTRIES);
        sqLiteDatabase.execSQL(GymContract.CardEntry.getSqlCreateEntries());
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
        sqLiteDatabase.execSQL(GymContract.ClientEntry.SQL_DELETE_ENTRIES);
<<<<<<< HEAD
        sqLiteDatabase.execSQL(GymContract.CardEntry.SQL_DELETE_ENTRIES);

=======
        sqLiteDatabase.execSQL(GymContract.CardEntry.getSqlCreateEntries());
>>>>>>> encrypt
        this.onCreate(sqLiteDatabase);
    }

    @Override
    public void onDowngrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        this.onUpgrade(db, oldVersion, newVersion);
    }
}






















