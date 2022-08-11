package com.miroslav.simpleGymMemberManage.fragments;

import android.content.Context;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.databinding.DataBindingUtil;
import androidx.fragment.app.Fragment;
import androidx.navigation.Navigation;

import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.miroslav.simpleGymMemberManage.MyEditTextController;
import com.miroslav.simpleGymMemberManage.MySharedPrefs;
import com.miroslav.simpleGymMemberManage.R;
import com.miroslav.simpleGymMemberManage.SharedPrefsImp;
import com.miroslav.simpleGymMemberManage.databinding.FragmentAddClientBinding;
import com.miroslav.simpleGymMemberManage.dateBase.ClientSqlQuery;



public class AddClientFragment extends Fragment implements SharedPrefsImp {
    MySharedPrefs mySharedPrefs;
    FragmentAddClientBinding fragmentAddClientBinding;
    ClientSqlQuery clientSqlQuery;
    Integer clientIdForNextClient;
    private MyEditTextController myEditTextController;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        fragmentAddClientBinding = DataBindingUtil.inflate(inflater,R.layout.fragment_add_client,container,false);
        return fragmentAddClientBinding.getRoot();
    }

    @Override
    public void onDestroyView() {
        clientSqlQuery.closeGymDbHelper();
        super.onDestroyView();
    }



    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        addClientLogic();


    }

    private void addClientLogic() {
        initializeSharedPrefs();
        initializeClientSqlQueryAndOpenDataBase();
        prepareCurrentClientIdForNextClient();
        addOnButtonClickListeners();


    }

    private void addOnButtonClickListeners() {
        onButtonClick(fragmentAddClientBinding.buttonAdd,this::addClient);
        onButtonClick(fragmentAddClientBinding.buttonCancel,this::popFragmentBackStack);
    }

    public void setMyEditTextController(EditText editText) {
        myEditTextController = new MyEditTextController(editText);
    }

    EditText getEditTextClientName(){
        return fragmentAddClientBinding.editTextClientName;
    }

    void addClient(){

        setMyEditTextController(getEditTextClientName());

        if(!myEditTextController.isEditTextStringEmpty()) {
            clientSqlQuery.insertData(myEditTextController.getEditTextString());
            prepareCurrentClientIdForNextClient();
            makeToastLengthLongGravityCenter(getString(R.string.client_added_text));
        }
    }

    void makeToastLengthLongGravityCenter(String message){
        Toast toast =  Toast.makeText(getActivity(),message,Toast.LENGTH_LONG);
        toast.setGravity(Gravity.CENTER,0,0);
        toast.show();
    }

    private void prepareCurrentClientIdForNextClient() {
        setCurrentClientIdForNextClient();
        setTextViewClientIdNumberText(String.valueOf(clientIdForNextClient));
    }

    private void setCurrentClientIdForNextClient() {
        setCurrentClientId(clientSqlQuery.getCountOfAllElements());
        incrementClientIdForNextClientByOne();
    }

    private void setTextViewClientIdNumberText(String clientId) {
        fragmentAddClientBinding.textViewClientIdNumber.setText(String.valueOf(clientId));
    }

    void incrementClientIdForNextClientByOne(){
        this.clientIdForNextClient =this.clientIdForNextClient +1;
    }

    private void setCurrentClientId(Integer countOfAllElements) {
        this.clientIdForNextClient =countOfAllElements;
    }

    /**
     * Create new instance of ClientSqlQuery
     */
    private void initializeClientSqlQueryAndOpenDataBase() {
        this.clientSqlQuery = new ClientSqlQuery(getActivity(), mySharedPrefs.getUserPasswordFromSharedPrefs());

        this.clientSqlQuery.openDataBaseWithPassword();
    }



    private void popFragmentBackStack(){
        Navigation.findNavController(getButtonToPopFragment()).popBackStack();
    }



    private Button getButtonToPopFragment() {
        return fragmentAddClientBinding.buttonCancel;
    }

    private void onButtonClick(Button button, MyButtonEventLogicImp myButtonEventLogicInterface) {
        button.setOnClickListener(view -> myButtonEventLogicInterface.doThisFromFragment());
    }

    @Override
    public void initializeSharedPrefs() {
        mySharedPrefs = new MySharedPrefs(getActivity(),getString(R.string.shared_prefs_file_key_card_password), Context.MODE_PRIVATE);
    }

    @Override
    public void initializeSharedPrefsAndSetUserPassword(String userPassword) {

    }
}






























