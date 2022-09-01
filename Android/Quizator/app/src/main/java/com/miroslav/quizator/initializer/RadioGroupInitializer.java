package com.miroslav.quizator.initializer;


import android.widget.RadioGroup;

import com.miroslav.quizator.databinding.FragmentQuizatorMainBinding;

public class RadioGroupInitializer extends QuizatorMainFragmentInitializer{
    RadioGroup radioGroupAnswers;
    public RadioGroupInitializer(FragmentQuizatorMainBinding binding) {
        super(binding);
        setRadioGroupAnswers();
    }

    void setRadioGroupAnswers(){
        radioGroupAnswers = super.binding.radioGroupAnswers;
    }

    public RadioGroup getRadioGroupAnswers(){
        return this.radioGroupAnswers;
    }

    public int getRadioGroupAnswerChildCount(){
        return radioGroupAnswers.getChildCount();
    }





}























