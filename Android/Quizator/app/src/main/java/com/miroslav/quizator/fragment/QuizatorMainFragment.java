package com.miroslav.quizator.fragment;

import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.databinding.DataBindingUtil;
import androidx.fragment.app.Fragment;
import androidx.navigation.Navigation;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.view.animation.AnimationSet;
import android.view.animation.ScaleAnimation;
import android.widget.ImageButton;
import android.widget.LinearLayout;
import android.widget.TextView;

import com.miroslav.quizator.AlphaAnimationHelper;
import com.miroslav.quizator.Binding;
import com.miroslav.quizator.R;
import com.miroslav.quizator.RadioGroupHelper;
import com.miroslav.quizator.actor.Player;
import com.miroslav.quizator.actor.Question;
import com.miroslav.quizator.actor.Questor;
import com.miroslav.quizator.actor.Quiz;
import com.miroslav.quizator.databinding.FragmentQuizatorMainBinding;

import java.util.ArrayList;
import java.util.Collections;


public class QuizatorMainFragment extends Fragment implements Binding {
    FragmentQuizatorMainBinding fragmentQuizatorMainBinding;
    FragmentQuizatorMainBinding dataBindingUtilContent;
    final int LAYOUT_QUIZATOR_MAIN_FRAGMENT_ID=  R.layout.fragment_quizator_main;
    private ImageButton imageButtonToNextQuestion;
    LinearLayout layoutQuestionRoot;
    LinearLayout layoutAnswersRoot;
    TextView textViewQuestionNumber;
    AlphaAnimationHelper alphaAnimationHelper;
    Player quizPlayer;
    Questor quizQuestor;
    RadioGroupHelper radioGroupHelper;
    ArrayList<Question> questions;
    private Quiz quiz;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        initFragmentDataBindingUtilContent(inflater,container);
        setBinding();
        this.questions = new ArrayList<>();
        quizQuestor = new Questor();
        imageButtonToNextQuestion = fragmentQuizatorMainBinding.imageButtonToNextQuestion;
        layoutQuestionRoot = fragmentQuizatorMainBinding.layoutQuestionRoot;
        layoutAnswersRoot = fragmentQuizatorMainBinding.layoutAnswersRoot;
        textViewQuestionNumber = fragmentQuizatorMainBinding.textViewQuestionNumber;
        alphaAnimationHelper = new AlphaAnimationHelper(layoutQuestionRoot,layoutAnswersRoot,fragmentQuizatorMainBinding);
        quizPlayer=new Player();


