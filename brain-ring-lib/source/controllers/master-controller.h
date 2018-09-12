#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include <QScopedPointer>
#include <QString>

#include <brain-ring-lib_global.h>
#include <controllers/navigation-controller.h>

namespace br {
namespace controllers {

//to use this class outside of this project (in the UI project), BRAINRINGLIBSHARED_EXPORT macro
class BRAINRINGLIBSHARED_EXPORT MasterController : public QObject
{
//inherit from QObject requires Q_OBJECT macro and an overloaded constructor that takes a QObject parent.
    Q_OBJECT

// creating	a new	property of the	QString	type to be able to ACCESS this member FROM QML
// refer to the property	as ui_welcomeMessage and get (or set) the	value in the MEMBER welcomeMessage
    Q_PROPERTY(QString ui_welcomeMessage READ welcomeMessage CONSTANT)

//br::controllers:: because UI QML is not executing within the scope of br namespace
    Q_PROPERTY(br::controllers::NavigationController* ui_navigationController READ navigationController CONSTANT)

public:
    explicit MasterController(QObject* parent = nullptr);
    ~MasterController();

    NavigationController* navigationController();
    const QString& welcomeMessage() const;

signals:

public slots:

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}
}

#endif // MASTERCONTROLLER_H
