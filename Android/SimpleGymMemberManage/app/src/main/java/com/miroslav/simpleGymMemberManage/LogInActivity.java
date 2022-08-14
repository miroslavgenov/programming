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

import com.miroslav.simpleGymMemberManage.databinding.ActivityLogInBinding;
import com.miroslav.simpleGymMemberManage.dateBase.GymSqlQuery;
import com.miroslav.simpleGymMemberManage.fragments.MyButtonEventLogicImp;

public class LogInActivity extends AppCompatActivity implements SharedPrefsImp {

    ActivityLogInBinding activityLogInBinding;
    int LOG_IN_ACTIVITY_LAYOUT = R.layout.activity_log_in;
    MySharedPrefs mySharedPrefs;
    GymSqlQuery gymSqlQuery;

    

    

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setActivityLogInBinding(DataBindingUtil.setContentView(this,LOG_IN_ACTIVITY_LAYOUT));
        
        main();
    }

    public void setActivityLogInBinding(ActivityLogInBinding dataBindingUtilContent) {
        this.activityLogInBinding = dataBindingUtilContent;
    }


    private void main() {
        setOnButtonClick();
    }

    private void setOnButtonClick() {

        onButtonClick(getActivityLogInBinding().buttonLogIn,()->{

            MyEditTextController myEditTextController = new MyEditTextController(getEditTextTextPassword());

            initializeSharedPrefs();


            String password = mySharedPrefs.getUserPasswordFromSharedPrefs();

            if(!myEditTextController.isEditTextStringEmpty()){

                Password myPassword = new Password(myEditTextController.getEditTextString(),password);

                if(myPassword.isPasswordsEqual()){



                    gymSqlQuery = new GymSqlQuery();
                    //initializeSharedPrefs();
                    String userPassword = mySharedPrefs.getUserPasswordFromSharedPrefs();

                    gymSqlQuery.createDataBaseWithDefaultUserPassword(getApplicationContext(),userPassword);


                    finishCurrentActivityAndStartMainMenuActivity();

                }

            }else{
                new MyToast(getApplicationContext(),"Incorrect password").show();
//                MyToast.makeToastSetMessageSetGravityCenterAndShowLong(getApplicationContext(),"Incorrect password");

            }

        });
    }



    private void onButtonClick(Button buttonLogIn, MyButtonEventLogicImp myButtonEventLogicInterface) {
        buttonLogIn.setOnClickListener(view -> myButtonEventLogicInterface.doThisFromFragment());
    }

    public ActivityLogInBinding getActivityLogInBinding() {
        return activityLogInBinding;
    }


    @Override
    public void initializeSharedPrefs() {
        this.mySharedPrefs = new MySharedPrefs(getApplicationContext(),getString(R.string.shared_prefs_file_key_card_password), Context.MODE_PRIVATE);
    }

    EditText getEditTextTextPassword(){
        return getActivityLogInBinding().editTextTextPassword;
    }
    
    private void finishCurrentActivityAndStartMainMenuActivity() {

        finish();
        startMainMenuActivity();
    }

    private void startMainMenuActivity() {
        Intent intent = new Intent(this,MainMenuActivity.class);
        startActivity(intent);

    }

    @Override
    public void initializeSharedPrefsAndSetUserPassword(String userPassword) {

    }
}




















































