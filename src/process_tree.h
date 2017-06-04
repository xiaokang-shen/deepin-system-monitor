/* -*- Mode: C++; indent-tabs-mode: nil; tab-width: 4 -*-
 * -*- coding: utf-8 -*-
 *
 * Copyright (C) 2011 ~ 2017 Deepin, Inc.
 *               2011 ~ 2017 Wang Yong
 *
 * Author:     Wang Yong <wangyong@deepin.com>
 * Maintainer: Wang Yong <wangyong@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */ 

#ifndef PROCESSTREE_H
#define PROCESSTREE_H

#include <QMap>
#include <QObject>
#include <proc/readproc.h>
#include <proc/sysinfo.h>

class ProcessTree : public QObject
{
    Q_OBJECT
    
    typedef std::map<int, proc_t> storedProcType;
    
    struct Process
    {
        int parentPid;
        QList<int> *childProcesses;
    };
    
public:
    ProcessTree();
    ~ProcessTree();
    
    QList<int> getAllChildPids(int pid);
    void getChildPids(int pid);
    void printNode(int pid);
    void printTree();
    void scanProcesses(storedProcType processes);
    
private:
    QList<int> childrenPids;
    QMap<int, Process> *processMap;
    int rootPid;
};

#endif
