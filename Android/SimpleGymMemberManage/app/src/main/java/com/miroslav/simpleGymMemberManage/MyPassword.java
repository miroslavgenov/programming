package com.miroslav.simpleGymMemberManage;

public class MyPassword {
    String userPasswordText;
    String repeatedUserPasswordText;

    public MyPassword(String userPasswordText, String repeatedUserPasswordText){
        setUserPasswordText(userPasswordText);
        setRepeatedUserPasswordText(repeatedUserPasswordText);
    }
    public void setUserPasswordText(String value){
        this.userPasswordText =value;
    }
    public void setRepeatedUserPasswordText(String value){
        this.repeatedUserPasswordText = value;
    }

    public String getUserPasswordText() {
        return userPasswordText;
    }

    public String getRepeatedUserPasswordText() {
        return repeatedUserPasswordText;
    }

    boolean isPasswordEqual(){
        return getUserPasswordText().equals(getRepeatedUserPasswordText());
    }
}


















