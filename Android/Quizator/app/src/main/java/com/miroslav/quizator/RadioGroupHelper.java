package com.miroslav.quizator;

import android.util.Log;
import android.widget.RadioButton;
import android.widget.RadioGroup;

/**
 * Author Miroslav Genov
 */
public class RadioGroupHelper {
    RadioGroup radioGroupAnswer;
    RadioButton[] radioButtonsAnswer;

    public RadioGroupHelper(RadioGroup radioGroupAnswer) {
        setRadioGroupAnswer(radioGroupAnswer);
        setRadioButtonsAnswer(radioGroupAnswer);
    }

    public void setRadioGroupAnswer(RadioGroup radioGroupAnswer) {
        this.radioGroupAnswer = radioGroupAnswer;
    }
    
    void setRadioButtonsAnswerSize(int size){
        radioButtonsAnswer = new RadioButton[size];
    }

    public int getRadioGroupAnswerSize(){
        return radioGroupAnswer.getChildCount();
    }

    public void setRadioButtonsAnswer(RadioGroup radioGroupAnswer) {
        setRadioButtonsAnswerSize(getRadioGroupAnswerSize());

        for (int i = 0; i < getRadioButtonsAnswerLength(); i++) {
            setRadioButtonAnswer(i,(RadioButton) radioGroupAnswer.getChildAt(i));
        }
    }

    int getRadioButtonsAnswerLength(){
        return radioButtonsAnswer.length;
    }
    
    void setRadioButtonAnswer(int buttonIndex,RadioButton valueRadioButton){
        radioButtonsAnswer[buttonIndex]  = valueRadioButton;
    }

    public String getCheckedAnswerFromPlayer() {
        int checkedButton = radioGroupAnswer.getCheckedRadioButtonId();
        for (RadioButton radioButtonAnswer : radioButtonsAnswer) {

            if(radioButtonAnswer.getId()== checkedButton){
                return radioButtonAnswer.getText().toString();
//                Log.d("MyQue",radioButtonAnswer.getText().toString());
            }
            //            return getCheckedRadioButtonTextString(radioButtonAnswer);
        }
        Log.d("MyGym","RadioGroupHelper.getCheckedAnswerFormPlayer().ERROR!!!!!");
        return "";
    }

    public String getCheckedRadioButtonTextString(RadioButton radioButton) {
        if (isButtonChecked(radioButton)) {
            return getRadioButtonTextString(radioButton);
        }
        return "";
    }

    public boolean isButtonChecked(RadioButton radioButton) {
        Log.d("MyQue",radioButton.getId()+ " "+ radioGroupAnswer.getCheckedRadioButtonId());
        return radioButton.getId() == getCheckedButtonIdFromRadioGroup();
    }

    public int getCheckedButtonIdFromRadioGroup() {
        return radioGroupAnswer.getCheckedRadioButtonId();
    }

    public String getRadioButtonTextString(RadioButton radioButton) {
        return radioButton.getText().toString();
    }
}






























