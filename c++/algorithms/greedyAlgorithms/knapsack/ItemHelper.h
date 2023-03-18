#pragma once

class ItemHelper{
public:
    int size;
    item** items = nullptr;

    ItemHelper(item** , int );

    int getPrice(int );

    int getWeight(int );

    int getSize();
};