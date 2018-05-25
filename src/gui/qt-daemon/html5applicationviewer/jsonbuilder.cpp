// Copyright (c) 2017-2018 The Purk Project Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "jsonbuilder.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QString>

#define KEY_DESTINATION "destinations"
#define KEY_ADDRESS   "address"
#define KEY_AMOUNT    "amount"
#define KEY_MIXIN_COUNT "mixin_count"
#define KEY_LOCK_TIME "lock_time"
#define KEY_PAYMENT_ID "payment_id"
#define KEY_FEE "fee"

#include <QDebug>

QString JsonBuilder::buildJsonInStringForm(int amount, QString walletAddress)
{
    QJsonDocument lDoc(buildJsonDocument(amount, walletAddress));
    QByteArray lByteArrayJson = lDoc.toJson();
    qDebug() << lByteArrayJson;
    return QString(lByteArrayJson);
}
QJsonDocument JsonBuilder::buildJsonDocument(int amount, QString walletAddress)
{
    QJsonDocument lJsonDocument(buildJsonObject(amount, walletAddress));
    return lJsonDocument;
}

QJsonObject JsonBuilder::buildJsonObject(int amount, QString walletAddress)
{
    QJsonObject lMainObject;
    QJsonObject lDestinationObject;
    lDestinationObject.insert(KEY_AMOUNT, QString::number(amount));
    lDestinationObject.insert(KEY_ADDRESS, walletAddress);

    QJsonArray lDestinationArray;
    lDestinationArray.append(lDestinationObject);

    lMainObject.insert(KEY_DESTINATION, lDestinationArray);
    lMainObject.insert(KEY_MIXIN_COUNT, 0);
    lMainObject.insert(KEY_LOCK_TIME, 0);
    lMainObject.insert(KEY_PAYMENT_ID,"");
    lMainObject.insert(KEY_FEE, "0.001");
    // QJsonArray lSubdirs;
    // foreach (EEFolderModel *dir, directory->getFolderList()) {
    //     lSubdirs.push_back(buildJsonObject(dir));
    // }
    // QJsonArray lFiles;
    // QJsonObject lFileObject;
    // foreach (EEModel *file, directory->getFilesList()) {
    //     lFileObject.insert(KEY_NAME, file->name());
    //     lFileObject.insert(KEY_UPDATED, file->updated().toString());
    //     lFiles.append(lFileObject);
    // }
    // lFolderObject.insert(KEY_FILES, lFiles);
    // lFolderObject.insert(KEY_SUBDIRS, lSubdirs);
    return lMainObject;
}
