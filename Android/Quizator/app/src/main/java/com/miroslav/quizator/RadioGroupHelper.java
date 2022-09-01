package com.miroslav.quizator;

import android.util.Log;
import android.widget.RadioButton;
import android.widget.RadioGroup;

import com.miroslav.quizator.databinding.FragmentQuizatorMainBinding;
import com.miroslav.quizator.initializer.RadioGroupInitializer;

/**
 * Author Miroslav Genov
 */
public class RadioGroupHelper {
    RadioGroup radioGroupAnswer;
    RadioButton[] radioButtonsAnswer;
    RadioGroupInitializer radioGroupInitializer;


    public RadioGroupHelper(FragmentQuizatorMainBinding binding){
        radioGroupInitializer = new RadioGroupInitializer(binding);
        this.radioGroupAnswer = radioGroupInitializer.getRadioGroupAnswers();
        setRadioButtonsAnswer(radioGroupAnswer);
    }

    void setRadioButtonsAnswerContainerSize(int size){
        radioButtonsAnswer = new RadioButton[size];
    }

    public void setRadioButtonsAnswer(RadioGroup radioGroupAnswer) {
        setRadioButtonsAnswerContainerSize(radioGroupInitializer.getRadioGroupAnswerChildCount());

        for (int i = 0; i < getRadioButtonsAnswerContainerLength(); i++) {
            setRadioButtonAnswer(i,(RadioButton) radioGroupAnswer.getChildAt(i));
        }
    }

    int getRadioButtonsAnswerContainerLength(){
        return radioButtonsAnswer.length;
    }
    
    void setRadioButtonAnswer(int buttonIndex,RadioButton valueRadioButton){
        radioButtonsAnswer[buttonIndex]  = valueRadioButton;
    }

    public String getCheckedAnswerFromPlayer() {
        int checkedRadioButtonId = radioGroupAnswer.getCheckedRadioButtonId();
        for (RadioButton radioButtonAnswer : radioButtonsAnswer) {
            if(radioButtonAnswer.getId()== checkedRadioButtonId){
                return radioButtonAnswer.getText().toString();
            }
        }
        Log.d("MyGym","RadioGroupHelper.getCheckedAnswerFormPlayer().ERROR!!!!!");
        return "";
    }
}






























