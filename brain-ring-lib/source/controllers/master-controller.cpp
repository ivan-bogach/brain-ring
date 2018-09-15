#include "master-controller.h"

namespace br {
namespace controllers {

class MasterController::Implementation
{
public:
    Implementation(MasterController* _masterController)
        : masterController(_masterController)
    {
        commandController = new CommandController(masterController);
        navigationController = new NavigationController(masterController);
    }

    MasterController* masterController{nullptr};
    NavigationController* navigationController{nullptr};
    CommandController* commandController{nullptr};
    QString welcomeMessage = "This is MasterController to MJBHjk  qaslkfjklasd";
};

MasterController::MasterController(QObject *parent) : QObject(parent)
{
    implementation.reset(new Implementation(this));
}

MasterController::~MasterController(){}

NavigationController* MasterController::navigationController()
{
    return implementation->navigationController;
}

CommandController* MasterController::commandController()
{
    return implementation->commandController;
}

const QString& MasterController::welcomeMessage() const
{
    return implementation->welcomeMessage;
}

}}

