package com.miroslav.simpleGymMemberManage.fragments;

import android.content.Context;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.databinding.DataBindingUtil;
import androidx.databinding.ViewDataBinding;
import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;

import com.miroslav.simpleGymMemberManage.MySharedPrefs;
import com.miroslav.simpleGymMemberManage.R;
import com.miroslav.simpleGymMemberManage.SharedPrefsImp;
import com.miroslav.simpleGymMemberManage.actors.Card;
import com.miroslav.simpleGymMemberManage.databinding.FragmentActiveClientBinding;
import com.miroslav.simpleGymMemberManage.dateBase.CardSqlQuery;
import com.miroslav.simpleGymMemberManage.dateBase.ClientSqlQuery;

import java.util.ArrayList;


public class ActiveClientFragment extends Fragment implements SharedPrefsImp {


    MySharedPrefs mySharedPrefs;
    FragmentActiveClientBinding fragmentActiveClientBinding;
    final Integer ACTIVE_CLIENT_FRAGMENT_LAYOUT = R.layout.fragment_active_client;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        setFragmentActiveClientBinding(DataBindingUtil.inflate(inflater,ACTIVE_CLIENT_FRAGMENT_LAYOUT,container,false));

        return fragmentActiveClientBinding.getRoot();
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);


        CardSqlQuery cardSqlQuery = new CardSqlQuery();
        initializeSharedPrefs();
        cardSqlQuery.openDataBaseWithPassword(getContext(),mySharedPrefs.getUserPasswordFromSharedPrefs());

//        makeTextViewAndPrint("Total card "+String.valueOf(cardSqlQuery.getCountOfAllElements()));
        makeTextViewAndPrint("Client id's");

        ArrayList<Card> allActiveCardsFromDataBase = cardSqlQuery.getAllActiveCardsFromDataBase();

        if(allActiveCardsFromDataBase!=null){
            for (int value=0;value<allActiveCardsFromDataBase.size();value++){
                if(allActiveCardsFromDataBase.get(value).isCardActive()) {
                    makeTextViewAndPrint(String.valueOf(allActiveCardsFromDataBase.get(value).getCard_client_id()));
                }else{
                    allActiveCardsFromDataBase.get(value).setCard_active(false);
                    cardSqlQuery.updateCardActiveToInActive(allActiveCardsFromDataBase.get(value));
                    cardSqlQuery.closeGymDbHelper();

                    ClientSqlQuery clientSqlQuery = new ClientSqlQuery();
                    clientSqlQuery.openDataBaseWithPassword(getContext(),mySharedPrefs.getUserPasswordFromSharedPrefs());
                    clientSqlQuery.setClientCardIdToZero(allActiveCardsFromDataBase.get(value));
                    clientSqlQuery.closeGymDbHelper();

                }

            }
        }









    }

    private void makeTextViewAndPrint(String textViewText) {
        TextView textView = new TextView(getActivity());
        textView.setText(textViewText);

        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT,
                LinearLayout.LayoutParams.WRAP_CONTENT
        );

        textView.setLayoutParams(params);
        fragmentActiveClientBinding.linearLayoutActiveClients.addView(textView);
    }


    private void setFragmentActiveClientBinding(ViewDataBinding viewDataBinding) {
        this.fragmentActiveClientBinding = (FragmentActiveClientBinding) viewDataBinding;

    }

    @Override
    public void initializeSharedPrefs() {
        mySharedPrefs = new MySharedPrefs(getActivity(),getString(R.string.shared_prefs_file_key_card_password), Context.MODE_PRIVATE);
    }

    @Override
    public void initializeSharedPrefsAndSetUserPassword(String userPassword) {

    }
}














































































