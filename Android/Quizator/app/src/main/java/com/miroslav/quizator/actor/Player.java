package com.miroslav.quizator.actor;

public class Player {
    int score;

    public int incrementScoreByOne() {
        //TODO Encapsulate Boundary Conditions

        return this.score + 1;
    }
    public void setScore(int score) {
        this.score = score;
    }
    public int getScore() {
        return score;
    }
}































