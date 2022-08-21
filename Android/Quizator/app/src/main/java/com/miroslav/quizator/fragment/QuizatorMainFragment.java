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
import com.miroslav.quizator.AnimationSetHelper;
import com.miroslav.quizator.Binding;
import com.miroslav.quizator.MyError;
import com.miroslav.quizator.R;
import com.miroslav.quizator.RadioGroupHelper;
import com.miroslav.quizator.ScaleAnimationHelper;
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
    AlphaAnimationHelper alphaAnimationHelperForLayoutQuestionAndAnswers;
    Player quizPlayer;
    Questor quizQuestor;
    RadioGroupHelper radioGroupHelper;
    ArrayList<Question> questions;
    private Quiz quiz;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    public void initQuestions(){
        this.questions = new ArrayList<>();
    }
    public void initQuestor(){
        quizQuestor = new Questor();
    }

    public void initQuizPlayer(){
        quizPlayer=new Player();
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        initFragmentDataBindingUtilContent(inflater,container);
        setBinding();
        initQuestions();
        initQuestor();
        initQuizPlayer();
        initImageButtonToNextQuestion();


        initLayoutQuestionRoot();

        initLayoutAnswersRoot();

        initTextViewQuestionNumber();

        try {
            initAlphaAnimationHelperForLayoutQuestionAndAnswers();
        } catch (MyError e) {
            e.printStackTrace();
        }


        return fragmentQuizatorMainBinding.getRoot();
    }

    private void initAlphaAnimationHelperForLayoutQuestionAndAnswers() throws MyError {

            if(layoutAnswersRoot==null || layoutQuestionRoot==null || fragmentQuizatorMainBinding == null){
                throw new MyError("QuizatorMainFragment.initialAlphaAnimationHelper() Answer or Question or fragmentBinding is null !!! ");
            }else{
                alphaAnimationHelperForLayoutQuestionAndAnswers = new AlphaAnimationHelper(layoutQuestionRoot, layoutAnswersRoot, fragmentQuizatorMainBinding);
            }


    }

    private void initTextViewQuestionNumber() {
        textViewQuestionNumber = fragmentQuizatorMainBinding.textViewQuestionNumber;
    }

    private void initLayoutAnswersRoot() {
        layoutAnswersRoot = fragmentQuizatorMainBinding.layoutAnswersRoot;
    }

    private void initLayoutQuestionRoot() {
        layoutQuestionRoot = fragmentQuizatorMainBinding.layoutQuestionRoot;
    }

    private void initImageButtonToNextQuestion() {
        imageButtonToNextQuestion = fragmentQuizatorMainBinding.imageButtonToNextQuestion;
    }

    public void setQuestions() {

        Question[] questions= new Question[]{
            new Question("Software development","What is Agile ?",new String[]{"Project management methodology","Programming language"}),
            new Question("Computing","How many bit's 1 byte have ?",new String[]{"8","16"}),
            new Question("Roblox","Which language is used to program games in Roblox Studio?",new String[]{"Lua","C++"}),
            new Question("Web development","What is HTML ?",new String[]{"Markup language","File format"}),
            new Question("C++","How did you write a comment in C++ ?",new String[]{"//","#"})
        };

        Collections.addAll(this.questions, questions);
        Collections.shuffle(this.questions);
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


        // TODO EDIT THE ANIMATION
        float[] scaleAnimationFromXYToXY = new float[]{
            1f,
            1f,
            1.2f,
            1.2f
        };
//        float scaleAnimationFromX=1f;
//        float scaleAnimationFromY=1f;
//        float scaleAnimationToX=1.2f;
//        float scaleAnimationToY=1.2f;

        ScaleAnimation secondScaleAnimationFotQuestionNumberEditText = ScaleAnimationHelper.createAnimation(scaleAnimationFromXYToXY[0],scaleAnimationFromXYToXY[2],scaleAnimationFromXYToXY[1],scaleAnimationFromXYToXY[3],600);

        secondScaleAnimationFotQuestionNumberEditText.setAnimationListener(new Animation.AnimationListener() {
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

        ScaleAnimation firstScaleAnimationFotQuestionNumberEditText = ScaleAnimationHelper.createAnimation(scaleAnimationFromXYToXY[2],scaleAnimationFromXYToXY[0],scaleAnimationFromXYToXY[3],scaleAnimationFromXYToXY[1],400);

        AlphaAnimation alphaAnimationFotQuestionNumberEditText = AlphaAnimationHelper.createAlphaAnimation(1,0,100);

        AnimationSet animationSetForQuestionNumberEditText = AnimationSetHelper.createAnimationSet(true,450,new Animation[]{
                firstScaleAnimationFotQuestionNumberEditText,alphaAnimationFotQuestionNumberEditText
        });

        firstScaleAnimationFotQuestionNumberEditText.setAnimationListener(new Animation.AnimationListener() {
            @Override
            public void onAnimationStart(Animation animation) {

            }

            @Override
            public void onAnimationEnd(Animation animation) {

                textViewQuestionNumber.startAnimation(secondScaleAnimationFotQuestionNumberEditText);
                setTextViewQuestionNumberText(quiz.getCurrentQuestionNumber());
//                textViewQuestionNumber.setText(String.valueOf(quiz.getCurrentQuestionNumber()));
            }

            @Override
            public void onAnimationRepeat(Animation animation) {

            }
        });



        imageButtonToNextQuestion.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                if(quiz.isQuizCompleted()){
                    quizQuestor.setQuestionAnswerPassedFromPlayer(radioGroupHelper.getCheckedAnswerFromPlayer());
                    quizQuestor.setQuestionGivenToPlayer(questions.get(quiz.getCurrentQuestionNumber()));

                    if(quizQuestor.isPlayerAnswerCorrect()){
                        quizPlayer.setScore(quizPlayer.incrementScoreByOne());
                    }

                    Bundle bundle = new Bundle();
                    bundle.putInt("player_score",quizPlayer.getScore());
                    Navigation.findNavController(view).navigate(R.id.action_quizatorMainFragment_to_resultFragment,bundle);
                }else{
                    if(Questor.isPlayerAnswerCorrect(questions.get(quiz.getCurrentQuestionNumber()),radioGroupHelper.getCheckedAnswerFromPlayer())){
                        quizPlayer.setScore(quizPlayer.incrementScoreByOne());
                    }

                    quiz.incrementQuestionNumber();

                    alphaAnimationHelperForLayoutQuestionAndAnswers.setQuestionForAnimation(quiz.getQuestionBesideCurrentQuestionNumber(quiz.getCurrentQuestionNumber()));
                    alphaAnimationHelperForLayoutQuestionAndAnswers.startAnimation();
                    textViewQuestionNumber.startAnimation(animationSetForQuestionNumberEditText);

                }
            }
        });
    }

    void setTextViewQuestionNumberText(String number){
        fragmentQuizatorMainBinding.textViewQuestionNumber.setText(number);
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
















































































