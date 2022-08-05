package com.miroslav.simpleGymMemberManage.actors;

import android.util.Log;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;

public class Card {
    int card_id;
    int card_client_id;
    Date card_date_from;
    Date card_date_end;
    boolean card_active;
    int card_price;
    int card_day;


    public Card(){}

    public Card(Date date){
        super();
        card_date_from= date;
        this.card_date_end = new Date(this.card_date_from.getYear(),this.card_date_from.getMonth(),this.card_date_from.getDate()+31);
    }

    public Card(int card_id, int card_client_id , int card_active , String dateFrom , String dateEnd,int card_price,int card_day){
        setCard_id(card_id);
        setCard_client_id(card_client_id);
        setCard_day(card_day);
        setCard_price(card_price);
//        String cardInfo = card_id + " "+ card_client_id + " " + card_active + " " + dateFrom
//                +" "+dateEnd+" "+card_day+" "+ card_price;
//        Log.d("MyGym","Constructor Card!!!!:  "+cardInfo);
//        Log.d("MyGym","Constructor Card!!!!:  "+dateFrom);
//        Log.d("MyGym","Constructor Card!!!!:  "+dateEnd);

        String[] dateFromSplit = getDateSplit(dateFrom);
        String[] dateEndSplit = getDateSplit(dateEnd);

        ArrayList<Integer> dateFromIntList = new ArrayList<>();
        ArrayList<Integer> dateEndIntList = new ArrayList<>();

        for(int i=0;i<dateFromSplit.length;i++){
             dateFromIntList.add(Integer.parseInt(dateFromSplit[i]));
             dateEndIntList.add(Integer.parseInt(dateEndSplit[i]));
        }
        this.setCard_date_from((new Date(dateFromIntList.get(0)-1900,dateFromIntList.get(1),dateFromIntList.get(2))));
        this.setCard_date_end((new Date(dateEndIntList.get(0)-1900,dateEndIntList.get(1),dateEndIntList.get(2))));

        if(card_active==1){
            this.setCard_active(true);
        }else{
            this.setCard_active(false);
        }




    }



    String [] getDateSplit(String date){
        return date.split("-");

    }



    public int getCard_id() {
        return card_id;
    }
    public void setCard_id(int card_id) {
        this.card_id = card_id;
    }
    public int getCard_client_id() {
        return card_client_id;
    }
    public void setCard_client_id(int card_client_id) {
        this.card_client_id = card_client_id;
    }
    public Date getCard_date_from() {
        return card_date_from;
    }
    public void setCard_date_from(Date card_date_from) {
        this.card_date_from = card_date_from;
    }
    public Date getCard_date_end() {
        return card_date_end;
    }
    public void setCard_date_end(Date card_date_end) {
        this.card_date_end = card_date_end;
    }
    public Boolean getCard_active() {
        return card_active;
    }
    public void setCard_active(Boolean card_active) {
        this.card_active = card_active;
    }
    public int getCard_price() {
        return card_price;
    }
    public String getCardPriceAsString(){return ""+this.card_price;}
    public void setCard_price(int card_price) {
        this.card_price = card_price;
    }
    public int getCard_day() {
        return card_day;
    }
    public void setCard_day(int card_day) {
        this.card_day = card_day;
    }

    public void setCardActive(String value){

        if(Integer.parseInt(value)==1){
            Log.d("MyGym","value == 1");
            this.card_active=true;
        }else{
            this.card_active=false;
        }
    }
    public String getStringDateFromDateFromSimpleDateFormatterForDataBinding(){
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd");

        return "From "+simpleDateFormat.format(getCard_date_from());
    }

    public String getStringDateFrom(){
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd");

        return simpleDateFormat.format(getCard_date_from());
    }

    public String getStringDateEnd(){
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd");

        return simpleDateFormat.format(getCard_date_end());
    }



    public String getStringDateEndDateFromSimpleDateFormatterForDataBinding(){
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd");

        return "End "+simpleDateFormat.format(getCard_date_end());
    }

    public boolean isCardActive(){
        return this.getCard_date_end().after(new Date());



    }

    @Override
    public String toString() {
//        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd");
//
//        String stringDateFrom = simpleDateFormat.format(card_date_from);
//        String stringDateEnd = simpleDateFormat.format(card_date_end);

        return "cardID: " + card_id + ", clientID: " + card_client_id + ", " + this.getStringDateFrom()
                + " " + this.getStringDateEnd() + ", active: " + card_active + ", price:"
                + card_price + ", days: " + card_day ;
    }
}






















