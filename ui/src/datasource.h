#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QObject>
#include <QVariant>

#include <KDb3/KDbConnection>

class DataSource: public QObject
{
    Q_OBJECT

public:
    enum Type {
        Heartrate = 1,
        Steps = 2,
        Sleep = 3,
        Intensity = 4,
        StepSummary = 5,
        SleepSummary = 6
    };
    Q_ENUM(Type)

    DataSource();
    void setConnection(KDbConnection *conn);

    Q_INVOKABLE QVariant data(DataSource::Type type, const QDate  &day);

private:
    KDbConnection *m_conn = nullptr;
};

#endif // DATASOURCE_H
