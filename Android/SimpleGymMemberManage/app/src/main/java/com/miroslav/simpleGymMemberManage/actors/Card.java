package com.miroslav.simpleGymMemberManage.actors;

import java.util.Date;

public class Card {
    Integer card_id;
    Integer card_client_id;
    Date card_date_from;
    Date card_date_end;
    Boolean is_card_active;
    Integer card_price;
    Integer card_days;

    /**
     * Constructor with parameters
     * <p>
     * Initialize the card actor
     * @param card_id integer identification
     * @param card_client_id client identity
     * @param card_date_from the date when card is created
     * @param card_date_end the date when card ends
     * @param is_card_active true or false if card is
     * 						 between  card_date_actuve  or card_and_end
     * @param card_price card price integer
     * @param card_days card days integer
     * @see Date
     * @see #setCard_client_id(Integer)
     */


    public Card(Integer card_id, Integer card_client_id, Date card_date_from, Date card_date_end,
                Boolean is_card_active, Integer card_price, Integer card_days) {
        super();
        this.card_id = card_id;
        this.card_client_id = card_client_id;
        this.card_date_from = card_date_from;
        this.card_date_end = new Date(this.card_date_from.getYear(),this.card_date_from.getMonth(),this.card_date_from.getDate()+31);
        this.is_card_active = is_card_active;
        this.card_price = card_price;
        this.card_days = card_days;
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
    public Boolean getIs_card_active() {
        return is_card_active;
    }
    public void setIs_card_active(Boolean is_card_active) {
        this.is_card_active = is_card_active;
    }
    public Integer getCard_price() {
        return card_price;
    }
    public void setCard_price(Integer card_price) {
        this.card_price = card_price;
    }
    public Integer getCard_days() {
        return card_days;
    }
    public void setCard_days(Integer card_days) {
        this.card_days = card_days;
    }
    @Override
    public String toString() {
//        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd");
//
//        String stringDateFrom = simpleDateFormat.format(card_date_from);
//        String stringDateEnd = simpleDateFormat.format(card_date_end);

        return "Card [card_id=" + card_id + ", card_client_id=" + card_client_id + ", card_date_from=" + this.getCard_date_from()
                + ", card_date_end=" + this.getCard_date_end() + ", is_card_active=" + is_card_active + ", card_price="
                + card_price + ", card_days=" + card_days + "]";
    }
}






















