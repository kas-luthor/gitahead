//
//          Copyright (c) 2017, Scientific Toolworks, Inc.
//
// This software is licensed under the MIT License. The LICENSE.md file
// describes the conditions under which this software may be distributed.
//
// Author: Jason Haslam
//

#include "ShowTool.h"
#include "conf/Settings.h"
#include "git/Repository.h"
#include <QDesktopServices>
#include <QDir>
#include <QFileInfo>
#include <QProcess>
#include <QUrl>

#if defined(Q_OS_MAC)
#define NAME "Finder"
#elif defined(Q_OS_WIN)
#define NAME "Explorer"
#else
#define NAME "Default File Browser"
#endif

bool ShowTool::openFileManager(QString path)
{
  QString fileManagerCmd = Settings::instance()->value("filemanager/command").toString();

  if (fileManagerCmd.isEmpty()) {
#if defined(Q_OS_WIN)
    fileManagerCmd = "explorer \"%1\"";

#elif defined(Q_OS_MACOS)
    fileManagerCmd = "open \"%1\"";

#elif defined(Q_OS_UNIX)
    fileManagerCmd = "xdg-open \"%1\"";
#endif
  }

  QStringList cmdParts = QProcess::splitCommand(fileManagerCmd);

  path = QDir::toNativeSeparators(path);

  for(QString &part : cmdParts)
    part = part.arg(path);

  QString program = cmdParts.takeFirst();
  return QProcess::startDetached(program, cmdParts);
}

ShowTool::ShowTool(const QString &file, QObject *parent)
  : ExternalTool(file, parent)
{}

ExternalTool::Kind ShowTool::kind() const
{
  return Show;
}

QString ShowTool::name() const
{
  return tr("Show in %1").arg(NAME);
}

bool ShowTool::start()
{
#if defined(Q_OS_MAC)
  return QProcess::startDetached("/usr/bin/osascript", {
    "-e", "tell application \"Finder\"",
    "-e", QString("reveal POSIX file \"%1\"").arg(mFile),
    "-e", "activate",
    "-e", "end tell"
  });
#elif defined(Q_OS_WIN)
  return QProcess::startDetached("explorer.exe", {
    "/select,", QDir::toNativeSeparators(mFile)
  });
#else
  QFileInfo info(mFile);
  return openFileManager(info.isDir() ? info.filePath() : info.path());
#endif
}
