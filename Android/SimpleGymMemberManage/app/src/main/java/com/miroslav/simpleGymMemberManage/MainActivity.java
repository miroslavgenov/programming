package com.miroslav.simpleGymMemberManage;

import androidx.appcompat.app.AppCompatActivity;
import androidx.databinding.DataBindingUtil;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;


import com.miroslav.simpleGymMemberManage.databinding.ActivityMainBinding;


public class MainActivity extends AppCompatActivity implements MyActivityBindingImp, SharedPrefsImp {

    ActivityMainBinding binding;
    MySharedPrefs mySharedPrefs;
    private static final int MAIN_ACTIVITY_LAYOUT_ID = R.layout.activity_main;
    final String libraryNameForSqlCipher ="sqlcipher";
    final String defaultUserPassword ="0";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        System.loadLibrary(libraryNameForSqlCipher);

        setActivityBinding(this.getDataBindingUtilContentViewForThisActivity());
        main();
}



    private void main() {

        initializeSharedPrefs();
        goToSetDefaultUserPasswordOrGoToLogInActivity();

        finish();
    }

    private void goToSetDefaultUserPasswordOrGoToLogInActivity() {
        if (mySharedPrefs.isSharedPrefsFileExists()) {
            setDefaultUserPasswordOrStartLogInActivity();
        } else {
            setDefaultUserPasswordAndStartSetDefaultActivity();
        }
    }

    private void setDefaultUserPasswordOrStartLogInActivity() {
        if (
                !mySharedPrefs.isDefaultUserPasswordEqualsZero()

        ) {
            startLogInActivity();
        } else {
            setDefaultUserPasswordAndStartSetDefaultActivity();
        }
    }

    private void setDefaultUserPasswordAndStartSetDefaultActivity() {
        setDefaultUserPassword(defaultUserPassword);
        startSetDefaultsActivity();
    }

    /**
     * Function that starts <b>MainMenuActivity</b>
     * @see MainMenuActivity
     */
    private void startLogInActivity() {
        Intent intentLogInActivity = new Intent(getApplicationContext(),LogInActivity.class);
        startActivity(intentLogInActivity);
    }


    @Override
    public void initializeSharedPrefs() {
        this.mySharedPrefs = new MySharedPrefs(getApplicationContext(), getResources().getString(R.string.shared_prefs_file_key_card_password), Context.MODE_PRIVATE);
    }

    @Override
    public void initializeSharedPrefsAndSetUserPassword(String userPassword) {

    }



    private void setDefaultUserPassword(String defaultUserPassword) {
        mySharedPrefs.setPasswordAtSharedPrefs(defaultUserPassword);
    }

    /**
     * Function that starts <b>SetDefaultsActivity</b>
     * @see SetDefaultsActivity
     */
    private void startSetDefaultsActivity() {
        Intent intentSetDefaultsActivity = new Intent(getApplicationContext(),SetDefaultsActivity.class);
        startActivity(intentSetDefaultsActivity);
    }

    //SETTERS & GETTERS
    //SET

    /**
     *
     * @param DataBindingUtilContent
     * @param <T> current activity binding
     */
    @Override
    public <T> void setActivityBinding(T DataBindingUtilContent) {
            this.binding = (ActivityMainBinding) DataBindingUtilContent;
    }

    @Override
    public <T> T getDataBindingUtilContentViewForThisActivity() {
        return (T) DataBindingUtil.setContentView(this,MAIN_ACTIVITY_LAYOUT_ID);
    }

    //GET
    final ActivityMainBinding getBinding() {
        return this.binding;
    }

}










































