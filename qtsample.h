#ifndef QTSAMPLE_H
#define QTSAMPLE_H

#include <QtWidgets/QMainWindow>
#include <QSettings>
#include <QDebug>
#include <QNetworkReply>
#include <QLabel>
#include <QJsonDocument>

#include "./cfgstore.h"
#include "./ui_qtsample.h"

class qtsample : public QMainWindow
{
	Q_OBJECT

public:
	qtsample(QWidget *parent = 0);
	~qtsample();

	//loads the settings and does the checks
	bool Init(const QString & strSettingsFile);

	//put something on the screen
	void Log(const QString & str);

	//remote API functions
	void Authenticate();
	void GetAccountInfo();


public slots:

	void onAuthRequestFinished(QNetworkReply *reply);
	void onAccInfoRequestFinished(QNetworkReply *reply);

	void onApiAuthError(QNetworkReply::NetworkError);
	void onApiAccountError(QNetworkReply::NetworkError);

//custom stuff
private:
	Ui::qtsampleClass ui;

	CfgStore m_Config;

	//account info response here
	QJsonDocument m_jsonAccInfo;

};

#endif // QTSAMPLE_H