        return fragmentQuizatorMainBinding.getRoot();
    }

    public void setQuestions() {

        Question[] questions= new Question[]{
            new Question("Software development","What is Agile?",new String[]{"project management methodology","programming language"}),
            new Question("C++","What is this operator?",new String[]{"pointer","object"}),
            new Question("Test++","What is this operator?",new String[]{"pointer","object"})
        };

        Collections.addAll(this.questions, questions);
    }

    void quizInit(){
        this.quiz = new Quiz(this.questions);

    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);


        setQuestions();
        this.quizInit();
        setTextViewQuestionNumberText(quiz.getCurrentQuestionNumber());
        setFirstQuestionToUI();
        initRadioGroupHelper();




        float scaleAnimationFromX=1f;
        float scaleAnimationFromY=1f;
        float scaleAnimationToX=1.2f;
        float scaleAnimationToY=1.2f;

        ScaleAnimation scaleAnimation1 = new ScaleAnimation(scaleAnimationToX,scaleAnimationFromX,scaleAnimationToY,scaleAnimationFromY);
        scaleAnimation1.setDuration(600);

        scaleAnimation1.setAnimationListener(new Animation.AnimationListener() {
            @Override
            public void onAnimationStart(Animation animation) {
                textViewQuestionNumber.setBackground(getResources().getDrawable(R.drawable.main_layout_gradient_start));
            }

            @Override
            public void onAnimationEnd(Animation animation) {
                textViewQuestionNumber.setBackground(getResources().getDrawable(R.drawable.radio_button_background_inactive_state));
            }

            @Override
            public void onAnimationRepeat(Animation animation) {

            }
        });


        ScaleAnimation scaleAnimation = new ScaleAnimation(scaleAnimationFromX,scaleAnimationToX,scaleAnimationFromY,scaleAnimationToY);
        scaleAnimation.setDuration(400);

        AlphaAnimation alphaAnimation = new AlphaAnimation(1,0);
        alphaAnimation.setDuration(100);

        AnimationSet animationSet = new AnimationSet(true);
        animationSet.setStartOffset(450);
        animationSet.addAnimation(scaleAnimation);
        animationSet.addAnimation(alphaAnimation);

        scaleAnimation.setAnimationListener(new Animation.AnimationListener() {
            @Override
            public void onAnimationStart(Animation animation) {

            }

            @Override
            public void onAnimationEnd(Animation animation) {

                textViewQuestionNumber.startAnimation(scaleAnimation1);

                textViewQuestionNumber.setText(String.valueOf(quiz.getCurrentQuestionNumber()));
            }

            @Override
            public void onAnimationRepeat(Animation animation) {

            }
        });



        imageButtonToNextQuestion.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                if(quiz.isQuizCompleted()){
                    quizQuestor.setQuestionAnswerPassedFromPlayer(radioGroupHelper.getSelectedAnswerFromPlayer());
                    quizQuestor.setQuestionGivenToPlayer(quiz.getQuestions().get(quiz.getCurrentQuestionNumber()));
                    Log.d("MyGym","quiz complete");
                    if(quizQuestor.isPlayerAnswerCorrect()){
                        Log.d("MyGym",radioGroupHelper.getSelectedAnswerFromPlayer());
                        quizPlayer.incrementScoreByOne();
                        Log.d("MyGym",String.valueOf(quizPlayer.getScore()));
                    }

                    Navigation.findNavController(view).navigate(R.id.action_quizatorMainFragment_to_resultFragment);


                }else{


                    quizQuestor.setQuestionAnswerPassedFromPlayer(radioGroupHelper.getSelectedAnswerFromPlayer());
                    quizQuestor.setQuestionGivenToPlayer(quiz.getQuestions().get(quiz.getCurrentQuestionNumber()));
                    Log.d("MyGym",String.valueOf(quizPlayer.getScore()));

                    if(quizQuestor.isPlayerAnswerCorrect()){
                        Log.d("MyGym",radioGroupHelper.getSelectedAnswerFromPlayer());
                        quizPlayer.incrementScoreByOne();
                        Log.d("MyGym",String.valueOf(quizPlayer.getScore()));
                    }
                    quiz.incrementQuestionNumber();

                    alphaAnimationHelper.setQuestion(
                            quiz.getQuestions().get(quiz.getCurrentQuestionNumber())
                    );


                    alphaAnimationHelper.startAnimation();

                    textViewQuestionNumber.startAnimation(animationSet);}
            }
        });
    }

    private void setFirstQuestionToUI() {
        fragmentQuizatorMainBinding.setQuestion(quiz.getFirstQuestion());
    }

    public void setTextViewQuestionNumberText(int questionNumber) {
        this.textViewQuestionNumber.setText(String.valueOf(questionNumber));
    }

    private void initRadioGroupHelper() {
        radioGroupHelper = new RadioGroupHelper(fragmentQuizatorMainBinding.radioGroupAnswers);
    }

    @Override
    public void initActivityDataBindingUtilContent() {

    }

    @Override
    public <T> T getBinding() {
        return (T) fragmentQuizatorMainBinding;
    }

    @Override
    public void initFragmentDataBindingUtilContent(LayoutInflater inflater, ViewGroup container) {
        dataBindingUtilContent = DataBindingUtil.inflate(inflater,LAYOUT_QUIZATOR_MAIN_FRAGMENT_ID,container,false);
    }

    @Override
    public void setBinding() {
        fragmentQuizatorMainBinding = dataBindingUtilContent;
    }


}
















































































