package com.miroslav.simpleGymMemberManage.dateBase;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;

import com.miroslav.simpleGymMemberManage.actors.Card;
import com.miroslav.simpleGymMemberManage.actors.Client;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;

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

        SQLiteDatabase db = super.gymDbHelper.getWritableDatabase();

        ContentValues contentValues = new ContentValues();
        contentValues.put("card_date_from",card.getStringDateFrom());
        contentValues.put("card_date_end",card.getStringDateEnd());
        contentValues.put("card_client_id",card.getCard_client_id());
        contentValues.put("card_active",1);
        contentValues.put("card_day",card.getCard_day());
        contentValues.put("card_price",card.getCard_price());

        long newRowIdOfNewCard = db.insert(GymContract.CardEntry.TABLE_NAME,null,contentValues);




        // UPDATE client_card_id data
        String selection = GymContract.ClientEntry.COLUMN_NAME_CLIENT_ID+"= ?";
        String [] selectionArg={String.valueOf(client.getClient_id())};

        ContentValues clientNewCardIdValue=new ContentValues();
        clientNewCardIdValue.put("client_card_id",newRowIdOfNewCard);


        int rowAffected = db.update(GymContract.ClientEntry.TABLE_NAME,
                clientNewCardIdValue,
                selection,
                selectionArg);

        if(newRowIdOfNewCard!=-1){
            Log.d("MyGym","inserted rowId= "+ newRowIdOfNewCard);
        }else {
            Log.d("MyGym","insertion error = " +newRowIdOfNewCard);
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

    public ArrayList<Card> getAllActiveCardsFromDataBase(){
        SQLiteDatabase db = super.gymDbHelper.getReadableDatabase();
        String[] projection ={
                "card_id","card_client_id","card_active","card_date_from",
                "card_date_end","card_price","card_day"
        };

        String selection = "card_active= ?";
        String []selectionArg={"1"};

        Cursor cursor = db.query(
          "card",
          projection,
          selection,
                selectionArg,
                null,null,null

        );

        ArrayList<Card> items = new ArrayList<>();
        Log.d("MyGym","is itemEmpty: "+items.isEmpty());
        while (cursor.moveToNext()){

            int cardId = cursor.getInt(0);
            int cardClientId = cursor.getInt(1);
            int cardActive = cursor.getInt(2);
            String cardDateFrom = cursor.getString(3);
            String cardDateEnd = cursor.getString(4);
            int cardPrice = cursor.getInt(5);
            int cardDay = cursor.getInt(6);

            String cardInfo = cardId + " "+ cardClientId + " " + cardActive + " " + cardDateFrom
                    +" "+cardDateEnd+" "+cardDay+" "+ cardPrice;
            Log.d("MyGym",cardInfo);
            Log.d("MyGym",cardDateEnd);

            Card c = new Card(cardId,cardClientId,cardActive,cardDateFrom,cardDateEnd,cardPrice,cardDay);
            Log.d("MyGymCard",c.toString());
            items.add(c);
        }

        db.close();

        if(items.isEmpty()){
            return null;
        }
        Log.d("MyGym","Size of arr Card: "+items.size());
        return items;

    }

    public void updateCardActiveToInActive(Card card){
        SQLiteDatabase db = super.gymDbHelper.getWritableDatabase();

        String newValue = "0";
        ContentValues contentValues = new ContentValues();
        contentValues.put("card_active",newValue);

            String selection = "card_id = ?";
            String[] selectionArg = {String.valueOf(card.getCard_id())};
            db.update("card",contentValues,selection,selectionArg);

        db.close();


    }


    @Override
    public Integer getCountOfAllElements() {
        SQLiteDatabase db = super.gymDbHelper.getReadableDatabase();
        Cursor cursor = db.rawQuery("select count(card_id) from card;",new String []{});
        cursor.moveToNext();
        Integer value = cursor.getInt(0);
        db.close();
        return value;

        
    }
}

































































