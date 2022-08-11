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

import com.miroslav.simpleGymMemberManage.databinding.ActivitySetDefaultsBinding;
import com.miroslav.simpleGymMemberManage.fragments.MyButtonEventLogicImp;


// TODO: make this activity Fragment

public class SetDefaultsActivity extends AppCompatActivity implements MyActivityBindingImp, SharedPrefsImp {
    ActivitySetDefaultsBinding activitySetDefaultsBinding;
    Password userPassword;
    Button buttonSetDefault;
    MyEditTextController myEditTextControllerPassword;
    MyEditTextController myEditTextControllerRepeatedPassword;
    MySharedPrefs mySharedPrefs;
//    GymSqlQuery gymSqlQuery;
    static Integer SET_DEFAULT_ACTIVITY_LAYOUT_ID = R.layout.activity_set_defaults;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setActivityBinding(getDataBindingUtilContentViewForThisActivity());
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

        if(isEditTextPasswordAndRepeatedPasswordCorrect()){
            initializePassword(myEditTextControllerPassword,myEditTextControllerRepeatedPassword);
            if(userPassword.isPasswordsEqual()){
                showMessageSavePasswordFinishThisActivityAndStartLoginActivity();
            }else{
                MyToast.makeToastSetMessageSetGravityCenterAndShowLong(getApplicationContext(),"Passwords are not equal!");
            }
        }else{
            MyToast.makeToastSetMessageSetGravityCenterAndShowLong(getApplicationContext(),"Password Length must be greater than "+Password.PASSWORD_REQUIRED_LENGTH+" !");

        }
    }

    private void showMessageSavePasswordFinishThisActivityAndStartLoginActivity() {
        MyToast.makeToastSetMessageSetGravityCenterAndShowLong(getApplicationContext(),"Password is set.");
        initializeSharedPrefsAndSetUserPassword(userPassword.getUserPassword());
        finishCurrentActivityAndStartLogInActivity();
    }

    private void initializePassword(MyEditTextController myEditTextControllerPassword, MyEditTextController myEditTextControllerRepeatedPassword) {
        userPassword = new Password(myEditTextControllerPassword.getEditTextString(),myEditTextControllerRepeatedPassword.getEditTextString());
    }


    boolean isEditTextPasswordAndRepeatedPasswordCorrect(){
        return myEditTextControllerPassword.isEditTextTextCorrectForPassword() && myEditTextControllerRepeatedPassword.isEditTextTextCorrectForPassword();
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
    private void onButtonClick(Button button, MyButtonEventLogicImp myButtonEventLogicInterface) {
        button.setOnClickListener(view -> myButtonEventLogicInterface.doThisFromFragment());

    }



    private void startLogInActivity(){
        Intent intent = new Intent(getApplicationContext(),LogInActivity.class);
        startActivity(intent);
    }


    //SET

    @Override
    public void initializeSharedPrefs() {
        mySharedPrefs=new MySharedPrefs(this,getString(R.string.shared_prefs_file_key_card_password), Context.MODE_PRIVATE);
    }

    @Override
    public void initializeSharedPrefsAndSetUserPassword(String userPassword) {
        mySharedPrefs = new MySharedPrefs(getApplicationContext(),getString(R.string.shared_prefs_file_key_card_password), Context.MODE_PRIVATE);
        mySharedPrefs.setPasswordAtSharedPrefs(userPassword);
    }


    private void setButtonSet(Button sourceButtonSetDefault) {
        this.buttonSetDefault = sourceButtonSetDefault;
    }
    @Override
    public <T> void setActivityBinding(T DataBindingUtilContent) {
        this.activitySetDefaultsBinding = (ActivitySetDefaultsBinding) DataBindingUtilContent;
    }

    //GET


    @Override
    public <T> T getDataBindingUtilContentViewForThisActivity() {
        return (T)DataBindingUtil.setContentView(this,SET_DEFAULT_ACTIVITY_LAYOUT_ID);
    }






    Button getButtonSetDefaultFromBinding(){return
            getActivityBinding().buttonSetDefault;
    }

    ActivitySetDefaultsBinding getActivityBinding() {
        return this.activitySetDefaultsBinding;
    }





}










































