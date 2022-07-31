package com.miroslav.simplegymmembermenage;

import android.content.Context;
import android.content.SharedPreferences;
import android.util.Log;

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

    }

    boolean isSharedPrefsFileExists(){
        createOrAccessExistingSharedPreferences();
        if(getSharedPreferences().contains(this.getSharedPrefKey())){
            Log.d("GymMenage","exists");
            return true;
        }
        else{
            Log.d("GymMenage","doesn't exists");
            return false;
        }

    }

    public void createOrAccessExistingSharedPreferences(){
        this.sharedPreferences = getContext().getSharedPreferences(getSharedPrefKey(), getContextModePrivate());
    }

    private int getContextModePrivate() {
        return this.getContext().MODE_PRIVATE;
    }


    public void writeDefaultCardPriceToSharedPrefs(Integer value){
        editor = getSharedPreferences().edit();
        editor.putInt(this.sharedPrefKey,value);
        editor.apply();
    }

    //SET
    public void setCardPriceToSharedPrefs(Integer value){
        writeDefaultCardPriceToSharedPrefs(value);
    }


    public void setContext(Context srcContext){
        this.context=srcContext;
    }

    //GET
    public Context getContext(){return this.context;}
    public SharedPreferences getSharedPreferences(){return this.sharedPreferences;}
    public String getSharedPrefKey(){return this.sharedPrefKey;}

    public Integer getCardPriceFromSharedPrefs(){
        Integer value = getSharedPreferences().getInt(getContext().getString(R.string.shared_prefs_file_key_card_price_default),this.context.getResources().getInteger(R.integer.default_card_price));
        return value;
    }
}

























