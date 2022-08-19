package com.miroslav.quizator;

import android.view.LayoutInflater;
import android.view.ViewGroup;

public interface Binding {
    void initActivityDataBindingUtilContent();

    void initFragmentDataBindingUtilContent(LayoutInflater inflater, ViewGroup container);

    void setBinding();

    <T> T getBinding();
}
