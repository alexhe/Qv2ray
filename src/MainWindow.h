#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define confDir "conf/"
#define confDatabase "conf/conf.db"
#include <QMainWindow>
#include "ConnectionEditWindow.h"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QScrollBar>

#include "vinteract.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    v2Instance *v2instance;
    QSystemTrayIcon *hTray;
    QMenu *trayMenu = new QMenu(this);
    QMenu *popMenu = new QMenu(this);
    QScrollBar *bar;
    ~MainWindow();

private slots:
    void on_restartButton_clicked();
    void on_actionEdit_triggered();
    void on_actionExisting_config_triggered();
    void UpdateConfigTable();
    void DeleteConfig();
    void showMenu(QPoint pos);
    void UpdateLog();
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void select_triggered();
    void on_clbutton_clicked();
    void on_rtButton_clicked();
    void GenerateConfig(int idIntable);
    void on_activatedTray(QSystemTrayIcon::ActivationReason reason);
    void toggleMainWindowVisibility();
    void quit();
    void on_actionExit_triggered();
    void renameRow();
    void scrollToBottom();
    void on_actionPreferences_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void closeEvent(QCloseEvent *);
    void createTrayAction();

    void CreateTrayIcon();
};

#endif // MAINWINDOW_H
