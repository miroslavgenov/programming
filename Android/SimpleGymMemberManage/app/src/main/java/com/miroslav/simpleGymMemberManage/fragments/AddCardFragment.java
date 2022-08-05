package com.miroslav.simpleGymMemberManage.fragments;

import android.content.Context;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.databinding.DataBindingUtil;
import androidx.fragment.app.Fragment;
import androidx.navigation.Navigation;

import android.util.Log;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.Toast;

import com.miroslav.simpleGymMemberManage.MyEditTextController;
import com.miroslav.simpleGymMemberManage.MySharedPrefs;
import com.miroslav.simpleGymMemberManage.R;
import com.miroslav.simpleGymMemberManage.SharedPrefsInitializer;
import com.miroslav.simpleGymMemberManage.actors.Card;
import com.miroslav.simpleGymMemberManage.actors.Client;
import com.miroslav.simpleGymMemberManage.databinding.FragmentAddCardBinding;
import com.miroslav.simpleGymMemberManage.dateBase.CardSqlQuery;
import com.miroslav.simpleGymMemberManage.dateBase.ClientSqlQuery;

import java.util.Date;

/**
 * A simple {@link Fragment} subclass.
 *
 */
public class AddCardFragment extends Fragment implements SharedPrefsInitializer {

   FragmentAddCardBinding fragmentAddCardBinding;
   MySharedPrefs mySharedPrefs;
   ClientSqlQuery clientSqlQuery;
   Client client;
   MyEditTextController myEditTextController;
    private CardSqlQuery cardSqlQuery;

    public AddCardFragment() {
        // Required empty public constructor
    }


    @Override
    public void onDestroyView() {
        clientSqlQuery.closeGymDbHelper();
        if(cardSqlQuery!=null){
            cardSqlQuery.closeGymDbHelper();
        }

        super.onDestroyView();
    }

    void setMyEditTextController(EditText editText){
        myEditTextController = new MyEditTextController(editText);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        fragmentAddCardBinding = DataBindingUtil.inflate(inflater,R.layout.fragment_add_card, container, false);
        return fragmentAddCardBinding.getRoot();
    }
    EditText getEditTextClientId(){
        return fragmentAddCardBinding.editTextClientID;
    }
    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);


        initializeSharedPrefs();
        clientSqlQuery = new ClientSqlQuery();
        clientSqlQuery.openDataBase(getContext());


        Card card = new Card(new Date(122,03,04));

        card.setCard_price(mySharedPrefs.getCardPriceFromSharedPrefs());
        fragmentAddCardBinding.setCard(card);

        fragmentAddCardBinding.buttonAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                setMyEditTextController(getEditTextClientId());

                if(myEditTextController.isEditTextTextCorrect()){

                    setClientToClientFoundFromDataBase();

                    if(client!=null){
                        // check if client don't have card;
                        Log.d("MyGym","client!=null client_card_id= "+client.getClient_card_id());


                        if(client.getClient_card_id()==0){
                            Log.d("MyGym","client_card_id==0: "+client.getClient_card_id());
                            //TODO insert card to client who don't have card
                            makeToastSetTextSetGravityAndShow("Client can make card");

                            cardSqlQuery  = new CardSqlQuery();
                            cardSqlQuery.openDataBase(getContext());
                            card.setCard_price(mySharedPrefs.getCardPriceFromSharedPrefs());

                            cardSqlQuery.insertCardToDataBaseAndUpdateClientCardId(card,client);

                        }else{
                            makeToastSetTextSetGravityAndShow("Client have card");
                        }

//                        Toast.makeText(getContext(),"Client exists",Toast.LENGTH_LONG).show();
                    }else{
                        makeToastSetTextSetGravityAndShow("Client doesn't exists");
                    }
                }
            }
        });

       fragmentAddCardBinding.buttonCancel.setOnClickListener(new View.OnClickListener() {
           @Override
           public void onClick(View view) {
               Navigation.findNavController(view).popBackStack();
           }
       });

    }

    private void makeToastSetTextSetGravityAndShow(String MESSAGE) {
        Toast toast;
        toast= Toast.makeText(getActivity(), MESSAGE,Toast.LENGTH_LONG);
        toast.setGravity(Gravity.CENTER,0,0);
        toast.show();
    }

    private void setClientToClientFoundFromDataBase() {
        client = clientSqlQuery.getClientFromDataBase(myEditTextController.getEditTextStringInteger());
    }

    @Override
    public void initializeSharedPrefs() {
        mySharedPrefs = new MySharedPrefs(getActivity(),getString(R.string.shared_prefs_file_key_card_price_default), Context.MODE_PRIVATE);


    }

    @Override
    public void initializeSharedPrefsAndSetCardPrice(int cardPrice) {

    }
}

























