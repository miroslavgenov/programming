package com.miroslav.simpleGymMemberManage;

//TODO change the name of SharedPrefsInitializer to SharedPrefsInitializerImp

public interface SharedPrefsInitializer {
    void initializeSharedPrefs();
    void initializeSharedPrefsAndSetUserPassword(String userPassword);

}
