package com.miroslav.quizator.fragment;

import android.os.Bundle;

import androidx.databinding.DataBindingUtil;
import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.AlphaAnimation;
import android.widget.TextView;

import com.miroslav.quizator.R;
import com.miroslav.quizator.databinding.FragmentResultBinding;


public class ResultFragment extends Fragment {

    FragmentResultBinding fragmentResultBinding;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        fragmentResultBinding = DataBindingUtil.inflate(inflater,R.layout.fragment_result,container,false);
        Bundle bundlePlayerScoreResult = getArguments();
        final int PLAYER_SCORE_RESULT =bundlePlayerScoreResult.getInt("player_score");

        TextView textViewPlayerScore = fragmentResultBinding.textViewPlayerScore;
        AlphaAnimation alphaAnimationForButtonPlay = new AlphaAnimation(0,1);
        alphaAnimationForButtonPlay.setDuration(1200);
        textViewPlayerScore.startAnimation(alphaAnimationForButtonPlay);
        textViewPlayerScore.setText(String.valueOf(PLAYER_SCORE_RESULT));

        return fragmentResultBinding.getRoot();
    }
}






















































