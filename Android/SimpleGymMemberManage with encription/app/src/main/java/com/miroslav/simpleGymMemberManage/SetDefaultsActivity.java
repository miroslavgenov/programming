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
    //setActivityBinding
    @Override
    public <T> void setActivityBinding(T DataBindingUtilContent) {
        this.activitySetDefaultsBinding = (ActivitySetDefaultsBinding) DataBindingUtilContent;
    }

    //getDataBindingUtilContentViewForThisActivity
    @Override
    public <T> T getDataBindingUtilContentViewForThisActivity() {
        return (T)DataBindingUtil.setContentView(this,SET_DEFAULT_ACTIVITY_LAYOUT_ID);
    }

    //main
    private void main() {



        setButtonSet(this.getButtonSetDefaultFromBinding());

        addOnButtonClickListeners();


    }

    //setButtonSet
    private void setButtonSet(Button sourceButtonSetDefault) {
        this.buttonSetDefault = sourceButtonSetDefault;
    }

    //getButtonSetDefaultFromBinding
    Button getButtonSetDefaultFromBinding(){return
        getActivityBinding().buttonSetDefault;
    }
    
    //getActivityBinding
    ActivitySetDefaultsBinding getActivityBinding() {
        return this.activitySetDefaultsBinding;
    }

    // addOnButtonClickListeners
    void addOnButtonClickListeners(){
        onButtonClick(this.getButtonSetDefaultFromBinding(),this::defaultActivityLogic);
    }

    //onButtonClick
    // events
    private void onButtonClick(Button button, MyButtonEventLogicImp myButtonEventLogicInterface) {
        button.setOnClickListener(view -> myButtonEventLogicInterface.doThisFromFragment());

    }

    

    //defaultActivityLogic
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
    //setMyEditTextController

    void setMyEditTextController(EditText editTextPassword,EditText editTextRepeatedPassword){
        myEditTextControllerPassword = new MyEditTextController(editTextPassword);
        myEditTextControllerRepeatedPassword = new MyEditTextController(editTextRepeatedPassword);
    }

    //getEditTextPassword
    private EditText getEditTextPassword() {
        return getActivityBinding().editTextTextPassword;
    }
    //getMyEditTextRepeatedPassword
    public EditText getMyEditTextRepeatedPassword() {
        return getActivityBinding().editTextTextRepeatPassword;
    }

    //isEditTextPasswordAndRepeatedPasswordCorrect
    boolean isEditTextPasswordAndRepeatedPasswordCorrect(){
        return myEditTextControllerPassword.isEditTextTextCorrectForPassword() && myEditTextControllerRepeatedPassword.isEditTextTextCorrectForPassword();
    }

    //initializePassword
    private void initializePassword(MyEditTextController myEditTextControllerPassword, MyEditTextController myEditTextControllerRepeatedPassword) {
        userPassword = new Password(myEditTextControllerPassword.getEditTextString(),myEditTextControllerRepeatedPassword.getEditTextString());
    }
    //showMessageSavePasswordFinishThisActivityAndStartLoginActivity
    private void showMessageSavePasswordFinishThisActivityAndStartLoginActivity() {
        MyToast.makeToastSetMessageSetGravityCenterAndShowLong(getApplicationContext(),"Password is set.");
        initializeSharedPrefsAndSetUserPassword(userPassword.getUserPassword());
        finishCurrentActivityAndStartLogInActivity();
    }

    //initializeSharedPrefsAndSetUserPassword
    @Override
    public void initializeSharedPrefsAndSetUserPassword(String userPassword) {
        mySharedPrefs = new MySharedPrefs(getApplicationContext(),getString(R.string.shared_prefs_file_key_card_password), Context.MODE_PRIVATE);
        mySharedPrefs.setPasswordAtSharedPrefs(userPassword);
    }

    //finishCurrentActivityAndStartLogInActivity
    private void finishCurrentActivityAndStartLogInActivity() {
        finish();
        startLogInActivity();
    }
    
    //startLogInActivity
    private void startLogInActivity(){
        Intent intent = new Intent(getApplicationContext(),LogInActivity.class);
        startActivity(intent);
    }
    

    @Override
    protected void onDestroy() {
//        this.gymSqlQuery.closeGymDbHelper();
        super.onDestroy();
    }

    


    

    

    

    

    


    

    

    



    

    



    


    //SET

     @Override
     public void initializeSharedPrefs() {
         mySharedPrefs=new MySharedPrefs(this,getString(R.string.shared_prefs_file_key_card_password), Context.MODE_PRIVATE);
     }

    


    
    

    //GET


    






    

    





}










































