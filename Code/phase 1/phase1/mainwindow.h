#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ZippingProcess.h"
#include "DirectoryRevision.h"
#include <QMainWindow>
#include <QCoreApplication>
#include "QDebug"
#include "JlCompress.h"
#include "QFile"
#include "QLabel"
#include "QLineEdit"
#include "QTreeWidget"
#include "QTreeWidgetItem"
#include "QIcon"
#include "QPixmap"
#include "QMessageBox"
#include "FileFormat.h"
#include "fstream"
#include "DataBaseConnection.h"
#include "QCheckBox"

using namespace std ;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow , public Directory
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void adjustLayout();
    void setSize();
    void setIconForTopLevelItem(QTreeWidgetItem *tr);
    void setIconForPhase1Children(QTreeWidgetItem *tr);
    void addingChildrenToTree();
    void readingFromDatabase(vector<FileFormat> &file);
    void makingNewDirectoryforTree(vector<FileFormat> &file);
    void removeWidgets();
    void generalSort();
    void sortName();
    void sortDate();
    void sortType();
    void removeChildMainList();
    void hideRemove_Add_Widgets();
    void removeFromTree();
    bool checkDirectoryExistance() ;
    void Unzipagain();
    ZippingProcess * zip ;
    QLabel * tree_header_label_first_column ;
    QTreeWidgetItem * tr_main;
    QTreeWidgetItem * tr_name_main ;
    QTreeWidgetItem * tr_date_main ;
    QTreeWidgetItem * tr_type_main ;
    QTreeWidgetItem * tr_remove_main ;
    QTreeWidgetItem * tr_main_sub_folder ;
    QList<QTreeWidgetItem *> items;
    QList<QTreeWidgetItem *> items_name;
    QList<QTreeWidgetItem *> items_date;
    QList<QTreeWidgetItem *> items_type;
    QList<QTreeWidgetItem *> items_remove ;
    Dbconnection  * db ;

private slots:
    void on_actionName_triggered();

    void on_actionDate_triggered();

    void on_actionType_triggered();

    void on_actionReset_triggered();

    void on_remove_clicked();

    void on_cancel_clicked();

    void on_add_clicked();

    void on_apply_clicked();

    void on_actionPrivacy_policy_triggered();

    void on_actionHelp_triggered();

private:
    Ui::MainWindow *ui;



};
#endif // MAINWINDOW_H
