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
import com.miroslav.quizator.QuizGame;
import com.miroslav.quizator.Layout;
import com.miroslav.quizator.R;
import com.miroslav.quizator.QuizatorMainXMLHelper;
import com.miroslav.quizator.actor.Player;
import com.miroslav.quizator.actor.Questor;
import com.miroslav.quizator.actor.Quiz;
import com.miroslav.quizator.databinding.FragmentQuizatorMainBinding;

public class QuizatorMainFragment extends Fragment implements Binding {
    FragmentQuizatorMainBinding fragmentQuizatorMainBinding;
    FragmentQuizatorMainBinding dataBindingUtilContent;
    Player quizPlayer;
    Questor quizQuestor;
    Quiz quiz;
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
        quizGame = new QuizGame();
        return fragmentQuizatorMainBinding.getRoot();
    }

    private void onCreateViewClassParametersInit(LayoutInflater inflater, ViewGroup container) {
        initFragmentDataBindingUtilContent(inflater, container);
        setBinding();
        quizatorMainXMLHelper = new QuizatorMainXMLHelper(fragmentQuizatorMainBinding);
        quizatorMainXMLHelper.initAllQuizatorMainXMLElements();
        initQuestor();
        initQuizPlayer();
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

    public void initQuestor() {
        quizQuestor = new Questor();
    }

    public void initQuizPlayer() {
        quizPlayer = new Player();
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        quizInit();
        quizatorMainXMLHelper.setQuestionNumberToUI(quiz.getCurrentQuestionIndex());
        quizatorMainXMLHelper.setQuestionToUI(quiz.getFirstQuestion());
        onImageButtonToNextQuestionClick();
    }

    void quizInit() {
        this.quiz = new Quiz();
    }

    private void onImageButtonToNextQuestionClick() {
        quizatorMainXMLHelper.getImageButtonToNextQuestion().setOnClickListener(
                view -> gameLogic()
        );
    }

    private void gameLogic() {

        quizQuestor.setQuestionGivenToPlayer(quiz.getCurrentQuestion());
//        quizGame.setQuestionGivenToPlayer(quiz.getCurrentQuestion());
        quizQuestor.setQuestionAnswerPassedFromPlayer(
                quizatorMainXMLHelper.getRadioGroupHelper().getCheckedAnswerFromPlayer());

        if (quiz.isQuizComplete()) {
            incrementPlayerScoreIfAnswerCorrect();

            bundlePlayerScore = new Bundle();
            bundlePlayerScore.putInt("player_score", quizPlayer.getScore());
            Navigation.findNavController(
                    quizatorMainXMLHelper.getImageButtonToNextQuestion()).navigate(
                            R.id.action_quizatorMainFragment_to_resultFragment, bundlePlayerScore
            );
        } else {
            incrementPlayerScoreIfAnswerCorrect();

            quiz.setCurrentQuestionIndex(quiz.incrementCurrentQuestionIndexByOne());
            quizatorMainXMLHelper.setTextViewQuestionNumberText(quiz.getCurrentQuestionIndex());
            quizatorMainXMLHelper.setQuestionToUI(quiz.getCurrentQuestion());
        }
    }

    private void incrementPlayerScoreIfAnswerCorrect() {
        if (quizQuestor.isPlayerAnswerCorrect()) {
            quizPlayer.setScore(quizPlayer.incrementScoreByOne());
        }
    }




}
















































































