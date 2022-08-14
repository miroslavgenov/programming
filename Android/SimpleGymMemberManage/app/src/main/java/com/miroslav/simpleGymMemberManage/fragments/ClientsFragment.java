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
    ArrayList<Client> clients;
    MySharedPrefs mySharedPrefs;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        fragmentClientsBinding = DataBindingUtil.inflate(inflater,R.layout.fragment_clients, container, false);

        initializeSharedPrefs();
        clientSqlQuery= new ClientSqlQuery(getActivity(),mySharedPrefs.getUserPasswordFromSharedPrefs());

        clientSqlQuery.openDataBaseWithPassword();

        setClients(clientSqlQuery.readAllData());
        showClients();
        showNoClients();

        return fragmentClientsBinding.getRoot();

    }

    @Override
    public void initializeSharedPrefs() {
        mySharedPrefs = new MySharedPrefs(getActivity(),getString(R.string.shared_prefs_file_key_card_password), Context.MODE_PRIVATE);
    }

    public void setClients(ArrayList<Client> clients) {
        this.clients = clients;
    }



    private void showClients() {
        if(!this.isClientsNull()){
            makeTextViewForAllClients();
        }
    }

    boolean isClientsNull(){
        return clients== null;
    }

    private void makeTextViewForAllClients() {
        for(int i = 0; i< clients.size(); i++){
            makeTextViewAndPrint(clients.get(i).toString());
        }
    }

    private void makeTextViewAndPrint(String textViewText) {
        TextView textView = new TextView(getActivity());
        textView.setText(textViewText);
        textView.setLayoutParams(getTextViewParams());
        getLinearLayoutInScrollViewClients().addView(textView);
    }

    private LinearLayout.LayoutParams getTextViewParams() {
        return new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT,
                LinearLayout.LayoutParams.WRAP_CONTENT
        );
    }


    LinearLayout getLinearLayoutInScrollViewClients(){
        return fragmentClientsBinding.linearLayoutInScrollViewClients;
    }


    private void showNoClients(){
        if(this.isClientsNull())
            makeTextViewAndPrint("No clients");
    }




    @Override
    public void onDestroyView() {
        clientSqlQuery.closeGymDbHelper();
        super.onDestroyView();
    }






    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
    }



    @Override
    public void initializeSharedPrefsAndSetUserPassword(String userPassword) {

    }
}
















































