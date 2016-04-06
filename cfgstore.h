#ifndef QTSAMPLE_CFGSTORE_H
#define QTSAMPLE_CFGSTORE_H

#include <QString>
#include <QSettings>

class CfgStore
{
public:
	struct CfgValues
	{
		QString m_strAuthenticateURI;
		QString m_strGetAccountURI;
		QString m_strAuthToken;
	};

public:
	void SetLocation(const QString & strFilename) { m_strFilename = strFilename; }
	
	//set initial values in case there is no setting file yet
	void SetDefault();

	bool Load();
	bool Save();
	
	//we allow the users to change it anytime
	CfgValues & Settings() { return m_Data; }

private:

	QString m_strFilename;
	CfgValues m_Data;

};

#endif