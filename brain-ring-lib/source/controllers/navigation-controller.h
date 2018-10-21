#ifndef NAVIGATIONCONTROLLER_H
#define NAVIGATIONCONTROLLER_H

#include <QObject>

#include <brain-ring-lib_global.h>
#include <models/game.h>
#include <data/stringdecorator.h>

namespace br {
namespace controllers {

class BRAINRINGLIBSHARED_EXPORT NavigationController : public QObject
{
    Q_OBJECT
public:
    explicit NavigationController(QObject* parent = nullptr) : QObject(parent){}

signals:
//    void goGameView(br::models::Game* game);
    void goDashboardView();
    void goCreateGameView();
    void goSettingsView();
    void goGameView();
    void goGameQuestionView(br::models::Game* game);
    void goGameAnswerView(br::data::StringDecorator* number);
    void goPlayerWinView(br::data::StringDecorator* number);
    void goEmptyQuestionsListView();
    void goGameOverView();
};

}
}

#endif // NAVIGATIONCONTROLLER_H
