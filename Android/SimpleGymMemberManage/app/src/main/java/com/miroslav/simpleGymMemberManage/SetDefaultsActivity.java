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
    EditText editTextCardPrice;
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
//        this.gymSqlQuery.closeGymDbHelper();
        super.onDestroy();
    }

    private void main() {

        loadAd();
        setButtonSet(this.getActivityBinding().buttonSetDefault);
        setEditTextCardPrice(getActivityBinding().editTextSetCardPrice);

        addOnButtonClickListeners();


    }

    void addOnButtonClickListeners(){
        onButtonClick(this.getButtonSetDefault(),
                //TODO make this in the lambda function
                ()->{
            if(
                    //TODO: MyEditTextController.isEditTextStringCorrect(editText)
                    isEditTextStringCorrect()
            ){
                initializeSharedPrefs();
                mySharedPrefs.setCardPriceAtSharedPrefs(getEditTextCardPriceNumber());


                //TODO: change the GymSqlQuery constructor
                gymSqlQuery = new GymSqlQuery();
                //TODO this createDatabase is in the constructor of gymSqlQuery
                gymSqlQuery.createDataBase(getApplicationContext(),getEditTextCardPriceNumber());



                finish();
                startMainMenuActivity();


            }else{
                makeToastSetTextToErrorPriceSetGravityAndShow();
            }
        });
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


    Boolean isEditTextCardStringEmpty(){
        return getEditTextCardPriceString().isEmpty();
    }

    Boolean isEditTextCardStringGreaterThanZero(){
        int cardPrice = Integer.parseInt(getEditTextCardPriceString());
        return cardPrice>0;
    }

    private Boolean isEditTextStringCorrect() {
        if(isEditTextCardStringEmpty()) {
            return false;
        }
        else{
            return isEditTextCardStringGreaterThanZero();
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
        addAdRequest();
    }

    private void addAdRequest() {
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
        return String.valueOf(getEditTextCardPrice().getText());
    }

    Button getButtonSetDefault(){return  this.buttonSetDefault;}

    ActivitySetDefaultsBinding getActivityBinding() {
        return this.activitySetDefaultsBinding;
    }

    Integer getEditTextCardPriceNumber(){
        return isEditTextStringCorrect() ?Integer.parseInt(getEditTextCardPriceString()):0;
    }

    @Override
    public void initializeSharedPrefs() {
        mySharedPrefs=new MySharedPrefs(this,getString(R.string.shared_prefs_file_key_card_price_default), Context.MODE_PRIVATE);
    }
}










































