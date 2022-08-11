package com.miroslav.simpleGymMemberManage;

//TODO change the name of SharedPrefsInitializer to SharedPrefsInitializerImp

public interface SharedPrefsImp {
    /**
     * Initialize MySharedPrefs object
     */
    void initializeSharedPrefs();

    /**
     *Initialize the MySharedPrefs object and
     * and set the userPassword
     *
     * @param userPassword the user password from edit text getText
     */
    void initializeSharedPrefsAndSetUserPassword(String userPassword);

}



































