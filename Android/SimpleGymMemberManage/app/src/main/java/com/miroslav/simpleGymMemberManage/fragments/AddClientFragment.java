package com.miroslav.simpleGymMemberManage.fragments;

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
import android.widget.Toast;

import com.miroslav.simpleGymMemberManage.R;
import com.miroslav.simpleGymMemberManage.databinding.FragmentAddClientBinding;
import com.miroslav.simpleGymMemberManage.dateBase.ClientSqlQuery;
//import com.miroslav.simpleGymMemberManage.dateBase.GymSqlQuery;


public class AddClientFragment extends Fragment {
    FragmentAddClientBinding fragmentAddClientBinding;
//    GymSqlQuery gymSqlQuery;
    ClientSqlQuery clientSqlQuery;
    Integer clientId;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        fragmentAddClientBinding = DataBindingUtil.inflate(inflater,R.layout.fragment_add_client,container,false);
        return fragmentAddClientBinding.getRoot();
    }

    @Override
    public void onDestroyView() {
        clientSqlQuery.closeGymDbHelper();
        super.onDestroyView();
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        this.clientSqlQuery = new ClientSqlQuery();
        this.clientSqlQuery.openDataBase(getActivity().getApplicationContext());

        clientId = clientSqlQuery.getCountOfAllElements();
        fragmentAddClientBinding.textViewClientIdNumber.setText(String.valueOf(clientId +1));

        fragmentAddClientBinding.buttonAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                if(!fragmentAddClientBinding.editTextClientName.getText().toString().isEmpty()) {

                    clientSqlQuery.insertData(fragmentAddClientBinding.editTextClientName.getText().toString());
                    clientId= clientSqlQuery.getCountOfAllElements();
                    fragmentAddClientBinding.textViewClientIdNumber.setText(String.valueOf(clientId+1));

                    Toast toast =  Toast.makeText(getActivity(),"Client added",Toast.LENGTH_LONG);
                    toast.setGravity(Gravity.CENTER,0,0);

                    toast.show();
                }
            }
        });

        fragmentAddClientBinding.buttonCancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Navigation.findNavController(view).popBackStack();
            }
        });


    }
}






























