package com.miroslav.simpleGymMemberManage.dateBase;

import android.content.ContentValues;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;

import com.miroslav.simpleGymMemberManage.actors.Card;
import com.miroslav.simpleGymMemberManage.actors.Client;

import java.net.ConnectException;
import java.util.ArrayList;

public class CardSqlQuery extends GymSqlQuery implements GymSqlQueryInterface{
    class CardSqlQueryException extends Exception{

        public CardSqlQueryException(String message){
            super(message);
        }

    }
    @Override
    public <T> ArrayList<T> readAllData() {
        return null;
    }


    public void insertCardToDataBaseAndUpdateClientCardId(Card card,Client client){
        Log.d("MyGym",card.toString()+"\n"+client.toString());

        card.setCard_client_id(client.getClient_id());
        card.setCard_days(31);

        SQLiteDatabase db = super.gymDbHelper.getWritableDatabase();

        ContentValues contentValues = new ContentValues();
        contentValues.put("card_date_from",card.getStringDateFrom());
        contentValues.put("card_date_end",card.getStringDateEnd());
        contentValues.put("card_client_id",card.getCard_client_id());
        contentValues.put("card_active",true);






        long newRowId = db.insert(GymContract.CardEntry.TABLE_NAME,null,contentValues);


        // update client data
        String selection = GymContract.ClientEntry.COLUMN_NAME_CLIENT_ID+"= ?";
        String [] selectionArg={String.valueOf(client.getClient_id())};

        ContentValues clientCardIdValue=new ContentValues();
        clientCardIdValue.put("client_card_id",newRowId);


        int rowAffected = db.update(GymContract.ClientEntry.TABLE_NAME,
                clientCardIdValue,
                selection,
                selectionArg);

        if(newRowId!=-1){
            Log.d("MyGym","inserted rowId= "+ newRowId);
        }else {
            Log.d("MyGym","insertion error = " +newRowId);
        }


        db.close();

    }

    @Override
    public <T> void insertData(T value) {




        //        SQLiteDatabase db = super.gymDbHelper.getWritableDatabase();

        // create a new map of values , where column names are the keys
//        ContentValues values = new ContentValues();
//        values.put(GymContract.ClientEntry.COLUMN_NAME_CLIENT_NAME,(String) value);


//        long newRowId = db.insert(GymContract.ClientEntry.TABLE_NAME,null,values);
//        if(newRowId!=-1){
//            Log.d("DataBase","inserted rowId= "+ newRowId);
//        }else {
//            Log.d("DataBase","insertion error = " +newRowId);
//        }
//        db.close();
    }


    @Override
    public Integer getCountOfAllElements() {
        return null;
    }
}

































































