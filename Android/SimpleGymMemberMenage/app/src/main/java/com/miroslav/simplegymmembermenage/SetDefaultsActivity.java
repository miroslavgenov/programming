package com.miroslav.simplegymmembermenage;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;

import android.os.Bundle;

import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdSize;
import com.google.android.gms.ads.AdView;
import com.google.android.gms.ads.MobileAds;
import com.google.android.gms.ads.initialization.InitializationStatus;
import com.google.android.gms.ads.initialization.OnInitializationCompleteListener;
import com.miroslav.simplegymmembermenage.databinding.ActivitySetDefaultsBinding;

public class SetDefaultsActivity extends AppCompatActivity implements MyActivityBindingInterface {
    ActivitySetDefaultsBinding activitySetDefaultsBinding;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setActivityBinding(DataBindingUtil.setContentView(this,R.layout.activity_set_defaults));

        // load ad
        AdView adView = activitySetDefaultsBinding.adView;




        MobileAds.initialize(this, new OnInitializationCompleteListener() {
            @Override
            public void onInitializationComplete(InitializationStatus initializationStatus) {

            }
        });
        AdRequest adRequest = new AdRequest.Builder().build();
        adView.loadAd(adRequest);
    }


    @Override
    public <T> void setActivityBinding(T DataBindingUtilContent) {
        this.activitySetDefaultsBinding = (ActivitySetDefaultsBinding) DataBindingUtilContent;
    }


    ActivitySetDefaultsBinding getActivityBinding() {
        return this.activitySetDefaultsBinding;
    }
}






















