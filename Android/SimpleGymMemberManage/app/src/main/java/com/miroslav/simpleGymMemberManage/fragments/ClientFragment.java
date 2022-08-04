package com.miroslav.simpleGymMemberManage.fragments;

import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.databinding.DataBindingUtil;
import androidx.fragment.app.Fragment;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.miroslav.simpleGymMemberManage.R;
import com.miroslav.simpleGymMemberManage.actors.Client;
import com.miroslav.simpleGymMemberManage.databinding.FragmentClientBinding;
import com.miroslav.simpleGymMemberManage.dateBase.ClientSqlQuery;

/**
 * A simple {@link Fragment} subclass.
 *
 */
public class ClientFragment extends Fragment {

    FragmentClientBinding fragmentClientBinding;

    public ClientFragment() {
        // Required empty public constructor
    }

    @Override
    public void onDestroyView() {

        super.onDestroyView();
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        fragmentClientBinding = DataBindingUtil.inflate(inflater,R.layout.fragment_client, container, false);



        return (View) fragmentClientBinding.getRoot();

    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);


        Integer clientIdFromBundle = Integer.parseInt(getArguments().get("clientId").toString());



        ClientSqlQuery clientSqlQuery = new ClientSqlQuery();
        clientSqlQuery.openDataBase(getActivity());

        Client client = clientSqlQuery.getClientFromDataBase(clientIdFromBundle);

        if(client!=null){
            fragmentClientBinding.setClient(client);

        }
        clientSqlQuery.closeGymDbHelper();
    }
}






























