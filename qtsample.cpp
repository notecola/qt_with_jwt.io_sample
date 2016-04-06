#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVBoxLayout>
#include <QLabel>

#include "./qtsample.h"


qtsample::qtsample(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

qtsample::~qtsample()
{

}

//just put the log on the screen
void qtsample::Log(const QString & str)
{
	qDebug() << str;
	
	QString strOld = ui.textEdit->toPlainText();
	strOld += '\n' + str;
	ui.textEdit->setText(strOld);
}

//load settings, initiate the first step
bool qtsample::Init(const QString & strSettingsFile)
{

	Log("Starting...");

	m_Config.SetLocation(strSettingsFile);
	m_Config.Load();

	//attempt to use old session token
	if (!m_Config.Settings().m_strAuthToken.isEmpty())
	{
		Log("Token found, using stored value...");
		GetAccountInfo();
	}
	else{
		Log("No token found, getting new...");
		Authenticate();
	}
	return true;
}

//remote API call to get a token
void qtsample::Authenticate()
{
	Log("Authenticating...");

    QNetworkAccessManager * pManager= new QNetworkAccessManager(this);
	connect(pManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(onAuthRequestFinished(QNetworkReply*)));

    QNetworkRequest request;
    QByteArray data;
	data.append("{\"password\":\"admin\", \"rememberMe\":true,\"username\":\"admin\"}");
	request.setRawHeader("Content-Type", "application/json");
	request.setRawHeader("Accept", "application/json");
	request.setUrl(QUrl(m_Config.Settings().m_strAuthenticateURI));

    QNetworkReply * pReply = pManager->post(request, data);
	QObject::connect(pReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onApiAuthError(QNetworkReply::NetworkError)));
}

//remote API call to get account info
void qtsample::GetAccountInfo()
{
	Log("Getting account info...");

    QNetworkAccessManager * pManager= new QNetworkAccessManager(this);
	connect(pManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(onAccInfoRequestFinished(QNetworkReply*)));

    QNetworkRequest request;
    QByteArray data;

	request.setUrl(QUrl(m_Config.Settings().m_strGetAccountURI));
	request.setRawHeader("Content-Type", "application/json");
	request.setRawHeader("Accept", "application/json");
	QString strBearer("Bearer ");
	strBearer.append(m_Config.Settings().m_strAuthToken);
	request.setRawHeader("Authorization", strBearer.toLocal8Bit());

	QNetworkReply * pReply = pManager->get(request);
	QObject::connect(pReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onApiAccountError(QNetworkReply::NetworkError)));
}

void qtsample::onApiAuthError(QNetworkReply::NetworkError err)
{
	Log(QString("Error while sending Authenticate request: ") + QString::number(err));
}

void qtsample::onApiAccountError(QNetworkReply::NetworkError err)
{
	Log(QString("Error while sending Account Info HTTP request: ") + QString::number(err));
}

//after auth success we initiate get account info
void qtsample::onAuthRequestFinished(QNetworkReply * pResponse)
{
	if (pResponse->error() == QNetworkReply::NoError)
	{
			const QByteArray & tmpData = pResponse->readAll();
			QJsonParseError parseError;
			QJsonDocument jsonData(QJsonDocument::fromJson(tmpData, &parseError));
			if (parseError.error != QJsonParseError::NoError)
			{
				Log("Auth response json malformed: " + parseError.errorString());
			}
			else
			{
				const QJsonObject & jsonObject = jsonData.object();
				const QString & strToken = jsonObject["id_token"].toString();
				Log(QString("we have a token: ") + strToken);
				m_Config.Settings().m_strAuthToken = strToken;
				m_Config.Save();

				//done with auth... do whatever we need
				GetAccountInfo();
			}
	}
	else
	{
			Log("Network error: " +  pResponse->errorString());

	}
}

void qtsample::onAccInfoRequestFinished(QNetworkReply * pResponse)
{
	if (pResponse->error() == QNetworkReply::NoError)
	{
			const QByteArray & tmpData = pResponse->readAll();
			QJsonParseError parseError;
			m_jsonAccInfo = QJsonDocument::fromJson(tmpData, &parseError);
			if (parseError.error != QJsonParseError::NoError)
			{
				Log("Account Info json malformed: " + parseError.errorString());
			}
			else
			{
				QString strBuffer;
				QTextStream txtData(&strBuffer);
				QJsonObject & jsonObject = m_jsonAccInfo.object();
				for (QJsonObject::iterator it = jsonObject.begin(), end = jsonObject.end(); it != end; it++) 
				{
					txtData << it.key() << ": " << it.value().toString();
					endl(txtData);
				}
				Log("Account Info request successful");
				Log(txtData.readAll());
			}
	}
	else
	{
			Log("Network error: " +  pResponse->errorString());

	}
}
