package com.miroslav.quizator;

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

    

    public void setRadioButtonsAnswer(RadioGroup radioGroupAnswer) {
        radioButtonsAnswer = new RadioButton[getRadioGroupAnswerSize()];
        for (int i = 0; i < radioButtonsAnswer.length; i++) {
            radioButtonsAnswer[i] = (RadioButton) this.radioGroupAnswer.getChildAt(i);
        }
    }
    
    public int getRadioGroupAnswerSize(){
        return radioGroupAnswer.getChildCount();
    }

    public String getCheckedAnswerFromPlayer() {
        for (RadioButton radioButtonAnswer : radioButtonsAnswer) {
            return getCheckedRadioButtonTextString(radioButtonAnswer);
        }
        return "";
    }

    public String getCheckedRadioButtonTextString(RadioButton radioButton) {
        if (isButtonChecked(radioButton)) {
            return getRadioButtonTextString(radioButton);
        }
        return "";
    }

    public boolean isButtonChecked(RadioButton radioButton) {
        return radioButton.getId() == getCheckedButtonIdFromRadioGroup();
    }

    public int getCheckedButtonIdFromRadioGroup() {
        return radioGroupAnswer.getCheckedRadioButtonId();
    }

    public String getRadioButtonTextString(RadioButton radioButton) {
        return radioButton.getText().toString();
    }
}
