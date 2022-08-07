package com.miroslav.simpleGymMemberManage.dateBase;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;

import com.miroslav.simpleGymMemberManage.actors.Card;
import com.miroslav.simpleGymMemberManage.actors.Client;

import java.util.ArrayList;

public class ClientSqlQuery extends GymSqlQuery implements GymSqlQueryInterface {



    @Override
    public <T> ArrayList<T> readAllData() {

        SQLiteDatabase db = super.gymDbHelper.getReadableDatabase();

        Cursor cursor = db.rawQuery("select * from client;",new String[]{});


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





        }
        Integer cursorPosition = cursor.getPosition();
        if(cursorPosition==0){
            return null;
        }



        cursor.close();
        db.close();






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


        ContentValues values = new ContentValues();
        values.put(GymContract.ClientEntry.COLUMN_NAME_CLIENT_NAME,(String) value);


        long newRowId = db.insert(GymContract.ClientEntry.TABLE_NAME,null,values);
        if(newRowId!=-1){

        }else {

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



        return count;


    }


    public Client getClientFromDataBase(Integer clientId) {
        SQLiteDatabase database = super.gymDbHelper.getReadableDatabase();
        Cursor cursor = database.rawQuery("select * from client where client_id= " + clientId + ";", new String[]{});

        if (cursor.moveToNext()) {
            int clientIndex = cursor.getInt(cursor.getColumnIndexOrThrow("client_id"));
            String clientName = cursor.getString(cursor.getColumnIndexOrThrow("client_name"));
            int clientCardIndex = cursor.getInt(cursor.getColumnIndexOrThrow("client_card_id"));


            return new Client(clientIndex, clientName, clientCardIndex);

        } else {
            return null;
        }


    }

    public void setClientCardIdToZero(Card card) {
        SQLiteDatabase db = super.gymDbHelper.getWritableDatabase();
        String selection = "client_id = ?";
        String[] selectionArg ={String.valueOf(card.getCard_client_id())};

        ContentValues newValues = new ContentValues();
        newValues.put("client_card_id",0);

        db.update(
                "client",
                newValues,selection,selectionArg
        );
        db.close();


    }
}



















































