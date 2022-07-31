package com.miroslav.simpleGymMemberMenage;

import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;

import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdView;
import com.google.android.gms.ads.MobileAds;
import com.google.android.gms.ads.initialization.InitializationStatus;
import com.google.android.gms.ads.initialization.OnInitializationCompleteListener;
import com.miroslav.simpleGymMemberMenage.databinding.ActivityMainMenuBinding;

public class MainMenuActivity extends AppCompatActivity implements MyActivityBindingInterface{
    ActivityMainMenuBinding activityMainMenuBinding;
    AdView adView;
    ImageButton imageButtonSearchClient;
    EditText editTextSearch;
    Button buttonAddClient;
    Button buttonAddCard;
    Button buttonActiveClient;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        main();
    }

    private void main() {
        setActivityBinding(DataBindingUtil.setContentView(this,R.layout.activity_main_menu));
        loadAd();
        setInitialElementsFromXML(getActivityMainMenuBinding());
        onButtonAddClientEvent();
        onButtonAddCardEvent();
        onButtonActiveClientEvent();
        onImageButtonSearchClient();



    }

    private void onImageButtonSearchClient() {
        executeOnImageButtonActiveClientEventListener();
    }

    private void executeOnImageButtonActiveClientEventListener() {
        getImageButtonSearchClient().setOnClickListener(view -> {
            //TODO do something
        });
    }

    private void onButtonActiveClientEvent() {
        executeOnButtonActiveClientEventListener();
    }

    private void executeOnButtonActiveClientEventListener() {
        getButtonActiveClient().setOnClickListener(view->{
            //TODO do something
        });
    }

    private void onButtonAddCardEvent() {
        executeOnButtonAddCardEventListener();
    }

    private void executeOnButtonAddCardEventListener() {
        getButtonAddCard().setOnClickListener(view->{
            //TODO do something
        });
    }


    private void loadAd(){

        setAdView(activityMainMenuBinding.adView);
        MobileAds.initialize(this, new OnInitializationCompleteListener() {
            @Override
            public void onInitializationComplete(InitializationStatus initializationStatus) {

            }
        });
        addAdRequest();
    }

    private void addAdRequest() {
        AdRequest adRequest = new AdRequest.Builder().build();
        getAdView().loadAd(adRequest);
    }
    //Events


    void onButtonAddClientEvent(){
        executeOnButtonAddClientEventListener();
    }

    private void executeOnButtonAddClientEventListener() {
        getButtonAddClient().setOnClickListener(view->{
            //TODO do something
        });
    }


    //    SET

    private void setInitialElementsFromXML(ActivityMainMenuBinding binding) {
        setImageButtonSearchClient(binding.imageButtonSearch);
        setEditTextSearch(binding.editTextSearchClientId);
        setButtonAddClient(binding.buttonAddClient);
        setButtonAddCard(binding.buttonAddCard);
        setButtonActiveClient(binding.buttonActiveClients);
    }

    void setImageButtonSearchClient(ImageButton imageButton){
        this.imageButtonSearchClient =imageButton;
    }

    void setEditTextSearch(EditText editText){
        this.editTextSearch=editText;
    }

    void setButtonAddClient(Button button){
        this.buttonAddClient=button;
    }

    void setButtonAddCard(Button button){
        this.buttonAddCard = button;

    }

    void setButtonActiveClient(Button button){
        this.buttonActiveClient=button;
    }

    void setAdView(AdView adView){
        this.adView = adView;
    }



    @Override
    public <T> void setActivityBinding(T DataBindingUtilContent) {
        this.activityMainMenuBinding = (ActivityMainMenuBinding) DataBindingUtilContent;
    }
    //    GET
    ActivityMainMenuBinding getActivityMainMenuBinding(){
        return this.activityMainMenuBinding;
    }

    AdView getAdView(){
        return this.adView;
    }

    ImageButton getImageButtonSearchClient(){return this.imageButtonSearchClient;}
    EditText getEditTextSearch(){return this.editTextSearch;}
    Button getButtonAddClient(){return this.buttonAddClient;}
    Button getButtonAddCard(){return this.buttonAddCard;}
    Button getButtonActiveClient(){return this.buttonActiveClient;}

}

















































