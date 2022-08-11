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
import com.miroslav.simpleGymMemberManage.MyToast;
import com.miroslav.simpleGymMemberManage.R;
import com.miroslav.simpleGymMemberManage.SharedPrefsImp;
import com.miroslav.simpleGymMemberManage.actors.Card;
import com.miroslav.simpleGymMemberManage.actors.Client;
import com.miroslav.simpleGymMemberManage.databinding.FragmentAddCardBinding;
import com.miroslav.simpleGymMemberManage.dateBase.CardSqlQuery;
import com.miroslav.simpleGymMemberManage.dateBase.ClientSqlQuery;

import java.util.ArrayList;
import java.util.Date;

/**
 * A simple {@link Fragment} subclass.
 *
 */
public class AddCardFragment extends Fragment implements SharedPrefsImp {

   FragmentAddCardBinding fragmentAddCardBinding;
   MySharedPrefs mySharedPrefs;
   ClientSqlQuery clientSqlQuery;
   Client client;
   Card cardContract;
   MyEditTextController myEditTextController;
   private CardSqlQuery cardSqlQuery;

    public AddCardFragment() {
        // Required empty public constructor
    }

    void initializeCardContract(){
        cardContract = new Card(new Date());
//        cardContract.setCard_price(mySharedPrefs.getCardPriceFromSharedPrefs());
        cardContract.setCard_day(31);
        fragmentAddCardBinding.setCard(cardContract);
    }

    @Override
    public void onDestroyView() {
        if(clientSqlQuery!=null) {
            clientSqlQuery.closeGymDbHelper();
        }
        if(cardSqlQuery!=null){
            cardSqlQuery.closeGymDbHelper();
        }

        super.onDestroyView();
    }

    void setMyEditTextController(EditText editText){
        myEditTextController = new MyEditTextController(editText);
    }

    Card getCardContract(){return this.cardContract;}

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
        initializeCardContract();
        clientSqlQuery = new ClientSqlQuery(getContext(), mySharedPrefs.getUserPasswordFromSharedPrefs());
        clientSqlQuery.openDataBaseWithPassword();

        cardSqlQuery = new CardSqlQuery(getContext(),mySharedPrefs.getUserPasswordFromSharedPrefs());
        cardSqlQuery.openDataBaseWithPassword();



        fragmentAddCardBinding.buttonAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                setMyEditTextController(getEditTextClientId());
                if(myEditTextController.isEditTextTextCorrectNumber()){
                    setClientToClientFoundFromDataBase();
                    if(client!=null){
                        MyEditTextController myEditTextPriceController = new MyEditTextController(fragmentAddCardBinding.editTextCardPrice);
                        if(client.getClient_card_id()==0 && myEditTextPriceController.isEditTextTextCorrectNumber()){





                                MyToast.makeToastSetMessageSetGravityCenterAndShowLong(getActivity(),"Card added");
                                cardContract.setCard_price(myEditTextPriceController.getEditTextStringInteger());
                                cardContract.setCard_client_id(client.getClient_id());
                                cardSqlQuery.insertCardToDataBaseAndUpdateClientCardId(cardContract,client);



//                            clientSqlQuery.closeGymDbHelper();



//                            cardSqlQuery.closeGymDbHelper();



                        }else if(!myEditTextPriceController.isEditTextTextCorrectNumber()){
                            MyToast.makeToastSetMessageSetGravityCenterAndShowLong(getActivity(),"Change the price!");
                        }
                        else{
                            // if card id is !=0
                            // check if the client have inactive card and remove it
                            ArrayList<Card> allActiveCards = cardSqlQuery.getAllActiveCardsFromDataBase();

                            if(allActiveCards!=null){
                                for(int i=0;i<allActiveCards.size();i++) {
                                    if (!allActiveCards.get(i).isCardActive()){
                                        clientSqlQuery.setClientCardIdToZero(allActiveCards.get(i));
                                    }
                                }
                            }
                            MyToast.makeToastSetMessageSetGravityCenterAndShowLong(getActivity(),"Client have card");

                        }
                    }else{
                        MyToast.makeToastSetMessageSetGravityCenterAndShowLong(getActivity(),"Client doesn't exists");

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

    //TODO
    void setOnButtonsClick(){
        //TODO
        onButtonClick(null,null);
    }

    private void onButtonClick(Button button , MyButtonEventLogicImp myButtonEventLogicInterface) {
        button.setOnClickListener(view -> myButtonEventLogicInterface.doThisFromFragment());
    }



    private void setClientToClientFoundFromDataBase() {
        client = clientSqlQuery.getClientFromDataBase(myEditTextController.getEditTextStringInteger());
    }

    @Override
    public void initializeSharedPrefs() {
        mySharedPrefs = new MySharedPrefs(getActivity(),getString(R.string.shared_prefs_file_key_card_password), Context.MODE_PRIVATE);


    }

    @Override
    public void initializeSharedPrefsAndSetUserPassword(String userPassword) {

    }


}

























