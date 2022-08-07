package com.miroslav.simpleGymMemberManage;

public interface SharedPrefsInitializer {
    void initializeSharedPrefs();
    void initializeSharedPrefsAndSetUserPassword(String userPassword);

}
