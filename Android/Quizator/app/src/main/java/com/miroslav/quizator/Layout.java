package com.miroslav.quizator;

public enum Layout {
    QuizatorMainFragment(R.layout.fragment_quizator_main),
    StartFragment(R.layout.fragment_start),
    ResultFragment(R.layout.fragment_result),
    MainActivity(R.layout.activity_main)    ;


    private int layout_id;

    Layout(int layout_id){
        this.layout_id = layout_id;
    }

    public int toInt(){
        return this.layout_id;
    }


}
































