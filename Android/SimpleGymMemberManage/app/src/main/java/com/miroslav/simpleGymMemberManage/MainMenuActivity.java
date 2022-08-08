package com.miroslav.simpleGymMemberManage;

import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;

import android.os.Bundle;

import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdView;
import com.google.android.gms.ads.MobileAds;
import com.miroslav.simpleGymMemberManage.databinding.ActivityMainBinding;
import com.miroslav.simpleGymMemberManage.databinding.ActivityMainMenuBinding;

//TODO: delete this activity replace it with MainActivity and transfer the adView

public class MainMenuActivity extends AppCompatActivity implements MyActivityBindingInterface{
    ActivityMainMenuBinding activityMainMenuBinding;
    AdView adView;

    private final int MAIN_MENU_ACTIVITY_LAYOUT_ID=  R.layout.activity_main_menu;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setActivityBinding(getDataBindingUtilContentViewForThisActivity());
        main();
    }



    private void main() {

        loadAd();

    }



    private void loadAd(){

        setAdView(activityMainMenuBinding.adView);
        MobileAds.initialize(this, initializationStatus -> {

        });
        addAdRequest();
    }

    private void addAdRequest() {
        AdRequest adRequest = new AdRequest.Builder().build();
        getAdView().loadAd(adRequest);
    }

    void setAdView(AdView adView){
        this.adView = adView;
    }



    @Override
    public <T> void setActivityBinding(T DataBindingUtilContent) {
        this.activityMainMenuBinding = (ActivityMainMenuBinding) DataBindingUtilContent;
    }

    @Override
    public <T> T getDataBindingUtilContentViewForThisActivity() {
        return (T)DataBindingUtil.setContentView(this,MAIN_MENU_ACTIVITY_LAYOUT_ID);
    }

    //    GET
    ActivityMainMenuBinding getActivityMainMenuBinding(){
        return this.activityMainMenuBinding;
    }

    AdView getAdView(){
        return this.adView;
    }



}

















































