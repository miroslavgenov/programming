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

    public ArrayList<Client> readAllClients() {
        SQLiteDatabase db = gymDbHelper.getReadableDatabase();

        //define a projection that specifies which column from database
        // you will actually select use after this query
        String [] projection={

                GymContract.ClientEntry.COLUMN_NAME_CLIENT_ID,//BaseColumns._ID,
                GymContract.ClientEntry.COLUMN_NAME_CLIENT_NAME,
                GymContract.ClientEntry.COLUMN_NAME_CLIENT_CARD_ID


        };

        //Filter results where "id" = 1
//        String selection = GymContract.ClientEntry.COLUMN_NAME_CLIENT_ID+ "= ? or client_id = ?";
        String selection = GymContract.ClientEntry.COLUMN_NAME_CLIENT_ID+" ";
//        String [] selectionArgs = {"1","2"};

        //how do you want the result to be sorted
//        String sortOrder = ClientContract.ClientEntry.COLUMN_NAME_CLIENT_ID+" DESC";

//        Cursor cursor = db.query(
//                ClientContract.ClientEntry.TABLE_NAME,
//                projection,
//                selection,
//                selectionArgs,
//                null,null,
//                sortOrder
//                );
        Cursor cursor = db.rawQuery("select * from client;",new String[]{});

//        List itemIds = new ArrayList<>();
        ArrayList<Client> clientArrayList = new ArrayList<>();

        while(cursor.moveToNext()){
            int itemId = cursor.getInt(
                    cursor.getColumnIndexOrThrow(GymContract.ClientEntry.COLUMN_NAME_CLIENT_ID)
            );
            String name = cursor.getString(
                    cursor.getColumnIndexOrThrow(GymContract.ClientEntry.COLUMN_NAME_CLIENT_NAME)
            );
            int cardId = cursor.getInt(
                    cursor.getColumnIndexOrThrow(GymContract.ClientEntry.COLUMN_NAME_CLIENT_CARD_ID)
            );
            clientArrayList.add(new Client(itemId,name,cardId==0?null:cardId));


//            itemIds.add(name);
//            itemIds.add(itemId);

        }
        Integer cursorPosition = cursor.getPosition();
        if(cursorPosition==0){
            return null;
        }
//        else{
//            Log.d("DataBase","Cursor position is: "+cursorPosition);
//        }
        cursor.close();
        db.close();

//        for(int i=0;i<itemIds.size();i++){
//            Log.d("DataBaseItems",itemIds.get(i).toString());
//        }


    return clientArrayList;

    }


    public void insertData(String clientName) {
        // inserting data in dataBase
        //get the data repository in write mode
        SQLiteDatabase db = gymDbHelper.getWritableDatabase();

        // create a new map of values , where column names are the keys
        ContentValues values = new ContentValues();
        values.put(GymContract.ClientEntry.COLUMN_NAME_CLIENT_NAME,clientName);


        long newRowId = db.insert(GymContract.ClientEntry.TABLE_NAME,null,values);
        if(newRowId!=-1){
            Log.d("DataBase","inserted rowId= "+ newRowId);
        }else {
            Log.d("DataBase","insertion error = " +newRowId);
        }
        db.close();
    }

}


























