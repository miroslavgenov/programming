package com.miroslav.simpleGymMemberManage.dateBase;

import android.provider.BaseColumns;



public final class GymContract {
    GymContract(){}

    public static final class ClientEntry implements BaseColumns {
        public static final String TABLE_NAME ="client";
        public static final String COLUMN_NAME_CLIENT_ID = "client_id";
        public static final String COLUMN_NAME_CLIENT_NAME= "client_name";
        public static final String COLUMN_NAME_CLIENT_CARD_ID= "client_card_id";

        public static final String SQL_CREATE_ENTRIES="" +
                "create table if not exists"+" client"+"(\n" +
                " client_id integer"+" not null primary key autoincrement,\n" +
                " client_name"+" nvarchar(50),\n" +
                " client_card_id"+" int null,\n" +
                " foreign key("+"client_card_id"+")\n" +
                " references card("+"card_id"+")\n" +
                ");";

        public static final String SQL_DELETE_ENTRIES="drop table if exists "+"client;";

    }

    public static final class CardEntry implements BaseColumns{
        public static final String TABLE_NAME = "card";
        public static final String COLUMN_NAME_CARD_ID = "card_id";
        public static final String COLUMN_NAME_CARD_CLIENT_ID = "card_client_id";
        public  static final String COLUMN_NAME_CARD_DATE_FROM = "card_date_from";
        public  static final String COLUMN_NAME_CARD_DATE_END = "card_date_end";
        public static final String COLUMN_NAME_CARD_ACTIVE = "card_active";
        public static final String COLUMN_NAME_CARD_PRICE = "card_price";
        public static final String COLUMN_NAME_CARD_DAYS = "card_days";

        public static final String SQL_CREATE_ENTRIES="" +
                "create table if not exists card(\n" +
                "    card_id integer not null primary key autoincrement,\n" +
                "    card_client_id integer not null,\n" +
                "    card_date_from datetime null,\n" +
                "    card_date_end datetime null,\n" +
                "    card_active boolean null,\n" +
                "    card_price integer null,\n" +
                "    card_day integer default(31),\n" +
                "    foreign key(card_client_id)\n" +
                "    references client(client_id)\n" +
                ");";

        public static String getSqlCreateEntries(){
            return "create table if not exists card(\n" +
                    "    card_id integer not null primary key autoincrement,\n" +
                    "    card_client_id integer not null,\n" +
                    "    card_date_from datetime,\n" +
                    "    card_date_end datetime,\n" +
                    "    card_active boolean default(0) not null,\n" +
                    "    card_price integer ,"+"\n" +
                    "    card_day integer default(31),\n" +
                    "    foreign key(card_client_id)\n" +
                    "    references client(client_id)\n" +
                    ");";
        }
        public static final String SQL_DELETE_ENTRIES="drop table if exists "+"card;";
    }

}














































