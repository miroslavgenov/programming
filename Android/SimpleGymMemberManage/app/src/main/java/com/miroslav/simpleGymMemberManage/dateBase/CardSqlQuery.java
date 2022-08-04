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
        card.setCard_day(31);

        SQLiteDatabase db = super.gymDbHelper.getWritableDatabase();

        ContentValues contentValues = new ContentValues();
        contentValues.put("card_date_from",card.getStringDateFrom());
        contentValues.put("card_date_end",card.getStringDateEnd());
        contentValues.put("card_client_id",card.getCard_client_id());
        contentValues.put("card_active",1);
        contentValues.put("card_day",card.getCard_day());
        contentValues.put("card_price",card.getCard_price());







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

    public ArrayList<Card> getAllActiveCardsFromDataBase(){
        SQLiteDatabase db = super.gymDbHelper.getReadableDatabase();
        ArrayList<Card> cardArrayList = new ArrayList<>();
        Cursor cursor = db.rawQuery("select * from card where card_active=1;",new String[]{});

        while(cursor.moveToNext()){
            Integer card_id = cursor.getInt(cursor.getColumnIndexOrThrow("card_id"));
            Integer card_client_id = cursor.getInt(cursor.getColumnIndexOrThrow("card_client_id"));
            String card_date_from = cursor.getString(cursor.getColumnIndexOrThrow("card_date_from"));
            String card_date_end = cursor.getString(cursor.getColumnIndexOrThrow("card_date_end"));
            String card_active =  cursor.getString(cursor.getColumnIndexOrThrow("card_active"));
            Integer card_price = cursor.getInt(cursor.getColumnIndexOrThrow("card_price"));
            Integer card_day = cursor.getInt(cursor.getColumnIndexOrThrow("card_day"));

            Log.d("MyGym",card_active);

            ArrayList<String> arrayListDateElement  = new ArrayList<String>(
                    Arrays.asList(card_date_from.split("-"))
            );
            Log.d("MyGym",arrayListDateElement.get(0)+" "+arrayListDateElement.get(1)+" "+ arrayListDateElement.get(2));

            Card card = new Card(new Date(
                    Integer.parseInt(arrayListDateElement.get(0))-1900,
                   Integer.parseInt(arrayListDateElement.get(1)),
                   Integer.parseInt(arrayListDateElement.get(2)))
            );
            card.setCard_id(card_id);
            card.setCard_client_id(card_client_id);
            card.setCardActive(card_active);
            cardArrayList.add(card);




//            Log.d("MyGym","cardID: "+  card_id +"  clientID: "+card_client_id+"  cardDateFrom: "+card_date_from+" cardDateEnd: "+card_date_end+
//                     " cardActive: "+card_active+" cardPrice: "+card_price+" cardDay: "+card_day);
//            cardArrayList.add(new Card(
//                    card_id,card_client_id,card_date_from,card_date_end,
//                    card_active,card_price,card_date_end
//            ));

        }
//        for(int i=0;i<cardArrayList.size();i++){
//            Log.d("MyGym",cardArrayList.get(i).toString());
//        }
//        if(cursor.getPosition()==0){
//            return null;
//        }

        return cardArrayList;

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

































































