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


import com.miroslav.simpleGymMemberManage.R;
import com.miroslav.simpleGymMemberManage.databinding.FragmentMainMenuBinding;

public class MainMenuFragment extends Fragment {
    private ImageButton imageButtonSearchClient;
    private EditText editTextSearch;
    private Button buttonAddCard;
    private Button buttonAddClient;
    private Button buttonActiveClient;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        FragmentMainMenuBinding fragmentMainMenuBinding = DataBindingUtil.inflate(inflater, R.layout.fragment_main_menu,container,false);
        setInitialElementsFromXML(fragmentMainMenuBinding);




//        View view = fragmentMainMenuBinding.getRoot();
        return fragmentMainMenuBinding.getRoot();
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        // here you will need to execute operations like setEventListener and etc.
        super.onViewCreated(view, savedInstanceState);


        getButtonAddCard().setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Navigation.findNavController(view).navigate(R.id.action_mainMenuFragment_to_addCardFragment);
            }
        });

        getButtonAddClient().setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Navigation.findNavController(view).navigate(R.id.action_mainMenuFragment_to_addClientFragment);
            }
        });

        getImageButtonSearchClient().setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(getEditTextSearch().getText().toString().isEmpty()){
                    Navigation.findNavController(view).navigate(R.id.action_mainMenuFragment_to_clientsFragment);
                }
            }
        });

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








































