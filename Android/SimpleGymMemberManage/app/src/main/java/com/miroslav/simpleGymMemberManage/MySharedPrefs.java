package com.miroslav.simpleGymMemberManage;

import  android.content.Context;
import android.content.SharedPreferences;
import androidx.security.crypto.EncryptedSharedPreferences;
import androidx.security.crypto.MasterKeys;

import java.io.IOException;
import java.security.GeneralSecurityException;

/**
 * This class is used to store shared prefs
 */

public class MySharedPrefs {
    Context context;
    SharedPreferences sharedPreferences;

    String sharedPrefKey;
    Integer contextMode;
    SharedPreferences.Editor editor;

    public MySharedPrefs(Context sourceContext,String shared_pref_key,Integer contextMode){
        this.context=sourceContext;
        this.sharedPrefKey =shared_pref_key;
        this.contextMode=contextMode;
        createOrAccessExistingSharedPreferences();

    }

    /**
     * This function check if shared prefs file exists
     * <p>
     * The shared preferences file contains data about the card price
     *
     *
     *
     * @return true or false
     * @see MySharedPrefs
     */
    public boolean isSharedPrefsFileExists(){
        createOrAccessExistingSharedPreferences();
        if(getSharedPreferences().contains(this.getSharedPrefKey())){
            return true;
        }
        else{
            return false;
        }

    }

    private void createOrAccessExistingSharedPreferences() {
//        this.sharedPreferences = getContext().getSharedPreferences(getSharedPrefKey(), getContextModePrivate());

        try {
            String masterKeyAlias = MasterKeys.getOrCreate(MasterKeys.AES256_GCM_SPEC);

            this.sharedPreferences = EncryptedSharedPreferences.create(
                    this.getSharedPrefKey(),
                    masterKeyAlias,
                    this.getContext(),
                    EncryptedSharedPreferences.PrefKeyEncryptionScheme.AES256_SIV,
                    EncryptedSharedPreferences.PrefValueEncryptionScheme.AES256_GCM
            );

        } catch (GeneralSecurityException | IOException e) {
            e.printStackTrace();
        }



    }

    private int getContextModePrivate() {
        return this.getContext().MODE_PRIVATE;
    }


    private void writePasswordToSharedPrefs(String value){
        editor = getSharedPreferences().edit();
        editor.putString(this.getSharedPrefKey(),value);
        editor.apply();
    }

    //SET
    public void setPasswordAtSharedPrefs(String value){
        writePasswordToSharedPrefs(value);
    }


    public void setContext(Context srcContext){
        this.context=srcContext;
    }

    //GET
    public Context getContext(){return this.context;}
    public SharedPreferences getSharedPreferences(){return this.sharedPreferences;}
    public String getSharedPrefKey(){return this.sharedPrefKey;}

    public boolean isDefaultPasswordEqualsZero(){
        return this.getPasswordFromSharedPrefs().equals("0");
    }

    public String getPasswordFromSharedPrefs(){
        String value = getSharedPreferences().getString(getContext().getString(R.string.shared_prefs_file_key_card_password),this.context.getResources().getString(R.string.default_password));
        return value;
    }
}

























