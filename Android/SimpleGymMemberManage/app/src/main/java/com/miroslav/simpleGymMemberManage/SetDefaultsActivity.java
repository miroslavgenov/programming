package com.miroslav.simpleGymMemberManage;

import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Gravity;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.miroslav.simpleGymMemberManage.databinding.ActivitySetDefaultsBinding;
import com.miroslav.simpleGymMemberManage.fragments.MyButtonEventLogicInterface;


// TODO: make this activity Fragment

public class SetDefaultsActivity extends AppCompatActivity implements MyActivityBindingInterface ,SharedPrefsInitializer{
    ActivitySetDefaultsBinding activitySetDefaultsBinding;

    Button buttonSetDefault;
    MyEditTextController myEditTextControllerPassword;
    MyEditTextController myEditTextControllerRepeatedPassword;
    MySharedPrefs mySharedPrefs;
//    GymSqlQuery gymSqlQuery;
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



        setButtonSet(this.getButtonSetDefaultFromBinding());

        addOnButtonClickListeners();


    }


    void setMyEditTextController(EditText editTextPassword,EditText editTextRepeatedPassword){
        myEditTextControllerPassword = new MyEditTextController(editTextPassword);
        myEditTextControllerRepeatedPassword = new MyEditTextController(editTextRepeatedPassword);
    }

    public EditText getMyEditTextRepeatedPassword() {
        return getActivityBinding().editTextTextRepeatPassword;
    }

    void defaultActivityLogic(){

        setMyEditTextController(getEditTextPassword(),getMyEditTextRepeatedPassword());

        Log.d("MyGym",""+myEditTextControllerPassword.isEditTextTextCorrectForPassword());
        Log.d("MyGym",""+myEditTextControllerRepeatedPassword.isEditTextTextCorrectForPassword());
        if
        (myEditTextControllerPassword.isEditTextTextCorrectForPassword() && myEditTextControllerRepeatedPassword.isEditTextTextCorrectForPassword()){

            MyPassword myPassword = new MyPassword(myEditTextControllerPassword.getEditTextString(),myEditTextControllerRepeatedPassword.getEditTextString());

            if(myPassword.isPasswordEqual()){

                makeToastSetTextToErrorPriceSetGravityAndShow("Password is set.");
                // initialize shared prefs
                initializeSharedPrefsAndSetUserPassword(myPassword.getPasswordText());
                finishCurrentActivityAndStartLogInActivity();

            }else{
                makeToastSetTextToErrorPriceSetGravityAndShow("Passwords are not equal!");
            }
        }else{
            makeToastSetTextToErrorPriceSetGravityAndShow("Password Length must be greater than 6 !");
        }



    }

    private void finishCurrentActivityAndStartLogInActivity() {
        finish();
        startLogInActivity();
    }

    void addOnButtonClickListeners(){
        onButtonClick(this.getButtonSetDefaultFromBinding(),this::defaultActivityLogic);}



    private EditText getEditTextPassword() {
        return getActivityBinding().editTextTextPassword;
    }

    // events
    private void onButtonClick(Button button, MyButtonEventLogicInterface myButtonEventLogicInterface) {
        button.setOnClickListener(view -> myButtonEventLogicInterface.doThisFromFragment());

    }



    private void startLogInActivity(){
        Intent intent = new Intent(getApplicationContext(),LogInActivity.class);
        startActivity(intent);
    }

    private void makeToastSetTextToErrorPriceSetGravityAndShow(String message) {
        Toast toast;
        toast= Toast.makeText(getApplicationContext(),message,Toast.LENGTH_LONG);
        toast.setGravity(Gravity.CENTER,0,0);
        toast.show();
    }





    //SET


    private void setButtonSet(Button sourceButtonSetDefault) {
        this.buttonSetDefault = sourceButtonSetDefault;
    }
    @Override
    public <T> void setActivityBinding(T DataBindingUtilContent) {
        this.activitySetDefaultsBinding = (ActivitySetDefaultsBinding) DataBindingUtilContent;
    }

    @Override
    public <T> T getDataBindingUtilContentViewForThisActivity() {
        return null;
    }

    //GET




    Button getButtonSetDefaultFromBinding(){return
            getActivityBinding().buttonSetDefault;
    }

    ActivitySetDefaultsBinding getActivityBinding() {
        return this.activitySetDefaultsBinding;
    }


    @Override
    public void initializeSharedPrefs() {
        mySharedPrefs=new MySharedPrefs(this,getString(R.string.shared_prefs_file_key_card_password), Context.MODE_PRIVATE);
    }

    @Override
    public void initializeSharedPrefsAndSetUserPassword(String userPassword) {
        mySharedPrefs = new MySharedPrefs(getApplicationContext(),getString(R.string.shared_prefs_file_key_card_password), Context.MODE_PRIVATE);
        mySharedPrefs.setPasswordAtSharedPrefs(userPassword);
    }


}










































