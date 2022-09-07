package com.miroslav.quizator.initializer;

import com.miroslav.quizator.actor.Player;
import com.miroslav.quizator.actor.Questor;
import com.miroslav.quizator.actor.Quiz;

public class GameUtilInitializer {

    public static Questor createQuestor() {
        return new Questor();
    }
    public static Player createPlayer(){return new Player();}
    public static Quiz createQuiz(){return new Quiz();}
}




















