#include "autocompleteaction.h"

void AutoCompleteAction::interface_slot_action_triggered()
{
    emit this->autocomplete_action_triggered(this->text());
}

AutoCompleteAction::AutoCompleteAction(QString content,QWidget* parent)
    :QAction(content,parent)
{
    connect(this,SIGNAL(triggered()),this,SLOT(interface_slot_action_triggered()));
}
