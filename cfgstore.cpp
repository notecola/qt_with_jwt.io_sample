#include "./cfgstore.h"

void CfgStore::SetDefault()
{
	m_Data.m_strAuthenticateURI = "http://ec2-54-183-171-105.us-west-1.compute.amazonaws.com/api/authenticate";
	m_Data.m_strGetAccountURI = "http://ec2-54-183-171-105.us-west-1.compute.amazonaws.com/api/account";
	m_Data.m_strAuthToken = "";
}


bool CfgStore::Load()
{
	QSettings settings("Sample Org", "Sample Soft");

	m_Data.m_strAuthenticateURI = settings.value("api_auth_uri", "").toString();
	m_Data.m_strGetAccountURI = settings.value("api_account_uri", "").toString();
	m_Data.m_strAuthToken = settings.value("auth_token", "").toString();

	//on errors we set all to defaults
	if (m_Data.m_strAuthenticateURI.isEmpty())
	{
		SetDefault();
	}
	return true;
}


bool CfgStore::Save()
{
	QSettings settings("Sample Org", "Sample Soft");
	settings.setValue("api_auth_uri", m_Data.m_strAuthenticateURI);
	settings.setValue("api_account_uri", m_Data.m_strGetAccountURI);
	settings.setValue("auth_token", m_Data.m_strAuthToken);
	settings.sync();
	return true;
}