package com.miroslav.simpleGymMemberManage;

import android.widget.EditText;

/**
 * this class test if the edit text text is correct , empty , greater than zero
 */
public class MyEditTextController {
    EditText editText;
    String editTextString;
    int editTextStringInteger;

    public MyEditTextController(EditText editText){
        this.editText = editText;
        this.editTextString = this.editText.getText().toString();

    }

    public String getEditTextString() {
        return editTextString;
    }

    public boolean isEditTextTextCorrectForPassword(){
        if(this.isEditTextStringEmpty()){
            return false;
        }else{
            return this.isEditTextStringLengthGreaterThanSix();
        }
    }

    private boolean isEditTextStringLengthGreaterThanSix() {
        return this.getEditTextString().length()>Password.PASSWORD_REQUIRED_LENGTH;
    }


    /**
     * Checks if the text is empty and if the string number is greater than zero
     * @return
     */
    public boolean isEditTextTextCorrectNumber(){
        if(this.isEditTextStringEmpty()){
            return false;
        }else{
            return this.isEditTextStringNumberGreaterThanZero();
        }
    }

    public boolean isEditTextStringEmpty(){
        return this.editTextString.isEmpty();
    }

    public boolean isEditTextStringNumberGreaterThanZero(){
        return this.getEditTextStringInteger()>0;
    }

    public int getEditTextStringInteger(){
        this.editTextStringInteger = Integer.parseInt(this.editTextString);
        return this.editTextStringInteger;
    }



}











































