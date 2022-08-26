package com.miroslav.quizator.actor;

import com.miroslav.quizator.Questions;

public class Quiz {
    Questions questionsForQuiz;

    public Quiz(){
        questionsForQuiz = new Questions();
        appendQuestions();
    }

    public void appendQuestions() {
        questionsForQuiz.appendQuestion(new Question("Software development","What is Agile ?",new String[]{"Project management methodology","Programming language"}));
        questionsForQuiz.appendQuestion(new Question("Computing","How many bit's 1 byte have ?",new String[]{"8","16"}));
        questionsForQuiz.appendQuestion(new Question("Roblox","Which language is used to program games in Roblox Studio?",new String[]{"Lua","C++"}));
        questionsForQuiz.appendQuestion(new Question("Web development","What is HTML ?",new String[]{"Markup language","File format"}));
        questionsForQuiz.appendQuestion(new Question("C++","How you can write a comment in C++ ?",new String[]{"//","#"}));
        questionsForQuiz.shuffleQuestions();
    }

    public Question getFirstQuestion(){
        return this.questionsForQuiz.getFirstQuestion();
    }

    public int getCurrentQuestionIndex() {
        return questionsForQuiz.getCurrentQuestionIndex();
    }

    public int incrementCurrentQuestionIndexByOne(){
        return questionsForQuiz.incrementCurrentQuestionIndexByOne();
    }
    public void setCurrentQuestionIndex(int number){
        questionsForQuiz.setCurrentQuestionIndex(number);
    }

    public boolean isQuizComplete(){
        return getCurrentQuestionIndex() == questionsForQuiz.getQuestionSize()-1;
    }
    public Question getCurrentQuestion(){
        return questionsForQuiz.getCurrentQuestion();
    }

}































