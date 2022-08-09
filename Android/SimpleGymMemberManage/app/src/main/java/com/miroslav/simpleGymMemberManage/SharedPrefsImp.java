package com.miroslav.simpleGymMemberManage;

//TODO change the name of SharedPrefsInitializer to SharedPrefsInitializerImp

public interface SharedPrefsImp {
    void initializeSharedPrefs();
    void initializeSharedPrefsAndSetUserPassword(String userPassword);

}
