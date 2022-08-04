package com.miroslav.simpleGymMemberManage.dateBase;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;

import com.miroslav.simpleGymMemberManage.actors.Client;

import java.util.ArrayList;

public class ClientSqlQuery extends GymSqlQuery implements GymSqlQueryInterface {



    @Override
    public <T> ArrayList<T> readAllData() {

        SQLiteDatabase db = super.gymDbHelper.getReadableDatabase();

        //define a projection that specifies which column from database
        // you will actually select use after this query
//        String [] projection={
//
//                GymContract.ClientEntry.COLUMN_NAME_CLIENT_ID,//BaseColumns._ID,
//                GymContract.ClientEntry.COLUMN_NAME_CLIENT_NAME,
//                GymContract.ClientEntry.COLUMN_NAME_CLIENT_CARD_ID
//
//
//        };

        //Filter results where "id" = 1
//        String selection = GymContract.ClientEntry.COLUMN_NAME_CLIENT_ID+ "= ? or client_id = ?";
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
            clientArrayList.add(new Client(itemId,name,cardId));


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


        return (ArrayList<T>) clientArrayList;


    }

    /**
     * This function inserts client into data base
     *
     * @param value client name
     * @see GymSqlQueryInterface#insertData(T)
     */
    @Override
    public <T> void insertData(T value) {


        SQLiteDatabase db = super.gymDbHelper.getWritableDatabase();

        // create a new map of values , where column names are the keys
        ContentValues values = new ContentValues();
        values.put(GymContract.ClientEntry.COLUMN_NAME_CLIENT_NAME,(String) value);


        long newRowId = db.insert(GymContract.ClientEntry.TABLE_NAME,null,values);
        if(newRowId!=-1){
            Log.d("DataBase","inserted rowId= "+ newRowId);
        }else {
            Log.d("DataBase","insertion error = " +newRowId);
        }
        db.close();



    }

    @Override
    public Integer getCountOfAllElements() {
        Integer count;
        SQLiteDatabase db = super.gymDbHelper.getReadableDatabase();
        Cursor cursor = db.rawQuery("select count(client_id) from client;",new String[]{});
        cursor.moveToNext();
        count = cursor.getInt(0);

        Log.d("MyGymMem","Member count= "+count);

        return count;


    }


    public Client getClientFromDataBase(Integer clientId) {
        SQLiteDatabase database = super.gymDbHelper.getReadableDatabase();
        Cursor cursor = database.rawQuery("select * from client where client_id= " + clientId + ";", new String[]{});

        if (cursor.moveToNext()) {
            Integer clientIndex = cursor.getInt(cursor.getColumnIndexOrThrow("client_id"));
            String clientName = cursor.getString(cursor.getColumnIndexOrThrow("client_name"));
            Integer clientCardIndex = cursor.getInt(cursor.getColumnIndexOrThrow("client_card_id"));
//            Log.d("MyGym",clientIndex+" "+clientName+" "+clientCardIndex);

            return new Client(clientIndex, clientName, clientCardIndex);
//            Log.d("MyGym",c.toString());
        } else {
            return null;
        }


    }
}



















































