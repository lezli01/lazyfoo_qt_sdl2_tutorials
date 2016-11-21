#pragma once

#include <string>

#include <QString>

class Exception
{
    public:
        Exception(const QString &message)
            : message(message)
        {}

        QString msg() const
        {
            return message;
        }

        std::string stdMsg() const
        {
            return message.toStdString();
        }

    protected:
        QString message;
};
