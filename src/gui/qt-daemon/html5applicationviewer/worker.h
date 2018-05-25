// Copyright (c) 2017-2018 The Purk Project Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QMutex>
#include <QWaitCondition>

class Worker : public QObject
{
    Q_OBJECT

public:
    explicit Worker(int argc, char* argv[], QObject *parent = 0);

private:
    int m_argc;
    char* m_argv[7]; 

public slots:
    bool stop();
    void mainLoop();
};

#endif // WORKER_H
