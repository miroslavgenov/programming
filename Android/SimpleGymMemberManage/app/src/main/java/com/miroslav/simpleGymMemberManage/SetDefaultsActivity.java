package com.miroslav.simpleGymMemberManage;

import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;

import android.content.Context;
import android.content.Intent;
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
import com.miroslav.simpleGymMemberManage.databinding.ActivitySetDefaultsBinding;
import com.miroslav.simpleGymMemberManage.dateBase.GymSqlQuery;
import com.miroslav.simpleGymMemberManage.fragments.MyButtonEventLogicInterface;


// TODO: make this activity Fragment

public class SetDefaultsActivity extends AppCompatActivity implements MyActivityBindingInterface ,SharedPrefsInitializer{
    ActivitySetDefaultsBinding activitySetDefaultsBinding;
    AdView adView;
    Button buttonSetDefault;
    MyEditTextController myEditTextController;
    MySharedPrefs mySharedPrefs;
    GymSqlQuery gymSqlQuery;
    static Integer SET_DEFAULT_ACTIVITY_LAYOUT_ID = R.layout.activity_set_defaults;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setActivityBinding(DataBindingUtil.setContentView(this,SET_DEFAULT_ACTIVITY_LAYOUT_ID));
        main();
    }



    @Override
    protected void onDestroy() {
        this.gymSqlQuery.closeGymDbHelper();
        super.onDestroy();
    }

    private void main() {

        loadAd();

        setButtonSet(this.getButtonSetDefaultFromBindin());

        addOnButtonClickListeners();


    }

    /**
     *
     * @param editText editText to be controlled
     */
    void setMyEditTextController(EditText editText){
        myEditTextController = new MyEditTextController(editText);
    }

    void defaultActivityLogic(){

        setMyEditTextController(getEditTextCardPrice());

        if(myEditTextController.isEditTextTextCorrect()){
            initializeSharedPrefsAndSetCardPrice(myEditTextController.getEditTextStringInteger());
            setGymSqlQueryAndCreateDataBaseWithDefaulCardPrice();
            finishCurrentActivityAndStartMainMenuActivity();

        }else{
            makeToastSetTextToErrorPriceSetGravityAndShow();
        }
    }

    private void finishCurrentActivityAndStartMainMenuActivity() {
        finish();
        startMainMenuActivity();
    }

    void addOnButtonClickListeners(){
        onButtonClick(this.getButtonSetDefaultFromBindin(),this::defaultActivityLogic);}

    private void setGymSqlQueryAndCreateDataBaseWithDefaulCardPrice() {
        gymSqlQuery = new GymSqlQuery();
        gymSqlQuery.createDataBaseWithDefaultCardPrice(getApplicationContext(),myEditTextController.getEditTextStringInteger());
    }

    private EditText getEditTextCardPrice() {
        return getActivityBinding().editTextSetCardPrice;
    }

    // events
    private void onButtonClick(Button button, MyButtonEventLogicInterface myButtonEventLogicInterface) {
        button.setOnClickListener(view -> myButtonEventLogicInterface.doThisFromFragment());

    }



    private void startMainMenuActivity(){
        Intent intent = new Intent(getApplicationContext(),MainMenuActivity.class);
        startActivity(intent);
    }

    private void makeToastSetTextToErrorPriceSetGravityAndShow() {
        Toast toast;
        toast= Toast.makeText(getApplicationContext(),getApplicationContext().getString(R.string.incorrect_card_price),Toast.LENGTH_LONG);
        toast.setGravity(Gravity.CENTER,0,0);
        toast.show();
    }


    // AD LOAD
    private void loadAd(){
        adView = activitySetDefaultsBinding.adView;
        MobileAds.initialize(this, new OnInitializationCompleteListener() {
            @Override
            public void onInitializationComplete(InitializationStatus initializationStatus) {

            }
        });
        addAdRequest();
    }

    private void addAdRequest() {
        AdRequest adRequest = new AdRequest.Builder().build();
        this.adView.loadAd(adRequest);
    }

    //SET


    private void setButtonSet(Button sourceButtonSetDefault) {
        this.buttonSetDefault = sourceButtonSetDefault;
    }
    @Override
    public <T> void setActivityBinding(T DataBindingUtilContent) {
        this.activitySetDefaultsBinding = (ActivitySetDefaultsBinding) DataBindingUtilContent;
    }

    //GET




    Button getButtonSetDefaultFromBindin(){return
            getActivityBinding().buttonSetDefault;
    }

    ActivitySetDefaultsBinding getActivityBinding() {
        return this.activitySetDefaultsBinding;
    }


    @Override
    public void initializeSharedPrefs() {
        mySharedPrefs=new MySharedPrefs(this,getString(R.string.shared_prefs_file_key_card_price_default), Context.MODE_PRIVATE);
    }

    @Override
    public void initializeSharedPrefsAndSetCardPrice(int cardPrice) {
        mySharedPrefs=new MySharedPrefs(this,getString(R.string.shared_prefs_file_key_card_price_default), Context.MODE_PRIVATE);
        mySharedPrefs.setCardPriceAtSharedPrefs(cardPrice);
    }
}










































