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
    private static final int MAIN_ACTIVITY_LAYOUT_ID = R.layout.activity_main;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setActivityBinding(DataBindingUtil.setContentView(this, MAIN_ACTIVITY_LAYOUT_ID));
        main();
}
    private void main() {

        initializeSharedPrefs();
        goToSetDefaultCardPriceOrGoToMainMenuActivity();

        finish();
    }

    private void goToSetDefaultCardPriceOrGoToMainMenuActivity() {
        if (mySharedPrefs.isSharedPrefsFileExists()) {
            setDefaultCardPriceOrStartMainMenuActivity();
        } else {
            setDefaultCardPrinceAndStartSetDefaultActivity();
        }
    }

    private void setDefaultCardPriceOrStartMainMenuActivity() {
        if (!mySharedPrefs.getPasswordFromSharedPrefs().equals("0")) {
            startMainMenuActivity();
        } else {
            setDefaultCardPrinceAndStartSetDefaultActivity();
        }
    }

    private void setDefaultCardPrinceAndStartSetDefaultActivity() {
        setDefaultPassword("0");
        startSetDefaultsActivity();
    }

    /**
     * Function that starts <b>MainMenuActivity</b>
     * @see MainMenuActivity
     */
    private void startMainMenuActivity() {
        Intent intent = new Intent(getApplicationContext(),MainMenuActivity.class);
        startActivity(intent);
    }


    @Override
    public void initializeSharedPrefs() {
        this.mySharedPrefs = new MySharedPrefs(getApplicationContext(), getResources().getString(R.string.shared_prefs_file_key_card_password), Context.MODE_PRIVATE);
    }

    @Override
    public void initializeSharedPrefsAndSetUserPassword(String userPassword) {

    }

//    @Override
//    public void initializeSharedPrefsAndSetPassword(int cardPrice) {
//
//    }

    private void setDefaultPassword(String defaultPassword) {
//        mySharedPrefs.setCardPriceAtSharedPrefs(defaultCardPrice);
        mySharedPrefs.setPasswordAtSharedPrefs("0");
    }

    /**
     * Function that starts <b>SetDefaultsActivity</b>
     * @see SetDefaultsActivity
     */
    private void startSetDefaultsActivity() {
        Intent intent = new Intent(getApplicationContext(),SetDefaultsActivity.class);
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










































