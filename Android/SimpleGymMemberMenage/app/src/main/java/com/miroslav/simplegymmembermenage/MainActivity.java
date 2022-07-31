package com.miroslav.simplegymmembermenage;

import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;


import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import com.miroslav.simplegymmembermenage.databinding.ActivityMainBinding;

// user will set default value to card if the default value is zero
// if default card price is not zero the will proceeed to main menu activity
// else will proceed to set default activity to set the card price

public class MainActivity extends AppCompatActivity implements  MyActivityBindingInterface,SharedPrefsInitializer{

    ActivityMainBinding activityMainBinding ;

    MySharedPrefs mySharedPrefs;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setActivityBinding(DataBindingUtil.setContentView(this,R.layout.activity_main));
        main();


    }

    private void main() {

        initializeSharedPrefs();
        if(mySharedPrefs.isSharedPrefsFileExists()){

            if(mySharedPrefs.getCardPriceFromSharedPrefs()==Card.DEFAULT_CARD_PRICE){
                startSetDefaultsActivity();
                Intent intent= new Intent();
                intent.setClass(this,MainMenuActivity.class);
                startActivity(intent);

            }else{

                Log.d("GymMem"," card price HMMM ");
                Intent intent= new Intent();
                intent.setClass(this,MainMenuActivity.class);
                startActivity(intent);
            }
        }
        else{
            setDefaultCardPrice(0);
            main();

        }





    }

    private void startActivitySetDefaultsOrActivityMainMenu() {
//        if(sfp.getCardPriceFromSharedPrefs()==Card.DEFAULT_CARD_PRICE){
//            startSetDefaultsActivity();
//        }else{
//            startMainMenuActivity();
//        }
    }
    @Override
     public void initializeSharedPrefs() {
        this.mySharedPrefs = mySharedPrefs = new MySharedPrefs(getApplicationContext(),getResources().getString(R.string.shared_prefs_file_key_card_price_default),Context.MODE_PRIVATE);
    }

    private void startMainMenuActivity(){

    }

    private void setDefaultCardPrice(Integer defaultCardPrice) {
        mySharedPrefs.createOrAccessExistingSharedPreferences();
        mySharedPrefs.writeDefaultCardPriceToSharedPrefs(defaultCardPrice);
    }

    private void startSetDefaultsActivity() {
        Intent intent = new Intent();
        intent.setClass(getApplicationContext(),SetDefaultsActivity.class);
        startActivity(intent);
    }


    //SETTERS & GETTERS

    //SET
    @Override
    public <T> void setActivityBinding(T DataBindingUtilContent) {
        this.activityMainBinding =  (ActivityMainBinding) DataBindingUtilContent;
    }

    //GET
    final ActivityMainBinding getActivityMainBinding(){
        return this.activityMainBinding;
    }



}











































