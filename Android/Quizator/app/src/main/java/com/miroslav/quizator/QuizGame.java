package com.miroslav.quizator;

import android.util.Log;

import com.miroslav.quizator.actor.Player;
import com.miroslav.quizator.actor.Question;
import com.miroslav.quizator.actor.Questor;
import com.miroslav.quizator.actor.Quiz;
import com.miroslav.quizator.initializer.GameUtilInitializer;

public class QuizGame {
    Player quizPlayer;
    Questor quizQuestor;
    Quiz quiz;
    QuizatorMainXMLHelper quizatorMainXMLHelper;

    public QuizGame(QuizatorMainXMLHelper quizatorMainXMLHelper){
        this.quizatorMainXMLHelper = quizatorMainXMLHelper;
        this.quizQuestor = GameUtilInitializer.createQuestor();
        this.quizPlayer = GameUtilInitializer.createPlayer();
        this.quiz = GameUtilInitializer.createQuiz();
        loadFirstQuestion();
    }

    public void loadFirstQuestion(){
        quizatorMainXMLHelper.setQuestionNumberToUI(quiz.getCurrentQuestionIndex());
        quizatorMainXMLHelper.setQuestionToUI(quiz.getFirstQuestion());
    }

    public int getPlayerScore(){
        return quizPlayer.getScore();
    }

    public boolean isQuizCompleted(){
        return quiz.isQuizComplete();
    }

    public void quizGameLogic() {
        quizQuestor.setQuestionAnswerPassedFromPlayer(quizatorMainXMLHelper.getCheckedAnswerFromPlayer());
        quizQuestor.setQuestionGivenToPlayer(quiz.getCurrentQuestion());

        if(quizQuestor.isPlayerAnswerCorrect()){
            quizPlayer.setScore(quizPlayer.incrementScoreByOne());
        }

        if(!quiz.isQuizComplete()){
            toNextQuestion();
        }
    }

    private void toNextQuestion() {
        quiz.setCurrentQuestionIndex(quiz.incrementCurrentQuestionIndexByOne());
        quizatorMainXMLHelper.setTextViewQuestionNumberText(quiz.getCurrentQuestionIndex());
        quizatorMainXMLHelper.setQuestionToUI(quiz.getCurrentQuestion());
    }

}






















