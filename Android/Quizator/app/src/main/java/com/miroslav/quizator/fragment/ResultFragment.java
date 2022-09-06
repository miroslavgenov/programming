package com.miroslav.quizator.fragment;

import android.os.Bundle;

import androidx.databinding.DataBindingUtil;
import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;


import com.miroslav.quizator.AlphaAnimationHelper;
import com.miroslav.quizator.Layout;
import com.miroslav.quizator.R;
import com.miroslav.quizator.databinding.FragmentResultBinding;


public class ResultFragment extends Fragment {
    FragmentResultBinding fragmentResultBinding;


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        fragmentResultBinding = DataBindingUtil.inflate(inflater, Layout.ResultFragment.toInt(), container,false);

        Bundle bundlePlayerScoreResult = getArguments();
        final int PLAYER_SCORE_RESULT =bundlePlayerScoreResult.getInt("player_score");

        new AlphaAnimationHelper(fragmentResultBinding.textViewPlayerScore,0,1,1200);
        fragmentResultBinding.textViewPlayerScore.setText(String.valueOf(PLAYER_SCORE_RESULT));

        return fragmentResultBinding.getRoot();
    }
}






















































