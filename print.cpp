#include "print.h"
#include<QPrinter>
#include<QPrintDialog>
#include<QTextDocument>
Print::Print()
{
}

void Print::printHtml(const QString &html){
    QPrinter  printer;
    QPrintDialog printDialog(&printer);
    if(printDialog.exec()){
        QTextDocument textDocument;
        textDocument.setHtml(html);
        textDocument.print(&printer);
    }
}
