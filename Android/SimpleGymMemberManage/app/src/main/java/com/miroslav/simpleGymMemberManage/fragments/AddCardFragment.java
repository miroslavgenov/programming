package com.miroslav.simpleGymMemberManage.fragments;

import android.content.Context;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.databinding.DataBindingUtil;
import androidx.fragment.app.Fragment;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import com.miroslav.simpleGymMemberManage.MySharedPrefs;
import com.miroslav.simpleGymMemberManage.R;
import com.miroslav.simpleGymMemberManage.SharedPrefsInitializer;
import com.miroslav.simpleGymMemberManage.actors.Card;
import com.miroslav.simpleGymMemberManage.actors.Client;
import com.miroslav.simpleGymMemberManage.databinding.FragmentAddCardBinding;
import com.miroslav.simpleGymMemberManage.dateBase.CardSqlQuery;
import com.miroslav.simpleGymMemberManage.dateBase.ClientSqlQuery;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * A simple {@link Fragment} subclass.
 *
 */
public class AddCardFragment extends Fragment implements SharedPrefsInitializer {

   FragmentAddCardBinding fragmentAddCardBinding;
   MySharedPrefs mySharedPrefs;
   ClientSqlQuery clientSqlQuery;
   Client client;
    public AddCardFragment() {
        // Required empty public constructor
    }





    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        fragmentAddCardBinding = DataBindingUtil.inflate(inflater,R.layout.fragment_add_card, container, false);
        return fragmentAddCardBinding.getRoot();
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);


        initializeSharedPrefs();


        Card card = new Card(new Date());
        card.setCard_price(mySharedPrefs.getCardPriceFromSharedPrefs());
        fragmentAddCardBinding.setCard(card);

        fragmentAddCardBinding.buttonAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(!fragmentAddCardBinding.editTextClientID.getText().toString().isEmpty() && Integer.parseInt(fragmentAddCardBinding.editTextClientID.getText().toString())>0){
                    if(isClientIdExist(Integer.parseInt(fragmentAddCardBinding.editTextClientID.getText().toString()))){
                        // check if client don't have card;


                        client = clientSqlQuery.getClientFromDataBase(Integer.parseInt(fragmentAddCardBinding.editTextClientID.getText().toString()));



                        Log.d("MyGym",""+client.getClient_card_id());

                        if(client.getClient_card_id()==0){
                        //TODO insert card to client who don't have card
                            Toast.makeText(getContext(),"Client can make card",Toast.LENGTH_LONG).show();
                            CardSqlQuery cardSqlQuery  = new CardSqlQuery();
                            cardSqlQuery.openDataBase(getContext());

                            cardSqlQuery.insertCardToDataBaseAndUpdateClientCardId(card,client);




                        }else{
                            Toast.makeText(getContext(),"Client have card",Toast.LENGTH_LONG).show();
                        }

//                        Toast.makeText(getContext(),"Client exists",Toast.LENGTH_LONG).show();
                    }else{
                        Toast.makeText(getContext(),"Client doesn't exists",Toast.LENGTH_LONG).show();
                    }

                }
            }
        });



    }

    public boolean isClientIdExist(Integer clientId) {
        clientSqlQuery = new ClientSqlQuery();
        clientSqlQuery.openDataBase(getContext());
        Client client = clientSqlQuery.getClientFromDataBase(clientId);
        if(client!=null){
            clientSqlQuery.closeGymDbHelper();
            return true;
        }
        else {
            clientSqlQuery.closeGymDbHelper();
            return false;
        }
    }

    @Override
    public void initializeSharedPrefs() {
        mySharedPrefs = new MySharedPrefs(getActivity(),getString(R.string.shared_prefs_file_key_card_price_default), Context.MODE_PRIVATE);


    }
}

























