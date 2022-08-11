package com.miroslav.simpleGymMemberManage;

public class Password {
    String userPasswordText;
    String repeatedUserPasswordText;
    public static final int PASSWORD_REQUIRED_LENGTH =6;

    public Password(String userPasswordText, String repeatedUserPasswordText){
        setUserPasswordText(userPasswordText);
        setRepeatedUserPasswordText(repeatedUserPasswordText);
    }
    public void setUserPasswordText(String value){
        this.userPasswordText =value;
    }
    public void setRepeatedUserPasswordText(String value){
        this.repeatedUserPasswordText = value;
    }

    public String getUserPassword() {
        return userPasswordText;
    }

    public String getRepeatedUserPasswordText() {
        return repeatedUserPasswordText;
    }

    boolean isPasswordsEqual(){
        return getUserPassword().equals(getRepeatedUserPasswordText());
    }
}


















