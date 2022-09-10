package com.miroslav.quizator.initializer;

import com.miroslav.quizator.actor.*;

public class GameUtilInitializer {
    public static Questor createQuestor() {
        return new Questor();
    }
    public static Player createPlayer(){return new Player();}
    public static Quiz createQuiz(){return new Quiz();}
}




















