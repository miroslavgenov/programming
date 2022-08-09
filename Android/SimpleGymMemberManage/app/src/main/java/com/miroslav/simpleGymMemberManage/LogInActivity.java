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

    public void setActivityLogInBinding(ActivityLogInBinding dataBindingUtilContent) {
        this.activityLogInBinding = dataBindingUtilContent;
    }

    public ActivityLogInBinding getActivityLogInBinding() {
        return activityLogInBinding;
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setActivityLogInBinding(DataBindingUtil.setContentView(this,LOG_IN_ACTIVITY_LAYOUT));

        main();
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
                MyPassword myPassword = new MyPassword(myEditTextController.getEditTextString(),password);
                if(myPassword.isPasswordEqual()){

                    Log.d("MyGym",password);

                    gymSqlQuery = new GymSqlQuery();
                    initializeSharedPrefs();
                    String userPassword = mySharedPrefs.getUserPasswordFromSharedPrefs();

                    gymSqlQuery.createDataBaseWithDefaultUserPassword(getApplicationContext(),userPassword);


                    finishCurrentActivityAndStartMainMenuActivity();

                }

            }else{
                makeToastSetMessageAndPlaceItToGravityCenter("Incorrect password");
            }

        });
    }

    private void setGymSqlQueryAndCreateDataBaseWithDefaultCardPrice() {
//        gymSqlQuery = new GymSqlQuery();
//        gymSqlQuery.createDataBaseWithDefaultCardPrice(getApplicationContext(),myEditTextController.getEditTextStringInteger());
    }

    private void finishCurrentActivityAndStartMainMenuActivity() {

        finish();
        startMainMenuActivity();
    }

    private void startMainMenuActivity() {
        Intent intent = new Intent(this,MainMenuActivity.class);
        startActivity(intent);

    }

    /**
     *
     * @param message message to be displayed
     */
    private void makeToastSetMessageAndPlaceItToGravityCenter(String message) {
    Toast toast =   Toast.makeText(this, message, Toast.LENGTH_SHORT);
    toast.setGravity(Gravity.CENTER,0,0);
    toast.show();
    }

    private void onButtonClick(Button buttonLogIn, MyButtonEventLogicImp myButtonEventLogicInterface) {
        buttonLogIn.setOnClickListener(view -> myButtonEventLogicInterface.doThisFromFragment());
    }

    EditText getEditTextTextPassword(){
        return getActivityLogInBinding().editTextTextPassword;
    }

    @Override
    public void initializeSharedPrefs() {
        this.mySharedPrefs = new MySharedPrefs(getApplicationContext(),getString(R.string.shared_prefs_file_key_card_password), Context.MODE_PRIVATE);
    }

    @Override
    public void initializeSharedPrefsAndSetUserPassword(String userPassword) {

    }
}




















































