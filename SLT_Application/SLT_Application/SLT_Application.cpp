#include "SLT_Application.h"
#include "AssessorForm.h"
#include "ManageAssessor.h"

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
    auto* window = new AssessorForm();
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->setWindowFlags(Qt::Window); // Faz abrir como janela independente
    window->setFixedSize(500, 400);     // Defina o tamanho desejado
    window->show();
}

void SLT_Application::on_actionManage_assessor_triggered()
{
    auto* window = new ManageAssessor();
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->setWindowFlags(Qt::Window);
    window->setFixedSize(700, 500); // ajuste conforme necessário
    window->show();
}