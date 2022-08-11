package com.miroslav.simpleGymMemberManage.fragments;

import android.content.Context;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.databinding.DataBindingUtil;
import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;

import com.miroslav.simpleGymMemberManage.MySharedPrefs;
import com.miroslav.simpleGymMemberManage.R;
import com.miroslav.simpleGymMemberManage.SharedPrefsImp;
import com.miroslav.simpleGymMemberManage.actors.Client;
import com.miroslav.simpleGymMemberManage.databinding.FragmentClientsBinding;
import com.miroslav.simpleGymMemberManage.dateBase.ClientSqlQuery;


import java.util.ArrayList;


/**
 * A simple {@link Fragment} subclass.
 *
 *
 */
public class ClientsFragment extends Fragment implements SharedPrefsImp {
    ClientSqlQuery clientSqlQuery;
    FragmentClientsBinding fragmentClientsBinding;
    ArrayList<Client> clientArrayList;
    MySharedPrefs mySharedPrefs;

    public void setClientArrayList(ArrayList<Client> clientArrayList) {
        this.clientArrayList = clientArrayList;
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        fragmentClientsBinding = DataBindingUtil.inflate(inflater,R.layout.fragment_clients, container, false);

        clientSqlQuery= new ClientSqlQuery();
        initializeSharedPrefs();
        clientSqlQuery.openDataBaseWithPassword(getActivity(),mySharedPrefs.getUserPasswordFromSharedPrefs());

        setClientArrayList(clientSqlQuery.readAllData());
        showClientIfAny();

        return fragmentClientsBinding.getRoot();

    }

    private void showClientIfAny() {
        if(clientArrayList!=null){
            makeTextViewForAllClients();
        }else{
            makeTextViewAndPrint("No clients");
        }
    }


    private void makeTextViewForAllClients() {
        for(int i=0;i<clientArrayList.size();i++){
            makeTextViewAndPrint(clientArrayList.get(i).toString());
        }
    }

    @Override
    public void onDestroyView() {
        clientSqlQuery.closeGymDbHelper();
        super.onDestroyView();
    }

    private void makeTextViewAndPrint(String textViewText) {
        TextView textView = new TextView(getActivity());
        textView.setText(textViewText);
        textView.setLayoutParams(getTextViewParams());
        getLinearLayoutInScrollViewClients().addView(textView);
    }
    LinearLayout getLinearLayoutInScrollViewClients(){
        return fragmentClientsBinding.linearLayoutInScrollViewClients;
    }

    private LinearLayout.LayoutParams getTextViewParams() {
        return new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT,
                LinearLayout.LayoutParams.WRAP_CONTENT
        );
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
    }

    @Override
    public void initializeSharedPrefs() {
        mySharedPrefs = new MySharedPrefs(getActivity(),getString(R.string.shared_prefs_file_key_card_password), Context.MODE_PRIVATE);
    }

    @Override
    public void initializeSharedPrefsAndSetUserPassword(String userPassword) {

    }
}
















































