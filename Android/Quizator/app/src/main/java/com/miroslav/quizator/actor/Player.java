package com.miroslav.quizator.actor;

public class Player {
    int score;

    public Player() {
    }

    public int getScore() {
        return score;
    }


    public int incrementScoreByOne() {
        return this.score += 1;
    }

    public void setScore(int score) {
        this.score = score;
    }
}































