#include "qua.h"


//unsigned int Questionnaire::QuestionsCount = 0;

int main() {
    /* 
        initialize the first question
    */
    std::string content = "How old are you?";
    unsigned int optionCount = 3;
    std::initializer_list<std::string> optionsLst = {"22", "23", "24"};
    Question question(content, optionCount, optionsLst);


    
    Questionnaire questionnnaire({ question, question });   // Initialize questionnaire
    questionnnaire.FillInProcess(); //  Fill in the whole questionnaire.
    return 0;
}