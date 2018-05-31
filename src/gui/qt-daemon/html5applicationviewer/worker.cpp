// Copyright (c) 2017-2018 The Purk Project Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "worker.h"
#include <QTimer>
#include <QEventLoop>

#include <QThread>
#include <QDebug>

#include "simplewallet/simplewallet.h"

Worker::Worker(int argc, char* argv[], QObject *parent) :
    QObject(parent)
{
    m_argc = argc;
    m_argv[0] = argv[0];
    m_argv[1] = argv[1];
    m_argv[2] = argv[2];
    m_argv[3] = argv[3];
    m_argv[4] = argv[4];
    m_argv[5] = argv[5];
    m_argv[6] = argv[6];
}

bool Worker::stop()
{
    return currency::stop_rpc();
}

void Worker::mainLoop()
{
    qDebug()<<"Starting worker mainLoop in Thread "<<thread()->currentThreadId();

    tools::set_confirmation_dialog(true);
    currency::run_wallet_rpc(m_argc, m_argv);
}
