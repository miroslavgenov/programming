package com.miroslav.quizator.fragment;

import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.databinding.DataBindingUtil;
import androidx.databinding.ViewDataBinding;
import androidx.fragment.app.Fragment;

import android.transition.Scene;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.RadioButton;

import com.miroslav.quizator.AnimationDrawableHelper;
import com.miroslav.quizator.Binding;
import com.miroslav.quizator.R;
import com.miroslav.quizator.actor.Question;
import com.miroslav.quizator.databinding.FragmentQuizatorMainBinding;



public class QuizatorMainFragment extends Fragment implements Binding {
    FragmentQuizatorMainBinding fragmentQuizatorMainBinding;
    FragmentQuizatorMainBinding dataBindingUtilContent;
    final int LAYOUT_QUIZATOR_MAIN_FRAGMENT_ID=  R.layout.fragment_quizator_main;



    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        initFragmentDataBindingUtilContent(inflater,container);
        setBinding();


//





        return fragmentQuizatorMainBinding.getRoot();


    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        Question question = new Question("C++","What is this operator?",new String[]{"1","2"});
        Question question1= new Question("Java","What is this operator?",new String[]{"0","1"});
        fragmentQuizatorMainBinding.setQuestion(question);
        AlphaAnimation alphaAnimation = new AlphaAnimation(0,1);
        alphaAnimation.setDuration(1000);

        fragmentQuizatorMainBinding.imageButtonToNextQuestion.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                fragmentQuizatorMainBinding.setQuestion(question1);
                int checkedRadioButtonID = fragmentQuizatorMainBinding.radioGroupAnswers.getCheckedRadioButtonId();
                RadioButton radioButtonFirstAnswer = fragmentQuizatorMainBinding.radioButtonFirstAnswer;
                RadioButton radioButtonSecondAnswer = fragmentQuizatorMainBinding.radioButtonSecondAnswer;

//                fragmentQuizatorMainBinding.layoutQuestionRoot.startAnimation(alphaAnimation);
                    AlphaAnimation a = (AlphaAnimation) AnimationUtils.loadAnimation(getContext(),R.anim.animation_alpa);
                    fragmentQuizatorMainBinding.layoutQuestionRoot.startAnimation(a);




                //TODO make class to check which radio button is checked
//                if(radioButtonFirstAnswer.getId()==checkedRadioButtonID){
//                  fragmentQuizatorMainBinding.editTextQuestionTitle.setText(radioButtonFirstAnswer.getText().toString());
//                }else if(radioButtonSecondAnswer.getId()==checkedRadioButtonID){
//                    fragmentQuizatorMainBinding.editTextQuestionTitle.setText(radioButtonSecondAnswer.getText().toString());
//                }
            }
        });









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
















































































