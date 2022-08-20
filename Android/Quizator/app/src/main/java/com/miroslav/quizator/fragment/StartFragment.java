package com.miroslav.quizator.fragment;

import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.databinding.DataBindingUtil;
import androidx.fragment.app.Fragment;
import androidx.navigation.Navigation;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.miroslav.quizator.AlphaAnimationHelper;
import com.miroslav.quizator.Binding;
import com.miroslav.quizator.R;
import com.miroslav.quizator.databinding.FragmentStartBinding;


public class StartFragment extends Fragment implements Binding {
    FragmentStartBinding fragmentStartBinding;
    FragmentStartBinding dataBindingUtilContent;
    final int LAYOUT_START_FRAGMENT_ID = R.layout.fragment_start;
    final int CURRENT_TO_QUIZATOR_MAIN_FRAGMENT_ID = R.id.action_startFragment_to_quizatorMainFragment;


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        initFragmentDataBindingUtilContent(inflater, container);
        setBinding();

        return fragmentStartBinding.getRoot();
    }

    @Override
    public void initFragmentDataBindingUtilContent(LayoutInflater inflater, ViewGroup container) {
        this.dataBindingUtilContent = DataBindingUtil.inflate(inflater, LAYOUT_START_FRAGMENT_ID, container, false);
    }

    @Override
    public void setBinding() {
        this.fragmentStartBinding = this.dataBindingUtilContent;
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        iniAnimationForButtonPlay();

        fragmentStartBinding.buttonPlay.setOnClickListener(view1 -> Navigation.findNavController(view1).navigate(CURRENT_TO_QUIZATOR_MAIN_FRAGMENT_ID));
    }

    private void iniAnimationForButtonPlay() {
        new AlphaAnimationHelper(fragmentStartBinding.buttonPlay,0,1,1200);
    }

    @Override
    public <T> T getBinding() {
        return (T) fragmentStartBinding;
    }




    @Override
    public void initActivityDataBindingUtilContent() {}

}




























































