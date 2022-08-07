package com.miroslav.simpleGymMemberManage;

public class MyPassword {
    String passwordText;
    String repeatedPasswordText;

    public MyPassword(String passwordText, String repeatedPasswordText){
        setPasswordText(passwordText);
        setRepeatedPasswordText(repeatedPasswordText);
    }
    public void setPasswordText(String value){
        this.passwordText=value;
    }
    public void setRepeatedPasswordText(String value){
        this.repeatedPasswordText = value;
    }

    public String getPasswordText() {
        return passwordText;
    }

    public String getRepeatedPasswordText() {
        return repeatedPasswordText;
    }

    boolean isPasswordEqual(){
        return getPasswordText().equals(getRepeatedPasswordText());
    }
}


















