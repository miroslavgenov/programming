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

import com.miroslav.quizator.Binding;
import com.miroslav.quizator.MyNav;
import com.miroslav.quizator.QuizGame;
import com.miroslav.quizator.Layout;
import com.miroslav.quizator.QuizatorMainXMLHelper;
import com.miroslav.quizator.databinding.FragmentQuizatorMainBinding;

public class QuizatorMainFragment extends Fragment implements Binding {
    FragmentQuizatorMainBinding fragmentQuizatorMainBinding;
    FragmentQuizatorMainBinding dataBindingUtilContent;
    QuizGame quizGame;
    QuizatorMainXMLHelper quizatorMainXMLHelper;
    Bundle bundlePlayerScore;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        onCreateViewClassParametersInit(inflater, container);

        return fragmentQuizatorMainBinding.getRoot();
    }

    private void onCreateViewClassParametersInit(LayoutInflater inflater, ViewGroup container) {
        initFragmentDataBindingUtilContent(inflater, container);
        setBinding();
        quizatorMainXMLHelper = new QuizatorMainXMLHelper(fragmentQuizatorMainBinding);
        quizatorMainXMLHelper.initAllQuizatorMainXMLElements();
        quizGame = new QuizGame(quizatorMainXMLHelper);
    }

    @Override
    public void initFragmentDataBindingUtilContent(LayoutInflater inflater, ViewGroup container) {
        dataBindingUtilContent = DataBindingUtil.inflate(
                inflater, Layout.QuizatorMainFragment.toInt(), container, false);
    }

    @Override
    public void setBinding() {
        fragmentQuizatorMainBinding = dataBindingUtilContent;
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        onImageButtonToNextQuestionClick();
    }

    private void onImageButtonToNextQuestionClick() {
        quizatorMainXMLHelper.getImageButtonToNextQuestion().setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(quizGame.isQuizCompleted()){
                    quizGame.quizGameLogic();
                    bundlePlayerScore = new Bundle();
                    bundlePlayerScore.putInt("player_score",quizGame.getPlayerScore());
                    int toResultFragment = MyNav.TO_RESULT_FRAGMENT.toInt();
                    Navigation.findNavController(view).navigate(toResultFragment,bundlePlayerScore);
                }else{
                    quizGame.quizGameLogic();
                }
            }
        });
    }
}
















































































