#include "KioskMessage.h"
#include <QUrl>

KioskMessage::KioskMessage(const QByteArray &rawMessage) :
    rawMessage_(rawMessage)
{
}

KioskMessage::KioskMessage(KioskMessage::Type type, QByteArray payload) :
    rawMessage_(payload.prepend((char) type))
{
}

KioskMessage::KioskMessage(const char *buffer, int length) :
    rawMessage_(buffer, length)
{
}

KioskMessage::Type KioskMessage::type() const
{
    return (KioskMessage::Type) rawMessage_.at(0);
}

QByteArray KioskMessage::payload() const
{
    return rawMessage_.mid(1);
}

KioskMessage KioskMessage::progressMessage(int progress)
{
    char message[2] = {KioskMessage::Progress, (char) progress};
    return KioskMessage(message, sizeof(message));
}

KioskMessage KioskMessage::loadingPageMessage()
{
    char message[1] = {KioskMessage::LoadingPage};
    return KioskMessage(message, sizeof(message));
}

KioskMessage KioskMessage::finishedLoadingPageMessage()
{
    char message[1] = {KioskMessage::FinishedLoadingPage};
    return KioskMessage(message, sizeof(message));
}

KioskMessage KioskMessage::urlChanged(const QUrl &url)
{
    QByteArray str = url.toString().toUtf8();
    return KioskMessage(KioskMessage::URLChanged, str);
}

KioskMessage KioskMessage::wakeup()
{
    char message[1] = {KioskMessage::Wakeup};
    return KioskMessage(message, sizeof(message));
}
