// Copyright (c) 2017-2018 The Purk Project Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "transferingwindow.h"

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSpacerItem>

TransferingWindow::TransferingWindow(QWidget *parent) : QDialog(parent) 
{
    m_PushButtonSendPayment = new QPushButton("Send Payment", this);
    m_PushButtonCancel = new QPushButton("Cancel", this);
    m_AmountTextLabel = new QLabel("Amount:", this);        
    m_WalletTextLabel = new QLabel("Wallet address:", this);

    m_AmountValueLabel = new QLabel(this);
    m_WalletValueLabel = new QLabel(this);


    m_MainLayout = new QVBoxLayout(this);
    m_InformationLayout = new QGridLayout(this);
    m_ButtonLayout = new QHBoxLayout(this);

    m_InformationLayout->addWidget(m_AmountTextLabel, 0, 0);
    m_InformationLayout->addWidget(m_AmountValueLabel, 0, 1);
    m_InformationLayout->addWidget(m_WalletTextLabel, 1, 0);
    m_InformationLayout->addWidget(m_WalletValueLabel, 1, 1);


    m_SpacerItem = new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed);
    m_ButtonLayout->addSpacerItem(m_SpacerItem);

    m_ButtonLayout->addWidget(m_PushButtonSendPayment);
    m_ButtonLayout->addWidget(m_PushButtonCancel);
    
    // m_MainLayout->resize(width, height);

    m_MainLayout->addLayout(m_InformationLayout);
    m_MainLayout->addLayout(m_ButtonLayout);
    this->setLayout(m_MainLayout);

    m_PushButtonSendPayment->setDefault(true);
    connect(m_PushButtonSendPayment, SIGNAL(clicked(bool)), this, SLOT(startSendPayment(bool)));
    connect(m_PushButtonCancel, SIGNAL(clicked(bool)), this, SLOT(close()));
}

TransferingWindow::~TransferingWindow() 
{
}

void TransferingWindow::initializeDevice(QString amount, QString wallet) 
{
    m_AmountValueLabel->setText(amount);

    //separate wallet's address on three parts
    int lWalletSize = wallet.size() / 3;
    wallet.insert(lWalletSize, "\n");
    wallet.insert(lWalletSize * 2 + 1, "\n");
    m_WalletValueLabel->setText(wallet);

    this->show();
    this->resize(350,150);
}

void TransferingWindow::startSendPayment(bool)
{
    emit startTransfering();
    close();
}
