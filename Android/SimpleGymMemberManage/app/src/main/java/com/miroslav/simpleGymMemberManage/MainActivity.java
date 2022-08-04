package com.miroslav.simpleGymMemberManage;

import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;

import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdView;
import com.google.android.gms.ads.MobileAds;
import com.miroslav.simpleGymMemberManage.databinding.ActivityMainBinding;


public class MainActivity extends AppCompatActivity implements  MyActivityBindingInterface,SharedPrefsInitializer {

    ActivityMainBinding activityMainBinding;
    MySharedPrefs mySharedPrefs;
    private static final int MAIN_ACTIVITY_LAYOUT_ID = R.layout.activity_main;
    private AdView adView;


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
        if (mySharedPrefs.getCardPriceFromSharedPrefs() != 0) {
            startMainMenuActivity();
        } else {
            setDefaultCardPrinceAndStartSetDefaultActivity();
        }
    }

    private void setDefaultCardPrinceAndStartSetDefaultActivity() {
        setDefaultCardPrice(0);
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
        this.mySharedPrefs = new MySharedPrefs(getApplicationContext(), getResources().getString(R.string.shared_prefs_file_key_card_price_default), Context.MODE_PRIVATE);
    }

    private void setDefaultCardPrice(Integer defaultCardPrice) {
        mySharedPrefs.setCardPriceAtSharedPrefs(defaultCardPrice);
    }

    /**
     * Function that starts <b>SetDefaultsActivity</b>
     * @see SetDefaultsActivity
     */
    private void startSetDefaultsActivity() {
        Intent intent = new Intent(getApplicationContext(),SetDefaultsActivity.class);
        startActivity(intent);
    }

    //TODO: make adview at main activity
    // LOAD ADD
    private void loadAd(){

//        setAdView(activityMainMenuBinding.adView);
//        MobileAds.initialize(this, initializationStatus -> {
//
//        });
//        addAdRequest();
    }

    private void addAdRequest() {
//        AdRequest adRequest = new AdRequest.Builder().build();
//        getAdView().loadAd(adRequest);
    }

    //SETTERS & GETTERS
    //SET

    void setAdView(AdView adView){
        this.adView = adView;
    }
    AdView getAdView(){
        return this.adView;
    }

    @Override
    public <T> void setActivityBinding(T DataBindingUtilContent) {

            this.activityMainBinding = (ActivityMainBinding) DataBindingUtilContent;


    }

    //GET
    final ActivityMainBinding getActivityMainBinding() {
        return this.activityMainBinding;
    }


}










































