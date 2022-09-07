package com.miroslav.quizator;

public enum MyNav{
    TO_RESULT_FRAGMENT(R.id.action_quizatorMainFragment_to_resultFragment);

    private final int NAVIGATION_ID;

    MyNav(int navigation_id){
        this.NAVIGATION_ID = navigation_id;
    }

    public int toInt(){return NAVIGATION_ID;}
};
