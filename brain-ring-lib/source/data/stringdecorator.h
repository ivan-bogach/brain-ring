#ifndef STRINGDECORATOR_H
#define STRINGDECORATOR_H

#include <QJsonObject>
#include <QJsonValue>
#include <QObject>
#include <QScopedPointer>
#include <QString>

#include <brain-ring-lib_global.h>
#include <data/datadecorator.h>

namespace br {
namespace data {

class BRAINRINGLIBSHARED_EXPORT StringDecorator : public DataDecorator
{
    Q_OBJECT

    Q_PROPERTY(QString ui_value READ value WRITE setValue NOTIFY valueChanged)

public:
    StringDecorator(Entity* parentEntity = nullptr, const QString& key = "SomeItemKey", const QString& label ="", const QString& value = "");
    ~StringDecorator();

    StringDecorator& setValue(const QString& value);
    const QString& value() const;

    QJsonValue jsonValue() const override;
    void update(const QJsonObject& jsonObject) override;

signals:
    void valueChanged();

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}
}

#endif // STRINGDECORATOR_H
