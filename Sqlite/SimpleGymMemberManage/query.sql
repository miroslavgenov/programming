create table if not exists client(
    client_id integer not null primary key autoincrement,
    client_name nvarchar(50),
    client_card_id int,
    foreign key(client_card_id)
    references card(card_id)
);

create table if not exists card(
    card_id integer not null primary key autoincrement,
    card_client_id integer not null,
    card_date_from datetime,
    card_date_end datetime,
    card_active boolean default(0) not null,
    card_price integer default(30),
    card_day integer default(31),
    foreign key(card_client_id)
    references client(client_id)
);

select card_id , client_id , card_date_from , card_date_end from card;
insert into client(client_name) values("ivan");
insert into client(client_name) values("alex");
insert into client(client_name) values("boris");

insert into card(card_client_id,card_date_from,card_date_end) values(1,datetime(),datetime('now','+31 day'));
insert into card(card_client_id,card_date_from,card_date_end) values(2,datetime(),datetime('now','+31 day'));
insert into card(card_client_id,card_date_from,card_date_end) values(3,datetime(),datetime('now','+31 day'));
insert into card(card_client_id,card_date_from,card_date_end) values(1,datetime('2022-05-02'),datetime('','+31 day'));
insert into card(card_client_id,card_date_from,card_date_end) values(1,datetime(),datetime('now','+31 day'));



delete from card where card_client_id=1;


select * from client inner join card on client.client_id = card.card_client_id where client.client_id=1;
select * from client inner join card on client.client_id = card.card_client_id where client.client_id=1 order by card.card_id desc limit 1;

update client set client_card_id=5 where client_id =1;

select card_date_end  from card where card_client_id=1 and card_id=5;


































