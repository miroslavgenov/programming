package com.miroslav.quizator.fragment;

import android.graphics.Color;
import android.graphics.LinearGradient;
import android.graphics.Shader;
import android.graphics.drawable.TransitionDrawable;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.databinding.DataBindingUtil;
import androidx.fragment.app.Fragment;
import androidx.navigation.Navigation;

import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;

import com.miroslav.quizator.Binding;
import com.miroslav.quizator.R;
import com.miroslav.quizator.databinding.FragmentStartBinding;


public class StartFragment extends Fragment implements Binding {
    FragmentStartBinding fragmentStartBinding;
    final int LAYOUT_START_FRAGMENT_ID = R.layout.fragment_start;
    FragmentStartBinding dataBindingUtilContent;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        initFragmentDataBindingUtilContent(inflater, container);
        this.setBinding();
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
    public <T> T getBinding() {
        return (T) fragmentStartBinding;
    }


    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);



        Button buttonPlay = fragmentStartBinding.buttonPlay;
        buttonPlay.setOnClickListener(view1 -> Navigation.findNavController(view1).navigate(R.id.action_startFragment_to_quizatorMainFragment));


//        TransitionDrawable transitionDrawable = (TransitionDrawable) buttonPlay.getBackground();
//        buttonPlay.setOnTouchListener((view1, motionEvent) -> {
//            if(motionEvent.getAction()==MotionEvent.ACTION_DOWN){
//                transitionDrawable.startTransition(50);
//            }else if(motionEvent.getAction()== MotionEvent.ACTION_UP){
//                transitionDrawable.reverseTransition(50);
//                Navigation.findNavController(view1).navigate(R.id.action_startFragment_to_quizatorMainFragment);
//            }
//            return false;
//        });

    }

    @Override
    public void initActivityDataBindingUtilContent() {

    }

}




























































