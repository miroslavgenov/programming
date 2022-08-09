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

import com.miroslav.simpleGymMemberManage.MySharedPrefs;
import com.miroslav.simpleGymMemberManage.R;
import com.miroslav.simpleGymMemberManage.SharedPrefsImp;
import com.miroslav.simpleGymMemberManage.actors.Client;
import com.miroslav.simpleGymMemberManage.databinding.FragmentClientBinding;
import com.miroslav.simpleGymMemberManage.dateBase.ClientSqlQuery;

/**
 * A simple {@link Fragment} subclass.
 *
 */
public class ClientFragment extends Fragment implements SharedPrefsImp {

    FragmentClientBinding fragmentClientBinding;
    private ClientSqlQuery clientSqlQuery;
    MySharedPrefs mySharedPrefs;

    public ClientFragment() {
        // Required empty public constructor
    }

    @Override
    public void onDestroyView() {
        clientSqlQuery.closeGymDbHelper();
        super.onDestroyView();
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        fragmentClientBinding = DataBindingUtil.inflate(inflater,R.layout.fragment_client, container, false);

        return fragmentClientBinding.getRoot();

    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        Integer clientIdFromBundle = Integer.parseInt(getArguments().get("clientId").toString());

        clientSqlQuery = new ClientSqlQuery();
        initializeSharedPrefs();
        clientSqlQuery.openDataBaseWithPassword(getActivity(),mySharedPrefs.getUserPasswordFromSharedPrefs());

        Client clientFromQuery = clientSqlQuery.getClientFromDataBase(clientIdFromBundle);

        if(clientFromQuery!=null){
            fragmentClientBinding.setClient(clientFromQuery);
        }

    }

    @Override
    public void initializeSharedPrefs() {
        mySharedPrefs=new MySharedPrefs(getActivity(),getString(R.string.shared_prefs_file_key_card_password), Context.MODE_PRIVATE);
    }

    @Override
    public void initializeSharedPrefsAndSetUserPassword(String userPassword) {

    }
}






























