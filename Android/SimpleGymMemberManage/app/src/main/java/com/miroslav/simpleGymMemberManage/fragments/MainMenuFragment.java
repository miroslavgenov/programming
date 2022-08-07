package com.miroslav.simpleGymMemberManage.fragments;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.databinding.DataBindingUtil;
import androidx.fragment.app.Fragment;
import androidx.navigation.Navigation;


import com.miroslav.simpleGymMemberManage.MyEditTextController;
import com.miroslav.simpleGymMemberManage.R;
import com.miroslav.simpleGymMemberManage.databinding.FragmentMainMenuBinding;

public class MainMenuFragment extends Fragment {
    private ImageButton imageButtonSearchClient;
    private EditText editTextSearch;
    private Button buttonAddCard;
    private Button buttonAddClient;
    private Button buttonActiveClient;
    MyEditTextController myEditTextController ;

    int CURRENT_TO_ADD_CARD_FRAGMENT = R.id.action_mainMenuFragment_to_addCardFragment;
    int CURRENT_TO_ADD_CLIENT_FRAGMENT = R.id.action_mainMenuFragment_to_addClientFragment;
    int CURRENT_TO_ACTIVE_CLIENT_FRAGMENT= R.id.action_mainMenuFragment_to_activeClientFragment2;
    int CURRENT_TO_CLIENTS_FRAGMENT= R.id.action_mainMenuFragment_to_clientsFragment;
    int CURRENT_TO_CLIENT_FRAGMENT = R.id.action_mainMenuFragment_to_clientFragment;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        FragmentMainMenuBinding fragmentMainMenuBinding = DataBindingUtil.inflate(inflater, R.layout.fragment_main_menu,container,false);
        setInitialElementsFromXML(fragmentMainMenuBinding);

        return fragmentMainMenuBinding.getRoot();
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        // here you will need to execute operations like setEventListener and etc.
        super.onViewCreated(view, savedInstanceState);

        main();
    }



    /**
     *  navigates the current fragment to id from nav graph
     *
     * @param view
     * @param idToNavigate
     */
    private void myNavigationNavigate(View view,int idToNavigate) {
        Navigation.findNavController(view).navigate(idToNavigate);
    }
    private void myNavigationNavigate(View view,int idToNavigate,Bundle bundle) {
        Navigation.findNavController(view).navigate(idToNavigate,bundle);
    }




    private void main() {
        setOnAllButtonsClick();
    }

    private void setOnAllButtonsClick() {
        onButtonClick(getButtonAddCard(),()->{myNavigationNavigate(getButtonAddCard(),CURRENT_TO_ADD_CARD_FRAGMENT);});
        onButtonClick(getButtonAddClient(),()->{ myNavigationNavigate(getButtonAddCard(),CURRENT_TO_ADD_CLIENT_FRAGMENT);});
        onButtonClick(getButtonActiveClient(),()-> myNavigationNavigate(getButtonActiveClient(),CURRENT_TO_ACTIVE_CLIENT_FRAGMENT));

        onImageButtonClick(getImageButtonSearchClient(),this::searchLogic);
    }
    void searchLogic(){
        setMyEditTextController(getEditTextSearch());
        navigateToClientsOrClient();

    }

    private void navigateToClientsOrClient() {
        if(myEditTextController.isEditTextStringEmpty()){
            myNavigationNavigate(getImageButtonSearchClient(),CURRENT_TO_CLIENTS_FRAGMENT);
        }else{
            if(myEditTextController.isEditTextStringNumberGreaterThanZero()){
                myNavigationNavigate(getImageButtonSearchClient(),CURRENT_TO_CLIENT_FRAGMENT,getBundleClientId());
            }
        }
    }

    Bundle getBundleClientId(){
        Bundle bundle = new Bundle();
        bundle.putInt("clientId", myEditTextController.getEditTextStringInteger());
        return bundle;
    }


    private void setMyEditTextController(EditText editText) {
        myEditTextController = new MyEditTextController(editText);
    }

    void onImageButtonClick(ImageButton button , MyButtonEventLogicInterface myButtonEventLogicInterface){
        button.setOnClickListener(view -> myButtonEventLogicInterface.doThisFromFragment());
    }

    void onButtonClick(Button button , MyButtonEventLogicInterface myButtonEventLogicInterface){
        button.setOnClickListener(view -> myButtonEventLogicInterface.doThisFromFragment());
    }


//    SET


    void setImageButtonSearchClient(ImageButton imageButton){
        this.imageButtonSearchClient =imageButton;
    }

    void setEditTextSearch(EditText editText){
        this.editTextSearch=editText;
    }

    void setButtonAddClient(Button button){
        this.buttonAddClient=button;
    }

    void setButtonAddCard(Button button){
        this.buttonAddCard = button;
    }

    void setButtonActiveClient(Button button){
        this.buttonActiveClient=button;
    }

    private void setInitialElementsFromXML(FragmentMainMenuBinding binding) {
        setImageButtonSearchClient(binding.imageButtonSearch);
        setEditTextSearch(binding.editTextSearchClientId);
        setButtonAddClient(binding.buttonAddClient);
        setButtonAddCard(binding.buttonAddCard);
        setButtonActiveClient(binding.buttonActiveClients);
    }

    //    GET
    ImageButton getImageButtonSearchClient(){return this.imageButtonSearchClient;}
    EditText getEditTextSearch(){return this.editTextSearch;}
    Button getButtonAddClient(){return this.buttonAddClient;}
    Button getButtonAddCard(){return this.buttonAddCard;}
    Button getButtonActiveClient(){return this.buttonActiveClient;}
}








































