package com.miroslav.quizator;

import android.util.Log;
import android.widget.RadioButton;
import android.widget.RadioGroup;

public class RadioGroupHelper {
    RadioGroup radioGroup;
    RadioButton[] radioButtonAnswers;

    public RadioGroupHelper(RadioGroup radioGroupAnswers) {
        radioGroup=radioGroupAnswers;
        radioButtonAnswers = new RadioButton[radioGroupAnswers.getChildCount()];
        for(int i=0;i<radioGroup.getChildCount();i++){
            radioButtonAnswers[i] = (RadioButton) radioGroup.getChildAt(i);
        }
    }
    public String getSelectedAnswerFromPlayer(){
        int checkRadioButtonId = radioGroup.getCheckedRadioButtonId();
        for (RadioButton radioButtonAnswer : radioButtonAnswers) {
            if (radioButtonAnswer.getId() == checkRadioButtonId) {
                return radioButtonAnswer.getText().toString();
            }
        }
        return "RadioGroupHelper.getSelectedAnswer() Error";
    }
}





























