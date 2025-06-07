#include "SLT_Application.h"
#include "Assessor.h"
#include "ManageAssessor.h"

using namespace silver;

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
    Assessor* window = new Assessor(this);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->setWindowFlags(Qt::Window);
    window->setFixedSize(500, 400);
    window->show();
}

void SLT_Application::on_actionManage_assessor_triggered()
{
    ManageAssessor* window = new ManageAssessor(this);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->setWindowFlags(Qt::Window);
    window->setFixedSize(700, 500);
    window->show();
}