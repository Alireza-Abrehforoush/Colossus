#ifndef AUTOCOMPLETEACTION_H
#define AUTOCOMPLETEACTION_H

#include <QObject>
#include <QACtion>
class AutoCompleteAction: public QAction
{
     Q_OBJECT

signals:
    void autocomplete_action_triggered(const QString& content);
private slots:
    void interface_slot_action_triggered();


public:
    AutoCompleteAction(QString text,QWidget* parent=nullptr);


};

#endif // AUTOCOMPLETEACTION_H
