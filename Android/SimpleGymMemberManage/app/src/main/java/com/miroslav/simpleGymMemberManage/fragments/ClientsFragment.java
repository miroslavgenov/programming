package com.miroslav.simpleGymMemberManage.fragments;

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

import com.miroslav.simpleGymMemberManage.R;
import com.miroslav.simpleGymMemberManage.actors.Client;
import com.miroslav.simpleGymMemberManage.databinding.FragmentClientsBinding;
import com.miroslav.simpleGymMemberManage.dateBase.ClientSqlQuery;
//import com.miroslav.simpleGymMemberManage.dateBase.GymSqlQuery;

import java.util.ArrayList;


/**
 * A simple {@link Fragment} subclass.
 *
 *
 */
public class ClientsFragment extends Fragment {
    ClientSqlQuery clientSqlQuery;
    FragmentClientsBinding fragmentClientsBinding;
    ArrayList<Client> clientArrayList;

    public void setClientArrayList(ArrayList<Client> clientArrayList) {
        this.clientArrayList = clientArrayList;
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        fragmentClientsBinding = DataBindingUtil.inflate(inflater,R.layout.fragment_clients, container, false);

        clientSqlQuery= new ClientSqlQuery();
        clientSqlQuery.openDataBase(getActivity());

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
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT,
                LinearLayout.LayoutParams.WRAP_CONTENT
        );
        return params;
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
    }
}
















































