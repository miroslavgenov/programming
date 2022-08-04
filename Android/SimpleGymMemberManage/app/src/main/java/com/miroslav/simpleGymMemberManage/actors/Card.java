package com.miroslav.simpleGymMemberManage.actors;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Card {
    Integer card_id;
    Integer card_client_id;
    Date card_date_from;
    Date card_date_end;
    Boolean card_active;
    Integer card_price;
    Integer card_days;




    public Card(Date date){
        super();
        card_date_from= date;
        this.card_date_end = new Date(this.card_date_from.getYear(),this.card_date_from.getMonth(),this.card_date_from.getDate()+31);
    }



    public Integer getCard_id() {
        return card_id;
    }
    public void setCard_id(Integer card_id) {
        this.card_id = card_id;
    }
    public Integer getCard_client_id() {
        return card_client_id;
    }
    public void setCard_client_id(Integer card_client_id) {
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
    public Integer getCard_price() {
        return card_price;
    }
    public String getCardPriceAsString(){return "Price "+this.card_price;}
    public void setCard_price(Integer card_price) {
        this.card_price = card_price;
    }
    public Integer getCard_days() {
        return card_days;
    }
    public void setCard_days(Integer card_days) {
        this.card_days = card_days;
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

        return "From "+simpleDateFormat.format(getCard_date_end());
    }



    public String getStringDateEndDateFromSimpleDateFormatterForDataBinding(){
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd");

        return "End "+simpleDateFormat.format(getCard_date_end());
    }

    @Override
    public String toString() {
//        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd");
//
//        String stringDateFrom = simpleDateFormat.format(card_date_from);
//        String stringDateEnd = simpleDateFormat.format(card_date_end);

        return "Card [card_id=" + card_id + ", card_client_id=" + card_client_id + ", card_date_from=" + this.getCard_date_from()
                + ", card_date_end=" + this.getCard_date_end() + ", is_card_active=" + card_active + ", card_price="
                + card_price + ", card_days=" + card_days + "]";
    }
}






















