#include "controller.h"

#include <string>

Controller::Controller(MathCalculator *m1, Credit *m2, Deposit *m3): model_math(m1), model_credit(m2), model_deposit(m3) {};

Controller::~Controller(){};

void Controller::OnCalculateButtonClicked(MainWindow* w) {
    std::string input_string = w->GetInputString();
    std::string input_string_x = w->GetInputStringX();
    model_math->CalculateAnswer(input_string, input_string_x);
    double answer = model_math->GetAnswer();
    w->SetAnswer(answer);
}

