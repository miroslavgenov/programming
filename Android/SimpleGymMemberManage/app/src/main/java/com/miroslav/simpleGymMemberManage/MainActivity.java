package com.miroslav.simpleGymMemberManage;

import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;

import com.miroslav.simpleGymMemberManage.databinding.ActivityMainBinding;


public class MainActivity extends AppCompatActivity implements  MyActivityBindingInterface,SharedPrefsInitializer {

    ActivityMainBinding activityMainBinding;
    MySharedPrefs mySharedPrefs;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setActivityBinding(DataBindingUtil.setContentView(this, R.layout.activity_main));
        main();
}
    private void main() {

        initializeSharedPrefs();
        boolean isSharedPrefsExists = mySharedPrefs.isSharedPrefsFileExists();

        if (isSharedPrefsExists) {
            if (mySharedPrefs.getCardPriceFromSharedPrefs() != 0) {
                startMainMenuActivity();
            } else {
                setDefaultCardPrice(0);
                startSetDefaultsActivity();
            }
        } else {
            setDefaultCardPrice(0);
            startSetDefaultsActivity();
        }
        finish();
    }

    private void startMainMenuActivity() {
        Intent intent = new Intent();
        intent.setClass(getApplicationContext(), MainMenuActivity.class);
        startActivity(intent);
    }

    @Override
    public void initializeSharedPrefs() {
        this.mySharedPrefs = new MySharedPrefs(getApplicationContext(), getResources().getString(R.string.shared_prefs_file_key_card_price_default), Context.MODE_PRIVATE);
    }

    private void setDefaultCardPrice(Integer defaultCardPrice) {
        mySharedPrefs.createOrAccessExistingSharedPreferences();
        mySharedPrefs.writeDefaultCardPriceToSharedPrefs(defaultCardPrice);
    }

    private void startSetDefaultsActivity() {
        Intent intent = new Intent();
        intent.setClass(getApplicationContext(), SetDefaultsActivity.class);
        startActivity(intent);
    }

    //SETTERS & GETTERS
    //SET
    @Override
    public <T> void setActivityBinding(T DataBindingUtilContent) {
        this.activityMainBinding = (ActivityMainBinding) DataBindingUtilContent;
    }

    //GET
    final ActivityMainBinding getActivityMainBinding() {
        return this.activityMainBinding;
    }

}










































