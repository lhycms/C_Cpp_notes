#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>


class Question {
private:
    std::string Content;    // The content of the question.
    unsigned int OptionsCount;  // The number of options in question.
    std::initializer_list<std::string> OptionsLst;  // The options for this question.
    unsigned int Answer;    // The answer for question.

public:
    /* 
        Initialize the Question object.
    */
    Question(std::string content, unsigned int optionsCount, std::initializer_list<std::string> optionsLst) {
        Content = content;
        OptionsCount = optionsCount;
        OptionsLst = optionsLst;
    }

    /*
        Show the question (content and options)
    */
    void ShowContentOptions() {
        std::cout << Content << std::endl;   // show the content
        unsigned int optionI = 1;
        for (auto begin = OptionsLst.begin(); begin != OptionsLst.end(); begin++){   // show the options
            std::cout << optionI++ << ". " << *begin << std::endl;
        }

        std::cout << std::endl;
    }

    void AnswerQuestion() {
        while(std::cin >> Answer) {
            if (Answer > 0 && Answer <= OptionsCount)
                return;
            else    
                std::cout << "Look carefully at options.\n";
        }
    }
};


class Questionnaire {
private:
    std::vector<Question> QuestionsLst;

public:
    static unsigned int QuestionsCount; // The number of question in questionnaire
    
    /*
        Constructor function
    */
    Questionnaire(std::vector<Question> questionsLst) {
        QuestionsLst = questionsLst;
    }

    void FillInProcess() {
        for (auto begin = QuestionsLst.begin(); begin != QuestionsLst.end(); begin++) {
            begin->ShowContentOptions();
            begin->AnswerQuestion();
        }
    }
};