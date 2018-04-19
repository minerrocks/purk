// Copyright (c) 2017-2018 The Purk Project Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRANSFERINGWINDOW_H
#define TRANSFERINGWINDOW_H

#include <QDialog>
#include <QString>

class QLabel;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class QSpacerItem;


class TransferingWindow : public QDialog
{
    Q_OBJECT
public:
    explicit TransferingWindow (QWidget * parent = 0);
    ~TransferingWindow ();
    void initializeDevice(QString amount, QString wallet);
signals:
    void startTransfering();
public slots:
    void startSendPayment(bool);
private:
    QLabel *m_AmountValueLabel;
    QLabel *m_AmountTextLabel;
    QLabel *m_WalletValueLabel;
    QLabel *m_WalletTextLabel;

    QPushButton *m_PushButtonSendPayment;
    QPushButton *m_PushButtonCancel;

    QVBoxLayout *m_MainLayout;
    QGridLayout *m_InformationLayout;
    QHBoxLayout *m_ButtonLayout;

    QSpacerItem *m_SpacerItem;
};

#endif
