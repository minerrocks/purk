// Copyright (c) 2017-2018 The Purk Project Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef JSONBUILDER_H
#define JSONBUILDER_H

#include <QObject>

class QJsonObject;
class QJsonArray;
class QJsonDocument;


class JsonBuilder : public QObject
{
    Q_OBJECT
public:
    static QString buildJsonInStringForm(int amount, QString walletAddress);
    static QJsonDocument buildJsonDocument(int amount, QString walletAddress);
private:
    static QJsonObject buildJsonObject(int amount, QString walletAddress);
};
#endif // JSONBUILDER_H
