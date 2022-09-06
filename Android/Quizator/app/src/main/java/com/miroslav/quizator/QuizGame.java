package com.miroslav.quizator;

import android.os.Bundle;

import androidx.navigation.Navigation;

import com.miroslav.quizator.actor.Player;
import com.miroslav.quizator.actor.Question;
import com.miroslav.quizator.actor.Questor;
import com.miroslav.quizator.actor.Quiz;
import com.miroslav.quizator.initializer.GameUtilInitializer;

public class QuizGame {
    Player quizPlayer;
    Questor quizQuestor;
    Quiz quiz;

    public QuizGame(){
        this.quizQuestor = GameUtilInitializer.createQuestor();
    }

    public void setQuestionGivenToPlayer(Question question){
        quizQuestor.setQuestionGivenToPlayer(question);
    }


    private void gameLogic() {

    }

}






















