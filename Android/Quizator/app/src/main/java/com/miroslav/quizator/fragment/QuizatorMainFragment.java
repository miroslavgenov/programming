package com.miroslav.quizator.fragment;

import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.databinding.DataBindingUtil;
import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.miroslav.quizator.Binding;
import com.miroslav.quizator.Questions;
import com.miroslav.quizator.R;
import com.miroslav.quizator.QuizatorMainXMLHelper;
import com.miroslav.quizator.actor.Player;
import com.miroslav.quizator.actor.Question;
import com.miroslav.quizator.actor.Questor;
import com.miroslav.quizator.actor.Quiz;
import com.miroslav.quizator.databinding.FragmentQuizatorMainBinding;

public class QuizatorMainFragment extends Fragment implements Binding {
    FragmentQuizatorMainBinding fragmentQuizatorMainBinding;
    FragmentQuizatorMainBinding dataBindingUtilContent;
    final int LAYOUT_QUIZATOR_MAIN_FRAGMENT_ID=  R.layout.fragment_quizator_main;
    Player quizPlayer;
    Questor quizQuestor;
    Questions questionsForQuiz;
    Quiz quiz;
    QuizatorMainXMLHelper quizatorMainXMLHelper;
    Bundle bundlePlayerScore;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        onCreateViewClassParametersInit(inflater,container);

        return fragmentQuizatorMainBinding.getRoot();
    }

    private void onCreateViewClassParametersInit(LayoutInflater inflater, ViewGroup container) {
        initFragmentDataBindingUtilContent(inflater,container);
        setBinding();
        quizatorMainXMLHelper = new QuizatorMainXMLHelper(fragmentQuizatorMainBinding);
        quizatorMainXMLHelper.initAllQuizatorMainXMLElements();
        initQuestions();
        initQuestor();
        initQuizPlayer();
    }

    @Override
    public void initFragmentDataBindingUtilContent(LayoutInflater inflater, ViewGroup container) {
        dataBindingUtilContent = DataBindingUtil.inflate(inflater,LAYOUT_QUIZATOR_MAIN_FRAGMENT_ID,container,false);
    }

    @Override
    public void setBinding() {
        fragmentQuizatorMainBinding = dataBindingUtilContent;
    }

    public void initQuestions(){
        this.questionsForQuiz = new Questions();
    }

    public void initQuestor(){
        quizQuestor = new Questor();
    }

    public void initQuizPlayer(){
        quizPlayer=new Player();
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        appendQuestions();
        quizInit();
        quizatorMainXMLHelper.setQuestionNumberToUI(quiz.getCurrentQuestionIndex());
        quizatorMainXMLHelper.setQuestionToUI(quiz.getFirstQuestion());
        onImageButtonToNextQuestionClick();
    }

    void quizInit(){
        this.quiz = new Quiz(this.questionsForQuiz);
    }

    private void onImageButtonToNextQuestionClick() {
        quizatorMainXMLHelper.getImageButtonToNextQuestion().setOnClickListener(view-> gameLogic());
    }

    private void gameLogic() {
        //TODO: xxx
        if(quiz.isQuizComplete()){

        }else{
            quizatorMainXMLHelper.setTextViewQuestionNumberText(quiz.toNextQuestionNumber());
            quizatorMainXMLHelper.setQuestionToUI(quiz.getCurrentQuestion());
        }


    }

    public void appendQuestions() {
        questionsForQuiz.appendQuestion(new Question("Software development","What is Agile ?",new String[]{"Project management methodology","Programming language"}));
        questionsForQuiz.appendQuestion(new Question("Computing","How many bit's 1 byte have ?",new String[]{"8","16"}));
        questionsForQuiz.appendQuestion(new Question("Roblox","Which language is used to program games in Roblox Studio?",new String[]{"Lua","C++"}));
        questionsForQuiz.appendQuestion(new Question("Web development","What is HTML ?",new String[]{"Markup language","File format"}));
        questionsForQuiz.appendQuestion(new Question("C++","How you can write a comment in C++ ?",new String[]{"//","#"}));
        questionsForQuiz.shuffleQuestions();
    }


    @Override
    public void initActivityDataBindingUtilContent() {

    }

    @Override
    public <T> T getBinding() {
        return (T) fragmentQuizatorMainBinding;
    }






}
















































































