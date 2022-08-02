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
import com.miroslav.simpleGymMemberManage.dateBase.GymSqlQuery;

import java.util.ArrayList;


/**
 * A simple {@link Fragment} subclass.
 *
 *
 */
public class ClientsFragment extends Fragment {
    GymSqlQuery gymSqlQuery;
    FragmentClientsBinding fragmentClientsBinding;
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        fragmentClientsBinding = DataBindingUtil.inflate(inflater,R.layout.fragment_clients, container, false);
        gymSqlQuery= new GymSqlQuery();
        gymSqlQuery.openDataBase(getActivity());
         ArrayList<Client> clientArrayList = gymSqlQuery.readAllClients();

         if(clientArrayList!=null){
        for(int i=0;i<clientArrayList.size();i++){
            makeTextViewAndPrint(clientArrayList.get(i).toString());
        }
         }else{
             makeTextViewAndPrint("No clients");
         }





        return fragmentClientsBinding.getRoot();

    }

    @Override
    public void onDestroyView() {
        gymSqlQuery.closeGymDbHelper();
        super.onDestroyView();
    }

    private void makeTextViewAndPrint(String textViewText) {
        TextView textView = new TextView(getActivity());
        textView.setText(textViewText);

        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(
          LinearLayout.LayoutParams.MATCH_PARENT,
          LinearLayout.LayoutParams.WRAP_CONTENT
        );

        textView.setLayoutParams(params);
        fragmentClientsBinding.linearLayoutContainer.addView(textView);
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

    }
}
















































