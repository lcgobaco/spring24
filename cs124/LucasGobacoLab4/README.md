In taskMenu.cpp, any line with a comment:

//TODO and DONE: Replaced TaskList with TaskHashTable

will show the new TaskHashTable calls with the old TaskList calls commented out.

There are 7 changes in TaskMenu.cpp
1.)

list = new TaskList();
replaced with
table = new TaskHashTable();

2.)

delete list;
replaced with
delete table;

3.)

list->printTable(false);
replaced with
table->printTable(false);

4.)

list->printTable(true);
replaced with
table->printTable(true);

5.)

list->addNew();
replaced with
table->addNew() wrapped in a try/catch.


6.)

list->editTask();
replaced with
table->editTask() wrapped in a try/catch.

7.)

list->deleteTask();
replaced with
table->deleteTask() wrapped in a try/catch.

