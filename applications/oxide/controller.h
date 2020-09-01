#pragma once

#include <QObject>
#include <QJsonObject>
#include "appitem.h"
#include "eventfilter.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    EventFilter* filter;
    QObject* root = nullptr;
    explicit Controller(QObject* parent = 0) : QObject(parent){}
    Q_INVOKABLE void loadSettings();
    Q_INVOKABLE void saveSettings();
    Q_INVOKABLE QList<QObject*> getApps();
    Q_INVOKABLE void powerOff();
    Q_INVOKABLE void suspend();
    Q_INVOKABLE void killXochitl();
    void updateBatteryLevel();
    void updateWifiState();
    Q_INVOKABLE void resetInactiveTimer();
    Q_PROPERTY(bool automaticSleep MEMBER m_automaticSleep WRITE setAutomaticSleep NOTIFY automaticSleepChanged);
    bool automaticSleep() const {
        return m_automaticSleep;
    };
    void setAutomaticSleep(bool);
    Q_PROPERTY(int columns MEMBER m_columns WRITE setColumns NOTIFY columnsChanged);
    int columns() const {
        return m_columns;
    };
    void setColumns(int);
    Q_PROPERTY(int fontSize MEMBER m_fontSize WRITE setFontSize NOTIFY fontSizeChanged);
    int fontSize() const {
        return m_fontSize;
    };
    void setFontSize(int);
    Q_PROPERTY(bool showWifiDb MEMBER m_showWifiDb WRITE setShowWifiDb NOTIFY showWifiDbChanged);
    bool showWifiDb() const {
        return m_showWifiDb;
    };
    void setShowWifiDb(bool);
    Q_PROPERTY(bool showBatteryPercent MEMBER m_showBatteryPercent WRITE setShowBatteryPercent NOTIFY showBatteryPercentChanged);
    bool showBatteryPercent() const {
        return m_showBatteryPercent;
    };
    void setShowBatteryPercent(bool);
    Q_PROPERTY(int sleepAfter MEMBER m_sleepAfter WRITE setSleepAfter NOTIFY sleepAfterChanged);
    int sleepAfter() const {
        return m_sleepAfter;
    };
    void setSleepAfter(int);
signals:
    void automaticSleepChanged(bool);
    void columnsChanged(int);
    void fontSizeChanged(int);
    void showWifiDbChanged(bool);
    void showBatteryPercentChanged(bool);
    void sleepAfterChanged(int);
private:
    bool m_automaticSleep = true;
    int m_columns = 6;
    int m_fontSize = 23;
    bool m_showWifiDb = false;
    bool m_showBatteryPercent = false;
    int m_sleepAfter = 5;

    bool batteryAlert = false;
    bool batteryWarning = false;
    bool batteryCharging = false;
    int batteryLevel = 0;
    int batteryTemperature = 0;

    QString wifiState = "Unknown";
    int wifiLink = 0;
    int wifiLevel = 0;
    bool wifiConnected = false;

};
bool exists(const std::string& name);
