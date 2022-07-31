package com.miroslav.simplegymmembermenage;

import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;

import android.content.Context;
import android.os.Bundle;
import android.view.Gravity;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdView;
import com.google.android.gms.ads.MobileAds;
import com.google.android.gms.ads.initialization.InitializationStatus;
import com.google.android.gms.ads.initialization.OnInitializationCompleteListener;
import com.miroslav.simplegymmembermenage.databinding.ActivitySetDefaultsBinding;

public class SetDefaultsActivity extends AppCompatActivity implements MyActivityBindingInterface ,SharedPrefsInitializer{
    ActivitySetDefaultsBinding activitySetDefaultsBinding;
    AdView adView;
    Button buttonSetDefault;
    EditText editTextCardPrice;
    MySharedPrefs mySharedPrefs;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setActivityBinding(DataBindingUtil.setContentView(this,R.layout.activity_set_defaults));
        main();
    }

    private void main() {
        loadAd();
        setButtonSet(this.getActivityBinding().buttonSetDefault);
        setEditTextCardPrice(getActivityBinding().editTextSetCardPrice);
        onButtonSetDefault();
    }

    // events
    private void onButtonSetDefault() {
        executeOnButtonSetDefaultEventListener();
    }

    //event execution
    private void executeOnButtonSetDefaultEventListener() {
        this.getButtonSetDefault().setOnClickListener(view -> {

                if(isEditTextStringCorrect()){
                    initializeSharedPrefs();
                    mySharedPrefs.createOrAccessExistingSharedPreferences();
                    mySharedPrefs.writeDefaultCardPriceToSharedPrefs(30);
                    finish();

                }else{
                    makeToastSetTextToErrorPriceSetGravityAndShow();
                }


        });
    }

    private void makeToastSetTextToErrorPriceSetGravityAndShow() {
        Toast toast;
        toast= Toast.makeText(getApplicationContext(),getApplicationContext().getString(R.string.incorrect_card_price),Toast.LENGTH_LONG);
        toast.setGravity(Gravity.CENTER,0,0);
        toast.show();
    }


    Boolean isEditTextCardStringEmpty(){
        if(getEditTextCardPriceString().isEmpty()){

            return true;
        }else {

            return false;
        }

    }

    Boolean isEditTextCardStringGreaterThanZero(){
        
        Integer cardPrice = Integer.parseInt(getEditTextCardPriceString());
        
        if(cardPrice>0){
            return true;
        }else{
            return false;
        }
    
    }

   private Boolean isEditTextStringCorrect() {
        if(isEditTextCardStringEmpty()){
            return false;
        }else{
            if(isEditTextCardStringGreaterThanZero()){
                return true;
            }else{
                return false;
            }

        }

   }


    // AD LOAD
    private void loadAd(){
        adView = activitySetDefaultsBinding.adView;
        MobileAds.initialize(this, new OnInitializationCompleteListener() {
            @Override
            public void onInitializationComplete(InitializationStatus initializationStatus) {

            }
        });
        addAdRequest(this.adView);
    }

    private void addAdRequest(AdView adView) {
        AdRequest adRequest = new AdRequest.Builder().build();
        this.adView.loadAd(adRequest);
    }

    //SET
    void setEditTextCardPrice(EditText srcEditText){
        this.editTextCardPrice = srcEditText;
    }

    private void setButtonSet(Button sourceButtonSetDefault) {
        this.buttonSetDefault = sourceButtonSetDefault;
    }
        @Override
    public <T> void setActivityBinding(T DataBindingUtilContent) {
        this.activitySetDefaultsBinding = (ActivitySetDefaultsBinding) DataBindingUtilContent;
    }

    //GET
    EditText getEditTextCardPrice(){return this.editTextCardPrice;}

    String getEditTextCardPriceString(){
//        Log.d("GymMenage",String.valueOf(getEditTextCardPrice().getText().toString().isEmpty()));
//        Log.d("GymMenage",String.valueOf(getEditTextCardPrice().getText()));
        return String.valueOf(getEditTextCardPrice().getText());
    }
    Button getButtonSetDefault(){return  this.buttonSetDefault;}
    ActivitySetDefaultsBinding getActivityBinding() {
        return this.activitySetDefaultsBinding;
    }
    Integer getEditTextCardPriceNumber(){
        return isEditTextStringCorrect()==true?Integer.parseInt(getEditTextCardPriceString()):99;
    }

    @Override
    public void initializeSharedPrefs() {
        mySharedPrefs=new MySharedPrefs(this,getString(R.string.shared_prefs_file_key_card_price_default), Context.MODE_PRIVATE);
    }
}











































