#include "SLT_Application.h"
#include "AssessorForm.h"

SLT_Application::SLT_Application(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

SLT_Application::~SLT_Application()
{
}

void SLT_Application::on_actionAdd_a_new_assessor_triggered()
{
    auto* widget = new AssessorForm(this);
    setCentralWidget(widget);
}